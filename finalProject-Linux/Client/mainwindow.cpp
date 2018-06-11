#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QMessageBox>
#include "../Sockets/Sockets.h"
#include "../Message/Message.h"
#include "../HttpCommCore/HttpCommCore.h"
#include <string>
#include <iostream>
#include <fstream>
#include "dialog.h"
#undef DELETE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir dir("/home/nupur/Desktop/newCode_0504_3am_pst/ClientStorage");
    ui->CheckInlistWidget->clear();
    ui->clientStorageRepoContent->clear();
    foreach(QFileInfo var, dir.entryInfoList()) {
        if (var.isFile())
            ui->CheckInlistWidget->addItem(var.fileName());
    }
    foreach(QFileInfo var, dir.entryInfoList()) {
        if (var.isFile())
            ui->clientStorageRepoContent->addItem(var.fileName());
    }
    ui->deleteButton->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Connect_clicked()
{
    ui->checkinButton->setEnabled(true);
    ui->checkoutpushButton->setEnabled(true);
    ui->viewFileButton->setEnabled(true);
    ui->deleteButton->setEnabled(true);
    HttpMessage<HttpRequest> msg;
    msg.type().command(HttpRequest::GET);
    msg.action("Connection check");

    HttpClient2 client;
    client.connect("localhost", 8080);

    HttpMessage<HttpReply> reply = client.postMessage(msg);
    std::string r = reply.toString();
    if (r.find("200") != std::string::npos)
        ui->statusBar->showMessage("Connection Established", 5000);

    HttpMessage<HttpRequest> msg4;
    msg4.type().command(HttpRequest::GET);
    msg4.action("GetRepoContent");

    client.connect("localhost", 8080);

    HttpMessage<HttpReply> reply4 = client.postMessage(msg4);
    std::string r1 = reply4.body().toString();
    int i = 0;
    ui->checkoutlistWidget->clear();
    ui->viewfilelistWidget->clear();
    ui->listWidget->clear();
    ui->deleteListWidget->clear();
    while (i < r1.size()) {
        size_t pos = r1.find_first_of('\n', i);
        QString q = QString::fromStdString(r1.substr(i, pos - i));
        ui->checkoutlistWidget->addItem(new QListWidgetItem(q, ui->checkoutlistWidget));
        ui->viewfilelistWidget->addItem(new QListWidgetItem(q, ui->viewfilelistWidget));
        ui->listWidget->addItem(new QListWidgetItem(q, ui->listWidget));
        ui->deleteListWidget->addItem(new QListWidgetItem(q, ui->deleteListWidget));
        i = pos + 1;
    }
}

void MainWindow::on_checkinButton_clicked()
{
    if (ui->CheckInlistWidget->selectedItems().size() != 0) {
        QList<QListWidgetItem*> file = ui->CheckInlistWidget->selectedItems();
        QString f = file[0]->text();
        std::string fileSpec = f.toLocal8Bit().constData();

        HttpMessage<HttpRequest> msg1;
        msg1.type().command(HttpRequest::PUT);
        msg1.action("File CheckIn");
        msg1.type().fileSpec(fileSpec);
        msg1.attribute("version", "New");

        HttpClient2 client;
        client.connect("localhost", 8080);

        HttpMessage<HttpReply> reply1 = client.postMessage(msg1);

        std::ifstream inFile;
        inFile.open(client.clientPath + fileSpec);
        if (!inFile) {
            std::cout << "\nUnable to open a file";
        }
        else {
            std::ifstream in(client.clientPath + fileSpec);
            std::stringstream b;
            b << in.rdbuf();
            std::string b1 = b.str();
            std::cout << b1.size();

            if (b1.size() > 1024) {
                size_t file_size = b1.size();
                int i = 0;
                while (file_size > 0) {
                    HttpMessage<HttpRequest> msg11;
                    msg11.type().command(HttpRequest::PUT);
                    msg11.action("File CheckIn");
                    msg11.type().fileSpec(reply1.body().toString().substr(reply1.body().toString().find_last_of(":") + 2));
                    if (file_size > 1024) {
                        msg11.body() = b1.substr(i, i + 1024);
                    }
                    else {
                        msg11.body() = b1.substr(i, i + (file_size % 1024));
                    }
                    msg11.contentLength(msg11.body().size());
                    msg11.attribute("version", "In-progress");

                    client.connect("localhost", 8080);
                    std::cout << "\n--Posting message to localhost:8080:";
                    msg11.show();

                    HttpMessage<HttpReply> reply11 = client.postMessage(msg11);

                    if (file_size >1024) {
                        i += 1024;
                        file_size -= 1024;
                    }
                    else {
                        i += (file_size % 1024);
                        file_size -= (file_size % 1024);
                    }

                }

            }
            else {

                HttpMessage<HttpRequest> msg11;
                msg11.type().command(HttpRequest::PUT);
                msg11.action("File CheckIn");
                msg11.type().fileSpec(reply1.body().toString().substr(reply1.body().toString().find_last_of(":") + 2));
                msg11.body() = b1;
                msg11.contentLength(msg11.body().size());
                msg11.attribute("version", "In-progress");

                client.connect("localhost", 8080);
                std::cout << "\n--Posting message to localhost:8080:";
                msg11.show();

                HttpMessage<HttpReply> reply11 = client.postMessage(msg11);
                if (reply11.toString().find("200") != std::string::npos)
                    ui->statusBar->showMessage("CheckIn successful", 5000);

            }

        }
        inFile.close();


    }
    else
        QMessageBox::critical(this, "Error", "Please select only or atleast 1 from the list");
}

