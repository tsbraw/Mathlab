
#include <QDateEdit>
#include <QDateTime>
#include <QVariant>
#include <QMessageBox>
#include <QInputDialog>
#include <QGridLayout>
#include <boost/bind.hpp>

#include "MathLabAddWidget.h"
#include "MathLabLoginWidget.h"
#include "MathLab.h"

Q_DECLARE_METATYPE(CourseInfoPtr);

MathLab::MathLab(QWidget *parent, Qt::WFlags flags, UserInfoPtr userinfo)
	: QMainWindow(parent, flags)
	, MathLabDataService()
{
	ui.setupUi(this);

	_myInfo = userinfo;

	setWindowIcon(QIcon(":/Icon/mathLab.ico"));

	Init();

	InitSystemTray();

	InitTreeWidget();

	if (_myInfo->Usertype == Students)
	{
		ui.pushButton_new->setHidden(true);
		ui.pushButton_del->setHidden(true);
	}
	else
	{
		connect(ui.tableWidget_MathClass, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(OnTableWidgetDouble(QTableWidgetItem*)));
	}

	connect(ui.pushButton_new, SIGNAL(clicked()), this, SLOT(OnNewCourseClicked()));
	connect(ui.pushButton_del, SIGNAL(clicked()), this, SLOT(OnDelCourseClicked()));
	connect(ui.pushButton_resetDate, SIGNAL(clicked()), this, SLOT(OnResetDateClicked()));
	connect(ui.dateEdit, SIGNAL(dateTimeChanged( const QDateTime & )), this, SLOT(OnDateEditChanged( const QDateTime & )));

}

void MathLab::Init()
{
	ui.tableWidget_MathClass->horizontalHeader()->setResizeMode(QHeaderView::Stretch); //自适应列宽;
	ui.tableWidget_MathClass->verticalHeader()->setResizeMode(QHeaderView::Stretch); //自适应行高;

	ui.tableWidget_MathClass->setRowCount(5);
	ui.tableWidget_MathClass->setColumnCount(7);

	ui.tableWidget_MathClass->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_MathClass->setSelectionMode(QAbstractItemView::SingleSelection);

	current_date_time = QDateTime::currentDateTime();

	ui.dateEdit->setCalendarPopup(true);
	ui.dateEdit->setDateTime(current_date_time);
	SetWeekTime(current_date_time);

	UpdateTable();

	pSystemTray = new QSystemTrayIcon(this);

	_LabList = GetLabCourseList();

	QAction * cInfo = new QAction(QString::fromLocal8Bit("课程安排"),this);
	connect(cInfo,SIGNAL(triggered()),this,SLOT(showMineCourses()));
	QAction * quit = new QAction(QString::fromLocal8Bit("登出"),this);
	connect(quit,SIGNAL(triggered()),this,SLOT(ReturnToLogin()));
	ui.menu_mine->addAction(cInfo);
	ui.menu_mine->addAction(quit);

	QAction * sch = new QAction(QString::fromLocal8Bit("按班级"),this);
	connect(sch,SIGNAL(triggered()),this,SLOT(SearchClassCourse()));
	ui.menu_search->addAction(sch);
}

MathLab::~MathLab()
{
	if (pSystemTray)
	{
		delete pSystemTray;
	}
	_LabList.clear();
	_DateList.clear();
}

void MathLab::OnDateEditChanged(const QDateTime & dateTime)
{
	SetWeekTime(dateTime);
	UpdateTable();
}

void MathLab::OnNewCourseClicked()
{
	QTableWidgetItem * item = ui.tableWidget_MathClass->currentItem();
	QTreeWidgetItem *trItem = ui.treeWidget_Class->currentItem();

	if (!trItem || !trItem->parent())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("未选择课程教室"),  QString::fromLocal8Bit("请在教室列表选择对应教室！")
			, QMessageBox::Ok, QMessageBox::Cancel);
	}
	else if (!item)
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("未选择课程时间"),  QString::fromLocal8Bit("请选择添加课程对应的时间段！")
			, QMessageBox::Ok, QMessageBox::Cancel);
	}
	else if (!item->text().isEmpty())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("已有课程"),  QString::fromLocal8Bit("该时间段已有课程安排！")
			, QMessageBox::Ok, QMessageBox::Cancel);
	}
	else
	{
		QString classRoom = trItem->text(0);
		OnNewCourse(classRoom, item);

	}
	
}

