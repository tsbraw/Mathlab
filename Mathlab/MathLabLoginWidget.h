#ifndef MATHLABLOGINWIDGET_H
#define MATHLABLOGINWIDGET_H

#include <QDialog>
#include "MathLabTypes.h"
#include "ui_MathLabLoginWidget.h"

class MathLabLoginWidget : public QDialog
{
	Q_OBJECT

public:
	MathLabLoginWidget(QWidget *parent = 0);
	~MathLabLoginWidget();

public:
	UsersTpye GetUserTypeByCheck();

	UserInfoPtr GetCurrentUser() const;

	void Init();

public slots:
	void on_Longin_clicked();

	void on_Edit_clicked();

	void on_Register_clicked();

	// �޸ĺ�ע��ʱ��������Ϣд��
	void on_Yes_clicked();

	void on_Return_clicked();

	void on_checkBox_stu_stateChanged(int arg);

	void on_checkBox_tea_stateChanged(int arg);

	// ������Ʊ༭��
	void on_lineEdit_textEdited(const QString edText);

private:
	void LogNoteInfo(QString note);

private:
	Ui::MathLabLoginWidget ui;

	bool _IsRegister;

	UserInfoList _Userlst;

	UserInfoPtr _user;

	//����Ա��Ϣ
	QString _ManagerName;
	QString _ManagerPwd;

};

#endif // MATHLABLOGINWIDGET_H
