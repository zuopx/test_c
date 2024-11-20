/*
| rsp  | stack pointer register | 指向栈顶，管理栈的增长和缩减                               |
| rbp  | base pointer register  | 保存函数的栈帧基地址，再加上偏移去访问函数的局部变量和参数 |
main函数中的局部变量的地址都小于rbp
*/
#include <iostream>
#include <iomanip>

int main()
{
    int i = 1;

    unsigned long long rsp, rbp;

    asm volatile (
        "mov %%rsp, %0\n\t"
        "mov %%rbp, %1\n\t"
        : "=r"(rsp), "=r"(rbp)
    );

    std::cout << std::hex << std::setfill('0');
    std::cout << "rsp: 0x" << std::setw(16) << rsp << std::endl;   
    std::cout << "rbp: 0x" << std::setw(16) << rbp << std::endl;   

    std::cout << "&int: " << &i << std::endl;
    std::cout << "&rsp: " << &rsp << std::endl;
    std::cout << "&rbp: " << &rbp << std::endl;

    return 0;
}
