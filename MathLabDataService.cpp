#include "MathLabDataService.h"


MathLabDataService::MathLabDataService(std::string userId)
{

	ReadDataFromDB(userId);
}


MathLabDataService::~MathLabDataService(void)
{

}

CourseInfoList MathLabDataService::GetCourseList() const
{
	return _CourseList;
}

void MathLabDataService::SetCourseList(CourseInfoList CourseList)
{
	_CourseList = CourseList;
}

UserCourseInfoList MathLabDataService::GetUserCourseList() const
{
	return _UserCourseList;
}

void MathLabDataService::SetUserCourseList(UserCourseInfoList userList)
{
	_UserCourseList = userList;
}

UsersTpye MathLabDataService::GetUserType() const
{
	return _UserType;
}

void MathLabDataService::SetUserType(UsersTpye user)
{
	_UserType = user;
}

void MathLabDataService::Init()
{

}

void MathLabDataService::ReadDataFromDB(std::string userId)
{

}

void MathLabDataService::WriteDataToDB(std::string userId)
{

}
