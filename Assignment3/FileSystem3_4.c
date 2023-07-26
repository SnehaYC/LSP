/*
 *---------------------------
 * A program which accept directory name from user and delete all empty files from that directory.
 * Author: Sneha Yogesh Choudhari
 *---------------------------
 */
#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	char DirName[20];
	DIR *dp = NULL;
	
	struct dirent * entry = NULL;
	char name[30];
	
	struct stat sobj;
	
	dp = opendir(argv[1]);
	
	if(dp == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}
	
	while((entry = readdir(dp)) != NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&sobj);
		
		if(S_ISREG(sobj.st_mode))
		{
			if(sobj.st_size == 0)
			{
				remove(name);
				printf("File deleted successfully");
			}
		}
	}

	closedir(dp);
	
	return 0;
}
