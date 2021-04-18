#ifndef MATHLABLOGINWIDGET_H
#define MATHLABLOGINWIDGET_H

#include <QDialog>
#include "MathLabDataService.h"
#include "ui_MathLabLoginWidget.h"

class MathLabLoginWidget : public QDialog, public MathLabDataService
{
	Q_OBJECT

public:
	MathLabLoginWidget(QWidget *parent = 0);
	~MathLabLoginWidget();

public:
	UsersTpye GetUserTypeByCheck();

	UserInfoPtr GetCurrentUser() const;

public slots:
	void on_Longin_clicked();

	void on_Edit_clicked();

	void on_Register_clicked();

	// 修改和注册时将新增信息写入
	void on_Yes_clicked();

	void on_Return_clicked();

	void on_checkBox_stu_stateChanged(int arg);

	void on_checkBox_tea_stateChanged(int arg);

	// 点击名称编辑行
	void on_lineEdit_textEdited(const QString edText);

private:
	void LogNoteInfo(QString note);

private:
	Ui::MathLabLoginWidget ui;

	bool _IsRegister;

	UserInfoList _Userlst;

	UserInfoPtr _user;
};

#endif // MATHLABLOGINWIDGET_H
