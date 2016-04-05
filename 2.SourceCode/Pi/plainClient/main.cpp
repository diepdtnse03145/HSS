#include <iostream>
#include <boost/asio.hpp>

boost::asio::io_service _io;
boost::asio::ip::tcp::socket _sock{_io};
boost::asio::ip::tcp::endpoint _ser{
    boost::asio::ip::address::from_string("127.0.0.1"),
            1337
};

void handleWrite(const boost::system::error_code& ec, std::size_t len)
{
    std::cout<<len<<std::endl;
}

void handleConnect(const boost::system::error_code& ec)
{
    boost::asio::async_write(_sock, boost::asio::buffer(std::string{"Moe Moe\n"}), &handleWrite);
}

int main(int argc, char *argv[])
{
    _sock.async_connect(_ser, &handleConnect);

    return _io.run();
}
