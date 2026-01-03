/*lambda表达式背后是一个匿名类，下面将使用一个lambda表达式，并创建一个与之等价的类，两者的汇编代码基本一致。

g++ -o 3.1.1.lambda.basic.out 3.1.1.lambda.basic.cpp
*/
#include <iostream>
using namespace std;

// 创建一个
class lambda2
{
public:
    // 构造函数，捕获变量作为参数传入
    lambda2(int argc, char **argv) : m_argc(argc), m_argv(argv) {}

    // 重载函数调用运算符，实现与lambda表达式相同的功能
    auto operator()(int x)
    {
        cout << "Arguments: " << m_argc << " " << m_argv[0] << " " << x << endl;
    }

private:
    // 捕获的变量作为成员变量
    int m_argc;
    char **m_argv;
};

int main(int argc, char *argv[])
{
    // 使用lambda表达式
    auto lambda1 = [argc, argv](auto x)
    {
        cout << "Arguments: " << argc << " " << argv[0] << " " << x << endl;
        return 0;
    };
    lambda1(42);

    // 使用等价的类
    lambda2{argc, argv}(43);

    return 0;
}