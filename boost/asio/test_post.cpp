#include <boost/asio.hpp>
#include <iostream>
namespace asio = boost::asio;

void basic_use()
{
    asio::io_context io;

    // 投递任务到 io_context
    asio::post(io, [] { std::cout << "任务1: 在 io_context 线程中执行\n"; });

    // 另一种等效写法
    asio::post(io, [] { std::cout << "任务2: 等效的 post 调用\n"; });

    // 运行 io_context
    io.run();
}

void use_with_strand()
{
    asio::io_context io;
    asio::strand<asio::io_context::executor_type> strand(io.get_executor());

    // 通过 strand 投递任务（保证顺序执行）
    asio::post(strand, [] { std::cout << "任务A\n"; });
    asio::post(strand, [] { std::cout << "任务B\n"; });

    // 混合普通 post 和 strand.post
    asio::post(io, [] { std::cout << "任务C\n"; });
    asio::post(strand, [] { std::cout << "任务D\n"; });

    io.run();
}

void task_with_args(int id, const std::string &msg)
{
    std::cout << "任务" << id << ": " << msg << "\n";
}

void handle_error(const std::error_code &ec)
{
    std::cerr << "错误发生: " << ec.message() << "\n";
}

void use_with_bind()
{
    asio::io_context io;

    // 绑定参数
    asio::post(io, std::bind(task_with_args, 1, "参数绑定示例"));

    // 捕获异常
    asio::post(io, [] {
        try
        {
            throw std::runtime_error("测试异常");
        }
        catch (const std::exception &e)
        {
            std::cerr << "捕获异常: " << e.what() << "\n";
        }
    });

    // 错误码传递
    std::error_code ec = make_error_code(std::errc::timed_out);
    asio::post(io, std::bind(handle_error, ec));

    io.run();
}

int main()
{
    basic_use();

    use_with_strand();

    use_with_bind();

    return 0;
}

/*
boost::asio::post函数用于将任务（函数或可调用对象）投递到指定的执行上下文（如io_context或strand）中执行。
*/