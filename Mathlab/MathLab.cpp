
#include <QDateEdit>
#include <QDateTime>
#include <QVariant>
#include <QMessageBox>

#include "MathLabAddWidget.h"
#include "MathLab.h"

Q_DECLARE_METATYPE(CourseInfoPtr);

MathLab::MathLab(QWidget *parent, Qt::WFlags flags, std::string userId)
	: QMainWindow(parent, flags)
	, MathLabDataService(userId)
{
	ui.setupUi(this);

	Init();

	InitSystemTray();

	_CourseList.clear();

	connect(ui.pushButton_new, SIGNAL(clicked()), this, SLOT(OnNewCourseClicked()));
	connect(ui.dateEdit, SIGNAL(dateTimeChanged( const QDateTime & )), this, SLOT(OnDateEditChanged( const QDateTime & )));
}

void MathLab::Init()
{
	ui.tableWidget_MathClass->horizontalHeader()->setResizeMode(QHeaderView::Stretch); //自适应列宽;
	ui.tableWidget_MathClass->verticalHeader()->setResizeMode(QHeaderView::Stretch); //自适应行高;

	ui.tableWidget_MathClass->setRowCount(7);
	ui.tableWidget_MathClass->setColumnCount(7);

	ui.tableWidget_MathClass->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_MathClass->setSelectionMode(QAbstractItemView::SingleSelection);

	// 初始化行列
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j ++)
		{
			if (j == 2 || j == 5)
			{
				continue;
			}

			QTableWidgetItem *item = new QTableWidgetItem();

			ui.tableWidget_MathClass->setItem(i, j, item);
		}
	}

	QDateTime current_date_time = QDateTime::currentDateTime();

	ui.dateEdit->setCalendarPopup(true);
	ui.dateEdit->setDateTime(current_date_time);
	SetWeekTime(current_date_time);

	pSystemTray = new QSystemTrayIcon(this);

	_CourseList = GetCourseList();
	_UserCourseList = GetUserCourseList();
	_UserType = GetUserType();

	if (_UserType == Teachers)
	{

	}
	else if (_UserType == Students)
	{
	}
}

MathLab::~MathLab()
{

}

void MathLab::OnDateEditChanged(const QDateTime & dateTime)
{
	// 初始化行列
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j ++)
		{
			if (j == 2 || j == 5)
			{
				continue;
			}

			QTableWidgetItem *item = new QTableWidgetItem();

			ui.tableWidget_MathClass->setItem(i, j, item);
		}
	}

	SetWeekTime(dateTime);
}

void MathLab::OnNewCourseClicked()
{
	QTableWidgetItem * item = ui.tableWidget_MathClass->item(1,1)/*ui.tableWidget_MathClass->currentItem()*/;

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
		MathLabAddWidget * addWidget = new MathLabAddWidget();

		if (!addWidget->exec())
		{
			int col = item->column();
			CourseInfoPtr courseInfo = addWidget->GetCourseInfo();
			QVariant val = ui.tableWidget_MathClass->horizontalHeaderItem(col)->data(0);
			QDateTime DayTime = val.toDateTime();
			int we = DayTime.date().dayOfWeek();
			courseInfo->TimeDay = DayTime;

			_CourseList.push_back(courseInfo);

			QString tex = courseInfo->CourseName + "\n" + courseInfo->TeacherName;

			item->setText(tex);
			item->setData(0, QVariant::fromValue(courseInfo));
		}
	}
	
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
	for (int i = 1; i <= 7; i++)
	{
		QDateTime NextTime = CurTime.addDays(i - weekday);
		QString next_dateWeek = NextTime.toString("ddd");
		QString next_date = NextTime.toString("yyyy.MM.dd");
		QString Curr = next_dateWeek + "\n" + next_date;
	
		header << Curr;

		if (QTableWidgetItem * ia = ui.tableWidget_MathClass->horizontalHeaderItem(i))
		{
			ui.tableWidget_MathClass->horizontalHeaderItem(i)->setData(0, QVariant::fromValue(NextTime));
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
	pSystemTray->setIcon(QIcon(":/EmitCrash/lab.png"));

	connect(pSystemTray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));

	// 显示系统托盘
	pSystemTray->show();
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