/*
 *---------------------------
 * A program which accept directory name from user and create new directory of that name.
 * Author: Sneha Yogesh Choudhari
 *---------------------------
 */
#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
 int main(int argc, char *argv[])
 {
 	DIR *dp = NULL;
	
	if(argc != 2)
	{
		printf("Insufficient arguments..\n");
		return -1;
	}
	
	dp = mkdir(argv[1],0777);
	
	if(!dp)
	{
		printf("Directory created\n");
	}
	else
	{
		printf("Unable to create directory\n");
		return -1;
	}
	
 	return 0;
 }