void MainWindow::on_checkinRefresh_clicked()
{
    ui->CheckInlistWidget->clear();
    QDir dir("/home/nupur/Desktop/newCode_0504_3am_pst/ClientStorage");
    foreach(QFileInfo var, dir.entryInfoList()) {
        if (var.isFile())
            ui->CheckInlistWidget->addItem(var.fileName());
    }
}

void MainWindow::on_checkoutpushButton_clicked()
{
    if (ui->checkoutlistWidget->selectedItems().size() != 0) {

        QList<QListWidgetItem*> file = ui->checkoutlistWidget->selectedItems();
        QString f = file[0]->text();
        std::string fileSpec = f.toLocal8Bit().constData();

        HttpMessage<HttpRequest> msg3;
        msg3.type().command(HttpRequest::GET);
        msg3.action("File CheckOut");
        msg3.type().fileSpec(fileSpec);
        msg3.attribute("version", "selected");
        HttpClient2 client;
        client.connect("localhost", 8080);

        HttpMessage<HttpReply> reply3 = client.postMessage(msg3);
        std::cout << "\n--Received reply:";
        reply3.show();

        if (reply3.body().toString().empty()) {
            std::cout << "\nFile Not Found";
        }
        else {
            std::ofstream outfile;
            std::string fName = reply3.attributes().at("filename");
            if (fName.find_first_of("0123456789") != std::string::npos) {
                std::string fName1 = fName.substr(0, fName.find_first_of("0123456789"));
                std::string fext = fName.substr(fName.find_last_of('.'));
                fName = fName1 + fext;
            }

            outfile.open(client.clientPath + fName);
            outfile << reply3.body().toString();
            outfile.close();
        }
        if (reply3.toString().find("200") != std::string::npos)
            ui->statusBar->showMessage("Connection Established", 5000);
    }
    else
        QMessageBox::critical(this, "Error", "Please select only or atleast 1 from the list");
}

void MainWindow::on_checkoutRefresh_clicked()
{
    ui->checkoutlistWidget->clear();
    HttpMessage<HttpRequest> msg4;
    msg4.type().command(HttpRequest::GET);
    msg4.action("GetRepoContent");
    HttpClient2 client;
    client.connect("localhost", 8080);

    HttpMessage<HttpReply> reply4 = client.postMessage(msg4);
    std::string r1 = reply4.body().toString();
    int i = 0;
    while (i < r1.size()) {
        size_t pos = r1.find_first_of('\n', i);
        QString q = QString::fromStdString(r1.substr(i, pos - i));
        ui->checkoutlistWidget->addItem(new QListWidgetItem(q, ui->checkoutlistWidget));
        i = pos + 1;
    }
}

void MainWindow::on_viewFileButton_clicked()
{
    if (ui->viewfilelistWidget->selectedItems().size() != 0) {

        QList<QListWidgetItem*> file = ui->viewfilelistWidget->selectedItems();
        QString f = file[0]->text();
        std::string fileSpec = f.toLocal8Bit().constData();

        HttpMessage<HttpRequest> msg5;
        msg5.type().command(HttpRequest::GET);
        msg5.action("View");
        msg5.type().fileSpec(fileSpec);
        msg5.attribute("version", "selected");
        HttpClient2 client;
        client.connect("localhost", 8080);

        HttpMessage<HttpReply> reply5 = client.postMessage(msg5);

        di = new Dialog(this);
        di->setWindowTitle("View File");
        QLabel *qLabel = new QLabel();
        qLabel->setText(QString::fromStdString(reply5.body().toString()));
        qLabel->setMinimumWidth(100);
        QWidget* centralWidget1 = new QWidget();
        QHBoxLayout * layout = new QHBoxLayout();
        layout->addWidget(qLabel);
        centralWidget1->setLayout(layout);
        di->setCentralWidget(centralWidget1);
        di->show();
    }
    else
        QMessageBox::critical(this, "Error", "Please select only or atleast 1 from the list");
}

