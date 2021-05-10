#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include <pugixml.hpp>
#include "MathLabTypes.h"
#include "MathLabLoginWidget.h"


MathLabLoginWidget::MathLabLoginWidget(QWidget *parent)
	: QDialog(parent)
	, MathLabDataService()
{
	ui.setupUi(this);

	Init();

	ui.checkBox_stu->setChecked(Qt::CheckState::Checked);
	ui.checkBox_tea->setChecked(Qt::CheckState::Unchecked);

	// ������ʾ��Ϣ��������Ϊ��ɫ
	ui.label_note->setHidden(true);
	ui.label_note->setStyleSheet("color:red;");
	ui.label_note->setAlignment(Qt::AlignRight);

	// ����ȷ���ͷ��ذ�ť
	ui.pushButton_Yes->setHidden(true);
	ui.pushButton_return->setHidden(true);

	// �༶��Ϣ��������
	ui.label_Class->setHidden(true);
	ui.lineEdit_Class->setHidden(true);

	// ȷ��������Ϣ
	ui.label_pwd->setHidden(true);
	ui.lineEdit_Repwd->setHidden(true);

	//����������ʾ����Ϊ�ڵ㣬���ɼ�
	 ui.lineEdit_Password->setEchoMode(QLineEdit::Password);
	 ui.lineEdit_Repwd->setEchoMode(QLineEdit::Password);
	 setWindowTitle("Login");

	_IsRegister = false;

	_Userlst = GetUserList();
	_user = boost::make_shared<UserInfo>();

	connect(ui.pushButton_login, SIGNAL(clicked()), this, SLOT(on_Longin_clicked()));
	connect(ui.pushButton_edit, SIGNAL(clicked()), this, SLOT(on_Edit_clicked()));
	connect(ui.pushButton_register, SIGNAL(clicked()), this, SLOT(on_Register_clicked()));
	connect(ui.pushButton_Yes, SIGNAL(clicked()), this, SLOT(on_Yes_clicked()));
	connect(ui.pushButton_return, SIGNAL(clicked()), this, SLOT(on_Return_clicked()));
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

void MathLabLoginWidget::Init()
{
	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("D:/Desktop/proC++/MathLab/Mathlab/config/LoginConfig.xml");

	if (result.status == pugi::status_ok)
	{
		pugi::xml_node managerNode = doc.child("mananger");
		if (managerNode)
		{
			pugi::xml_node manaName = managerNode.child("managername");
			pugi::xml_node mamaPwd = managerNode.child("managerpwd");

			if (mamaPwd && manaName)
			{
				_ManagerName = manaName.text().as_string();
				_ManagerPwd = mamaPwd.text().as_string();
			}
		}
	}
	else
	{
		/*std::cout << "Load ManagerInfo Failed!" << std::endl;*/
	}
}

void MathLabLoginWidget::on_Longin_clicked()
{
	ui.label_note->setHidden(true);
	QString userName = ui.lineEdit_Name->text();
	QString userPwd = ui.lineEdit_Password->text();
	UsersTpye userType = GetUserTypeByCheck();

	if (userName == _ManagerName && userPwd == _ManagerPwd)
	{
		LogNoteInfo(QString::fromLocal8Bit("��ӭ����Ա��¼��"));

		_user->UserName = userName;
		_user->UserPwd = userPwd;
		_user->Usertype = Manager;

		this->accept();
	}
	else
	{
		UserInfoList::iterator it = std::find_if(_Userlst.begin(), _Userlst.end(), [&](UserInfoPtr user){
			return user->Usertype == userType && user->UserName == userName;
		});
		if (it != _Userlst.end())
		{
			_user = *it;
			if (_user->UserPwd == userPwd)
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
	}

	//this->accept();
}

void MathLabLoginWidget::on_Edit_clicked()
{
	ui.label_note->setHidden(true);
	setWindowTitle("Edit");
	QString userName = ui.lineEdit_Name->text();
	QString userPwd = ui.lineEdit_Password->text();
	UsersTpye userType = GetUserTypeByCheck();

	if (userName == _ManagerName)
	{
		LogNoteInfo(QString::fromLocal8Bit("���˺��ѱ�ʹ�ã�"));
	}
	else
	{
		UserInfoList::iterator it = std::find_if(_Userlst.begin(), _Userlst.end(), [&](UserInfoPtr user){
			return user->Usertype == userType && user->UserName == userName;
		});
		if (it != _Userlst.end())
		{
			ui.label_pwd->setHidden(false);
			ui.lineEdit_Repwd->setHidden(false);
			ui.label_Class->setHidden(false);
			ui.lineEdit_Class->setHidden(false);
			ui.pushButton_login->setHidden(true);
			ui.pushButton_edit->setHidden(true);
			ui.pushButton_register->setHidden(true);
			ui.pushButton_Yes->setHidden(false);
			ui.pushButton_return->setHidden(false);

			_IsRegister = false;
		}
		else
		{
			LogNoteInfo(QString::fromLocal8Bit("�û��������ڣ�"));
		}
	}
	
}

void MathLabLoginWidget::on_Register_clicked()
{
	ui.label_note->setHidden(true);
	setWindowTitle("Register");

	ui.label_pwd->setHidden(false);
	ui.lineEdit_Repwd->setHidden(false);
	ui.label_Class->setHidden(false);
	ui.lineEdit_Class->setHidden(false);
	ui.pushButton_login->setHidden(true);
	ui.pushButton_edit->setHidden(true);
	ui.pushButton_register->setHidden(true);
	ui.pushButton_Yes->setHidden(false);
	ui.pushButton_return->setHidden(false);

	_IsRegister = true;
}

void MathLabLoginWidget::on_Yes_clicked()
{
	ui.label_note->setHidden(true);
	QString userName = ui.lineEdit_Name->text();
	QString userClass = ui.lineEdit_Class->text();
	QString userPwd = ui.lineEdit_Password->text();
	QString userRePwd = ui.lineEdit_Repwd->text();
	UsersTpye userType = GetUserTypeByCheck();
	
	if (userName == _ManagerName)
	{
		LogNoteInfo(QString::fromLocal8Bit("���˺��ѱ�ʹ�ã�"));
	}
	else
	{
		UserInfoList::iterator it = std::find_if(_Userlst.begin(), _Userlst.end(), [&](UserInfoPtr user){
			return user->Usertype == userType && user->UserName == userName;
		});
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
		addUser->Usertype = userType;

		if (userRePwd.isEmpty() && !userPwd.isEmpty())
		{
			LogNoteInfo(QString::fromLocal8Bit("������ȷ�����룡"));
			return;
		}
		else if (userRePwd != userPwd)
		{
			LogNoteInfo(QString::fromLocal8Bit("ȷ�����벻һ�£�"));
			return;
		}

		_Userlst.push_back(addUser);
		if (_IsRegister)
		{
			LogNoteInfo(QString::fromLocal8Bit("ע��ɹ���"));
			on_Return_clicked();
		}
		else
		{
			LogNoteInfo(QString::fromLocal8Bit("�޸ĳɹ���"));
			on_Return_clicked();
		}

		SetUserList(_Userlst);
	}
	
}

void MathLabLoginWidget::on_Return_clicked()
{
	ui.label_note->setHidden(true);
	setWindowTitle("Login");
	ui.label_pwd->setHidden(true);
	ui.lineEdit_Repwd->setHidden(true);
	ui.label_Class->setHidden(true);
	ui.lineEdit_Class->setHidden(true);
	ui.pushButton_login->setHidden(false);
	ui.pushButton_edit->setHidden(false);
	ui.pushButton_register->setHidden(false);
	ui.pushButton_Yes->setHidden(true);
	ui.pushButton_return->setHidden(true);
}

void MathLabLoginWidget::on_checkBox_stu_stateChanged(int arg)
{
	ui.label_note->setHidden(true);
	if(arg == Qt::CheckState::Checked)
	{
		ui.checkBox_tea->blockSignals(true);
		ui.checkBox_tea->setCheckState(Qt::CheckState::Unchecked);
		ui.checkBox_tea->blockSignals(false);
		
		ui.label_Class->setText(QString::fromLocal8Bit("�༶��"));
	}
}

void MathLabLoginWidget::on_checkBox_tea_stateChanged(int arg)
{
	ui.label_note->setHidden(true);
	if(arg == Qt::CheckState::Checked)
	{
		ui.checkBox_stu->blockSignals(true);
		ui.checkBox_stu->setCheckState(Qt::CheckState::Unchecked);
		ui.checkBox_stu->blockSignals(false);

		ui.label_Class->setText(QString::fromLocal8Bit("��ʦ������"));
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
