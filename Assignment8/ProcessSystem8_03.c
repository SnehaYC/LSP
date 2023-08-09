/*
 *---------------------------
 * A program which creates three different processes internally as process2, process3, process4.
 * Author: Sneha YC
 *---------------------------
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int pid = 0, pid1 = 0, pid2 = 0;
	pid = fork();
	
	if(pid == 0)
	{
		printf("Child process id is: %d and its parent process if is %d\n", getpid(), getppid());
	}
	else
	{
		pid1 =fork();
		
		if(pid1 == 0)
		{
			printf("Child process id is: %d and its parent process if is %d\n", getpid(), getppid());
		}
		else
		{
			pid2 =fork();
			if(pid2 == 0)
			{
			printf("Child process id is: %d and its parent process if is %d\n", getpid(), getppid());
			}
		}
		
	}
	
}
