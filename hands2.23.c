#include<stdio.h>
#include<unistd.h>
#include<sys/file.h>
#include<fcntl.h>
#include<limits.h>
#include<stdlib.h>

int main()
{
long maxfiles=sysconf(_SC_OPEN_MAX);
if(maxfiles==-1)
{
perror("error in sysconf");
return 1;
}
printf("maximun number of files that can be opened with ina process : %ld\n",maxfiles);
int pipe_fd[2];
if(pipe(pipe_fd)==-1)
{
perror("error creating pipe");
return 1;
}
long pipesize=fpathconf(pipe_fd[0],_PC_PIPE_BUF);
if(pipesize==-1)
{
perror("error in f pathconf");
return 1;
}
printf("size of the pipe circular buffer :%ld bytes\n",pipesize);
close(pipe_fd[0]);
close(pipe_fd[1]);
return 0;
}

