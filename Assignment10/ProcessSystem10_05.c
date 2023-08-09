/*
 *---------------------------
 * A program which is used to get thread id inside thread function.
 * Author: Sneha YC
 *---------------------------
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
	    printf("In thread function \nthread id = %d\n", pthread_self());
		pthread_exit(NULL);
}

int main()
{
	pthread_t TID;
	int ret = 0;
	
	ret = pthread_create(&TID,  NULL, ThreadProc, NULL);

	if(ret != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread is created in main thread with ID: %d\n", TID);
	
	pthread_join(TID, NULL);
	
	return 0;
}
