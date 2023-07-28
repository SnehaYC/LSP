/*
 *---------------------------
 * A program which accept directory name from user and copy first 10 bytes from all regular file into newly created file named as Demo.txt
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
	DIR *dp = NULL;
	
	struct dirent * entry = NULL;
	char name[30];
	
	struct stat sobj;
	int fd = 0;
	
	dp = opendir(argv[1]);
	
	if(dp == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}
	fd = creat("Demo.txt", 0777);
	while((entry = readdir(dp)) != NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&sobj);
		
		if(S_ISREG(sobj.st_mode))
		{
			while(name(sobj.st_size) == 10)
			{
				strcpy(name,"Demo.txt"));
			}
		}
	}

	closedir(dp);
	
	return 0;
 }
