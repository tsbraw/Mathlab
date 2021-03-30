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
	SetWeekTime(dateTime);
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

		//ui.tableWidget_MathClass->itemAt(0, i)->setData(0, QVariant::fromValue(NextTime));
	}
	return header;
}

