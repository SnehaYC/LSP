/*
 *---------------------------
 * A program which is used to increase the priority by 5.
 * Author: Sneha YC
 *---------------------------
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int ret = 0, pid = 0, ret1 = 0, ret2 = 0;
	
	printf("Jay Ganesh\n");
	ret = fork();
	
	pid = getpid();
	if(ret != 0)
	{
		printf("The pid of the running process is: %d\n", pid);
		ret1 = getpriority(PRIO_PROCESS, pid);

		printf("Priority of process is: %d\n", ret1);
	
		ret2 = setpriority(PRIO_PROCESS, pid, 5);
	
		ret1 = getpriority(PRIO_PROCESS, pid);

		printf("Priority of process is: %d\n", ret1);

	}
    
    return 0;
}
