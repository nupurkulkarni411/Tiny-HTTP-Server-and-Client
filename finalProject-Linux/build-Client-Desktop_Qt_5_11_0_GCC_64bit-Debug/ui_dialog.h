/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *centralwidget;
    QLabel *diaLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(800, 600);
        centralwidget = new QWidget(Dialog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        diaLabel = new QLabel(centralwidget);
        diaLabel->setObjectName(QStringLiteral("diaLabel"));
        diaLabel->setGeometry(QRect(10, 10, 761, 531));
        Dialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Dialog);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Dialog->setMenuBar(menubar);
        statusbar = new QStatusBar(Dialog);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Dialog->setStatusBar(statusbar);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QMainWindow *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "MainWindow", nullptr));
        diaLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
