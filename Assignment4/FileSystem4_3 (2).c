/*
 *---------------------------
 * A program which accept two file names from user and check whether contents of that two files are equal or not.
 * Author: Sneha Yogesh Choudhari
 *---------------------------
 */
#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

#define BLOCKSIZE 1024
int main(int argc, char *argv[])
{
	int fd1 = 0, fd2 = 0, ret1=0, ret2=0;
	struct stat st1;
	struct stat st2;
	char buffer1[BLOCKSIZE] = {'\0'}, buffer2[BLOCKSIZE] = {'\0'};
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	if((stat(argv[1], &st1) ==0) && (stat(argv[2], &st2) ==0))
	{
		if(st1.st_size != st2.st_size)
		{
			printf("Two files have different size of data.so files don't have same contents.\n");
			return -1;
		}
		else{
			printf("Size are same. Lets check the data. \n");
		}
	}
	else{
		printf("Unable to find the file info. \n");
		return -1;
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	
 
	if( (fd1 == -1) || (fd1 == -1) )
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	while((ret1 = read(fd1, buffer1, sizeof(buffer1))) != 0 && (ret2 = read(fd2, buffer2, sizeof(buffer2))) != 0)
	{
		if(strncmp(buffer1, buffer2, sizeof(buffer1)) != 0)
		{
			printf("Two files are not equal");
			return -1;
		}
		memset(buffer1, 0, sizeof(buffer1));
		memset(buffer2, 0, sizeof(buffer2));
	}
	printf("%s and %s files have equal contents\n", argv[1], argv[2]);

	close(fd1);
	close(fd2);
	
	return -1;
}
