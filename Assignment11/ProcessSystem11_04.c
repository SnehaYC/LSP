/*
 *---------------------------
 * A program which creates two threads and by using appropriate synchronization technique avoid the scheduling problem.
 * Author: Sneha YC
 *---------------------------
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;
  
void* threadProcess(void* arg)
{
    pthread_mutex_lock(&lock);
  
    unsigned long i = 0;
    counter += 1;
    printf("Process %d has started\n", counter);
  
    for (i = 0; i < (0xFFFFFFFF); i++);
        
  
    printf("Process %d has finished\n", counter);
  
    pthread_mutex_unlock(&lock);
  
    return NULL;
}
  
int main(void)
{
    int i = 0;
    int error;
  
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex init has failed\n");
        return 1;
    }
  
    while (i < 2) {
        error = pthread_create(&(tid[i]), NULL,  &threadProcess, NULL);
        if (error != 0)
            printf("Thread can't be created :[%s]", strerror(error));
        i++;
    }
  
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);
  
    return 0;
}
