#include "MathLabLoginWidget.h"
#include "MathLab.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MathLab w;
	//w.show();
	MathLabLoginWidget logindlg;//�����Լ��½�����Ķ���
	if(logindlg.exec()==QDialog::Accepted) //���� Accepted �ź��ж� enterBtn �Ƿ񱻰�
	{
		w.show();  //��������£���ʾ������
		return a.exec();  //����һֱִ�У�ֱ�������ڹر�
	}
	else
	{
		return 0;//���û�����£��򲻻���������ڣ����������������
	}
}
