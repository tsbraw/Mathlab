#include <QDateEdit>
#include <QDateTime>
#include "MathLab.h"

MathLab::MathLab(QWidget *parent, Qt::WFlags flags, std::string userId)
	: QMainWindow(parent, flags)
	, MathLabDataService(userId)
{
	ui.setupUi(this);

	Init();

	connect(ui.dateEdit, SIGNAL(dateTimeChanged( const QDateTime & )), this, SLOT(OnDateEditChanged( const QDateTime & )));
}

void MathLab::Init()
{
	ui.tableWidget_MathClass->horizontalHeader()->setResizeMode(QHeaderView::Stretch); //自适应列宽;
	ui.tableWidget_MathClass->verticalHeader()->setResizeMode(QHeaderView::Stretch); //自适应行高;

	QDateTime current_date_time = QDateTime::currentDateTime();

	ui.dateEdit->setCalendarPopup(true);
	ui.dateEdit->setDateTime(current_date_time);
	SetWeekTime(current_date_time);

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

}

void MathLab::SetWeekTime(QDateTime CurTime)
{
	QString current_dateWeek = CurTime.toString("ddd");
	int weekday = 0;
	//设置表头内容
	QStringList header;
	if (current_dateWeek == "周一")
	{
		weekday = 1;

		header = FillWeekTime(CurTime, weekday);
	}
	else if (current_dateWeek == "周二")
	{
		weekday = 2;

		header = FillWeekTime(CurTime, weekday);
	}
	else if (current_dateWeek == "周三")
	{
		weekday = 3;

		header = FillWeekTime(CurTime, weekday);
	}
	else if (current_dateWeek == "周四")
	{
		weekday = 4;

		header = FillWeekTime(CurTime, weekday);
	}
	else if (current_dateWeek == "周五")
	{
		weekday = 5;

		header = FillWeekTime(CurTime, weekday);
	}
	else if (current_dateWeek == "周六")
	{
		weekday = 6;

		header = FillWeekTime(CurTime, weekday);
	}
	else if (current_dateWeek == "周日")
	{
		weekday = 7;

		header = FillWeekTime(CurTime, weekday);
	}

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

		ui.tableWidget_MathClass->itemAt(0, i)->setData(0, QVariant::fromValue(NextTime));
	}
	return header;
}

