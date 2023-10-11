#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>
struct message {
    long mtype; 
    char mtext[100]; 
};
int main()
{
key_t key;
int msgid;
struct message msg;
key=ftok("/tmp",'A');
msgid=msgget(key,IPC_CREAT | IPC_EXCL | 0666);
if(msgid==-1)
{
perror("msgget");
exit(1);
}
msg.mtype=1;
strcpy(msg.mtext,"hello,mssg queue!");
if(msgsnd(msgid,&msg,sizeof(msg.mtext),0)==-1)
{
perror("msgsnd");
exit(1);
}
printf("mssg send to the queue.\n");
printf("$ ipc -q\n");
msgctl(msgid,IPC_RMID,NULL);
return 0;
}

