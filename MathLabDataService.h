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
	
	// 初始化数据库服务
	void Init();

	void ReadDataFromDB(std::string userId);

	void WriteDataToDB(std::string userId);


	UserCourseInfoList _UserCourseList;

private:
	CourseInfoList _CourseList;

	UsersTpye _UserType;

};

