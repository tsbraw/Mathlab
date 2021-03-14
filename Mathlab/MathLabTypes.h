#pragma once

#include <boost/shared_ptr.hpp>
#include <QDateTime>
#include <vector>
#include <map>


//�û�����
enum UsersTpye
{
	Teachers,

	Students
};


//ѡ����Ϣ
struct CourseInfo
{
	CourseInfo()
		: CourseName("")
		, TeacherName("")
	{

	}

	//�γ�����
	std::string CourseName;

	//��ʦ����
	std::string TeacherName;

	//�༶����
	std::vector<std::string> ClassNames;

	//��Ŀ˵��
	std::string ProjectInfo;

	//�γ�����
	QDateTime TimeDay;
};
typedef boost::shared_ptr<CourseInfo> CourseInfoPtr;
typedef std::vector<CourseInfoPtr> CourseInfoList;
typedef std::map<std::string, CourseInfoList> UserCourseInfoList;