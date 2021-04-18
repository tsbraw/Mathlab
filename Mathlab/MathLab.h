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
	MathLab(QWidget *parent = 0, Qt::WFlags flags = 0, UserInfoPtr userinfo = nullptr);

	void Init();

	~MathLab();

public slots:
	// 跳转到指定日期
	void OnDateEditChanged(const QDateTime & dateTime);

	// 点击新建课程按钮
	void OnNewCourseClicked();

	void OnNewCourse(QString classRoom, QTableWidgetItem * item);

	// 点击删除课程按钮
	void OnDelCourseClicked();

	// 双击表格单元格
	void OnTableWidgetDouble(QTableWidgetItem *item);

	// 还原当前时间
	void OnResetDateClicked();

	// 取消关闭窗口退出程序
	virtual void closeEvent(QCloseEvent * event);

	// 点击托盘按钮
	void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

private slots:
	void on_treeWidget_customContextMenuRequested(const QPoint& p);

	void on_treeWidget_itemClicked(QTreeWidgetItem *item, int col);

	// 添加教室
	void on_addItem_triggered();

	// 编辑教室
	void on_editItem_triggered();

	// 删除教室
	void on_delItem_triggered();

	// 返回登录界面
	void ReturnToLogin();

	// 展示我的课程信息
	void showMineCourses();

	// 查询指定班级的课程信息
	void SearchClassCourse();

	// 查找具体班级课程信息/教师课程安排
	void SearchByUserClass(CourseInfoList &courseLst, QString searchClass, bool teachersPaln);

private:

	// 设置表头内容
	void SetWeekTime(QDateTime CurTime);
	QStringList FillWeekTime(QDateTime CurTime, int weekday);

	// 初始化系统托盘
	void InitSystemTray();

	void InitTreeWidget();

	// 更新表格数据
	void UpdateTable();

	bool CheckExistInTree(QString text);

private:
	Ui::MathLabClass ui;

	// 个人信息
	UserInfoPtr _myInfo;

	// 课程信息列表
	DateCourseInfoList _DateList;

	// 实验室信息列表
	LabCourseInoList _LabList;

	// 系统托盘
	QSystemTrayIcon *pSystemTray;

	// 当前时间
	QDateTime current_date_time;
};
#endif // EMITCRASH_H
