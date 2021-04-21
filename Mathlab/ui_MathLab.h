/********************************************************************************
** Form generated from reading UI file 'MathLabgqHp32.ui'
**
** Created: Wed Apr 21 20:25:38 2021
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MATHLABGQHP32_H
#define MATHLABGQHP32_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MathLabClass
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget_Class;
    QLabel *label_date;
    QDateEdit *dateEdit;
    QPushButton *pushButton_resetDate;
    QTableWidget *tableWidget_MathClass;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_new;
    QPushButton *pushButton_del;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menu_mine;
    QMenu *menu_search;

    void setupUi(QMainWindow *MathLabClass)
    {
        if (MathLabClass->objectName().isEmpty())
            MathLabClass->setObjectName(QString::fromUtf8("MathLabClass"));
        MathLabClass->resize(1226, 705);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/EmitCrash/lab.png"), QSize(), QIcon::Normal, QIcon::Off);
        MathLabClass->setWindowIcon(icon);
        centralwidget = new QWidget(MathLabClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        treeWidget_Class = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget_Class->setHeaderItem(__qtreewidgetitem);
        treeWidget_Class->setObjectName(QString::fromUtf8("treeWidget_Class"));

        gridLayout->addWidget(treeWidget_Class, 0, 0, 3, 1);

        label_date = new QLabel(centralwidget);
        label_date->setObjectName(QString::fromUtf8("label_date"));

        gridLayout->addWidget(label_date, 0, 1, 1, 1);

        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 2, 1, 2);

        pushButton_resetDate = new QPushButton(centralwidget);
        pushButton_resetDate->setObjectName(QString::fromUtf8("pushButton_resetDate"));

        gridLayout->addWidget(pushButton_resetDate, 0, 4, 1, 1);

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
        if (tableWidget_MathClass->rowCount() < 5)
            tableWidget_MathClass->setRowCount(5);
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
        tableWidget_MathClass->setObjectName(QString::fromUtf8("tableWidget_MathClass"));

        gridLayout->addWidget(tableWidget_MathClass, 1, 1, 1, 4);

        horizontalSpacer = new QSpacerItem(531, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 2);

        pushButton_new = new QPushButton(centralwidget);
        pushButton_new->setObjectName(QString::fromUtf8("pushButton_new"));

        gridLayout->addWidget(pushButton_new, 2, 3, 1, 1);

        pushButton_del = new QPushButton(centralwidget);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));

        gridLayout->addWidget(pushButton_del, 2, 4, 1, 1);

        gridLayout->setColumnStretch(2, 1);
        MathLabClass->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MathLabClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MathLabClass->setStatusBar(statusbar);
        menubar = new QMenuBar(MathLabClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1226, 26));
        menu_mine = new QMenu(menubar);
        menu_mine->setObjectName(QString::fromUtf8("menu_mine"));
        menu_search = new QMenu(menubar);
        menu_search->setObjectName(QString::fromUtf8("menu_search"));
        MathLabClass->setMenuBar(menubar);

        menubar->addAction(menu_mine->menuAction());
        menubar->addAction(menu_search->menuAction());

        retranslateUi(MathLabClass);

        QMetaObject::connectSlotsByName(MathLabClass);
    } // setupUi

    void retranslateUi(QMainWindow *MathLabClass)
    {
        MathLabClass->setWindowTitle(QApplication::translate("MathLabClass", "\345\244\247\345\255\246\346\225\260\345\255\246\345\256\236\351\252\214\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        label_date->setText(QApplication::translate("MathLabClass", "\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_resetDate->setText(QApplication::translate("MathLabClass", "\350\277\230\345\216\237", 0, QApplication::UnicodeUTF8));
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
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_MathClass->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("MathLabClass", "\347\254\254\344\270\211\345\244\247\350\212\202", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_MathClass->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("MathLabClass", "\347\254\254\345\233\233\345\244\247\350\212\202", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_MathClass->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("MathLabClass", "\347\254\254\344\272\224\345\244\247\350\212\202", 0, QApplication::UnicodeUTF8));
        pushButton_new->setText(QApplication::translate("MathLabClass", "\346\226\260\345\242\236", 0, QApplication::UnicodeUTF8));
        pushButton_del->setText(QApplication::translate("MathLabClass", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        menu_mine->setTitle(QApplication::translate("MathLabClass", "\346\210\221\347\232\204", 0, QApplication::UnicodeUTF8));
        menu_search->setTitle(QApplication::translate("MathLabClass", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MathLabClass: public Ui_MathLabClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MATHLABGQHP32_H
