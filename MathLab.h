#ifndef EMITCRASH_H
#define EMITCRASH_H

#include <QtGui/QMainWindow>

#include "MathLabTypes.h"
#include "MathLabDataService.h"
#include "ui_MathLab.h"

class MathLab : public QMainWindow, public MathLabDataService
{
	Q_OBJECT

public:
	MathLab(QWidget *parent = 0, Qt::WFlags flags = 0, std::string userId = "");
	~MathLab();

public slots:
	//显示当前周的实验安排;
	void OnShowCurWeek();
	
	void OnSearchEdit();

private:
	Ui::MathLabClass ui;

	int _UserType;

	CourseInfoList _CourseList;
};

#endif // EMITCRASH_H
