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
		, ProjectInfo("")
	{

	}

	//�γ�����
	QString CourseName;

	//��ʦ����
	QString TeacherName;

	//�༶����
	std::vector<QString> ClassNames;

	//��Ŀ˵��
	QString ProjectInfo;

	//�γ�����
	QDateTime TimeDay;

	//�γ����
	int CourseIdx;
};
typedef boost::shared_ptr<CourseInfo> CourseInfoPtr;
typedef std::vector<CourseInfoPtr> CourseInfoList;
typedef std::map<QDateTime, CourseInfoList> DateCourseInfoList;