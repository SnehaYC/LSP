/*
 *---------------------------
 * A program which is used to create the simple thread by using pthread library.
 * Author: Sneha YC
 *---------------------------
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
	printf("Jay Ganesh...\n");
}

int main()
{
    pthread_t TID;
    int ret = 0;

    ret = pthread_create(&TID, NULL, ThreadProc, NULL);

    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    printf("Thread is created with ID : %d\n", TID);

    return 0;
}