void MainWindow::on_viefilerefresh_clicked()
{
    ui->viewfilelistWidget->clear();
    HttpMessage<HttpRequest> msg4;
    msg4.type().command(HttpRequest::GET);
    msg4.action("GetRepoContent");
    HttpClient2 client;
    client.connect("localhost", 8080);

    HttpMessage<HttpReply> reply4 = client.postMessage(msg4);
    std::string r1 = reply4.body().toString();
    int i = 0;
    while (i < r1.size()) {
        size_t pos = r1.find_first_of('\n', i);
        QString q = QString::fromStdString(r1.substr(i, pos - i));
        ui->viewfilelistWidget->addItem(new QListWidgetItem(q, ui->viewfilelistWidget));
        i = pos + 1;
    }
}

void MainWindow::on_repoContent_clicked()
{
    ui->listWidget->clear();
    HttpMessage<HttpRequest> msg4;
    msg4.type().command(HttpRequest::GET);
    msg4.action("GetRepoContent");
    HttpClient2 client;
    client.connect("localhost", 8080);

    HttpMessage<HttpReply> reply4 = client.postMessage(msg4);
    std::string r1 = reply4.body().toString();
    int i = 0;
    while (i < r1.size()) {
        size_t pos = r1.find_first_of('\n', i);
        QString q = QString::fromStdString(r1.substr(i, pos - i));
        ui->listWidget->addItem(new QListWidgetItem(q, ui->listWidget));
        i = pos + 1;
    }
}

void MainWindow::on_repoStorageClientStorage_clicked()
{
    ui->clientStorageRepoContent->clear();
    QDir dir("/home/nupur/Desktop/newCode_0504_3am_pst/ClientStorage");
    foreach(QFileInfo var, dir.entryInfoList()) {
        if (var.isFile())
            ui->clientStorageRepoContent->addItem(var.fileName());
    }
}

void MainWindow::on_deleteButton_clicked()
{
    if (ui->deleteListWidget->selectedItems().size() != 0) {

        QList<QListWidgetItem*> file = ui->deleteListWidget->selectedItems();
        QString f = file[0]->text();
        std::string fileSpec = f.toLocal8Bit().constData();

        HttpMessage<HttpRequest> msg5;
        msg5.type().command(HttpRequest::DELETE);
        msg5.action("Delete");
        msg5.type().fileSpec(fileSpec);
        msg5.attribute("version", "selected");
        HttpClient2 client;
        client.connect("localhost", 8080);

        HttpMessage<HttpReply> reply5 = client.postMessage(msg5);
        if (reply5.toString().find("200") != std::string::npos)
            ui->statusBar->showMessage("File deletion successful", 5000);
        ui->deleteListWidget->clear();
        std::string r1 = reply5.body().toString();
        int i = 0;
        while (i < r1.size()) {
            size_t pos = r1.find_first_of('\n', i);
            QString q = QString::fromStdString(r1.substr(i, pos - i));
            ui->deleteListWidget->addItem(new QListWidgetItem(q, ui->deleteListWidget));
            i = pos + 1;
        }

    }
    else
        QMessageBox::critical(this, "Error", "Please select only or atleast 1 from the list");
}

void MainWindow::on_deleteRefresh_clicked()
{
    ui->deleteListWidget->clear();
    HttpMessage<HttpRequest> msg4;
    msg4.type().command(HttpRequest::GET);
    msg4.action("GetRepoContent");
    HttpClient2 client;
    client.connect("localhost", 8080);

    HttpMessage<HttpReply> reply4 = client.postMessage(msg4);
    std::string r1 = reply4.body().toString();
    int i = 0;
    while (i < r1.size()) {
        size_t pos = r1.find_first_of('\n', i);
        QString q = QString::fromStdString(r1.substr(i, pos - i));
        ui->deleteListWidget->addItem(new QListWidgetItem(q, ui->deleteListWidget));
        i = pos + 1;
    }
}

HttpClient2::HttpClient2() : HttpCommCore(&socket) {}

HttpMessage<HttpReply> HttpClient2::postMessage(HttpMessage<HttpRequest> msg)
{
    HttpCommCore::postMessage<HttpRequest>(msg);
    HttpMessage<HttpReply> reply = HttpCommCore::getMessage<HttpReply>();
    return reply;
}

bool HttpClient2::connect(const std::string & address, size_t port)
{
    socket.shutDown();
    return socket.connect(address, port);
}
