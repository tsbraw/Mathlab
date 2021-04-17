#include <QTextCodec>
#include <QSystemSemaphore>
#include <QSharedMemory>
#include <QMessageBox>
#include <QtGui/QApplication>
#include "MathLabLoginWidget.h"
#include "MathLab.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	QSystemSemaphore sema("a",1,QSystemSemaphore::Open);
	sema.acquire();// 在临界区操作共享内存   SharedMemory
	QSharedMemory mem("MathLab");// 全局对象名
	if (!mem.create(1))// 如果全局对象以存在则退出
	{
		QMessageBox::information(0, QObject::tr("warning"),QObject::tr("已有程序运行"));
		sema.release();
		return 0;
	}
	sema.release();

	MathLabLoginWidget logindlg;
	if(logindlg.exec() == QDialog::Accepted) //利用 Accepted 信号判断 Longin 是否被按
	{
		UserInfoPtr tp = logindlg.GetCurrentUser();
		MathLab w(NULL,0,tp);
		w.show();
		return a.exec();
	}
	else
	{
		return 0;//如果没被按下，则不会进入主窗口，整个程序结束运行
	}
}
