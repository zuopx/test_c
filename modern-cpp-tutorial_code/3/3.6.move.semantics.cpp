//
// 3.5.move.semantics.cpp
// modern c++ tutorial
//
// created by changkun at changkun.de
// https://github.com/changkun/modern-cpp-tutorial
//

#include <iostream> // std::cout
#include <string>   // std::string
#include <utility>  // std::move
#include <vector>   // std::vector

int main() {

    std::string str = "Hello world.";
    std::vector<std::string> v;

    // use push_back(const T&), copy
    v.push_back(str);
    // "str: Hello world."
    std::cout << "str: " << str << std::endl;

    // use push_back(const T&&), no copy
    // the string will be moved to vector, and therefore std::move can reduce
    // copy cost
    v.push_back(std::move(str));
    // str is empty now
    std::cout << "str: " << str << std::endl;

    return 0;
}


/*
g++ -o 3.6.move.semantics.out 3.6.move.semantics.cpp

push_back根据参数类型，触发深拷贝或浅拷贝；
深拷贝另辟内存，不影响实参
浅拷贝和实参共用内存，但为了安全和自洽，就把实参改变了，从而独占了内存
*/
