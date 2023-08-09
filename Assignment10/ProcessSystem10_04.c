/*
 *---------------------------
 * A program which creates single thread and it accepts one value from user and it returns some value to the caller thread.
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
	int iSum = 5;
	printf("Value Received from main thread is: %d\n", (int)ptr);
	iSum = iSum + (int)ptr;
	return (void *) iSum;
}

int main()
{
	pthread_t TID;
	int ret = 0, no = 11, status = 0;
	
	ret = pthread_create(&TID,  NULL, ThreadProc, (int *)no);

	if(ret != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread is created with ID: %d\n", TID);
	
	pthread_join(TID, &status);
	printf("End of main thread with return value %d\n", (int)status);
	
	return 0;
}
