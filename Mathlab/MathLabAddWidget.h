#ifndef MATHLABADDWIDGET_H
#define MATHLABADDWIDGET_H

#include <QDialog>
#include "MathLabTypes.h"

namespace Ui {class MathLabAddWidget;};

class MathLabAddWidget : public QDialog
{
	Q_OBJECT

public:
	MathLabAddWidget(QWidget *parent = 0);
	~MathLabAddWidget();

	CourseInfoPtr GetCourseInfo();

private slots:
	void On_pushButton_Ok_clicked();

private:
	Ui::MathLabAddWidget *ui;

	CourseInfoPtr _newCourse;
};

#endif // MATHLABADDWIDGET_H
