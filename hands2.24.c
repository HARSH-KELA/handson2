#include<sys/msg.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/file.h>
#include<fcntl.h>
#include<stdio.h>
int main()
{
int  key =ftok(".",'a');
int  msgid=msgget(key,IPC_CREAT|IPC_EXCL|0744);
printf("key=0x%0x\t msgid=%d\n",key,msgid);
}
