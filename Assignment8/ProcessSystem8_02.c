/*
 *---------------------------
 * A program which create three level process hierarchy where process1 creates process2 and it internally creates process3.
 * Author: Sneha YC
 *---------------------------
 */
 #include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int ret = 0, cpid = 0, Exit_status = 0;
	
	ret = fork();
	if(ret == 0)
	{
		execl("./process", NULL);
	}
	else
	{
		printf("child[1] id is %d & parent id is : %d \n", getpid(), getppid());
		cpid = wait(&Exit_status);
	}
	
	return 0;
}
