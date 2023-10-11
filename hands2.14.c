#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/file.h>





int main()
{
int i,j,fd[20];
char buff[80];
i=pipe(fd);
printf("i=%d\n",i);
j=write(fd[1],"hello\n",7);
read(fd[0],buff,j);
printf("from pipe : %s\n",buff);
}

