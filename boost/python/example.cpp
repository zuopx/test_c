/*
Boost.Python 通过自动化的引用计数管理简化了 C++ 和 Python 之间的对象生命周期管理。
Boost.Python is a separately-compiled (as opposed to header-only) library

进入boost目录，生成b2和project-config.jam：
    ./bootstrap.sh --help
    ./bootstrap.sh --with-python=/root/miniconda3/envs/py3/bin/python --with-libraries=python

生成头文件和链接库：
    ./b2 --help
    ./b2 stage: 在./stage目录下生成链接库
    ./b2 install: 在usr/local目录头文件和链接库

编译和链接：
    g++ -shared -fPIC -o example.so example.cpp -lboost_python312 -I/root/miniconda3/envs/py3/include/python3.12

运行：
    export LD_LIBRARY_PATH=/usr/local/lib
    python test_example.py
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
