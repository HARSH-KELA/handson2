#include<unistd.h>
#include<fcntl.h>
#include<sys/file.h>
#include<sys/wait.h>
#include<stdio.h>
int main()
{
char buff1[80],buff2[80];
int fd1[2],fd2[2];
pipe(fd1);
pipe(fd2);
if(!fork())
{
close(fd1[0]);
close(fd2[1]);
printf("enter the message to parent : ");
scanf("%[^\n]",buff1);
write(fd1[1],buff1,sizeof(buff1));
read(fd2[0],buff2,sizeof(buff2));
printf("message fronm parent :%s\n",buff2);
}
else
{
close(fd1[1]);
close (fd2[0]);
read(fd1[0],buff1,sizeof(buff1));
printf("message from chidle :%s\n",buff1);
printf("enter message to the child : ");
scanf("%[^\n]",buff2);
write(fd2[1],buff1,sizeof(buff1));
}
}

