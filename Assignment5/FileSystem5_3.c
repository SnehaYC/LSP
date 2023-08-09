/*
 *---------------------------
 * A program which accept directory name from user and write information of all regular file in and read the contents from that file.
 * Author: Sneha Yogesh Choudhari
 *---------------------------
 */
 #include<stdio.h>
 #include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
 int main(int argc, char *argv[])
{
	int fd=0, Ret=0;
	DIR *dp = NULL;
	struct dirent *entry = NULL;
	char *path = NULL;
	struct stat sobj;
	char buffer[20] = {'\0'};
	
	if(argc != 2)
	{
		printf("insufficient arguments\n");
		return -1;
	}
	
	dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open %s directory\n", argv[1]);
        return -1;
    }
	
	while((entry = readdir(dp)) != NULL)
	{
		path = malloc(strlen(argv[1])+strlen(entry->d_name)+1);
		sprintf(path,"%s/%s", argv[1], entry->d_name);
		stat(path, &sobj);
		if(S_ISREG(sobj.st_mode) && (sobj.st_size!=0))
		{
			printf("File name : %s\n", entry->d_name);
			printf("File size is : %d\n", sobj.st_size);
			printf("Number of links : %d\n", sobj.st_nlink);
			printf("Inode number : %d\n", sobj.st_ino);
			printf("File system number : %d\n", sobj.st_dev);
			printf("Number of blocks : %d\n", sobj.st_blocks);
			printf("User Id : %d\n", sobj.st_uid);
			printf("Group Id : %d\n", sobj.st_gid);
			printf("Block Size: %d\n", sobj.st_blksize);
			
			fd = open(path, O_RDONLY);
			
			if(fd == -1)
			{
				printf("Unable to open file %s\n", entry->d_name);
			}
			else
			{
				printf("File Data is :\n");
				while((Ret = read(fd,buffer,sizeof(buffer))) != 0)
				{
					printf("%s", buffer);
					memset(buffer, 0, sizeof(buffer));
				}
			}
		}
		else
		{
			printf("%s is not a regular file\n", entry->d_name);
		}
	
	}
}
