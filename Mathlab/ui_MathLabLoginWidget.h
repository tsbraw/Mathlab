/********************************************************************************
** Form generated from reading UI file 'MathLabLoginWidgety15280.ui'
**
** Created: Fri Apr 16 22:29:04 2021
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MATHLABLOGINWIDGETY15280_H
#define MATHLABLOGINWIDGETY15280_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MathLabLoginWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_Name;
    QLabel *label_2;
    QLineEdit *lineEdit_Password;
    QPushButton *pushButton_login;
    QPushButton *pushButton_register;
    QPushButton *pushButton_edit;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_stu;
    QCheckBox *checkBox_tea;

    void setupUi(QWidget *MathLabLoginWidget)
    {
        if (MathLabLoginWidget->objectName().isEmpty())
            MathLabLoginWidget->setObjectName(QString::fromUtf8("MathLabLoginWidget"));
        MathLabLoginWidget->resize(443, 246);
        gridLayout = new QGridLayout(MathLabLoginWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(MathLabLoginWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit_Name = new QLineEdit(MathLabLoginWidget);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));
        lineEdit_Name->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_Name, 1, 1, 1, 1);

        label_2 = new QLabel(MathLabLoginWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEdit_Password = new QLineEdit(MathLabLoginWidget);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));
        lineEdit_Password->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_Password, 2, 1, 1, 1);

        pushButton_login = new QPushButton(MathLabLoginWidget);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));

        gridLayout->addWidget(pushButton_login, 3, 0, 1, 2);

        pushButton_register = new QPushButton(MathLabLoginWidget);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));

        gridLayout->addWidget(pushButton_register, 4, 0, 1, 2);

        pushButton_edit = new QPushButton(MathLabLoginWidget);
        pushButton_edit->setObjectName(QString::fromUtf8("pushButton_edit"));

        gridLayout->addWidget(pushButton_edit, 5, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox_stu = new QCheckBox(MathLabLoginWidget);
        checkBox_stu->setObjectName(QString::fromUtf8("checkBox_stu"));

        horizontalLayout->addWidget(checkBox_stu);

        checkBox_tea = new QCheckBox(MathLabLoginWidget);
        checkBox_tea->setObjectName(QString::fromUtf8("checkBox_tea"));

        horizontalLayout->addWidget(checkBox_tea);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);

        retranslateUi(MathLabLoginWidget);

        QMetaObject::connectSlotsByName(MathLabLoginWidget);
    } // setupUi

    void retranslateUi(QWidget *MathLabLoginWidget)
    {
        MathLabLoginWidget->setWindowTitle(QApplication::translate("MathLabLoginWidget", "MathLabLoginWidget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MathLabLoginWidget", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MathLabLoginWidget", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_login->setText(QApplication::translate("MathLabLoginWidget", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton_register->setText(QApplication::translate("MathLabLoginWidget", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        pushButton_edit->setText(QApplication::translate("MathLabLoginWidget", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        checkBox_stu->setText(QApplication::translate("MathLabLoginWidget", "\345\255\246\347\224\237\347\253\257", 0, QApplication::UnicodeUTF8));
        checkBox_tea->setText(QApplication::translate("MathLabLoginWidget", "\350\200\201\345\270\210\347\253\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MathLabLoginWidget: public Ui_MathLabLoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MATHLABLOGINWIDGETY15280_H
