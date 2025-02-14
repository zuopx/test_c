/*简单消息队列

ipcs -q
ipcrm --all=msg
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_struct {
    int type;
    char content[100];
} message;

int main()
{
    //生成IPC Key
    key_t key = ftok("./path", 65);

    //创建一个Message Queue，获得Message Queue ID
    int mqid = msgget(key, 0666 | IPC_CREAT);
    printf("mqid：%d\n", mqid);

    while(1){
        //输入文本
        printf("请输入要发送的文本：");
        fgets(message.content, 100, stdin);
        message.type = 1;

        //发送数据
        msgsnd(mqid, &message, sizeof(message), 0);
        printf("发送的数据：%s", message.content);
    }

    return 0;
}
