#pragma once

#include <boost/shared_ptr.hpp>
#include <QDateTime>
#include <vector>
#include <map>


//�û�����
enum UsersTpye
{
	Teachers,

	Students,

	Manager
};

//�û���Ϣ
struct UserInfo 
{
	UserInfo()
		:UserName("")
		,Usertype(Students)
		,UserPwd("")
		,UserClass("")
	{

	}
	// �û���
	QString UserName;

	// �û�����
	UsersTpye Usertype;

	// �û�����
	QString UserPwd;

	// �����༶ or ��ʦ����
	QString UserClass;
};
typedef boost::shared_ptr<UserInfo> UserInfoPtr;
typedef std::vector<UserInfoPtr> UserInfoList;

//ѡ����Ϣ
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

	//ʵ��������
	QString LabName;

	//�γ����
	int CourseIdx;
};
typedef boost::shared_ptr<CourseInfo> CourseInfoPtr;
typedef std::vector<CourseInfoPtr> CourseInfoList;
typedef std::map<QDateTime, CourseInfoList> DateCourseInfoList;
typedef std::map<QString, DateCourseInfoList> LabCourseInoList;