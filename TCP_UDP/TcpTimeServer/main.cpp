#include <QCoreApplication>
#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

// 返回当前的时间
std::string make_daytime_string()
{
  using namespace std; // For time_t, time and ctime;
  time_t now = time(0);
  return ctime(&now);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int port = 8899; // default port;

    if (argc == 2)
    {
        //  用命令行指定Serve的端口
        port = QString(argv[1]).toInt();
    }

    // io_service
    boost::asio::io_service io_service;

    // acceptor
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), port));
    std::cout << "listen on port: " << port << std::endl;
    for (;;)
    {
      // socket
      tcp::socket socket(io_service);

      // 首先会阻塞在这里
      acceptor.accept(socket);
      std::cout << "Remote EndPont Access: "
                << socket.remote_endpoint().address().to_string()
                << ":"
                << socket.remote_endpoint().port()
                << std::endl;

      // 当前时间
      std::string message = make_daytime_string();

      std::cout << "Write Message: " << message << std::endl;
      boost::system::error_code ignored_error;
      socket.write_some(boost::asio::buffer(message));
    }

    return a.exec();
}
