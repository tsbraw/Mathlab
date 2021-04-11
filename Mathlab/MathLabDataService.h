#pragma once

#include <QtSql/QSqlDatabase>
#include "MathLabTypes.h"

class MathLabDataService
{
public:
	MathLabDataService(std::string userId);
	~MathLabDataService(void);

	CourseInfoList GetCourseList() const;
	void SetCourseList(CourseInfoList CourseList);

	DateCourseInfoList GetDateCourseList() const;
	void SetDateCourseList(DateCourseInfoList dateList);

	UsersTpye GetUserType() const;
	void SetUserType(UsersTpye user);

public:
	
	// ���������ļ�
	void Init();

	// ��ʼ�����ݿ����
	bool InitDB();

	void ReadDataFromDB(std::string userId);

	void WriteDataToDB(std::string userId);


	DateCourseInfoList _DateCourseList;

private:
	CourseInfoList _CourseList;

	UsersTpye _UserType;

	QString _Host;
	int _Port;
	QString _DBName;
	QString _User;
	QString _Pwd;

	QSqlDatabase _DataBase;
};

