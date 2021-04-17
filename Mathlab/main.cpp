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
	sema.acquire();// ���ٽ������������ڴ�   SharedMemory
	QSharedMemory mem("MathLab");// ȫ�ֶ�����
	if (!mem.create(1))// ���ȫ�ֶ����Դ������˳�
	{
		QMessageBox::information(0, QObject::tr("warning"),QObject::tr("���г�������"));
		sema.release();
		return 0;
	}
	sema.release();

	MathLabLoginWidget logindlg;
	if(logindlg.exec() == QDialog::Accepted) //���� Accepted �ź��ж� Longin �Ƿ񱻰�
	{
		UserInfoPtr tp = logindlg.GetCurrentUser();
		MathLab w(NULL,0,tp);
		w.show();
		return a.exec();
	}
	else
	{
		return 0;//���û�����£��򲻻���������ڣ����������������
	}
}
