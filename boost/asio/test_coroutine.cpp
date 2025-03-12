#include <boost/asio.hpp>
#include <boost/asio/awaitable.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/use_awaitable.hpp>
#include <iostream>

namespace asio = boost::asio;
using asio::awaitable;
using asio::co_spawn;
using asio::detached;
using asio::use_awaitable;
using asio::ip::tcp;

class AsyncServer
{
  public:
    AsyncServer(asio::io_context &io) : acceptor_(io, tcp::endpoint(tcp::v4(), 12345))
    {
        // 启动协程接受连接
        co_spawn(io, accept_loop(), detached);
    }

  private:
    // 协程：持续接受连接的循环
    awaitable<void> accept_loop()
    {
        for (;;)
        {
            try // 统一 try/catch 块处理异常
            {
                // 协程式异步接受
                tcp::socket socket = co_await acceptor_.async_accept(use_awaitable);

                // 为每个连接启动独立协程，detached 表示不跟踪协程状态
                co_spawn(acceptor_.get_executor(), handle_client(std::move(socket)), detached);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Accept error: " << e.what() << "\n";
            }
        }
    }

    // 协程：处理客户端会话
    awaitable<void> handle_client(tcp::socket socket)
    {
        try
        {
            std::array<char, 1024> buffer; // 在协程挂起时自动保存
            for (;;)
            {
                // 协程式异步读取
                size_t len = co_await socket.async_read_some(asio::buffer(buffer), use_awaitable);

                std::cout << "Received: " << std::string(buffer.data(), len) << "\n";
            }
        }
        catch (const std::exception &e)
        {
            if (socket.is_open())
            {
                std::cerr << "Client error: " << e.what() << "\n";
            }
        }
    }

    tcp::acceptor acceptor_;
};

int main()
{
    asio::io_context io;
    AsyncServer server(io);

    io.run();
}
