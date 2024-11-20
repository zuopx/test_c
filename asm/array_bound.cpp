/*
数组越界

gcc -o array_bound.out array_bound.cpp
*/

#include <stdio.h>
#include <stdlib.h>

void malfunc()
{
    printf("$$$$\n");
    exit(4);
}

void func1()
{
    long a[2];
    a[3] = (long)malfunc;  // 往上写，把调用者改为malfunc了
    a[1] = 1;
    a[0] = 2;
    a[-1] = 3;  // 往下写，向空闲区乱写
    a[-2] = 4;
}

int main()
{
    func1();
    printf("done\n");
}