void MathLab::OnNewCourse(QString classRoom, QTableWidgetItem * item)
{
	MathLabAddWidget * addWidget = new MathLabAddWidget();

	if (addWidget->exec() == QDialog::Accepted)
	{
		int col = item->column();
		CourseInfoPtr courseInfo = addWidget->GetCourseInfo();
		if (courseInfo)
		{
			QString Da = ui.tableWidget_MathClass->horizontalHeaderItem(col)->data(Qt::UserRole).value<QString>();
			QDateTime DayTime = QDateTime::fromString(Da, "yyyy.MM.dd");
			courseInfo->TimeDay = DayTime;
			courseInfo->TeacherName = _myInfo->UserClass;
			courseInfo->CourseIdx = item->row();
			courseInfo->LabName = classRoom;
			_DateList[DayTime].push_back(courseInfo);
		}


		_LabList[classRoom] = _DateList;
		SetLabCourseList(_LabList);

		UpdateTable();
	}
}

void MathLab::OnDelCourseClicked()
{
	QTableWidgetItem * item = ui.tableWidget_MathClass->currentItem();
	QTreeWidgetItem *trItem = ui.treeWidget_Class->currentItem();
	if (!item)
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("未选中单元格"),  QString::fromLocal8Bit("请选择删除课程对应的单元格！")
			, QMessageBox::Ok, QMessageBox::Cancel);
	}
	else if (item->text().isEmpty())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("无课程安排"),  QString::fromLocal8Bit("当前时间段无课程安排！")
			, QMessageBox::Ok, QMessageBox::Cancel);
	}
	else
	{
		QString Da = ui.tableWidget_MathClass->horizontalHeaderItem(item->column())->data(Qt::UserRole).value<QString>();
		QDateTime DayTime = QDateTime::fromString(Da, "yyyy.MM.dd");
		CourseInfoList::iterator courseIt = std::find_if(_DateList[DayTime].begin(), _DateList[DayTime].end(), boost::bind(&CourseInfo::CourseIdx, _1) == item->row());
		if (courseIt != _DateList[DayTime].end())
		{
			CourseInfoPtr courseinfo = *courseIt;
			if (courseinfo)
			{
				if (courseinfo->TeacherName != _myInfo->UserClass && _myInfo->Usertype != Manager)
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("无权限删除"),  QString::fromLocal8Bit("该用户无权限删除当前选课！")
						, QMessageBox::Ok, QMessageBox::Cancel);
					return;
				}

			}
			
			courseIt = _DateList[DayTime].erase(courseIt);
		}

		if (_LabList.find(trItem->text(0)) != _LabList.end())
		{
			_LabList.at(trItem->text(0)) = _DateList;
		}
		
		UpdateTable();
	}
}

