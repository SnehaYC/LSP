/* 
 * A program which creates child process and parent process will communicate with child process by sending signals.
 * Author: SnehaYC
 *
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void sighup();
void sigint();
void sigquit();

int main()
{
	
	signal(SIGHUP, sighup);
    signal(SIGINT, sigint);
    signal(SIGQUIT, sigquit);
	int pid = 0;
	
	pid = fork();
	
	if(pid == -1)
	{
		printf("Unable to create the process");
        return -1;
	}
	
	if(pid == 0) 
	{
		 for(;;); 
	}
	else 
	{
		signal(SIGHUP, SIG_DFL);
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);

		
		printf("\nPARENT: sending SIGHUP\n\n");
        kill(pid, SIGHUP);
        sleep(3); 
		
        printf("\nPARENT: sending SIGINT\n\n");
        kill(pid, SIGINT);
        sleep(3); 
		
        printf("\nPARENT: sending SIGQUIT\n\n");
        kill(pid, SIGQUIT);
        sleep(3);
	}
	
	return 0;
}

void sighup()
{
    signal(SIGHUP, sighup); 
    printf("CHILD: I have received a SIGHUP\n");
}

void sigint()
{
    signal(SIGINT, sigint); 
    printf("CHILD: I have received a SIGINT\n");
}


void sigquit()
{
    printf("Child Process gets stop!!!\n");
    exit(0);
}