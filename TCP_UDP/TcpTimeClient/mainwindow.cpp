#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/make_shared.hpp>
#include "tcpclient.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString addressStr = ui->lineEdit_address->text();  // IP地址
    QString portStr = ui->lineEdit_port->text();        // IP端口

    // 解析IP地址
    boost::system::error_code ec;
    auto address = boost::asio::ip::address_v4::from_string(addressStr.toStdString());
    if (!ec)  // SUCCESS
    {
        int port = portStr.toInt();
        if (port >= 0 && port <= 65535)
        {
            boost::asio::ip::tcp::endpoint endpoint(address, port);
            TcpClient* client = new TcpClient(endpoint);

            // 在界面中显示连接结果
            connect(client, &TcpClient::connect_success, this, &MainWindow::OnConnectSuccess);
            connect(client, &TcpClient::connect_failed, this, &MainWindow::OnConnectFailed);

            // 开始连接
            client->Connect();
        }
        else
        {
            ui->textEdit->append("Parse Port Fail");
        }
    }
    else   // FAIL
    {
        ui->textEdit->append("Parse Address Fail");
    }
}

void MainWindow::OnConnectSuccess()
{
    ui->textEdit->append("Connect Success");
}

void MainWindow::OnConnectFailed()
{
    ui->textEdit->append("Connect Failed");
}


