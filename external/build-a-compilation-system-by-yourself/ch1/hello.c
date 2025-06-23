#include <stdio.h>
int main()
{
    printf("Hello World!\n");
    return 0;
}

/*
gcc -o hello hello.c -static -v
    cc1 -quiet -v hello.c -o /tmp/ccySnjMn.s  // 预处理和汇编
    as -v --64 -o /tmp/cc6hQwef.o /tmp/ccySnjMn.s  // 编译
    collect2 -static -o hello \  //静态 链接
        /usr/lib/gcc/.../crt1.o \
        /usr/lib/gcc/.../crti.o \
        /usr/lib/gcc/.../crtbeginT.o \
        /tmp/cc6hQwef.o \
        -lgcc -lgcc_eh -lc \  # 静态链接 GCC 运行时和 C 标准库
        /usr/lib/gcc/.../crtend.o \
        /usr/lib/gcc/.../crtn.o

        gcc -o hello hello.c -v
    cc1 -quiet -v hello.c -o /tmp/ccySnjMn.s  // 预处理和汇编
    as -v --64 -o /tmp/cc6hQwef.o /tmp/ccySnjMn.s  // 编译
    collect2 -o hello_dynamic \  // 动态链接
        -dynamic-linker /lib64/ld-linux-x86-64.so.2  # 动态链接器
        -pie                                          # 生成位置无关可执行文件
        /usr/lib/.../Scrt1.o                          # 动态版启动文件
        /usr/lib/.../crtbeginS.o                      # 动态版初始化代码
        /tmp/ccLsbdyL.o
        -lgcc_s -lc -lgcc_s                           # 链接动态库
        /usr/lib/.../crtendS.o                        # 动态版终止代码


gcc -o hello.i -E hello.c
gcc -o hello.s -S hello.i
gcc -o hello.o -c hello.s
gcc -o hello hello.o -static
*/
