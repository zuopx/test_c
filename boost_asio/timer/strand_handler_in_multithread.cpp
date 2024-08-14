// Timer.5 - Synchronising completion handlers in multithreaded programs
// https://www.boost.org/doc/libs/1_85_0/doc/html/boost_asio/tutorial/tuttimer5.html
// 先分配一个全局io_service，然后开启多个线程，每个线程都调用这个io_service的run()方法。
// 当某个异步事件完成时，io_service就会将相应的 event handler 交给任意一个线程去执行。

#include <functional>
#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include <ctime>


class printer
{
public:
    printer(boost::asio::io_context& io): 
    strand_(boost::asio::make_strand(io)), 
    timer1_(io, boost::asio::chrono::seconds(1)), timer2_(io, boost::asio::chrono::seconds(1)), count_(0)
    {   
        time_t now = time(0);
        std::cout << "Start count is " << count_ << " " << std::this_thread::get_id() << " " << ctime(&now) << std::endl;

        timer1_.async_wait(boost::asio::bind_executor(strand_, std::bind(&printer::print1, this)));
        timer2_.async_wait(boost::asio::bind_executor(strand_, std::bind(&printer::print2, this)));
    }

    ~printer()
    {
        time_t now = time(0);
        std::cout << "Final count is " << count_ << " " << std::this_thread::get_id() << " " << ctime(&now) << std::endl;
    }

    void print1()
    {
        if (count_ < 10)
        {
            std::cout << "Timer 1: " << count_ << " " << std::this_thread::get_id() << std::endl;
            ++count_;

            timer1_.expires_at(timer1_.expiry() + boost::asio::chrono::seconds(1));
            timer1_.async_wait(boost::asio::bind_executor(strand_, std::bind(&printer::print1, this)));
        }
    }

    void print2()
    {
        if (count_ < 10)
        {
            std::cout << "Timer 2: " << count_ << " " << std::this_thread::get_id() << std::endl;
            ++count_;

            timer2_.expires_at(timer2_.expiry() + boost::asio::chrono::seconds(1));
            timer2_.async_wait(boost::asio::bind_executor(strand_, std::bind(&printer::print2, this)));
        }
    }

private:
    boost::asio::strand<boost::asio::io_context::executor_type> strand_;
    boost::asio::steady_timer timer1_;
    boost::asio::steady_timer timer2_;
    int count_;
};


int main()
{
    boost::asio::io_context io;

    printer p(io);

    std::thread t([&] {io.run();});
    io.run();

    t.join();

    return 0;
}
