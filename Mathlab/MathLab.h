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
	// ��ת��ָ������
	void OnDateEditChanged(const QDateTime & dateTime);

	// ����½��γ̰�ť
	void OnNewCourseClicked();

	// ��ԭ��ǰʱ��
	void OnResetDateClicked();

	// ȡ���رմ����˳�����
	virtual void closeEvent(QCloseEvent * event);

	// ������̰�ť
	void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

private:

	// ���ñ�ͷ����
	void SetWeekTime(QDateTime CurTime);
	QStringList FillWeekTime(QDateTime CurTime, int weekday);

	// ��ʼ��ϵͳ����
	void InitSystemTray();

private:
	Ui::MathLabClass ui;

	// �û�����(��Ӧ�û�Ȩ��)
	UsersTpye _UserType;

	// �γ���Ϣ�б�
	CourseInfoList _CourseList;
	DateCourseInfoList _DateCourses;

	// ϵͳ����
	QSystemTrayIcon *pSystemTray;
};
#endif // EMITCRASH_H
