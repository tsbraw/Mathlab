#include "MathLabLoginWidget.h"
#include "MathLab.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MathLab w;
	//w.show();
	MathLabLoginWidget logindlg;
	if(logindlg.exec() == QDialog::Accepted) //利用 Accepted 信号判断 Longin 是否被按
	{
		w.show();
		return a.exec();
	}
	else
	{
		return 0;//如果没被按下，则不会进入主窗口，整个程序结束运行
	}
}
