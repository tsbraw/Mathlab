#pragma once

#include <QtSql/QSqlDatabase>
#include "MathLabTypes.h"

class MathLabDataService
{
public:
	MathLabDataService();
	~MathLabDataService(void);

	CourseInfoList GetCourseList() const;
	void SetCourseList(CourseInfoList CourseList);

	DateCourseInfoList GetDateCourseList() const;
	void SetDateCourseList(DateCourseInfoList dateList);

	LabCourseInoList GetLabCourseList() const;

	UserInfoList GetUserList() const;
	void SetUserList(UserInfoList userLst);

public:
	
	// 加载配置文件
	void Init();

	// 初始化数据库服务
	bool InitDB();

	void ReadDataFromDB();

	void WriteDataToDB();


	DateCourseInfoList _DateCourseList;

private:
	CourseInfoList _CourseList;

	UserInfoList _UserList;

	QString _Host;
	int _Port;
	QString _DBName;
	QString _User;
	QString _Pwd;

	QSqlDatabase _DataBase;
};

