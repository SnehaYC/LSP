/*
 *---------------------------
 * A program which accept directory name from user and create new directory of that name.
 * Author: Sneha YC
 *---------------------------
 */

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	
	struct stat st = {0};
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	if (stat(argv[1], &st) == -1) {
		mkdir(argv[1], 0700);
		printf("%s directory created\n", argv[1]);
	}
	
    return 0;
}

