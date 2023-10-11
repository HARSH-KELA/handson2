#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/file.h>
int main()
{
int fd1,fd2;
char buff1[80],buff2[80];
fd1=open("harsh.txt",O_WRONLY);
fd2=open("harsh.txt",O_RDONLY);
printf("enter the text");
scanf("%[^\n]",buff1);
write(fd1,buff1,sizeof(buff1));
read(fd2,buff2,sizeof(buff2));
printf("the text from fifo file : %s\n",buff2);
}

