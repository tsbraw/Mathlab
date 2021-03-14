#pragma once

#include <boost/shared_ptr.hpp>
#include <QDateTime>
#include <vector>
#include <map>


//用户类型
enum UsersTpye
{
	Teachers,

	Students
};


//选课信息
struct CourseInfo
{
	CourseInfo()
		: CourseName("")
		, TeacherName("")
	{

	}

	//课程名称
	std::string CourseName;

	//教师名称
	std::string TeacherName;

	//班级名称
	std::vector<std::string> ClassNames;

	//项目说明
	std::string ProjectInfo;

	//课程日期
	QDateTime TimeDay;
};
typedef boost::shared_ptr<CourseInfo> CourseInfoPtr;
typedef std::vector<CourseInfoPtr> CourseInfoList;
typedef std::map<std::string, CourseInfoList> UserCourseInfoList;