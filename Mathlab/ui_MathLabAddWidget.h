/********************************************************************************
** Form generated from reading UI file 'MathLabAddWidget.ui'
**
** Created: Sun May 16 21:59:33 2021
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATHLABADDWIDGET_H
#define UI_MATHLABADDWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MathLabAddWidget
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_Course;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QPushButton *pushButton_Cancel;
    QLineEdit *lineEdit_instruction;
    QLineEdit *lineEdit_Classes;
    QPushButton *pushButton_Ok;
    QLabel *label_4;

    void setupUi(QWidget *MathLabAddWidget)
    {
        if (MathLabAddWidget->objectName().isEmpty())
            MathLabAddWidget->setObjectName(QString::fromUtf8("MathLabAddWidget"));
        MathLabAddWidget->resize(425, 162);
        gridLayout = new QGridLayout(MathLabAddWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_Course = new QLineEdit(MathLabAddWidget);
        lineEdit_Course->setObjectName(QString::fromUtf8("lineEdit_Course"));

        gridLayout->addWidget(lineEdit_Course, 0, 2, 1, 3);

        label = new QLabel(MathLabAddWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 2, 1, 1);

        label_3 = new QLabel(MathLabAddWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        pushButton_Cancel = new QPushButton(MathLabAddWidget);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));

        gridLayout->addWidget(pushButton_Cancel, 3, 4, 1, 1);

        lineEdit_instruction = new QLineEdit(MathLabAddWidget);
        lineEdit_instruction->setObjectName(QString::fromUtf8("lineEdit_instruction"));

        gridLayout->addWidget(lineEdit_instruction, 2, 2, 1, 3);

        lineEdit_Classes = new QLineEdit(MathLabAddWidget);
        lineEdit_Classes->setObjectName(QString::fromUtf8("lineEdit_Classes"));

        gridLayout->addWidget(lineEdit_Classes, 1, 2, 1, 3);

        pushButton_Ok = new QPushButton(MathLabAddWidget);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));

        gridLayout->addWidget(pushButton_Ok, 3, 3, 1, 1);

        label_4 = new QLabel(MathLabAddWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);


        retranslateUi(MathLabAddWidget);

        QMetaObject::connectSlotsByName(MathLabAddWidget);
    } // setupUi

    void retranslateUi(QWidget *MathLabAddWidget)
    {
        MathLabAddWidget->setWindowTitle(QApplication::translate("MathLabAddWidget", "\345\256\236\351\252\214\350\247\204\345\210\222", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MathLabAddWidget", "\350\257\276\347\250\213\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MathLabAddWidget", "\347\217\255\347\272\247\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_Cancel->setText(QApplication::translate("MathLabAddWidget", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        pushButton_Ok->setText(QApplication::translate("MathLabAddWidget", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MathLabAddWidget", "\350\257\264\346\230\216\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MathLabAddWidget: public Ui_MathLabAddWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATHLABADDWIDGET_H
