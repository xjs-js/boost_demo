#include "tcpclient.h"
#include <boost/make_shared.hpp>
#include <boost/thread.hpp>
#include <iostream>

TcpClient::TcpClient(boost::asio::ip::tcp::endpoint endpoint)
    : m_endpoint(endpoint)
{
    m_work = boost::make_shared<boost::asio::io_service::work>(m_ios);
    m_socket = boost::make_shared<boost::asio::ip::tcp::socket>(m_ios);
    boost::shared_ptr<boost::thread> trd = boost::make_shared<boost::thread>(boost::bind(
                                                                                 &boost::asio::io_service::run, &m_ios));
    trd->detach();
}

TcpClient::~TcpClient()
{

}

void TcpClient::Connect()
{
    std::cout << "Start Connect..." << m_endpoint.address().to_string() << ": " << m_endpoint.port() << std::endl;

    m_socket->async_connect(m_endpoint
                          , boost::bind(
                                        &TcpClient::handle_connect
                                        , this
                              , boost::asio::placeholders::error));
}

void TcpClient::handle_connect(const boost::system::error_code &ec)
{
    std::cout << "handle_connect..." << std::endl;
    if (!ec) // Success
    {
        std::cout << "connect success" << std::endl;
    }
    else // Fail
    {
        std::cout << "connect fail" << std::endl;
        std::cout << ec.message() << std::endl;
    }
}



