/*
内存越界

gcc -o test_overflow.out test_overflow.c
gcc -o test_overflow.out test_overflow.c -fsanitize=address -fno-omit-frame-pointer -g -O1
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    // printf("pid: %d\n", getpid());

    char str[4] = {0};
    strcpy(str, "hello");

    // printf("%s\n", str);

    return 0;
}