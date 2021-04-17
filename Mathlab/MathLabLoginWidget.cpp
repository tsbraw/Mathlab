#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include "MathLabTypes.h"
#include "MathLabLoginWidget.h"


MathLabLoginWidget::MathLabLoginWidget(QWidget *parent)
	: QDialog(parent)
	, MathLabDataService()
{
	ui.setupUi(this);

	ui.checkBox_stu->setChecked(Qt::CheckState::Checked);
	ui.checkBox_tea->setChecked(Qt::CheckState::Unchecked);

	// ������ʾ��Ϣ��������Ϊ��ɫ
	ui.label_note->setHidden(true);
	ui.label_note->setStyleSheet("color:red;");
	ui.label_note->setAlignment(Qt::AlignRight);

	// ����ȷ���޸ĺͱ༭��ť
	ui.pushButton_Yes->setHidden(true);

	// �༶��Ϣ��������
	ui.label_Class->setHidden(true);
	ui.lineEdit_Class->setHidden(true);

	//����������ʾ����Ϊ�ڵ㣬���ɼ�
	 ui.lineEdit_Password->setEchoMode(QLineEdit::Password);

	 setWindowTitle("Login");

	_IsRegister = false;

	_Userlst = GetUserList();
	_user = boost::make_shared<UserInfo>();

	connect(ui.pushButton_login, SIGNAL(clicked()), this, SLOT(on_Longin_clicked()));
	connect(ui.pushButton_edit, SIGNAL(clicked()), this, SLOT(on_Edit_clicked()));
	connect(ui.pushButton_register, SIGNAL(clicked()), this, SLOT(on_Register_clicked()));
	connect(ui.pushButton_Yes, SIGNAL(clicked()), this, SLOT(on_Yes_clicked()));
	connect(ui.checkBox_stu, SIGNAL(stateChanged(int)), this, SLOT(on_checkBox_stu_stateChanged(int)));
	connect(ui.checkBox_tea, SIGNAL(stateChanged(int)), this, SLOT(on_checkBox_tea_stateChanged(int)));
	connect(ui.lineEdit_Name, SIGNAL(textEdited(const QString)), this, SLOT(on_lineEdit_textEdited(const QString)));
}

MathLabLoginWidget::~MathLabLoginWidget()
{

}

UsersTpye MathLabLoginWidget::GetUserTypeByCheck()
{
	UsersTpye _CurType = Students;
	if (ui.checkBox_stu->checkState() == Qt::CheckState::Checked)
	{
		_CurType = Students;
	}
	else
	{
		_CurType = Teachers;
	}
	return _CurType;
}

UserInfoPtr MathLabLoginWidget::GetCurrentUser() const
{
	return _user;
}

void MathLabLoginWidget::on_Longin_clicked()
{
	QString userName = ui.lineEdit_Name->text();
	QString userPwd = ui.lineEdit_Password->text();
	UserInfoList::iterator it = std::find_if(_Userlst.begin(), _Userlst.end(), boost::bind(&UserInfo::UserName, _1) == userName);
	if (it != _Userlst.end())
	{
		_user = *it;
		if (_user->UserPwd == userPwd && _user->Usertype == GetUserTypeByCheck())
		{
			this->accept();
		}
		else
		{
			LogNoteInfo(QString::fromLocal8Bit("����������������룡"));
		}
	}
	else
	{
		LogNoteInfo(QString::fromLocal8Bit("�û��������ڣ�"));
	}

	//this->accept();
}

