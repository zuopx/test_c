//
// timer.cpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2024 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <boost/asio.hpp>

void print(const boost::system::error_code& /*e*/)
{
    std::cout << "World" << std::endl;
}

int main()
{
    boost::asio::io_context io;

    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(15));

    t.async_wait(&print);

    std::cout << "Hello" << std::endl;

    io.run();

    return 0;
}
