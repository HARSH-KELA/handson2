#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<unistd.h>


void main()
{
key_t queuekey;
int queueidentifier;
ssize_t messagesize;
struct msgbuf
{
long mtype;
int somenumber;
}data;
queuekey=ftok(".",1);
if(queuekey==-1)
{
  perror("error while computing key!");
  _exit(0);
}
data.mtype=1;
data.somenumber=1;
messagesize=msgrcv(queueidentifier,&data,sizeof(data),data.mtype,0);
if(messagesize==-1)
{
perror("error while sending gettinf via message queue!");
_exit(0);
}
printf("recieved number :%d\n",data.somenumber);
}

