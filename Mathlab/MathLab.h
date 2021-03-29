#ifndef EMITCRASH_H
#define EMITCRASH_H

#include <QtGui/QMainWindow>

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
	void OnDateEditChanged(const QDateTime & dateTime);


private:

	// 设置表头内容
	void SetWeekTime(QDateTime CurTime);

	QStringList FillWeekTime(QDateTime CurTime, int weekday);

private:
	Ui::MathLabClass ui;

	UsersTpye _UserType;

	CourseInfoList _CourseList;

	MathLab *_caa;
};

typedef boost::shared_ptr<MathLab> MathLabPtr;
#endif // EMITCRASH_H
