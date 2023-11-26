/********************************************************************************
** Form generated from reading UI file 'volemachine.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLEMACHINE_H
#define UI_VOLEMACHINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_voleMachine
{
public:
    QWidget *centralwidget;
    QTextEdit *memory_field;
    QTextEdit *reg_field;
    QLabel *label;
    QLabel *label_2;
    QPushButton *fetch_button;
    QTextEdit *screen;
    QLabel *label_3;
    QLineEdit *pc;
    QLineEdit *ir;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *groupBox;
    QPushButton *load_button;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QLabel *isoppend;
    QLabel *isValed;
    QLabel *label_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *voleMachine)
    {
        if (voleMachine->objectName().isEmpty())
            voleMachine->setObjectName("voleMachine");
        voleMachine->resize(800, 600);
        centralwidget = new QWidget(voleMachine);
        centralwidget->setObjectName("centralwidget");
        memory_field = new QTextEdit(centralwidget);
        memory_field->setObjectName("memory_field");
        memory_field->setEnabled(true);
        memory_field->setGeometry(QRect(10, 50, 181, 461));
        memory_field->setReadOnly(true);
        reg_field = new QTextEdit(centralwidget);
        reg_field->setObjectName("reg_field");
        reg_field->setEnabled(true);
        reg_field->setGeometry(QRect(210, 50, 191, 461));
        reg_field->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 63, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 20, 71, 20));
        fetch_button = new QPushButton(centralwidget);
        fetch_button->setObjectName("fetch_button");
        fetch_button->setGeometry(QRect(510, 170, 83, 29));
        screen = new QTextEdit(centralwidget);
        screen->setObjectName("screen");
        screen->setEnabled(true);
        screen->setGeometry(QRect(510, 330, 281, 181));
        screen->setReadOnly(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(520, 300, 63, 20));
        pc = new QLineEdit(centralwidget);
        pc->setObjectName("pc");
        pc->setGeometry(QRect(680, 270, 113, 28));
        pc->setAlignment(Qt::AlignCenter);
        pc->setReadOnly(true);
        ir = new QLineEdit(centralwidget);
        ir->setObjectName("ir");
        ir->setGeometry(QRect(680, 220, 113, 28));
        ir->setAlignment(Qt::AlignCenter);
        ir->setReadOnly(true);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(550, 220, 131, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(560, 270, 121, 20));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(510, 30, 271, 131));
        load_button = new QPushButton(groupBox);
        load_button->setObjectName("load_button");
        load_button->setGeometry(QRect(10, 30, 83, 29));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(12, 90, 251, 24));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 70, 131, 20));
        isoppend = new QLabel(groupBox);
        isoppend->setObjectName("isoppend");
        isoppend->setGeometry(QRect(100, 30, 131, 20));
        isValed = new QLabel(centralwidget);
        isValed->setObjectName("isValed");
        isValed->setGeometry(QRect(610, 169, 141, 31));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(320, 520, 211, 31));
        voleMachine->setCentralWidget(centralwidget);
        menubar = new QMenuBar(voleMachine);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        voleMachine->setMenuBar(menubar);
        statusbar = new QStatusBar(voleMachine);
        statusbar->setObjectName("statusbar");
        voleMachine->setStatusBar(statusbar);

        retranslateUi(voleMachine);

        QMetaObject::connectSlotsByName(voleMachine);
    } // setupUi

    void retranslateUi(QMainWindow *voleMachine)
    {
        voleMachine->setWindowTitle(QCoreApplication::translate("voleMachine", "voleMachine", nullptr));
        label->setText(QCoreApplication::translate("voleMachine", "Memory", nullptr));
        label_2->setText(QCoreApplication::translate("voleMachine", "Registers", nullptr));
        fetch_button->setText(QCoreApplication::translate("voleMachine", "Fetch", nullptr));
        label_3->setText(QCoreApplication::translate("voleMachine", "Screen", nullptr));
        label_4->setText(QCoreApplication::translate("voleMachine", "Instruction register", nullptr));
        label_5->setText(QCoreApplication::translate("voleMachine", "Program counter", nullptr));
        groupBox->setTitle(QCoreApplication::translate("voleMachine", "File", nullptr));
        load_button->setText(QCoreApplication::translate("voleMachine", "Load file", nullptr));
        label_6->setText(QCoreApplication::translate("voleMachine", "Path:", nullptr));
        isoppend->setText(QString());
        isValed->setText(QString());
        label_7->setText(QCoreApplication::translate("voleMachine", "Hint: all data are represented with hex", nullptr));
    } // retranslateUi

};

namespace Ui {
    class voleMachine: public Ui_voleMachine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLEMACHINE_H
