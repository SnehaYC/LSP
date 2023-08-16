/* 
 * A program which creates child process and parent process will communicate with child process by sending signals.
 * Author: SnehaYC
 *
 */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define BLOCKSIZE 512

int main()
{
    int Fd = 0;
    char Buffer[BLOCKSIZE];
    char * Path = "/tmp/mypipe";

    Fd = open(Path,O_RDONLY);
    if(Fd == -1)
    {
        printf("Unable to open file.. \n");
        return -1;
    }

    read(Fd,Buffer,sizeof(Buffer));

    printf("Data from pipe : %s\n",Buffer);
    
    close(Fd);

    return 0;
}