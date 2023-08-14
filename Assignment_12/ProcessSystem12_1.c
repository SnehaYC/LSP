/* 
 * A program which is used to create unnamed pipe. Parent process creates new child processs and both the processes will communicate with each other.
 * Author: SnehaYC
 *
 */

#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define BLOCKSIZE 512

int main()
{
    int Fd[2];
    int iret = 0;
    char Arr[] = "Sneha Choudhari";
    char Buffer[BLOCKSIZE];

    pipe(Fd);

    iret = fork();
    if(iret == 0)
    {
        printf("Child is ready to write data in Pipe : \n");
        close(Fd[0]);
        write(Fd[1],Arr,strlen(Arr));
    }
    else
    {
        printf("Parent is ready to read data from Pipe : \n");
        close(Fd[1]);
        read(Fd[0],Buffer,sizeof(Buffer));
        printf("Date from Pipe : %s\n",Buffer);
    }

    return 0;
}