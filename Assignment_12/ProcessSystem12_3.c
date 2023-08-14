/* 
 * A program which creates one child process, child process write something in unnamed pipe and parent process read the data from that pip.
 * Author: SnehaYC
 *
 */

#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

#define BLOCKSIZE 512

int main()
{
    int shmid = 0;
    int key = 1234;
    int shmsize = 100;
    char *ptr = NULL;
    char Buffer[BLOCKSIZE];
    int iCnt = 0;

    shmid = shmget(key,shmsize,0666);
    if(shmid != -1)
    {
        printf("Shared memory allocated successfully.. \n");
    }

    ptr = shmat(shmid,NULL,0);
    if(ptr != NULL)
    {
        printf("Shared memory attach successfully..\n");
    }

    while(ptr[iCnt] != '\0')
    {
        Buffer[iCnt] = ptr[iCnt];
        iCnt++;
    }
    printf("Data from shared memory: %s\n",Buffer);

    return 0;
}