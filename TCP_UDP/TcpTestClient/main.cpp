#include <QCoreApplication>
#include <string>
#include <boost/asio.hpp>
#include "tcpclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (argc == 3)
    {
        std::string ip_address = argv[1];
        int port = QString(argv[2]).toInt();
        boost::asio::ip::tcp::endpoint endpoint(
                    boost::asio::ip::address::from_string(ip_address), port);

        TcpClient* client = new TcpClient(endpoint);
        client->Connect();
    }

    return a.exec();
}
