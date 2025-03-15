#include <stdio.h>
#include <pthread.h>
#include <unistd.h>  // for sleep

void *func1(void*)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("func1 is running %d \n", i);
        sleep(1);
    }
    return NULL;
}

void *func2(void*)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("func2 is running %d \n", i);
        sleep(1);
    }
    return NULL;
}

void *func3(void*)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("func3 is running %d \n", i);
        sleep(1);
    }
    return NULL;
}

int main()
{
    int i = 0, ret = 0;
    pthread_t func1_id, func2_id, func3_id;

    ret = pthread_create(&func1_id, NULL, func1, NULL);
    if (ret)
    {
        printf("Cannot create func1./n");
        return 1;
    }
    ret = pthread_create(&func2_id, NULL, func2, NULL);
    if (ret)
    {
        printf("Cannot create func1./n");
        return 1;
    }

    ret = pthread_create(&func3_id, NULL, func3, NULL);
    if (ret)
    {
        printf("Cannot create func1./n");
        return 1;
    }

    // Wait for func3.
    pthread_join(func3_id, NULL);

    printf("Main thread exists.\n");

    return 0;
}