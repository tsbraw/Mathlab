#ifndef MATHLABLOGINWIDGET_H
#define MATHLABLOGINWIDGET_H

#include <QWidget>
#include "ui_MathLabLoginWidget.h"

class MathLabLoginWidget : public QWidget
{
	Q_OBJECT

public:
	MathLabLoginWidget(QWidget *parent = 0);
	~MathLabLoginWidget();

private:
	Ui::MathLabLoginWidget ui;
};

#endif // MATHLABLOGINWIDGET_H
