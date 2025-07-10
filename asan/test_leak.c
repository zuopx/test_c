/*
内存泄漏

gcc -o test_leak.out test_leak.c
gcc -o test_leak.out test_leak.c -fsanitize=address -fno-omit-frame-pointer -g -O1

ASAN_OPTIONS=halt_on_error=0 ./test_overflow.out
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fun1(char *str)
{
    static char *p;
    p = malloc(64);
    strcpy(p, str);
    return p;
}

int main()
{
    char *str = fun1("abcd");
    printf("str=%s\n", str);
    return 0;
}