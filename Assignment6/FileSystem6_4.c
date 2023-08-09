/*
 *---------------------------
 * A program which accept directory name from user and delete all such files whose size is greater than 100 bytes.
 * Author: Sneha YC
 *---------------------------
 */
 #include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    char namecopy[30] = {'\0'};
	int limit = atoi(argv[2]);
    
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    };

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open %s directory \n", argv[1]);
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
	
        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size> limit)
            {
                remove(name);
				printf("Removed %s file from %s directory whose size %d is greater than %d byte \n" , entry->d_name, argv[1], sobj.st_size, limit);
            }
			else
			{
				printf("Not removed %s file from %s directory whose size %d is greater than %d byte \n" , entry->d_name, argv[1], sobj.st_size, limit);
            }
        }
    }

    closedir(dp);
    
    return 0;

}
