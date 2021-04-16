#include "MathLabLoginWidget.h"
#include "MathLab.h"
#include "MathLabDataService.h"


MathLabLoginWidget::MathLabLoginWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.checkBox_stu->setChecked(Qt::CheckState::Checked);
	ui.checkBox_tea->setChecked(Qt::CheckState::Unchecked);



	connect(ui.pushButton_login, SIGNAL(clicked()), this, SLOT(on_Longin_clicked()));
	connect(ui.pushButton_edit, SIGNAL(clicked()), this, SLOT(on_Edit_clicked()));
	connect(ui.pushButton_register, SIGNAL(clicked()), this, SLOT(on_Register_clicked()));
	connect(ui.checkBox_stu, SIGNAL(stateChanged(int)), this, SLOT(on_checkBox_stu_stateChanged(int)));
	connect(ui.checkBox_tea, SIGNAL(stateChanged(int)), this, SLOT(on_checkBox_tea_stateChanged(int)));
}

MathLabLoginWidget::~MathLabLoginWidget()
{

}

void MathLabLoginWidget::on_Longin_clicked()
{
	this->accept();
}

void MathLabLoginWidget::on_Edit_clicked()
{

}

void MathLabLoginWidget::on_Register_clicked()
{

}

void MathLabLoginWidget::on_checkBox_stu_stateChanged(int arg)
{
	if(arg==Qt::CheckState::Checked)
	{
		ui.checkBox_tea->blockSignals(true);
		ui.checkBox_tea->setCheckState(Qt::CheckState::Unchecked);
		ui.checkBox_tea->blockSignals(false);
	}
}

void MathLabLoginWidget::on_checkBox_tea_stateChanged(int arg)
{
	if(arg==Qt::CheckState::Checked)
	{
		ui.checkBox_stu->blockSignals(true);
		ui.checkBox_stu->setCheckState(Qt::CheckState::Unchecked);
		ui.checkBox_stu->blockSignals(false);
	}
}
