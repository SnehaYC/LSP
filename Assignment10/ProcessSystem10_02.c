/*
 *---------------------------
 * Write a program which creates two threads, first thread print numbers from 1 to 500. and other thread print the numbers from 500 to 1.
 * Author: Sneha YC
 *---------------------------
 */
  
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
	printf("The Numbers from 1 to 500 are:\n");
	int i = 0;
	for(i = 1; i <= 500; i++)
	{
		printf("%d\n", i);
	}
	pthread_exit(NULL);
}

void * ThreadProc2(void *ptr)
{
	printf("The Numbers from 500 to 1 are:\n");
	int i = 0;
	for(i = 500; i > 0; i--)
	{
		printf("%d\n", i);
	}
	pthread_exit(NULL);
}

int main()
{
    pthread_t TID1;
    pthread_t TID2;
    int ret1 = 0, ret2 = 0, state1 =  0, state2 = 0;
	

    ret1 = pthread_create(&TID1, NULL, ThreadProc1, NULL);

    if(ret1 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
	
	pthread_join(TID1, state1);
	printf("Return value from thread is: %d\n", state1);
	printf("End of first thread\n");

    ret2 = pthread_create(&TID2, NULL, ThreadProc2, NULL);

    if(ret2 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
	
	pthread_join(TID2, state2);
	printf("Return value from thread is: %d\n", state2);
	printf("End of second thread\n");

	pthread_exit(NULL);

    return 0;
}
