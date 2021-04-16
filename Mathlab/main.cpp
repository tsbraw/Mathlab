#include "MathLabLoginWidget.h"
#include "MathLab.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MathLab w;
	//w.show();
	MathLabLoginWidget logindlg;//建立自己新建的类的对象
	if(logindlg.exec()==QDialog::Accepted) //利用 Accepted 信号判断 enterBtn 是否被按
	{
		w.show();  //如果被按下，显示主窗口
		return a.exec();  //程序一直执行，直到主窗口关闭
	}
	else
	{
		return 0;//如果没被按下，则不会进入主窗口，整个程序结束运行
	}
}
