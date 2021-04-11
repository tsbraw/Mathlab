
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <pugixml.hpp>
#include <pugixml.cpp>

#include "MathLabDataService.h"


MathLabDataService::MathLabDataService(std::string userId)
{

	ReadDataFromDB(userId);
}


MathLabDataService::~MathLabDataService(void)
{

}

CourseInfoList MathLabDataService::GetCourseList() const
{
	return _CourseList;
}

void MathLabDataService::SetCourseList(CourseInfoList CourseList)
{
	_CourseList = CourseList;
}

UserCourseInfoList MathLabDataService::GetUserCourseList() const
{
	return _UserCourseList;
}

void MathLabDataService::SetUserCourseList(UserCourseInfoList userList)
{
	_UserCourseList = userList;
}

UsersTpye MathLabDataService::GetUserType() const
{
	return _UserType;
}

void MathLabDataService::SetUserType(UsersTpye user)
{
	_UserType = user;
}

void MathLabDataService::Init()
{
	pugi::xml_document doc;
}

bool MathLabDataService::InitDB()
{
	_DataBase = QSqlDatabase::addDatabase("QOCI");

	_DataBase.setHostName(_Host);
	_DataBase.setPort(_Port);
	_DataBase.setDatabaseName(_DBName);
	_DataBase.setUserName(_User);
	_DataBase.setPassword(_Pwd);

	//_DataBase.setConnectOptions(TODO);

	bool isopen = _DataBase.open();

	if (isopen)
	{
		return true;
	}
	else
	{
		QString ErrorStr = _DataBase.lastError().databaseText();
		QMessageBox::critical(0, QObject::tr("�޷������ݿ�"),
			"�޷��������ݿ����ӣ�", QMessageBox::Cancel);

		return false;
	}


	// ������������
	// ��� MySQL ���ݿ����Ѿ�����ͬ���ı���ô����Ĵ��벻��ִ��
	QSqlQuery query(_DataBase);

	// ʹ���ݿ�֧������
	query.exec("SET NAMES 'Latin1'");
	// ���� course ��
	query.exec("create table course (id int primary key, "
		"name varchar(20), teacher varchar(20))");
	query.exec("insert into course values(0, '��ѧ', '����ʦ')");
	query.exec("insert into course values(1, '����', '����ʦ')");
	query.exec("insert into course values(2, 'Ӣ��', '����ʦ')");
	return true;
}

void MathLabDataService::ReadDataFromDB(std::string userId)
{
	if (_DataBase.isOpen())
	{
		QSqlQuery query(_DataBase);

		query.prepare("CALL READ_DATA()");


	}
}

void MathLabDataService::WriteDataToDB(std::string userId)
{

}
