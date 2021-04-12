
#include <boost/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include <QDateTime>
#include <QLineEdit>

#include "MathLabAddWidget.h"
#include "ui_MathLabAddWidget.h"

MathLabAddWidget::MathLabAddWidget(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::MathLabAddWidget();
	ui->setupUi(this);

	_newCourse = boost::make_shared<CourseInfo>();

	connect(ui->pushButton_Ok, SIGNAL(clicked()), this, SLOT(On_pushButton_Ok_clicked()));
	connect(ui->pushButton_Cancel, SIGNAL(clicked()), this, SLOT(close()));
}

MathLabAddWidget::~MathLabAddWidget()
{
	delete ui;
}

CourseInfoPtr MathLabAddWidget::GetCourseInfo()
{
	if (!_newCourse)
	{
		_newCourse = boost::make_shared<CourseInfo>();
	}
	return _newCourse;
}

void MathLabAddWidget::SetCourseInfo(CourseInfoPtr courseInfo)
{
	if (courseInfo)
	{
		_newCourse = courseInfo;
	}
	ui->lineEdit_Course->setText(courseInfo->CourseName);
	ui->lineEdit_Teacher->setText(courseInfo->TeacherName);

	QStringList Classes;
	for (int i = 0; i < courseInfo->ClassNames.size(); i++)
	{
		Classes.push_back(courseInfo->ClassNames.at(i));
	}
	QString ClassStr = Classes.join(";");
	ui->lineEdit_Classes->setText(ClassStr);
	ui->lineEdit_instruction->setText(courseInfo->ProjectInfo);
}

void MathLabAddWidget::On_pushButton_Ok_clicked()
{
	if (_newCourse)
	{
		_newCourse->CourseName = ui->lineEdit_Course->text();
		_newCourse->TeacherName = ui->lineEdit_Teacher->text();

		QString ClassText = ui->lineEdit_Classes->text();
		QStringList Classes = ClassText.split(";");
		for (int i = 0; i < Classes.size(); i++)
		{
			_newCourse->ClassNames.push_back(Classes[i]);
		}

		_newCourse->ProjectInfo = ui->lineEdit_instruction->text();
	}

	close();
}