void MathLabLoginWidget::on_Edit_clicked()
{
	setWindowTitle("Edit");
	QString userName = ui.lineEdit_Name->text();
	QString userPwd = ui.lineEdit_Password->text();
	UserInfoList::iterator it = std::find_if(_Userlst.begin(), _Userlst.end(), boost::bind(&UserInfo::UserName, _1) == userName);
	if (it != _Userlst.end())
	{
		ui.label_Class->setHidden(false);
		if (GetUserTypeByCheck() == Teachers)
		{
			ui.label_Class->setText(QString::fromLocal8Bit("��ʦ������"));
		}
		else
		{
			ui.label_Class->setText(QString::fromLocal8Bit("�༶��"));
		}
		ui.lineEdit_Class->setHidden(false);
		ui.pushButton_login->setHidden(true);
		ui.pushButton_edit->setHidden(true);
		ui.pushButton_register->setHidden(true);
		ui.pushButton_Yes->setHidden(false);

		_IsRegister = false;
	}
	else
	{
		LogNoteInfo(QString::fromLocal8Bit("�û��������ڣ�"));
	}
}

void MathLabLoginWidget::on_Register_clicked()
{
	setWindowTitle("Register");

	ui.label_Class->setHidden(false);
	if (GetUserTypeByCheck() == Teachers)
	{
		ui.label_Class->setText(QString::fromLocal8Bit("��ʦ������"));
	}
	else
	{
		ui.label_Class->setText(QString::fromLocal8Bit("�༶��"));
	}
	ui.lineEdit_Class->setHidden(false);
	ui.pushButton_login->setHidden(true);
	ui.pushButton_edit->setHidden(true);
	ui.pushButton_register->setHidden(true);
	ui.pushButton_Yes->setHidden(false);

	_IsRegister = true;
}

void MathLabLoginWidget::on_Yes_clicked()
{
	QString userName = ui.lineEdit_Name->text();
	QString userClass = ui.lineEdit_Class->text();
	QString userPwd = ui.lineEdit_Password->text();
	
	UserInfoList::iterator it = std::find_if(_Userlst.begin(), _Userlst.end(), boost::bind(&UserInfo::UserName, _1) == userName);
	if (it != _Userlst.end())
	{
		if (_IsRegister)
		{
			LogNoteInfo(QString::fromLocal8Bit("���û����Ѵ��ڣ�"));
			return;
		}
		else
		{
			it = _Userlst.erase(it);
		}
		
	}

	UserInfoPtr addUser = boost::make_shared<UserInfo>();
	addUser->UserName = userName;
	addUser->UserPwd = userPwd;
	addUser->UserClass = userClass;
	addUser->Usertype = GetUserTypeByCheck();

	_Userlst.push_back(addUser);
	if (_IsRegister)
	{
		LogNoteInfo(QString::fromLocal8Bit("ע��ɹ���"));
	}
	else
	{
		LogNoteInfo(QString::fromLocal8Bit("�޸ĳɹ���"));
	}

	SetUserList(_Userlst);
	setWindowTitle("Login");
	ui.label_Class->setHidden(true);
	ui.lineEdit_Class->setHidden(true);
	ui.pushButton_login->setHidden(false);
	ui.pushButton_edit->setHidden(false);
	ui.pushButton_register->setHidden(false);
	ui.pushButton_Yes->setHidden(true);
}

void MathLabLoginWidget::on_checkBox_stu_stateChanged(int arg)
{
	if(arg == Qt::CheckState::Checked)
	{
		ui.checkBox_tea->blockSignals(true);
		ui.checkBox_tea->setCheckState(Qt::CheckState::Unchecked);
		ui.checkBox_tea->blockSignals(false);
	}
}

void MathLabLoginWidget::on_checkBox_tea_stateChanged(int arg)
{
	if(arg == Qt::CheckState::Checked)
	{
		ui.checkBox_stu->blockSignals(true);
		ui.checkBox_stu->setCheckState(Qt::CheckState::Unchecked);
		ui.checkBox_stu->blockSignals(false);
	}
}

void MathLabLoginWidget::on_lineEdit_textEdited(const QString edText)
{
	ui.label_note->setHidden(true);
}

void MathLabLoginWidget::LogNoteInfo(QString note)
{
	ui.label_note->setHidden(false);
	ui.label_note->setText(note);
}
