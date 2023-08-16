/* 
 * A program which creates two process as reader and writer and that processes should communicate with each other using FIFO.
 * Author: SnehaYC
 *
 */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main()
{   
    int Fd = 0;
    char * Path = "/tmp/mypipe";
    char Arr[] = "SnehaYC";

    Fd = mkfifo(Path,0666);
    if(Fd == -1)
    {
        printf("unable to create pipe..\n");
        return -1;
    }

    Fd = open(Path,O_WRONLY);
    if(Fd == -1)
    {
        printf("Unable to open pipe...\n");
        return -1;
    }

    write(Fd,Arr,strlen(Arr));

    close(Fd);

    unlink(Path);

    return 0;
}