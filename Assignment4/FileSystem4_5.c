/*
 *---------------------------
 * A program which accept file name and position from user and read 20 bytes from that position.
 * Author: Sneha YC
 *---------------------------
 */
 

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char buffer[20] = {'\0'};
    int ret = 0;

    if(argc != 3)
    {
        printf("Insufficient arguments...\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open %s file\n", argv[1]);
        return -1;
    }
	
	lseek(fd, atoi(argv[2]), SEEK_CUR);
	
    ret = read(fd,buffer,20);
    if(ret == 0)
    {
        printf("Unable to read data from %s file\n", argv[1]);
        return -1;
    }

    printf("Date from 20 bytes:\n %s\n",buffer);
	close(fd);
    return 0;
}




