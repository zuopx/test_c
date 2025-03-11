/*异步模式之一：回调

g++ -g -o test_callback.out test_callback.cpp
*/
#include <boost/asio.hpp>
#include <iostream>
#include <memory>

using boost::asio::ip::tcp;

class AsyncServer
{
public:
    AsyncServer(boost::asio::io_context &io)
        : acceptor_(io, tcp::endpoint(tcp::v4(), 12345))
    {
        start_accept();
    }

private:
    void start_accept()
    {
        auto socket = std::make_shared<tcp::socket>(acceptor_.get_executor());
        acceptor_.async_accept(*socket,
                               [this, socket](boost::system::error_code ec)
                               {
                                   if (!ec)
                                   {
                                       std::cout << "Client connected.\n";
                                       read_from_socket(socket);
                                   }
                                   start_accept();
                               });
    }

    void read_from_socket(std::shared_ptr<tcp::socket> socket)
    {
        auto buffer = std::make_shared<std::array<char, 1024>>();
        socket->async_read_some(boost::asio::buffer(*buffer),
                                [this, socket, buffer](boost::system::error_code ec, size_t len)
                                {
                                    if (!ec)
                                    {
                                        std::cout << "Received: "
                                                  << std::string(buffer->data(), len) << "\n";
                                        read_from_socket(socket);  // 在调用处理程序前，async_read已释放内部资源（如临时缓冲区），处理程序中的async_read可立即重用socket。
                                    }
                                    else
                                    {
                                        std::cerr << "Error: " << ec.message() << "\n";
                                    }
                                });
    }

    tcp::acceptor acceptor_;
};

int main()
{
    boost::asio::io_context io;
    AsyncServer server(io);
    io.run();
}

/*
调用栈：可见和python3的asyncio有雷同之处，其中出现频率最高的词汇是scheduler和handler
    AsyncServer::read_from_socket(AsyncServer * const this, std::shared_ptr<boost::asio::basic_stream_socket<boost::asio::ip::tcp, boost::asio::any_io_executor> > socket) (\home\percy\project\c\test_c\boost\asio\test_callback.cpp:38)
    AsyncServer::start_accept()::{lambda(boost::system::error_code)#1}::operator()(boost::system::error_code) const(const struct {...} * const __closure, boost::system::error_code ec) (\home\percy\project\c\test_c\boost\asio\test_callback.cpp:30)
    boost::asio::detail::binder1<AsyncServer::start_accept()::{lambda(boost::system::error_code)#1}, boost::system::error_code>::operator()()(boost::asio::detail::binder1<AsyncServer::start_accept()::<lambda(boost::system::error_code)>, boost::system::error_code> * const this) (\usr\include\boost\asio\detail\bind_handler.hpp:171)
    boost::asio::asio_handler_invoke<boost::asio::detail::binder1<AsyncServer::start_accept()::{lambda(boost::system::error_code)#1}, boost::system::error_code> >(boost::asio::detail::binder1<AsyncServer::start_accept()::{lambda(boost::system::error_code)#1}, boost::system::error_code>&, ...)(boost::asio::detail::binder1<AsyncServer::start_accept()::<lambda(boost::system::error_code)>, boost::system::error_code> & function) (\usr\include\boost\asio\handler_invoke_hook.hpp:88)
    boost_asio_handler_invoke_helpers::invoke<boost::asio::detail::binder1<AsyncServer::start_accept()::{lambda(boost::system::error_code)#1}, boost::system::error_code>, AsyncServer::start_accept()::{lambda(boost::system::error_code)#1}>(boost::asio::detail::binder1<AsyncServer::start_accept()::{lambda(boost::system::error_code)#1}, boost::system::error_code>&, AsyncServer::start_accept()::{lambda(boost::system::error_code)#1}&)(boost::asio::detail::binder1<AsyncServer::start_accept()::<lambda(boost::system::error_code)>, boost::system::error_code> & function, struct {...} & context) (\usr\include\boost\asio\detail\handler_invoke_helpers.hpp:54)
    boost::asio::detail::handler_work<AsyncServer::start_accept()::{lambda(boost::system::error_code)#1}, boost::asio::any_io_executor, void>::complete<boost::asio::detail::binder1<AsyncServer::start_accept()::{lambda(boost::system::error_code)#1}, boost::system::error_code> >(boost::asio::detail::binder1<AsyncServer::start_accept()::{lambda(boost::system::error_code)#1}, boost::system::error_code>&, AsyncServer::start_accept()::{lambda(boost::system::error_code)#1}&)(boost::asio::detail::handler_work<AsyncServer::start_accept()::<lambda(boost::system::error_code)>, boost::asio::any_io_executor, void> * const this, boost::asio::detail::binder1<AsyncServer::start_accept()::<lambda(boost::system::error_code)>, boost::system::error_code> & function, struct {...} & handler) (\usr\include\boost\asio\detail\handler_work.hpp:520)
    boost::asio::detail::reactive_socket_accept_op<boost::asio::basic_socket<boost::asio::ip::tcp, boost::asio::any_io_executor>, boost::asio::ip::tcp, AsyncServer::start_accept()::{lambda(boost::system::error_code)#1}, boost::asio::any_io_executor>::do_complete(void*, boost::asio::detail::scheduler_operation*, boost::system::error_code const&, unsigned long)(void * owner, boost::asio::detail::operation * base) (\usr\include\boost\asio\detail\reactive_socket_accept_op.hpp:150)
    boost::asio::detail::scheduler_operation::complete(boost::asio::detail::scheduler_operation * const this, void * owner, const boost::system::error_code & ec, std::size_t bytes_transferred) (\usr\include\boost\asio\detail\scheduler_operation.hpp:40)
    boost::asio::detail::epoll_reactor::descriptor_state::do_complete(void * owner, boost::asio::detail::operation * base, const boost::system::error_code & ec, std::size_t bytes_transferred) (\usr\include\boost\asio\detail\impl\epoll_reactor.ipp:806)
    boost::asio::detail::scheduler_operation::complete(boost::asio::detail::scheduler_operation * const this, void * owner, const boost::system::error_code & ec, std::size_t bytes_transferred) (\usr\include\boost\asio\detail\scheduler_operation.hpp:40)
    boost::asio::detail::scheduler::do_run_one(boost::asio::detail::scheduler * const this, boost::asio::detail::conditionally_enabled_mutex::scoped_lock & lock, boost::asio::detail::scheduler::thread_info & this_thread, const boost::system::error_code & ec) (\usr\include\boost\asio\detail\impl\scheduler.ipp:492)
    boost::asio::detail::scheduler::run(boost::asio::detail::scheduler * const this, boost::system::error_code & ec) (\usr\include\boost\asio\detail\impl\scheduler.ipp:210)
    boost::asio::io_context::run(boost::asio::io_context * const this) (\usr\include\boost\asio\impl\io_context.ipp:63)
    main() (\home\percy\project\c\test_c\boost\asio\test_callback.cpp:62)
*/
