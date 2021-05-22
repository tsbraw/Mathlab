#pragma once

#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>

#include <QtSql/QSqlDatabase>
#include "MathLabTypes.h"


class MathLabDataService
{
public:
	~MathLabDataService(void);

private:
	MathLabDataService();

	static MathLabDataService * _instance;

public:
	static MathLabDataService *Instance();

	CourseInfoList GetCourseList() const;
	void SetCourseList(CourseInfoList CourseList);

	LabCourseInoList GetLabCourseList();
	void SetLabCourseList(LabCourseInoList labList);

	UserInfoList GetUserList() const;
	void SetUserList(UserInfoList userLst);

public:
	
	// ���������ļ�
	void Init();

	// ��ʼ�����ݿ����
	bool InitDB();

	void ReadDataFromDB();

	void WriteUserInfoToDB();
	void WriteCourseInfoToDB();

private:
	LabCourseInoList _LabCourseList;
	CourseInfoList _CourseList;
	UserInfoList _UserList;

	QString _Host;
	int _Port;
	QString _DBName;
	QString _User;
	QString _Pwd;

	QSqlDatabase _DataBase;

	boost::mutex _ReadMutex;
	boost::mutex _WriteMutex;
};

