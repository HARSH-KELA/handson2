
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/file.h>
int main()
{
char buff[80];

int fd =open("harsh.txt",O_RDONLY,O_CREAT);
printf("enter the text");
scanf("%[^\n]",buff);
write(fd,buff,sizeof(buff));
}


