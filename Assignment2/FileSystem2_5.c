/*
 *---------------------------
 * A program which accept directory name from user and print name of such a file having largest size.
 * Author: Sneha Yogesh Choudhari
 *---------------------------
 */
#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char *argv[])
{
	char DirName[20];
	DIR *dp = NULL;
	
	struct dirent * entry = NULL;
	char name[30];
	
	struct stat sobj;
	char namecopy[30] = {'\0'};
	int iMax = 0;
	
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
		
		if(iMax < sobj.st_size)
		{
			
			iMax = sobj.st_size;
			strcpy(namecopy,name);
		}
		
	}
	
	printf("Name of largest file: %s with size %d bytes \n",namecopy,iMax);
	
	closedir(dp);
	
	return 0;
}
