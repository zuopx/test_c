#include <iostream>

int main()
{
    int a = 1;
    int b = 2;

    int& r = a;
    r = b;  // 这并不会使 ref 指向 b，只是将 b 的值赋给 a
    // r = &b;  // invalid conversion from ‘int*’ to ‘int’

    int* p = &a;
    p = &b;

    int* const cp = &a;  // 指针常量 const pointer
    *cp = b;
    // cp = &b;  // error: assignment of read-only variable ‘cp’

    const int* pc = &a;  // 常量指针 pointer to const
    pc = &b;
    // *pc = b;  // error: assignment of read-only location ‘* pc’

    std::cout << "r: " << r << std::endl;
    std::cout << "p: " << *p << std::endl;
    std::cout << "const p: " << *cp << std::endl;
    std::cout << "p const: " << *pc << std::endl;

    return 0;
}

/*
引用：必须在声明时初始化，且一旦绑定到某个对象，就不能改变。
常量指针：你可以改变这个指针的指向，但不能通过它修改所指向的值。
指针常量：你太不可以改变这个指针的指向，但能通过它修改所指向的值。
*/