void MathLab::OnTableWidgetDouble(QTableWidgetItem *item)
{
	QTreeWidgetItem * trItem = ui.treeWidget_Class->currentItem();
	
	if (!trItem || !trItem->parent())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("未选择课程教室"),  QString::fromLocal8Bit("请在教室列表选择对应教室！")
			, QMessageBox::Ok, QMessageBox::Cancel);
		return;
	}

	if (item)
	{
		QString classRoom = trItem->text(0);
		if (!item->text().isEmpty())
		{
			QString Da = ui.tableWidget_MathClass->horizontalHeaderItem(item->column())->data(Qt::UserRole).value<QString>();
			QDateTime DayTime = QDateTime::fromString(Da, "yyyy.MM.dd");

			MathLabAddWidget * EditWidget = new MathLabAddWidget();
			CourseInfoList::iterator it = std::find_if(_DateList[DayTime].begin(), _DateList[DayTime].end(), boost::bind(&CourseInfo::CourseIdx, _1) == item->row());
			if (it != _DateList[DayTime].end())
			{
				CourseInfoPtr courseInfo = *it;
				if (courseInfo)
				{
					if (courseInfo->TeacherName != _myInfo->UserClass && _myInfo->Usertype != Manager)
					{
						QMessageBox::warning(this, QString::fromLocal8Bit("无权限修改"),  QString::fromLocal8Bit("该用户无权限修改当前选课！")
							, QMessageBox::Ok, QMessageBox::Cancel);
						return;
					}
					EditWidget->SetCourseInfo(courseInfo);

					if (EditWidget->exec() == QDialog::Accepted)
					{
						courseInfo = EditWidget->GetCourseInfo();
						courseInfo->TeacherName = _myInfo->UserClass;
						courseInfo->TimeDay = DayTime;
						courseInfo->CourseIdx = item->row();
						courseInfo->LabName = classRoom;

						if (_LabList.find(trItem->text(0)) != _LabList.end())
						{
							_LabList.at(trItem->text(0)) = _DateList;
							SetLabCourseList(_LabList);
						}
						UpdateTable();
					}
				}
			}
		}
		else
		{
			OnNewCourse(classRoom, item);
		}
	}
}

void MathLab::OnResetDateClicked()
{
	ui.dateEdit->setDateTime(current_date_time);

	SetWeekTime(current_date_time);
	UpdateTable();
}

void MathLab::closeEvent(QCloseEvent * event)
{
	if(pSystemTray->isVisible())
	{
		this->hide();

		event->ignore();
	}
	else {
		event->accept();
	}
}

void MathLab::SetWeekTime(QDateTime CurTime)
{
	int weekday = 1;
	//设置表头内容
	QStringList header;

	weekday = CurTime.date().dayOfWeek();
	
	header = FillWeekTime(CurTime, weekday);

	ui.tableWidget_MathClass->setHorizontalHeaderLabels(header);
}

QStringList MathLab::FillWeekTime(QDateTime CurTime, int weekday)
{
	QStringList header;
	for (int col = 1; col <= 7; col++)
	{
		QDateTime NextTime = CurTime.addDays(col - weekday);
		QString next_dateWeek = NextTime.toString("ddd");
		QString next_date = NextTime.toString("yyyy.MM.dd");
		QString Curr = next_dateWeek + "\n" + next_date;
	
		header << Curr;

		if (QTableWidgetItem * ia = ui.tableWidget_MathClass->horizontalHeaderItem(col - 1))
		{
			ui.tableWidget_MathClass->horizontalHeaderItem(col - 1)->setData(Qt::UserRole, QVariant::fromValue(next_date));
		}
		
	}
	return header;
}

void MathLab::InitSystemTray()
{
	if (!pSystemTray)
	{
		pSystemTray = new QSystemTrayIcon(this);
	}

	QAction * restor = new QAction(QString::fromLocal8Bit("恢复"),this);
	connect(restor,SIGNAL(triggered()),this,SLOT(showNormal()));
	QAction * quit = new QAction(QString::fromLocal8Bit("退出"),this);
	connect(quit,SIGNAL(triggered()),qApp,SLOT(quit()));
	QMenu * menu = new QMenu();
	menu->addAction(restor);
	menu->addSeparator(); //分割
	menu->addAction(quit);
	pSystemTray->setContextMenu(menu);

	pSystemTray->setIcon(QIcon("D:\\Desktop\\proC++\\MathLab\\Mathlab/mathLab.ico"));
	pSystemTray->setToolTip(QString::fromLocal8Bit("MathLab"));
	

	connect(pSystemTray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));

	// 显示系统托盘
	pSystemTray->show();
}


