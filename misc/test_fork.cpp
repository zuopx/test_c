/*fork

fork后，父子进程两者的进程空间完全相同，所以代码将执行两次
    在父进程，返回子进程的pid
    在子进程，返回pid为0
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid;

    int var = 1024;

    pid = fork();

    if (pid < 0) {
        printf("fork error");
        exit(1);
    } else if (pid == 0) {
        /* 子进程 */
        printf("child: %d\n", var);
    } else {
        /* 父进程 */
        sleep(1);
        printf("parent: %d\n", var);
    }

    return 0;
}
