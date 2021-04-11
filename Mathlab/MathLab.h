#ifndef EMITCRASH_H
#define EMITCRASH_H

#include <QtGui/QMainWindow>
#include <QSystemTrayIcon>
#include <QCloseEvent>

#include "MathLabTypes.h"
#include "MathLabDataService.h"
#include "ui_MathLab.h"

class MathLab : public QMainWindow, public MathLabDataService
{
	Q_OBJECT

public:
	MathLab(QWidget *parent = 0, Qt::WFlags flags = 0, std::string userId = "");

	void Init();

	~MathLab();

public slots:
	// 跳转到指定日期
	void OnDateEditChanged(const QDateTime & dateTime);

	// 点击新建课程按钮
	void OnNewCourseClicked();

	// 还原当前时间
	void OnResetDateClicked();

	// 取消关闭窗口退出程序
	virtual void closeEvent(QCloseEvent * event);

	// 点击托盘按钮
	void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

private:

	// 设置表头内容
	void SetWeekTime(QDateTime CurTime);
	QStringList FillWeekTime(QDateTime CurTime, int weekday);

	// 初始化系统托盘
	void InitSystemTray();

private:
	Ui::MathLabClass ui;

	// 用户类型(对应用户权限)
	UsersTpye _UserType;

	// 课程信息列表
	CourseInfoList _CourseList;
	DateCourseInfoList _DateCourses;

	// 系统托盘
	QSystemTrayIcon *pSystemTray;
};
#endif // EMITCRASH_H
