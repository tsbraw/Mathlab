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
	// ��ת��ָ������
	void OnDateEditChanged(const QDateTime & dateTime);

	// ����½��γ̰�ť
	void OnNewCourseClicked();

	void OnNewCourse(QString classRoom, QTableWidgetItem * item);

	// ���ɾ���γ̰�ť
	void OnDelCourseClicked();

	// ˫�����Ԫ��
	void OnTableWidgetDouble(QTableWidgetItem *item);

	// ��ԭ��ǰʱ��
	void OnResetDateClicked();

	// ȡ���رմ����˳�����
	virtual void closeEvent(QCloseEvent * event);

	// ������̰�ť
	void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

private slots:
	void on_treeWidget_customContextMenuRequested(const QPoint& p);

	void on_treeWidget_itemClicked(QTreeWidgetItem *item, int col);

	// ��ӽ���
	void on_addItem_triggered();

	// �༭����
	void on_editItem_triggered();

	// ɾ������
	void on_delItem_triggered();

	// ���ص�¼����
	void ReturnToLogin();

	// չʾ�ҵĿγ���Ϣ
	void showMineCourses();

	// ��ѯָ���༶�Ŀγ���Ϣ
	void SearchClassCourse();

	// ���Ҿ���༶�γ���Ϣ/��ʦ�γ̰���
	void SearchByUserClass(CourseInfoList &courseLst, QString searchClass, bool teachersPaln);

private:

	// ���ñ�ͷ����
	void SetWeekTime(QDateTime CurTime);
	QStringList FillWeekTime(QDateTime CurTime, int weekday);

	// ��ʼ��ϵͳ����
	void InitSystemTray();

	void InitTreeWidget();

	// ���±������
	void UpdateTable();

	bool CheckExistInTree(QString text);

private:
	Ui::MathLabClass ui;

	// ������Ϣ
	UserInfoPtr _myInfo;

	// �γ���Ϣ�б�
	DateCourseInfoList _DateList;

	// ʵ������Ϣ�б�
	LabCourseInoList _LabList;

	// ϵͳ����
	QSystemTrayIcon *pSystemTray;

	// ��ǰʱ��
	QDateTime current_date_time;
};
#endif // EMITCRASH_H
