/* 
 * A program which creates two processes ant that twwo processes can communicate with each other by using shared memory.
 * Author: SnehaYC
 *
 */

#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
    int shmid = 0;
    int key = 1234;
    int shmsize = 100;
    char *ptr = NULL;

    int iCnt = 0;
    int len = 0;
    char Arr[] = "SnehaYC";

    shmid = shmget(key,shmsize,IPC_CREAT|0666);
    if(shmid != -1)
    {
        printf("Shared memory allocated.. : \n");
    }

    ptr = shmat(shmid,NULL,0);
    if(ptr != NULL)
    {
        printf("Shared memory attached successfully..\n");
    }

    len = strlen(Arr);

    for(iCnt = 0;iCnt<len;iCnt++)
    {
        ptr[iCnt] = Arr[iCnt];
    }

    ptr[len] = '\0';

    return 0;
}