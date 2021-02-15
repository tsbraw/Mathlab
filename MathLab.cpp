#include "MathLab.h"

MathLab::MathLab(QWidget *parent, Qt::WFlags flags, std::string userId)
	: QMainWindow(parent, flags)
	, MathLabDataService(userId)
{
	ui.setupUi(this);

	ui.tableWidget_Week->horizontalHeader()->setResizeMode(QHeaderView::Stretch); //自适应列宽;
	ui.tableWidget_Week->verticalHeader()->setResizeMode(QHeaderView::Stretch); //自适应行高;


	_CourseList = GetCourseList();
	_UserCourseList = GetUserCourseList();
	_UserType = GetUserType();

	if (_UserType == (int)Teachers)
	{
	}
	else if (_UserType == (int)Students)
	{
	}
}

MathLab::~MathLab()
{

}

void MathLab::OnShowCurWeek()
{
	
	QString ClassroomName = ui.treeWidget_Class->currentItem()->text(0);
}

void MathLab::OnSearchEdit()
{

}
