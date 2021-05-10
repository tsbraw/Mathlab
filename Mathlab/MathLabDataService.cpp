
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <pugixml.hpp>
#include <pugixml.cpp>

#include "MathLabDataService.h"


MathLabDataService::MathLabDataService()
{
	Init();
	ReadDataFromDB();
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

LabCourseInoList MathLabDataService::GetLabCourseList() const
{
	return _LabCourseList;
}

void MathLabDataService::SetDateCourseList(LabCourseInoList labList)
{
	_LabCourseList = labList;
}

UserInfoList MathLabDataService::GetUserList() const
{
	return _UserList;
}

void MathLabDataService::SetUserList(UserInfoList userLst)
{
	_UserList = userLst;
}

void MathLabDataService::Init()
{
	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("D:/Desktop/proC++/MathLab/Mathlab/config/DataServiceConfig.xml");

	if (result.status == pugi::status_ok)
	{
		pugi::xml_node managerNode = doc.child("DataService");
		if (managerNode)
		{
			pugi::xml_node HostName = managerNode.child("Host");
			pugi::xml_node Port = managerNode.child("Port");
			pugi::xml_node DBName = managerNode.child("DBName");
			pugi::xml_node UserName = managerNode.child("UserName");
			pugi::xml_node Pwd = managerNode.child("Password");

			if (HostName && Port && DBName && UserName && Pwd)
			{
				_Host = HostName.text().as_string();
				_Port = Port.text().as_int();
				_DBName = DBName.text().as_string();
				_User = UserName.text().as_string();
				_Pwd = Pwd.text().as_string();

				InitDB();
			}
		}
	}
	else
	{
		/*std::cout << "Load ManagerInfo Failed!" << std::endl;*/
	}
}

bool MathLabDataService::InitDB()
{
	_DataBase = QSqlDatabase::addDatabase("QODBC");

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
		/*QMessageBox::critical(0, QObject::tr("无法打开数据库"),
			"无法创建数据库连接！", QMessageBox::Cancel);*/

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

void MathLabDataService::ReadDataFromDB()
{
	if (_DataBase.isOpen())
	{
		QSqlQuery query(_DataBase);

		bool isOK= query.prepare("CALL READ_DATA()");


	}
}

void MathLabDataService::WriteDataToDB()
{

}
