/*
 *---------------------------
 * A program which creates two processes as addition and subtraction and our parent process terminates till both the process terminates.
 * Author: Sneha YC
 *---------------------------
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int ret1 = 0, ret2 = 0;
	int status1 = 0, status2 = 0;
	
	ret1 = fork();
	if(ret1 != 0)
	{
		execl("./addition", "addition", "10", "11", NULL);
	}
	
	wait(&status1);
	
	ret2 = fork();
	if(ret2 != 0)
	{
		execl("./subtraction", "subtraction", "11", "10", NULL);
	}
	wait(&status2);

	return 0;
}

