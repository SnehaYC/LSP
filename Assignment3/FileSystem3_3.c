/*
 *---------------------------
 * A program which accept two directory names from user and move all files from source directory to destination directory.
 * Author: Sneha Yogesh Choudhari
 *---------------------------
 */
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/dir.h>


int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Insufficient arguments..\n");
		return -1;
	}
	
	DIR *dp = NULL;
	struct dirent *entry = NULL;
	char oldname[50];
	char newname[50];
	
	dp = opendir(argv[1]);
	
	if(dp == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}
	
	while((entry = readdir(dp)) != NULL)
	{
		sprintf(oldname,"%s/%s",argv[1],entry->d_name);
		sprintf(newname,"%s/%s",argv[2],entry->d_name);
		
		rename(oldname, newname);
	}
	printf("Successfully moved all files from source to destination..\n");
	closedir(dp);
	
	return 0;
}


