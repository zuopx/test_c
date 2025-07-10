/*
内存非法访问

gcc -o test_illegal.out test_illegal.c
gcc -o test_illegal.out test_illegal.c -fsanitize=address -fno-omit-frame-pointer -g -O1
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char *p = NULL;
    strcpy(p, "a"); // 这里会发生非法内存访问
    return 0;
}