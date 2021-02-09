#include "MathLab.h"

MathLab::MathLab(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	ui.tableWidget_Week->horizontalHeader()->setResizeMode(QHeaderView::Stretch); //自适应列宽;
	ui.tableWidget_Week->verticalHeader()->setResizeMode(QHeaderView::Stretch); //自适应行高;

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
