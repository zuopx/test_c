/*同步方式下boost_asio依然非常可取

跨平台封装：统一Windows IOCP/Linux epoll/BSD kqueue等底层I/O模型
对象化接口：通过tcp::acceptor和tcp::socket对象封装原生socket描述符
生命周期管理：自动处理socket创建/关闭等资源操作

进程的状态：就绪、阻塞、执行；由操作系统调度。

g++ -g -o test_sync.out test_sync.cpp
*/

#include <boost/asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;

class SyncServer
{
public:
    SyncServer(boost::asio::io_context &io_context)
        : acceptor_(io_context, tcp::endpoint(tcp::v4(), 12345))
    {
        start_accept();
    }

private:
    void start_accept()
    {
        // 创建一个新的 socket
        tcp::socket socket(acceptor_.get_executor()); // 使用 io_context 创建 socket
        acceptor_.accept(socket);                               // 阻塞直到有客户端连接

        std::cout << "Client connected." << std::endl;
        read_from_socket(std::move(socket));
    }

    void read_from_socket(tcp::socket socket)
    {
        while (true)
        {
            boost::system::error_code ec;
            std::size_t length = socket.read_some(boost::asio::buffer(data_), ec); // 阻塞读取数据（操作系统调度该进程进入阻塞态）

            if (ec)
            {
                std::cerr << "Error on receive: " << ec.message() << std::endl;
                break; // 发生错误，退出循环
            }

            // 处理读取到的数据
            std::cout << "Received: " << std::string(data_.data(), length) << std::endl;
        }

        std::cout << "Client disconnected." << std::endl;

        // start_accept();
    }

    tcp::acceptor acceptor_;
    std::array<char, 1024> data_;
};

int main()
{
    boost::asio::io_context io_context;

    SyncServer server(io_context);

    // io_context.run();
    return 0;
}