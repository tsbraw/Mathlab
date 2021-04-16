#ifndef MATHLABLOGINWIDGET_H
#define MATHLABLOGINWIDGET_H

#include <QDialog>
#include "ui_MathLabLoginWidget.h"

class MathLabLoginWidget : public QDialog
{
	Q_OBJECT

public:
	MathLabLoginWidget(QWidget *parent = 0);
	~MathLabLoginWidget();

public slots:
	void on_Longin_clicked();

	void on_Edit_clicked();

	void on_Register_clicked();

	void on_checkBox_stu_stateChanged(int arg);

	void on_checkBox_tea_stateChanged(int arg);

private:
	Ui::MathLabLoginWidget ui;



};

#endif // MATHLABLOGINWIDGET_H
