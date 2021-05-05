#pragma once

#include <boost/shared_ptr.hpp>
#include <QDateTime>
#include <vector>
#include <map>


//用户类型
enum UsersTpye
{
	Teachers,

	Students,

	Manager
};

//用户信息
struct UserInfo 
{
	UserInfo()
		:UserName("")
		,Usertype(Students)
		,UserPwd("")
		,UserClass("")
	{

	}
	// 用户名
	QString UserName;

	// 用户类型
	UsersTpye Usertype;

	// 用户密码
	QString UserPwd;

	// 所属班级 or 教师名称
	QString UserClass;
};
typedef boost::shared_ptr<UserInfo> UserInfoPtr;
typedef std::vector<UserInfoPtr> UserInfoList;

//选课信息
struct CourseInfo
{
	CourseInfo()
		: CourseName("")
		, TeacherName("")
		, ProjectInfo("")
		, LabName("")
		, CourseIdx(0)
	{

	}

	//课程名称
	QString CourseName;

	//教师名称
	QString TeacherName;

	//班级名称
	std::vector<QString> ClassNames;

	//项目说明
	QString ProjectInfo;

	//课程日期
	QDateTime TimeDay;

	//实验室名称
	QString LabName;

	//课程序号
	int CourseIdx;
};
typedef boost::shared_ptr<CourseInfo> CourseInfoPtr;
typedef std::vector<CourseInfoPtr> CourseInfoList;
typedef std::map<QDateTime, CourseInfoList> DateCourseInfoList;
typedef std::map<QString, DateCourseInfoList> LabCourseInoList;