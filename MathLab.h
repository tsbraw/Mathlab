#ifndef EMITCRASH_H
#define EMITCRASH_H

#include <QtGui/QMainWindow>
#include "ui_MathLab.h"

class MathLab : public QMainWindow
{
	Q_OBJECT

public:
	MathLab(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MathLab();

public slots:
	//显示当前周的实验安排;
	void OnShowCurWeek();
	
	void OnSearchEdit();

private:
	Ui::MathLabClass ui;
};

#endif // EMITCRASH_H
