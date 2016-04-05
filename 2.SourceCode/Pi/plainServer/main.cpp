#include <iostream>
#include <boost/asio.hpp>

void handleAccept(const boost::system::error_code& ec);
void handleRead(const boost::system::error_code& ec, std::size_t len);

boost::asio::io_service _io;
boost::asio::ip::tcp::acceptor _tcp_sv{_io, boost::asio::ip::tcp::endpoint{
        boost::asio::ip::tcp::v4(),
                1337}
                                      };
boost::asio::ip::tcp::socket _sock{_io};
boost::asio::ip::tcp::socket _acpsock{_io};

boost::asio::ip::tcp::endpoint _end;
boost::asio::streambuf _buf;

void handleAccept(const boost::system::error_code& ec)
{
    _sock.close();
    _sock = std::move(_acpsock);
    boost::asio::async_read_until(_sock, _buf, "\n", &handleRead);
    _tcp_sv.async_accept(_acpsock, _end, &handleAccept);
}

void handleRead(const boost::system::error_code& ec, std::size_t len)
{
    switch(ec.value()) {
    case boost::asio::error::operation_aborted:
    case boost::system::errc::no_such_file_or_directory:
        break;
    case boost::system::errc::success:
    {
        auto bufs = _buf.data();
        std::string line(
                    boost::asio::buffers_begin(bufs),
                    boost::asio::buffers_begin(bufs) + len
                    );
        _buf.consume(len);
        std::cout<<__FUNCTION__<<": "<<line<<std::endl;
    }
    default:
        boost::asio::async_read_until(_sock, _buf, "\n", &handleRead);
        break;
    }
}

int main(int argc, char *argv[])
{
    std::cout << "Hello World!" << std::endl;

    _tcp_sv.async_accept(_acpsock, _end, &handleAccept);

    _io.run();
    return 0;
}