void MathLab::InitTreeWidget()
{
	ui.treeWidget_Class->setHeaderHidden(true);
	ui.treeWidget_Class->setCurrentItem(NULL);
	ui.treeWidget_Class->setSelectionMode(QAbstractItemView::SingleSelection);

	// 初始教室树节点
	QTreeWidgetItem *Nine = new QTreeWidgetItem();
	Nine->setText(0, QString::fromLocal8Bit("九号楼"));
	QTreeWidgetItem *Nine1 = new QTreeWidgetItem(Nine);
	Nine1->setText(0, QString::fromLocal8Bit("09101"));
	QTreeWidgetItem *Nine2 = new QTreeWidgetItem(Nine);
	Nine2->setText(0, QString::fromLocal8Bit("09102"));
	QTreeWidgetItem *Nine3 = new QTreeWidgetItem(Nine);
	Nine3->setText(0, QString::fromLocal8Bit("09103"));
	ui.treeWidget_Class->addTopLevelItem(Nine);

	QTreeWidgetItem *Elev = new QTreeWidgetItem();
	Elev->setText(0, QString::fromLocal8Bit("十一号楼"));
	QTreeWidgetItem *Elev1 = new QTreeWidgetItem(Elev);
	Elev1->setText(0, QString::fromLocal8Bit("11101"));
	QTreeWidgetItem *Elev2 = new QTreeWidgetItem(Elev);
	Elev2->setText(0, QString::fromLocal8Bit("11102"));
	QTreeWidgetItem *Elev3 = new QTreeWidgetItem(Elev);
	Elev3->setText(0, QString::fromLocal8Bit("11103"));
	ui.treeWidget_Class->addTopLevelItem(Elev);
	ui.treeWidget_Class->setContextMenuPolicy(Qt::CustomContextMenu);
	ui.treeWidget_Class->expandAll();

	connect(ui.treeWidget_Class, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(on_treeWidget_itemClicked(QTreeWidgetItem *, int)));
	if (_myInfo->Usertype == Manager)
	{
		connect(ui.treeWidget_Class,SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(on_treeWidget_customContextMenuRequested(const QPoint&)));
	}
}

void MathLab::UpdateTable()
{
	for (int col = 0; col < 7; col++)
	{
		QString Da = ui.tableWidget_MathClass->horizontalHeaderItem(col)->data(Qt::UserRole).value<QString>();
		QDateTime DayTime = QDateTime::fromString(Da, "yyyy.MM.dd");

		CourseInfoList dateCourses;
		if (_DateList[DayTime].size())
		{
			dateCourses = _DateList[DayTime];
		}

		// 填充单元格内容
		for (int row = 0; row < 5; row++)
		{
			ui.tableWidget_MathClass->setItem(row, col, new QTableWidgetItem());

			CourseInfoList::iterator courseIt = std::find_if(dateCourses.begin(), dateCourses.end(), boost::bind(&CourseInfo::CourseIdx, _1) == row);
			if (courseIt != dateCourses.end())
			{
				CourseInfoPtr courseInfo = *courseIt;
				QStringList Classes;
				QString tex = "";
				for (int i = 0; i < courseInfo->ClassNames.size(); i++)
				{
					Classes.push_back(courseInfo->ClassNames.at(i));
				}
				QString ClassStr = Classes.join(";");
				tex = QString::fromLocal8Bit("课程名称:%1 \n教师名称:%2 \n班级名称:%3 \n项目说明:%4")
					.arg(courseInfo->CourseName).arg(courseInfo->TeacherName).arg(ClassStr).arg(courseInfo->ProjectInfo);

				ui.tableWidget_MathClass->item(row, col)->setText(tex);
			}
		}

	}
}

bool MathLab::CheckExistInTree(QString text)
{
	QTreeWidgetItemIterator it(ui.treeWidget_Class);
	while (*it) 
	{
		if ((*it)->text(0) == text)
		{
			return true;
		}
		++it;
	}
	return false;
}

void MathLab::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason) {
	case QSystemTrayIcon::Trigger:
		break;
	case QSystemTrayIcon::DoubleClick:
		this->show();
		break;
	default:
		break;
	}
}

