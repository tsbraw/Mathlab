#include "MathLab.h"

MathLab::MathLab(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	ui.tableWidget_Week->horizontalHeader()->setResizeMode(QHeaderView::Stretch); //����Ӧ�п�;
	ui.tableWidget_Week->verticalHeader()->setResizeMode(QHeaderView::Stretch); //����Ӧ�и�;

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
