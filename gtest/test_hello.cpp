/*
获取gtest，并查看头文件和静态库目录
    ~/project/c/test_c# apt install libgtest-dev
    ~/project/c/test_c# dpkg -L libgtest-dev
    /usr/include/gtest/gtest-assertion-result.h
    /usr/include/gtest/gtest-death-test.h
    /usr/include/gtest/gtest-matchers.h
    /usr/include/gtest/gtest-message.h
    /usr/include/gtest/gtest-param-test.h
    /usr/include/gtest/gtest-printers.h
    /usr/include/gtest/gtest-spi.h
    /usr/include/gtest/gtest-test-part.h
    /usr/include/gtest/gtest-typed-test.h
    /usr/include/gtest/gtest.h
    /usr/include/gtest/gtest_pred_impl.h
    /usr/include/gtest/gtest_prod.h
    ...
    /usr/lib/x86_64-linux-gnu
    /usr/lib/x86_64-linux-gnu/libgtest.a
    /usr/lib/x86_64-linux-gnu/libgtest_main.a

编译并链接(gcc version 12.2.0 (Debian 12.2.0-14))
    g++ -o test_hello.out test_hello.cpp -L/usr/lib/x86_64-linux-gnu -lgtest -lgtest_main

运行
    ~/project/c/test_c#./test_hello.out
    Running main() from ./googletest/src/gtest_main.cc
    [==========] Running 1 test from 1 test suite.
    [----------] Global test environment set-up.
    [----------] 1 test from HelloTest
    [ RUN      ] HelloTest.BasicAssertions
    [       OK ] HelloTest.BasicAssertions (0 ms)
    [----------] 1 test from HelloTest (0 ms total)

    [----------] Global test environment tear-down
    [==========] 1 test from 1 test suite ran. (0 ms total)
    [  PASSED  ] 1 test.
*/
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}
