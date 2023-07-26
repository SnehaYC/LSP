/*
 *---------------------------
 * A program which accept directory name from user and print all file names and its types from that directory.
 * Author: Sneha Yogesh Choudhari
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
	struct stat sobj;
	char name[30];
	
	dp = opendir(argv[1]);
	
	if(dp == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}
	
	while((entry = readdir(dp)) != NULL)
	{
		sprintf(name,"%s",entry->d_name);
		stat(name,&sobj);
		
		if(S_ISREG(sobj.st_mode))
		{
			printf("%s It is a regular file\n",name);
		}
		else if(S_ISDIR(sobj.st_mode))
		{
			printf("%s It is a directory\n",entry->d_name);
		}
		else if(S_ISLNK(sobj.st_mode))
		{
			printf("%s It is a symbolic link\n",name);
		}
	}
	
	closedir(dp);
	
	return 0;
}

