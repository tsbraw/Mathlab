#include <QDateEdit>
#include <QDateTime>
#include "MathLab.h"

MathLab::MathLab(QWidget *parent, Qt::WFlags flags, std::string userId)
	: QMainWindow(parent, flags)
	, MathLabDataService(userId)
{
	ui.setupUi(this);

	ui.tableWidget_MathClass->horizontalHeader()->setResizeMode(QHeaderView::Stretch); //����Ӧ�п�;
	ui.tableWidget_MathClass->verticalHeader()->setResizeMode(QHeaderView::Stretch); //����Ӧ�и�;

	QDateTime current_date_time = QDateTime::currentDateTime();
	
	ui.dateEdit->setCalendarPopup(true);
	ui.dateEdit->setDateTime(current_date_time);

	ui.tableView_MathClass->setItemDelegateForColumn(1, new QAbstractItemDelegate("yyyy-dd-MM"));

	QString current_dateWeek = current_date_time.toString("ddd");
	QString current_date = current_date_time.toString("yyyy.MM.dd");
	QString Curr = current_dateWeek + "\n" + current_date;

	//���ñ�ͷ����
	QStringList header;
	header << Curr;
	ui.tableWidget_MathClass->setHorizontalHeaderLabels(header);

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

