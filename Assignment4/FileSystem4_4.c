/*
 *---------------------------
 * A program which accept directory name from user and copy first 10 bytes from all regular file into newly created file named as Demo.txt
 * Author: Sneha YC
 *---------------------------
 */
 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	int fd1 = 0, fd2 = 0, Ret = 0;
	DIR *dp = NULL;
	char *path = NULL;
	struct stat sobj;
	struct dirent *entry = NULL;
	char buffer[10] = {'\0'};
	
	if(argc != 3)
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
	
	fd2 = creat(argv[2], 0777);
    if(fd2 == -1)
    {
        printf("Unable to create %s destination file\n", argv[2]);
        return -1;
    }
	
	while((entry = readdir(dp)) != NULL)
	{
		path = malloc(strlen(argv[1])+strlen(entry->d_name)+1);
		sprintf(path,"%s/%s", argv[1], entry->d_name);
		stat(path, &sobj);
		if(S_ISREG(sobj.st_mode) && (sobj.st_size!=0))
		{
			fd = open(path, O_RDONLY);
			if(fd == -1)
			{
				printf("Unable to open file %s\n", entry->d_name);
			}
			else
			{
				if((Ret = read(fd,buffer,10)) != 0)
				{
					write(fd2, buffer, sizeof(buffer));
					memset(buffer, 0, sizeof(buffer));
					printf("Successfully write 10 bytes from %s file into %s file\n", entry->d_name,argv[2]);
				}
			}
			close(fd);
		}
		else
		{
			printf("%s is not a regular file\n", entry->d_name);
		}
		printf("============================\n");
	}
	close(fd2);
	printf("Successfully write 10 bytes into %s file \n", argv[2]);
	return 0;
}
 
