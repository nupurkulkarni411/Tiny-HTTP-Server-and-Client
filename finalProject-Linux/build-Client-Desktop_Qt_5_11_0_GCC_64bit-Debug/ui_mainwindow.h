/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *connectTab;
    QVBoxLayout *verticalLayout;
    QPushButton *Connect;
    QWidget *checkinTab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *checkInLabel;
    QListWidget *CheckInlistWidget;
    QPushButton *checkinButton;
    QPushButton *checkinRefresh;
    QWidget *ckeckoutTab;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *checkoutLabel;
    QListWidget *checkoutlistWidget;
    QPushButton *checkoutpushButton;
    QPushButton *checkoutRefresh;
    QWidget *ViewFile;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QLabel *viewServerStorage;
    QListWidget *viewfilelistWidget;
    QPushButton *viewFileButton;
    QPushButton *viefilerefresh;
    QWidget *repositorycontent;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_5;
    QLabel *repoContentServerStorage;
    QListWidget *listWidget;
    QPushButton *repoContent;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_6;
    QLabel *repoContentClientStorage;
    QListWidget *clientStorageRepoContent;
    QPushButton *repoStorageClientStorage;
    QWidget *deleteTab;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_7;
    QLabel *deleteServerStorage;
    QListWidget *deleteListWidget;
    QPushButton *deleteButton;
    QPushButton *deleteRefresh;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(686, 382);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 651, 291));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        connectTab = new QWidget();
        connectTab->setObjectName(QStringLiteral("connectTab"));
        verticalLayout = new QVBoxLayout(connectTab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Connect = new QPushButton(connectTab);
        Connect->setObjectName(QStringLiteral("Connect"));

        verticalLayout->addWidget(Connect);

        tabWidget->addTab(connectTab, QString());
        checkinTab = new QWidget();
        checkinTab->setObjectName(QStringLiteral("checkinTab"));
        layoutWidget = new QWidget(checkinTab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 631, 241));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkInLabel = new QLabel(layoutWidget);
        checkInLabel->setObjectName(QStringLiteral("checkInLabel"));

        verticalLayout_2->addWidget(checkInLabel);

        CheckInlistWidget = new QListWidget(layoutWidget);
        CheckInlistWidget->setObjectName(QStringLiteral("CheckInlistWidget"));

        verticalLayout_2->addWidget(CheckInlistWidget);

        checkinButton = new QPushButton(layoutWidget);
        checkinButton->setObjectName(QStringLiteral("checkinButton"));
        checkinButton->setEnabled(false);

        verticalLayout_2->addWidget(checkinButton);

        checkinRefresh = new QPushButton(layoutWidget);
        checkinRefresh->setObjectName(QStringLiteral("checkinRefresh"));

        verticalLayout_2->addWidget(checkinRefresh);

        tabWidget->addTab(checkinTab, QString());
        ckeckoutTab = new QWidget();
        ckeckoutTab->setObjectName(QStringLiteral("ckeckoutTab"));
        layoutWidget1 = new QWidget(ckeckoutTab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 631, 241));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        checkoutLabel = new QLabel(layoutWidget1);
        checkoutLabel->setObjectName(QStringLiteral("checkoutLabel"));

        verticalLayout_3->addWidget(checkoutLabel);

        checkoutlistWidget = new QListWidget(layoutWidget1);
        checkoutlistWidget->setObjectName(QStringLiteral("checkoutlistWidget"));
        sizePolicy.setHeightForWidth(checkoutlistWidget->sizePolicy().hasHeightForWidth());
        checkoutlistWidget->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(checkoutlistWidget);

        checkoutpushButton = new QPushButton(layoutWidget1);
        checkoutpushButton->setObjectName(QStringLiteral("checkoutpushButton"));
        checkoutpushButton->setEnabled(false);

        verticalLayout_3->addWidget(checkoutpushButton);

        checkoutRefresh = new QPushButton(layoutWidget1);
        checkoutRefresh->setObjectName(QStringLiteral("checkoutRefresh"));

        verticalLayout_3->addWidget(checkoutRefresh);

        tabWidget->addTab(ckeckoutTab, QString());
        ViewFile = new QWidget();
        ViewFile->setObjectName(QStringLiteral("ViewFile"));
        layoutWidget2 = new QWidget(ViewFile);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 631, 241));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        viewServerStorage = new QLabel(layoutWidget2);
        viewServerStorage->setObjectName(QStringLiteral("viewServerStorage"));

        verticalLayout_4->addWidget(viewServerStorage);

        viewfilelistWidget = new QListWidget(layoutWidget2);
        viewfilelistWidget->setObjectName(QStringLiteral("viewfilelistWidget"));

        verticalLayout_4->addWidget(viewfilelistWidget);

        viewFileButton = new QPushButton(layoutWidget2);
        viewFileButton->setObjectName(QStringLiteral("viewFileButton"));
        viewFileButton->setEnabled(false);

        verticalLayout_4->addWidget(viewFileButton);

        viefilerefresh = new QPushButton(layoutWidget2);
        viefilerefresh->setObjectName(QStringLiteral("viefilerefresh"));

        verticalLayout_4->addWidget(viefilerefresh);

        tabWidget->addTab(ViewFile, QString());
        repositorycontent = new QWidget();
        repositorycontent->setObjectName(QStringLiteral("repositorycontent"));
        layoutWidget3 = new QWidget(repositorycontent);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 10, 311, 241));
        verticalLayout_5 = new QVBoxLayout(layoutWidget3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        repoContentServerStorage = new QLabel(layoutWidget3);
        repoContentServerStorage->setObjectName(QStringLiteral("repoContentServerStorage"));

        verticalLayout_5->addWidget(repoContentServerStorage);

        listWidget = new QListWidget(layoutWidget3);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_5->addWidget(listWidget);

        repoContent = new QPushButton(layoutWidget3);
        repoContent->setObjectName(QStringLiteral("repoContent"));

        verticalLayout_5->addWidget(repoContent);

        layoutWidget4 = new QWidget(repositorycontent);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(340, 10, 301, 241));
        verticalLayout_6 = new QVBoxLayout(layoutWidget4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        repoContentClientStorage = new QLabel(layoutWidget4);
        repoContentClientStorage->setObjectName(QStringLiteral("repoContentClientStorage"));

        verticalLayout_6->addWidget(repoContentClientStorage);

        clientStorageRepoContent = new QListWidget(layoutWidget4);
        clientStorageRepoContent->setObjectName(QStringLiteral("clientStorageRepoContent"));

        verticalLayout_6->addWidget(clientStorageRepoContent);

        repoStorageClientStorage = new QPushButton(layoutWidget4);
        repoStorageClientStorage->setObjectName(QStringLiteral("repoStorageClientStorage"));

        verticalLayout_6->addWidget(repoStorageClientStorage);

        tabWidget->addTab(repositorycontent, QString());
        deleteTab = new QWidget();
        deleteTab->setObjectName(QStringLiteral("deleteTab"));
        layoutWidget5 = new QWidget(deleteTab);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 10, 631, 241));
        verticalLayout_7 = new QVBoxLayout(layoutWidget5);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        deleteServerStorage = new QLabel(layoutWidget5);
        deleteServerStorage->setObjectName(QStringLiteral("deleteServerStorage"));

        verticalLayout_7->addWidget(deleteServerStorage);

        deleteListWidget = new QListWidget(layoutWidget5);
        deleteListWidget->setObjectName(QStringLiteral("deleteListWidget"));

        verticalLayout_7->addWidget(deleteListWidget);

        deleteButton = new QPushButton(layoutWidget5);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setEnabled(false);

        verticalLayout_7->addWidget(deleteButton);

        deleteRefresh = new QPushButton(layoutWidget5);
        deleteRefresh->setObjectName(QStringLiteral("deleteRefresh"));

        verticalLayout_7->addWidget(deleteRefresh);

        tabWidget->addTab(deleteTab, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 686, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(connectTab), QApplication::translate("MainWindow", "Connect to Server", nullptr));
        checkInLabel->setText(QApplication::translate("MainWindow", "Client Storage", nullptr));
        checkinButton->setText(QApplication::translate("MainWindow", "CheckIn File", nullptr));
        checkinRefresh->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(checkinTab), QApplication::translate("MainWindow", "CheckIn", nullptr));
        checkoutLabel->setText(QApplication::translate("MainWindow", "Server Storage", nullptr));
        checkoutpushButton->setText(QApplication::translate("MainWindow", "CheckOut File", nullptr));
        checkoutRefresh->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ckeckoutTab), QApplication::translate("MainWindow", "CheckOut", nullptr));
        viewServerStorage->setText(QApplication::translate("MainWindow", "Server Storage", nullptr));
        viewFileButton->setText(QApplication::translate("MainWindow", "View File", nullptr));
        viefilerefresh->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ViewFile), QApplication::translate("MainWindow", "View File", nullptr));
        repoContentServerStorage->setText(QApplication::translate("MainWindow", "Server Storage", nullptr));
        repoContent->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        repoContentClientStorage->setText(QApplication::translate("MainWindow", "Client Storage", nullptr));
        repoStorageClientStorage->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(repositorycontent), QApplication::translate("MainWindow", "Repository Contents", nullptr));
        deleteServerStorage->setText(QApplication::translate("MainWindow", "Server Storage", nullptr));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        deleteRefresh->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(deleteTab), QApplication::translate("MainWindow", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
