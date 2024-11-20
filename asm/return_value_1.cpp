/*
c++，返回临时对象，栈帧怎样处理？

从程序输出结果可知，func_2()创建的临时对象（即便未返回）保留在调用者（test_1）的栈帧

关注test_1的汇编语句sub rsp, 48，这表明它给自己分配了48字节的栈帧空间，刚好足够存储6个long对象，
其中func_2()占用3个，long a = func_4()和long b = 1各占用1个，至于剩下的一个，实验证明是分配给了func_4()；
可见test_1为子函数创建的临时变量分配了存储空间，即便它们并没有返回。

address	value
rbp - 8	    12
rbp - 16	6
rbp - 24	4
rbp - 32	2
rbp - 40	1
rbp - 48	

编译器对func_3()提出了警告：address of local variable ‘a’ returned。其汇编语句显示，编译器使其直接返回了0作为惩罚。

而为了保护func_2()创建的临时对象不被后面的函数调用覆写，编译器以rbp-32作为调用func_2,func_3,func_4的栈帧基地址，func_2往上写，而func_3,func_4往下写。
*/


#include <iostream>
using namespace std;

class A {
public: 
    long x[3];
};

void func_1() {
    A a;
    a.x[0] = 1 * 1;
    a.x[1] = 2 * 1;
    a.x[2] = 3 * 1;
}

A func_2() {
    A a;
    a.x[0] = 1 * 2;
    a.x[1] = 2 * 2;
    a.x[2] = 3 * 2;
    return a;
}

A* func_3() {
    A a;
    a.x[0] = 1 * 3;
    a.x[1] = 2 * 3;
    a.x[2] = 3 * 3;
    return &a;
}

long func_4() {
    A a;
    a.x[0] = 1 * 4;
    a.x[1] = 2 * 4;
    a.x[2] = 3 * 4;
    return a.x[2];
}

void test_1() {
    func_1();
    func_2();
    func_3();
    func_4();
    long a = func_4();
    long b = 1;

    cout << b << endl;
    cout << *(&b + 1) << endl;
    cout << *(&b + 2) << endl;
    cout << *(&b + 3) << endl;
    cout << *(&b + 4) << endl;
}

int main() {
    test_1();

    return 0;
}
