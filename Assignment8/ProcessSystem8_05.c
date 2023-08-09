/*
 *---------------------------
 * A a program which is used to create daemon process.
 * Author: Sneha YC
 *---------------------------
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

int main()
{
	int ret = 0, sid = 0, fd = 0, iCnt = 0;
	
	ret = fork();
	if(ret < 0)
	{
		printf("fork failed!\n");
		exit(1);
	}
	
	if(ret > 0)
	{
		printf("pid of child process %d \n", getpid());
		exit(0);
	}
	
	umask(0);
	
	sid = setsid();
	if(sid < 0)
	{
		exit(1);
	}
	
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	
	fd = open("demo.txt", O_WRONLY | O_CREAT, 0666);
	
	while(iCnt < 5)
	{
		write(fd, "Jay Ganesh...\n", 13);
		iCnt++;
	}
	
	close(fd);
	return (0);
}

