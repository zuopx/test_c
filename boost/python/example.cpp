/*
Boost.Python 通过自动化的引用计数管理简化了 C++ 和 Python 之间的对象生命周期管理。
Boost.Python is a separately-compiled (as opposed to header-only) library

进入boost目录，生成b2和project-config.jam：
    ./bootstrap.sh --help
    ./bootstrap.sh --with-python=/root/miniconda3/envs/py3/bin/python --with-libraries=python

生成头文件和链接库：
    ./b2 --help
    ./b2 stage --help
    ./b2 stage: 在./stage目录下生成链接库
    ./b2 install: 在usr/local目录下生成头文件和链接库
    ./b2 install link=static variant=debug: 生成静态链接库
    ./b2 install cxxflags=-fPIC link=static variant=debug: 生成静态链接库，用于动态链接


编译和链接：
    g++ -shared -fPIC -o example.so example.cpp -lboost_python312 -I/root/miniconda3/envs/py3/include/python3.12
    g++ -shared -fPIC -o example.so example.cpp /usr/local/lib/libboost_python312.a -I/root/miniconda3/envs/py3/include/python3.12

运行：
    export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
    echo $LD_LIBRARY_PATH
    python test_example.py

-fPIC:
    -fPIC是GCC编译器的一个编译选项，用于指示编译器生成位置无关代码（Position Independent Code）。
    这种代码可以加载到进程的任意位置，而不会因为加载位置的不同导致地址问题。
    这在创建动态链接库（如Linux下的.so文件）时是必须的，因为动态库的加载位置在运行时才确定。
    对于静态库来说，通常情况下，-fPIC选项并不是必须的，因为静态库是直接链接到最终的可执行文件中。
    然而，如果静态库最终用于创建动态库，或者静态库中包含了内联汇编代码等可能需要在运行时被重定位的代码，则必须在构建静态库时添加-fPIC选项。
*/

#include <boost/python.hpp>
#include <iostream>
#include <string>

class Greeter {
public:
    Greeter() {}
    
    void greet(const std::string &name) {
        std::cout << "Hello, " << name << "!" << std::endl;
    }

    int add(int a, int b) {
        return a + b;
    }
};

BOOST_PYTHON_MODULE(example) {
    using namespace boost::python;
    class_<Greeter>("Greeter")
        .def("greet", &Greeter::greet)
        .def("add", &Greeter::add);
}