void MathLab::on_treeWidget_customContextMenuRequested(const QPoint& p)
{
	// 右键菜单栏
	QAction * additem = new QAction(QString::fromLocal8Bit("新增"), ui.treeWidget_Class);
	connect(additem, SIGNAL(triggered()), this, SLOT(on_addItem_triggered()));
	QAction * edititem = new QAction(QString::fromLocal8Bit("修改"), ui.treeWidget_Class);
	connect(edititem, SIGNAL(triggered()), this, SLOT(on_editItem_triggered()));
	QAction * delitem = new QAction(QString::fromLocal8Bit("删除"), ui.treeWidget_Class);
	connect(delitem, SIGNAL(triggered()), this, SLOT(on_delItem_triggered()));
	QMenu * menu = new QMenu(ui.treeWidget_Class);
	
	bool isItem = ui.treeWidget_Class->indexAt(p).isValid();
	if (isItem)
	{
		menu->addAction(additem);
		menu->addAction(edititem);
		menu->addSeparator(); //分割
		menu->addAction(delitem);
		menu->exec(QCursor::pos());
	}
	else
	{
		ui.treeWidget_Class->setCurrentItem(NULL);
		menu->addAction(additem);
		menu->addAction(delitem);
		menu->exec(QCursor::pos());
	}

}

void MathLab::on_treeWidget_itemClicked(QTreeWidgetItem *item, int col)
{
	_DateList.clear();
	if (item && item->parent())
	{
		LabCourseInoList::iterator it = _LabList.find(item->text(0));
		if (it != _LabList.end())
		{
			_DateList = _LabList.at(item->text(0));
		}

		UpdateTable();
	}
}

void MathLab::on_addItem_triggered()
{
	bool ok;
	QString text = QInputDialog::getText(this, tr("新增教室"),tr("请输入教室名称："), QLineEdit::Normal,0, &ok);

	if (CheckExistInTree(text))
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("教室已存在"),  QString::fromLocal8Bit("当前输入教室已存在！")
			, QMessageBox::Ok, QMessageBox::Cancel);
		return;
	}

	if (ok && !text.isEmpty())
	{
		QTreeWidgetItem * item = ui.treeWidget_Class->currentItem();
		if (item)
		{
			if (item->parent())
			{
				QTreeWidgetItem * additem = new QTreeWidgetItem(item->parent());
				additem->setText(0, text);
			}
			else
			{
				QTreeWidgetItem * additem = new QTreeWidgetItem(item);
				additem->setText(0, text);
			}
		}
		else 
		{
			QTreeWidgetItem * additem = new QTreeWidgetItem();
			additem->setText(0, text);
			ui.treeWidget_Class->addTopLevelItem(additem);
		}
	}
	ui.treeWidget_Class->expandAll();
}

void MathLab::on_editItem_triggered()
{
	QTreeWidgetItem * item = ui.treeWidget_Class->currentItem();
	if (item)
	{
		bool ok;
		QString text = QInputDialog::getText(this, tr("修改教室"),tr("请输入教室名称："), QLineEdit::Normal, item->text(0), &ok);

		if (CheckExistInTree(text))
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("教室已存在"),  QString::fromLocal8Bit("当前输入教室已存在！")
				, QMessageBox::Ok, QMessageBox::Cancel);
			return;
		}

		if (ok && !text.isEmpty())
		{
			item->setText(0, text);
		}
	}
}

void MathLab::on_delItem_triggered()
{
	QTreeWidgetItem * item = ui.treeWidget_Class->currentItem();
	if (item)
	{
		int count = item->childCount();
		if(count == 0)//没有子节点，直接删除
		{
			delete item;
			return;
		}

		for(int i = 0; i < count; i++)
		{
			QTreeWidgetItem *childItem = item->child(0);//删除子节点
			delete childItem;
		}
		delete item;//最后将自己删除

	}
}

void MathLab::ReturnToLogin()
{
	qApp->quit();
}

void MathLab::showMineCourses()
{
	//CourseInfoList courseLst = GetCourseList(); //TODO
	CourseInfoList courseLst;
	LabCourseInoList::iterator it1 = _LabList.begin();
	for (; it1 != _LabList.end(); it1++)
	{
		DateCourseInfoList dateLst = it1->second;
		DateCourseInfoList::iterator it2 = dateLst.begin();
		for (; it2 != dateLst.end(); it2++)
		{
			courseLst.insert(courseLst.end(),it2->second.begin(),it2->second.end());
		}
	}

	QString searchClass = _myInfo->UserClass;

	bool teachersPaln = _myInfo->Usertype == Teachers ? true : false;

	SearchByUserClass(courseLst, searchClass, teachersPaln);
}

