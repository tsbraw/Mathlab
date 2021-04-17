
#include <QDateEdit>
#include <QDateTime>
#include <QVariant>
#include <QMessageBox>

#include <boost/bind.hpp>

#include "MathLabAddWidget.h"
#include "MathLab.h"

Q_DECLARE_METATYPE(CourseInfoPtr);

MathLab::MathLab(QWidget *parent, Qt::WFlags flags, UsersTpye userType)
	: QMainWindow(parent, flags)
	, MathLabDataService()
{
	ui.setupUi(this);

	Init();

	InitSystemTray();

	setWindowIcon(QIcon(":/Icon/mathLab.ico"));

	connect(ui.pushButton_new, SIGNAL(clicked()), this, SLOT(OnNewCourseClicked()));
	connect(ui.pushButton_del, SIGNAL(clicked()), this, SLOT(OnDelCourseClicked()));
	connect(ui.pushButton_resetDate, SIGNAL(clicked()), this, SLOT(OnResetDateClicked()));
	connect(ui.tableWidget_MathClass, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(OnTableWidgetDouble(QTableWidgetItem*)));
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

	ui.treeWidget_Class->setHeaderHidden(true);
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

	QDateTime current_date_time = QDateTime::currentDateTime();

	ui.dateEdit->setCalendarPopup(true);
	ui.dateEdit->setDateTime(current_date_time);
	SetWeekTime(current_date_time);

	UpdateTable();

	pSystemTray = new QSystemTrayIcon(this);

	_DateCourseList = GetDateCourseList();

}

MathLab::~MathLab()
{

}

void MathLab::OnDateEditChanged(const QDateTime & dateTime)
{
	SetWeekTime(dateTime);
}

void MathLab::OnNewCourseClicked()
{
	QTableWidgetItem * item = ui.tableWidget_MathClass->currentItem();

	if (!item)
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("未选中单元格"),  QString::fromLocal8Bit("请选择添加课程对应的单元格！")
			, QMessageBox::Ok, QMessageBox::Cancel);
	}
	else if (!item->text().isEmpty())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("已有课程"),  QString::fromLocal8Bit("该时间段已有课程安排！")
			, QMessageBox::Ok, QMessageBox::Cancel);
	}
	else
	{
		OnNewCourse(item);

	}
	
}

void MathLab::OnNewCourse(QTableWidgetItem * item)
{
	MathLabAddWidget * addWidget = new MathLabAddWidget();

	if (!addWidget->exec())
	{
		int col = item->column();
		CourseInfoPtr courseInfo = addWidget->GetCourseInfo();
		QDateTime DayTime = ui.tableWidget_MathClass->horizontalHeaderItem(col)->data(Qt::UserRole).value<QDateTime>();
		courseInfo->TimeDay = DayTime;
		courseInfo->CourseIdx = item->row();
		_DateCourses[DayTime].push_back(courseInfo);

		UpdateTable();
	}
}

void MathLab::OnDelCourseClicked()
{
	QTableWidgetItem * item = ui.tableWidget_MathClass->currentItem();

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
		QDateTime DayTime = ui.tableWidget_MathClass->horizontalHeaderItem(item->column())->data(Qt::UserRole).value<QDateTime>();
		CourseInfoList::iterator courseIt = std::find_if(_DateCourses[DayTime].begin(), _DateCourses[DayTime].end(), boost::bind(&CourseInfo::CourseIdx, _1) == item->row());
		if (courseIt != _DateCourses[DayTime].end())
		{
			courseIt = _DateCourses[DayTime].erase(courseIt);
		}

		UpdateTable();
	}
}

void MathLab::OnTableWidgetDouble(QTableWidgetItem *item)
{
	if (item)
	{
		if (!item->text().isEmpty())
		{
			QDateTime DayTime = ui.tableWidget_MathClass->horizontalHeaderItem(item->column())->data(Qt::UserRole).value<QDateTime>();

			MathLabAddWidget * EditWidget = new MathLabAddWidget();
			CourseInfoList::iterator it = std::find_if(_DateCourses[DayTime].begin(), _DateCourses[DayTime].end(), boost::bind(&CourseInfo::CourseIdx, _1) == item->row());
			if (it != _DateCourses[DayTime].end())
			{
				CourseInfoPtr courseInfo = *it;
				if (courseInfo)
				{
					EditWidget->SetCourseInfo(courseInfo);

					if (!EditWidget->exec())
					{
						courseInfo = EditWidget->GetCourseInfo();
						courseInfo->TimeDay = DayTime;
						courseInfo->CourseIdx = item->row();

						UpdateTable();
					}
				}
			}
		}
		else
		{
			OnNewCourse(item);
		}
	}
}

void MathLab::OnResetDateClicked()
{
	ui.dateEdit->setDateTime(QDateTime::currentDateTime());

	SetWeekTime(ui.dateEdit->dateTime());
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

		if (QTableWidgetItem * ia = ui.tableWidget_MathClass->horizontalHeaderItem(col))
		{
			ui.tableWidget_MathClass->horizontalHeaderItem(col)->setData(Qt::UserRole, QVariant::fromValue(NextTime));
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
	//connect(quit,&QAction::triggered,this,&MainWindow::close);
	connect(quit,SIGNAL(triggered()),qApp,SLOT(quit()));
	QMenu * menu = new QMenu();
	menu->addAction(restor);
	menu->addSeparator(); //分割
	menu->addAction(quit);
	pSystemTray->setContextMenu(menu);

	pSystemTray->setToolTip(QString::fromLocal8Bit("MathLab"));
	pSystemTray->setIcon(QIcon(":/Icon/mathLab.ico"));

	connect(pSystemTray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));

	// 显示系统托盘
	pSystemTray->show();
}


void MathLab::UpdateTable()
{
	for (int col = 0; col < 7; col++)
	{
		QDateTime DayTime = ui.tableWidget_MathClass->horizontalHeaderItem(col)->data(Qt::UserRole).value<QDateTime>();
		CourseInfoList dateCourses;
		if (_DateCourses[DayTime].size())
		{
			dateCourses = _DateCourses[DayTime];
		}

		// 填充单元格内容
		for (int row = 0; row < 5; row++)
		{
			QString tex = "";
			CourseInfoList::iterator courseIt = std::find_if(dateCourses.begin(), dateCourses.end(), boost::bind(&CourseInfo::CourseIdx, _1) == row);
			if (courseIt != dateCourses.end())
			{
				CourseInfoPtr courseInfo = *courseIt;
				tex = courseInfo->CourseName + "\n" + courseInfo->TeacherName;
			}

			ui.tableWidget_MathClass->setItem(row, col, new QTableWidgetItem(QString("%1").arg(tex)));

		}

	}
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