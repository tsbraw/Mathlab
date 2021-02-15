#pragma once

#include <boost/shared_ptr.hpp>
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
		, ClassName("")
		, TeacherName("")
		, TimeWeek(0)
		, TimeDay(0)
	{

	}

	std::string CourseName;

	std::string ClassName;

	std::string TeacherName;

	double TimeWeek;

	double TimeDay;

	double LeftCount;

	double SumCount;
};
typedef boost::shared_ptr<CourseInfo> CourseInfoPtr;
typedef std::vector<CourseInfoPtr> CourseInfoList;
typedef std::map<std::string, CourseInfoPtr> UserCourseInfoList;