#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <QObject>

class TcpClient
{
public:
    TcpClient(boost::asio::ip::tcp::endpoint endpoint);
    ~TcpClient();

    void Connect();

private:
    void handle_connect(const boost::system::error_code& ec);

private:
    boost::asio::ip::tcp::endpoint m_endpoint;
    boost::asio::io_service m_ios;
    boost::shared_ptr<boost::asio::io_service::work> m_work;
    boost::shared_ptr<boost::asio::ip::tcp::socket> m_socket;
};

#endif // TCPCLIENT_H