void MathLab::SearchClassCourse()
{
	CourseInfoList courseLst;
	LabCourseInoList::iterator it1 = _LabList.begin();
	for (; it1 != _LabList.end(); it1++)
	{
		DateCourseInfoList dateLst = it1->second;
		DateCourseInfoList::iterator it2 = dateLst.begin();
		for (; it2 != dateLst.end(); it2++)
		{
			courseLst.insert(courseLst.end(),it2->second.begin(),it2->second.end());
		}
	}

	bool ok = false;
	QString text = QInputDialog::getText(this, tr("按班级查询"),tr("请输入查询班级名称："), QLineEdit::Normal, 0, &ok);

	if (ok && !text.isEmpty())
	{
		SearchByUserClass(courseLst, text, false);
	}
}

void MathLab::SearchByUserClass(CourseInfoList &courseLst, QString searchClass, bool teachersPaln)
{
	QDialog * mydlg = new QDialog();
	mydlg->setWindowTitle(QString::fromLocal8Bit("我的课程信息"));
	QGridLayout * layout = new QGridLayout();
	QTreeWidget * myTree = new QTreeWidget();
	if(QTreeWidgetItem* header = myTree->headerItem()) 
	{
		header->setText(0, QString::fromLocal8Bit("课程名称"));
		header->setText(1, QString::fromLocal8Bit("教师名称"));
		header->setText(2, QString::fromLocal8Bit("项目说明"));
		header->setText(3, QString::fromLocal8Bit("课程日期"));
		header->setText(4, QString::fromLocal8Bit("实验室名称"));
		header->setText(5, QString::fromLocal8Bit("课程安排"));
	}
	myTree->header()->setResizeMode(QHeaderView::Stretch);
	layout->addWidget(myTree);
	mydlg->setLayout(layout);
	mydlg->resize(600,500);//改变窗口大小

	for (int i = 0; i < courseLst.size(); i++)
	{
		CourseInfoPtr courseInfo = courseLst.at(i);
		// 按班级信息查询
		if (!teachersPaln)
		{
			std::vector<QString> ClassLst = courseInfo->ClassNames;
			std::vector<QString>::iterator it = std::find(ClassLst.begin(), ClassLst.end(), searchClass);
			if (it != ClassLst.end())
			{
				QTreeWidgetItem *item = new QTreeWidgetItem();
				item->setText(0, courseInfo->CourseName);
				item->setText(1, courseInfo->TeacherName);
				item->setText(2, courseInfo->ProjectInfo);
				item->setText(3, QString::fromLocal8Bit("%1\n%2").arg(courseInfo->TimeDay.toString("yyyy.MM.dd"))
					.arg(courseInfo->TimeDay.toString("ddd")));
				item->setText(4, courseInfo->LabName);
				item->setText(5, QString::fromLocal8Bit("第%1大节").arg(courseInfo->CourseIdx + 1));
				myTree->addTopLevelItem(item);
			}
		}
		else //按教师身份查询
		{
			if (courseInfo->TeacherName == searchClass)
			{
				QTreeWidgetItem *item = new QTreeWidgetItem();
				item->setText(0, courseInfo->CourseName);
				item->setText(1, courseInfo->TeacherName);
				item->setText(2, courseInfo->ProjectInfo);
				item->setText(3, QString::fromLocal8Bit("%1\n%2").arg(courseInfo->TimeDay.toString("yyyy.MM.dd"))
					.arg(courseInfo->TimeDay.toString("ddd")));
				item->setText(4, courseInfo->LabName);
				item->setText(5, QString::fromLocal8Bit("第%1大节").arg(courseInfo->CourseIdx + 1));
				myTree->addTopLevelItem(item);
			}
		}

	}

	mydlg->exec();
}
