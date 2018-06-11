#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Message/Message.h"
#include "../HttpCommCore/HttpCommCore.h"
#include "../Sockets/Sockets.h"
#include <string>
#include "dialog.h"

using namespace HttpCommunication;
using namespace Sockets;

namespace Ui {
class MainWindow;
class HttpClient2;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Connect_clicked();

    void on_checkinButton_clicked();

    void on_checkinRefresh_clicked();

    void on_checkoutpushButton_clicked();

    void on_checkoutRefresh_clicked();

    void on_viewFileButton_clicked();

    void on_viefilerefresh_clicked();

    void on_repoContent_clicked();

    void on_repoStorageClientStorage_clicked();

    void on_deleteButton_clicked();

    void on_deleteRefresh_clicked();

private:
    Ui::MainWindow *ui;
	Dialog1 *di;
};

class HttpClient2 : HttpCommCore
{
public:
	HttpClient2();
	HttpMessage<HttpReply> postMessage(HttpMessage<HttpRequest> msg);
	bool connect(const std::string& address, size_t port);
	std::string clientPath = "../ClientStorage/";
private:
	Sockets::SocketConnecter socket;
	Sockets::SocketSystem ss;
};

#endif // MAINWINDOW_H
