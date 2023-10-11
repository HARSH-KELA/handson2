#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/file.h>
#include<fcntl.h>
int main()
{
char  buff[80];
int fd[2];
pipe(fd);
if(fork())
{
close(fd[0]);//close read end of the pipe for parent
printf("enter the mesage to the child :");
scanf("%[^\n]",buff);
write(fd[1],buff,sizeof(buff));
}
else
{
close(fd[1]);
read(fd[0],buff,sizeof(buff));
printf("message from parent :%s\n",buff);
}
wait(0);
}


