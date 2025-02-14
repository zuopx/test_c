/*fort + wait

由父进程处理子进程的结束
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    pid_t pid = fork();
    if (pid < 0) //无法创建子进程
    {
        printf("出错啦！");
    }
    else if (pid == 0) //子进程
    {
        //做一些很漫长的运算
        int sum = 0;
        for (int i = 0; i < 10000000; i++)
        {
            for (int j = 0; j < 100; j++)
            {
            sum += i;
            }
        }
        exit(0);
    }
    else //父进程
    {
        int status;
        printf("子进程PID %d...\n", pid);
        //等待子进程结束
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (! WIFEXITED(status) && ! WIFSIGNALED(status));
        //status是子进程返回值
        printf("子进程返回值 %d\n", status);
    }
}