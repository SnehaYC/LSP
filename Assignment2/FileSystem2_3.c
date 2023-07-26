/*
 *---------------------------
 * A program which accept directory name from user and print all files names from that directory.
 * Author: Sneha YC
 *---------------------------
 */
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	char DirName[20];
	DIR *dp = NULL;
	struct dirent *entry = NULL;
	
	dp = opendir(argv[1]);
	
	if(dp == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}
	
	while((entry = readdir(dp)) != NULL)
	{
		printf("%s\n",entry->d_name);
	}
	
	closedir(dp);
	
	return 0;
}

