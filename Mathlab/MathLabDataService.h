#pragma once

#include "MathLabTypes.h"

class MathLabDataService
{
public:
	MathLabDataService(std::string userId);
	~MathLabDataService(void);

	CourseInfoList GetCourseList() const;
	void SetCourseList(CourseInfoList CourseList);

	UserCourseInfoList GetUserCourseList() const;
	void SetUserCourseList(UserCourseInfoList userList);

	UsersTpye GetUserType() const;
	void SetUserType(UsersTpye user);

public:
	
	// 加载配置文件
	void Init();

	// 初始化数据库服务
	bool InitDB();

	void ReadDataFromDB(std::string userId);

	void WriteDataToDB(std::string userId);


	UserCourseInfoList _UserCourseList;

private:
	CourseInfoList _CourseList;

	UsersTpye _UserType;

	QString _Host;
	int _Port;
	QString _DBName;
	QString _User;
	QString _Pwd;
};

