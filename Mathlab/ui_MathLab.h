/********************************************************************************
** Form generated from reading UI file 'MathLabHp4740.ui'
**
** Created: Sun Mar 14 19:40:23 2021
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MATHLABHP4740_H
#define MATHLABHP4740_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MathLabClass
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QDateEdit *dateEdit;
    QLabel *label;
    QTableWidget *tableWidget_MathClass;
    QTableView *tableView_MathClass;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MathLabClass)
    {
        if (MathLabClass->objectName().isEmpty())
            MathLabClass->setObjectName(QString::fromUtf8("MathLabClass"));
        MathLabClass->resize(838, 546);
        centralwidget = new QWidget(MathLabClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tableWidget_MathClass = new QTableWidget(centralwidget);
        if (tableWidget_MathClass->columnCount() < 7)
            tableWidget_MathClass->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_MathClass->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_MathClass->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_MathClass->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_MathClass->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_MathClass->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_MathClass->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_MathClass->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget_MathClass->rowCount() < 7)
            tableWidget_MathClass->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_MathClass->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_MathClass->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_MathClass->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_MathClass->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_MathClass->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_MathClass->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_MathClass->setVerticalHeaderItem(6, __qtablewidgetitem13);
        tableWidget_MathClass->setObjectName(QString::fromUtf8("tableWidget_MathClass"));

        gridLayout->addWidget(tableWidget_MathClass, 2, 0, 1, 2);

        tableView_MathClass = new QTableView(centralwidget);
        tableView_MathClass->setObjectName(QString::fromUtf8("tableView_MathClass"));

        gridLayout->addWidget(tableView_MathClass, 1, 0, 1, 2);

        gridLayout->setColumnStretch(1, 1);
        MathLabClass->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MathLabClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MathLabClass->setStatusBar(statusbar);
        menubar = new QMenuBar(MathLabClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 838, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MathLabClass->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());

        retranslateUi(MathLabClass);

        QMetaObject::connectSlotsByName(MathLabClass);
    } // setupUi

    void retranslateUi(QMainWindow *MathLabClass)
    {
        MathLabClass->setWindowTitle(QApplication::translate("MathLabClass", "\345\244\247\345\255\246\346\225\260\345\255\246\345\256\236\351\252\214\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MathLabClass", "\345\275\223\345\211\215\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_MathClass->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MathLabClass", "\345\221\250\344\270\200", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_MathClass->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MathLabClass", "\345\221\250\344\272\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_MathClass->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MathLabClass", "\345\221\250\344\270\211", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_MathClass->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MathLabClass", "\345\221\250\345\233\233", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_MathClass->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MathLabClass", "\345\221\250\344\272\224", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_MathClass->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MathLabClass", "\345\221\250\345\205\255", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_MathClass->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MathLabClass", "\345\221\250\346\227\245", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_MathClass->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MathLabClass", "\347\254\254\344\270\200\345\244\247\350\212\202", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_MathClass->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MathLabClass", "\347\254\254\344\272\214\345\244\247\350\212\202", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_MathClass->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("MathLabClass", "\347\254\254\344\270\211\345\244\247\350\212\202", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_MathClass->verticalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("MathLabClass", "\347\254\254\345\233\233\345\244\247\350\212\202", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_MathClass->verticalHeaderItem(6);
        ___qtablewidgetitem11->setText(QApplication::translate("MathLabClass", "\347\254\254\344\272\224\345\244\247\350\212\202", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MathLabClass", "\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MathLabClass", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MathLabClass: public Ui_MathLabClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MATHLABHP4740_H
