
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QVariant>
#include <QMessageBox>
#include <boost/smart_ptr/make_shared.hpp>
#include <boost/bind.hpp>
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
	_CourseList.clear();
	_LabCourseList.clear();
}

CourseInfoList MathLabDataService::GetCourseList() const
{
	return _CourseList;
}

void MathLabDataService::SetCourseList(CourseInfoList CourseList)
{
	_CourseList = CourseList;

	WriteDataToDB();
}

LabCourseInoList MathLabDataService::GetLabCourseList()
{
	std::map<QString, CourseInfoList> LabCourses;
	CourseInfoList::const_iterator it = _CourseList.begin();
	for (; it != _CourseList.end(); it++)
	{
		CourseInfoPtr courseInfo = *it;
		if (courseInfo)
		{
			QString Lab = courseInfo->LabName;

			LabCourses[Lab].push_back(courseInfo);
		}
	}

	std::map<QString, CourseInfoList>::iterator mapIt = LabCourses.begin();
	for (; mapIt != LabCourses.end(); mapIt++)
	{
		QString LabName = mapIt->first;
		DateCourseInfoList dateMap;
		CourseInfoList courLst = mapIt->second;
		CourseInfoList::const_iterator courIt = courLst.begin();
		for (; courIt != courLst.end(); courIt++)
		{
			CourseInfoPtr courInfo = *courIt;
			if (courInfo)
			{
				QDateTime dateT = courInfo->TimeDay;

				dateMap[dateT].push_back(courInfo);
			}
		}
		_LabCourseList[LabName] = dateMap;
	}

	return _LabCourseList;
}

void MathLabDataService::SetLabCourseList(LabCourseInoList labList)
{
	_LabCourseList = labList;

	CourseInfoList courLst;
	LabCourseInoList::iterator labIt = _LabCourseList.begin();
	for (; labIt != _LabCourseList.end(); labIt++)
	{
		DateCourseInfoList dateLst = labIt->second;
		DateCourseInfoList::iterator dateIt = dateLst.begin();
		for (; dateIt != dateLst.end(); dateIt++)
		{
			std::copy(dateIt->second.begin(), dateIt->second.end(), std::back_inserter(courLst));
		}
	}
	SetCourseList(courLst);
}

UserInfoList MathLabDataService::GetUserList() const
{
	return _UserList;
}

void MathLabDataService::SetUserList(UserInfoList userLst)
{
	_UserList = userLst;

	WriteDataToDB();
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

	_DataBase.setConnectOptions("SQL_ATTR_LOGIN_TIMEOUT=5;SQL_ATTR_CONNECT_TIMEOUT=5");

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
}

void MathLabDataService::ReadDataFromDB()
{
	if (_DataBase.isOpen())
	{
		QString usersql = "Select * from  USERINFO t";

		QSqlQuery userQuery(usersql, _DataBase);

		_UserList.clear();
		while (userQuery.next())
		{
			UserInfoPtr userInfo = boost::make_shared<UserInfo>();
			//读取数据
			userInfo->UserName = userQuery.value(0).toString();
			userInfo->Usertype = (UsersTpye)userQuery.value(1).toInt();
			userInfo->UserPwd = userQuery.value(2).toString();
			userInfo->UserClass = userQuery.value(3).toString();
			
			_UserList.push_back(userInfo);
		}

		QString coursesql = "select * from COURSEINFO t";

		QSqlQuery courseQuery(coursesql, _DataBase);

		_CourseList.clear();
		while (courseQuery.next())
		{
			CourseInfoPtr courseInfo = boost::make_shared<CourseInfo>();
			//读取数据
			courseInfo->CourseName = courseQuery.value(0).toString();
			courseInfo->TeacherName = courseQuery.value(1).toString();

			QString ClassText = courseQuery.value(2).toString();
			QStringList Classes = ClassText.split(";");
			courseInfo->ClassNames.clear();
			for (int i = 0; i < Classes.size(); i++)
			{
				courseInfo->ClassNames.push_back(Classes[i]);
			}

			courseInfo->ProjectInfo = courseQuery.value(3).toString();
			courseInfo->TimeDay = QDateTime::fromString(courseQuery.value(4).toString(), "yyyy.MM.dd");
			courseInfo->LabName = courseQuery.value(5).toString();
			courseInfo->CourseIdx = courseQuery.value(6).toInt();

			_CourseList.push_back(courseInfo);
		}
	}
}

void MathLabDataService::WriteDataToDB()
{
	if (_DataBase.isOpen())
	{
		//QString usersql = "Truncate table USERINFO t reuse storage";

		//QSqlQuery userQuery(usersql, _DataBase);

		UserInfoList::iterator userIt = _UserList.begin();
		for (; userIt != _UserList.end(); userIt++)
		{
			UserInfoPtr usr = *userIt;

			// 写入数据
			QString writeSql =  "insert into USERINFO(" + usr->UserName + "," + (int)usr->Usertype + "," + usr->UserPwd + "," + usr->UserClass + ") select * from USERINFO";
			//"insert into USERINFO(username, usertype, userpwd, userclass) values('Jim', '28')";
			_DataBase.exec(writeSql);
		}


// 		QString courSql = "select t.*, t.rowid from USERINFO t";
// 		QSqlQuery courseQuery(courSql, _DataBase);

		CourseInfoList::iterator courIt = _CourseList.begin();
		for (; courIt != _CourseList.end(); courIt++)
		{
			CourseInfoPtr cour = *courIt;

			QStringList Classes;
			for (int i = 0; i < cour->ClassNames.size(); i++)
			{
				Classes.push_back(cour->ClassNames.at(i));
			}
			QString ClassStr = Classes.join(";");
			// 写入数据
			QString wrSql =  "insert into COURSEINFO(coursename,teachername,classnames,projectinfo,timeday,labname, courseidx) values(" + cour->CourseName + "," + cour->TeacherName + "," + ClassStr + "," + cour->ProjectInfo + "," + cour->TimeDay.toString("yyyy.MM.dd") + "," + cour->LabName + "," + cour->CourseIdx + ")";
			//_DataBase.exec("insert into COURSEINFO(coursename,teachername,classnames,projectinfo,timeday,labname, courseidx) values('test', 'Make', '242', 'test prj', '2021.05.15', '09101', '3')");
			_DataBase.exec(wrSql);
		}
	}
}
