#include "MathLabLoginWidget.h"
#include "MathLab.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MathLab w;
	//w.show();
	MathLabLoginWidget logindlg;
	if(logindlg.exec() == QDialog::Accepted) //���� Accepted �ź��ж� Longin �Ƿ񱻰�
	{
		w.show();
		return a.exec();
	}
	else
	{
		return 0;//���û�����£��򲻻���������ڣ����������������
	}
}
