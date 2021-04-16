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

	UesrInfoList GetUserList() const;
	void SetUserIntoList(UesrInfoPtr user);

public:
	
	// ���������ļ�
	void Init();

	// ��ʼ�����ݿ����
	bool InitDB();

	void ReadDataFromDB();

	void WriteDataToDB();


	DateCourseInfoList _DateCourseList;

private:
	CourseInfoList _CourseList;

	UesrInfoList _UserList;

	QString _Host;
	int _Port;
	QString _DBName;
	QString _User;
	QString _Pwd;

	QSqlDatabase _DataBase;
};

