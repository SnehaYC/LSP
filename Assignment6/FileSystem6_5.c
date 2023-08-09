/*
 *---------------------------
 * A program which accept file name from user and offset, remove all the data from that offset.
 * Author: Sneha YC
 *---------------------------
 */
 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	int fd = 0;
    int ret = 0;
	char *buffer=NULL;

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
	buffer=malloc(atoi(argv[2])*sizeof(char));

    fd = open(argv[1], O_RDONLY|O_WRONLY, 0666);
	
    if(fd == -1)
    {
        printf("Unable to open %s file\n", argv[1]);
        return -1;
    }
	
	ret = ftruncate(fd, atoi(argv[2]));
    printf("Deleted data after %s position from %s file\n",argv[2], argv[1]);
	close(fd);
    return 0;
}
