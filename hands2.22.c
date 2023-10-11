#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/file.h>
int main()
{
fd_set rfds;
struct timeval tv;
tv.tv_sec=100000;
char buff[80];
int fd=open("harsh.txt",O_RDONLY);
FD_ZERO(&rfds);
FD_SET(fd,&rfds);
if(!select(fd+1,&rfds,NULL,NULL, &tv))
printf("no data is avail for read yet\n");
else
{
printf("data is available now \n");
read(fd,buff,sizeof(buff));
printf("data from fifo : %s \n",buff);
}
}

