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

	if (_UserType == Teachers)
	{
	}
	else if (_UserType == Students)
	{
	}

	ui.treeWidget_Class->expandAll();

	connect(ui.treeWidget_Class, SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)), this, SLOT(OnShowCurWeek(QTreeWidgetItem * , int)));
	connect(ui.lineEdit_Search, SIGNAL(textChanged(QString)), ui.treeWidget_Class, SLOT(OnSearchEdit(QString)));
}

MathLab::~MathLab()
{

}

void MathLab::OnShowCurWeek(QTreeWidgetItem * item, int column)
{
	
	QString ClassroomName = ui.treeWidget_Class->currentItem()->text(0);
}

void MathLab::OnSearchEdit(QString str)
{
	int TreeCount = ui.treeWidget_Class->columnCount();

	for (int i = 0; i < TreeCount; i++)
	{
		QTreeWidgetItem * item = ui.treeWidget_Class->itemAt(i, 1);
		if (item->text().contains(str))
		{
			item->setHidden(false);
		}
		else
		{
			item->setHidden(true);
		}
	}
}
