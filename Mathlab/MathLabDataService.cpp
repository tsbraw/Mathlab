
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

DateCourseInfoList MathLabDataService::GetDateCourseList() const
{
	return _DateCourseList;
}

void MathLabDataService::SetDateCourseList(DateCourseInfoList dateList)
{
	_DateCourseList = dateList;
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

	_DataBase.setConnectOptions("SQL_ATTR_LOGIN_TIMEOUT=5;SQL_ATTR_CONNECT_TIMROUT=5");

	bool isopen = _DataBase.open();

	if (isopen)
	{
		return true;
	}
	else
	{
		QString ErrorStr = _DataBase.lastError().databaseText();
		QMessageBox::critical(0, QObject::tr("无法打开数据库"),
			"无法创建数据库连接！", QMessageBox::Cancel);

		return false;
	}


	// 下面来创建表
	// 如果 MySQL 数据库中已经存在同名的表，那么下面的代码不会执行
	QSqlQuery query(_DataBase);

	// 使数据库支持中文
	query.exec("SET NAMES 'Latin1'");
	// 创建 course 表
	query.exec("create table course (id int primary key, "
		"name varchar(20), teacher varchar(20))");
	query.exec("insert into course values(0, '数学', '张老师')");
	query.exec("insert into course values(1, '语文', '李老师')");
	query.exec("insert into course values(2, '英语', '王老师')");
	return true;
}

void MathLabDataService::ReadDataFromDB(std::string userId)
{
	if (_DataBase.isOpen())
	{
		QSqlQuery query(_DataBase);

		bool isOK= query.prepare("CALL READ_DATA()");


	}
}

void MathLabDataService::WriteDataToDB(std::string userId)
{

}
