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
	//��ʾѡ�н��ҵ�ǰ�ܵ�ʵ�鰲��;
	void OnShowCurWeek(QTreeWidgetItem * item, int column);
	
	void OnSearchEdit(QString str);

private:
	Ui::MathLabClass ui;

	UsersTpye _UserType;

	CourseInfoList _CourseList;
};

#endif // EMITCRASH_H
