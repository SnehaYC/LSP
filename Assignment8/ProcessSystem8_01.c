/*
 *---------------------------
 * A program in which parent process waits till its child process terminates.
 * Author: Sneha YC
 *---------------------------
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char * argv[])
{
	int ret = 0, cpid = 0, Exit_status = 0;
	ret = fork();
	if(ret == 0)
	{
		execl("./childProcess", "Demo", "Hello", "Sneha", NULL);
	}
	else
	{
		printf("Parent is running with PID is: %d \n", getpid());
		cpid = wait(&Exit_status);
		printf("child process terminated having PID %d with exit status %d\n", cpid, Exit_status);
	}
	
	return 0;
}
