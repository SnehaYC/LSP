/* 
 * A program which such a process which accept signals from the terminal.
 * Author: SnehaYC
 *
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <strings.h>

int main()
{
	
	int pid = 0;
	char buf1[100];
	
	pid  = fork();
	
	if(pid == -1)
	{
		printf("Unable to create the process\n");
		return -1;
	}
	
	if(pid == 0) //child
	{
		
	}
	else  //parent 
	{
		while(1)
		{
			fgets(buf1, 100, stdin);
		}
	}
	
	
}



















