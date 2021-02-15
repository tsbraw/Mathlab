/********************************************************************************
** Form generated from reading UI file 'MathLab.ui'
**
** Created: Mon Feb 15 17:46:38 2021
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATHLAB_H
#define UI_MATHLAB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MathLabClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_Search;
    QPushButton *pushButton_add;
    QTableWidget *tableWidget_Week;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *treeWidget_Class;
    QPushButton *pushButton_delete;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MathLabClass)
    {
        if (MathLabClass->objectName().isEmpty())
            MathLabClass->setObjectName(QString::fromUtf8("MathLabClass"));
        MathLabClass->resize(1218, 698);
        centralWidget = new QWidget(MathLabClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_Search = new QLineEdit(centralWidget);
        lineEdit_Search->setObjectName(QString::fromUtf8("lineEdit_Search"));

        gridLayout->addWidget(lineEdit_Search, 0, 0, 1, 1);

        pushButton_add = new QPushButton(centralWidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        gridLayout->addWidget(pushButton_add, 2, 2, 1, 1);

        tableWidget_Week = new QTableWidget(centralWidget);
        if (tableWidget_Week->columnCount() < 7)
            tableWidget_Week->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Week->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Week->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Week->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Week->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Week->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Week->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Week->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget_Week->rowCount() < 7)
            tableWidget_Week->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Week->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Week->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_Week->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Week->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Week->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_Week->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Week->setVerticalHeaderItem(6, __qtablewidgetitem13);
        tableWidget_Week->setObjectName(QString::fromUtf8("tableWidget_Week"));
        tableWidget_Week->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(tableWidget_Week, 0, 1, 2, 3);

        horizontalSpacer = new QSpacerItem(615, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        treeWidget_Class = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("\346\225\231\345\256\244"));
        treeWidget_Class->setHeaderItem(__qtreewidgetitem);
        treeWidget_Class->setObjectName(QString::fromUtf8("treeWidget_Class"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget_Class->sizePolicy().hasHeightForWidth());
        treeWidget_Class->setSizePolicy(sizePolicy);
        treeWidget_Class->setMinimumSize(QSize(0, 0));
        treeWidget_Class->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(treeWidget_Class, 1, 0, 2, 1);

        pushButton_delete = new QPushButton(centralWidget);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));

        gridLayout->addWidget(pushButton_delete, 2, 3, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);
        MathLabClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MathLabClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MathLabClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MathLabClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MathLabClass->setStatusBar(statusBar);

        retranslateUi(MathLabClass);

        QMetaObject::connectSlotsByName(MathLabClass);
    } // setupUi

    void retranslateUi(QMainWindow *MathLabClass)
    {
        MathLabClass->setWindowTitle(QApplication::translate("MathLabClass", "MathLab", 0, QApplication::UnicodeUTF8));
        pushButton_add->setText(QApplication::translate("MathLabClass", "\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Week->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MathLabClass", "\346\230\237\346\234\237\344\270\200", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Week->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MathLabClass", "\346\230\237\346\234\237\344\272\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Week->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MathLabClass", "\346\230\237\346\234\237\344\270\211", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Week->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MathLabClass", "\346\230\237\346\234\237\345\233\233", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Week->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MathLabClass", "\346\230\237\346\234\237\344\272\224", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Week->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MathLabClass", "\346\230\237\346\234\237\345\205\255", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Week->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MathLabClass", "\346\230\237\346\234\237\345\244\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Week->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MathLabClass", "8:00-9:40", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Week->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MathLabClass", "10:10-11:50", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_Week->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("MathLabClass", "14:00-15:40", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_Week->verticalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("MathLabClass", "16:10-17:50", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_Week->verticalHeaderItem(6);
        ___qtablewidgetitem11->setText(QApplication::translate("MathLabClass", "19:00-21:30", 0, QApplication::UnicodeUTF8));
        pushButton_delete->setText(QApplication::translate("MathLabClass", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MathLabClass: public Ui_MathLabClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATHLAB_H
