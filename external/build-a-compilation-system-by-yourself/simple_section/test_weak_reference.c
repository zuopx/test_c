#include <stdio.h>
#include <pthread.h>

 __attribute__((weak)) int pthread_create(pthread_t *, const pthread_attr_t *, void *(*)(void *), void *);

 int main()
{
    if (pthread_create)
    {
        printf("This is multi-thread version!\n");
    }
    else
    {
        printf("This is single-thread version!\n");
    }

    return 0;
}

/*
    __attribute__((weak)) void foo();
    int main()
    {
        if (foo)
            foo();
        return 0;
    }

*/
