#include "MathLab.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MathLab w;
	w.show();
	return a.exec();
}
