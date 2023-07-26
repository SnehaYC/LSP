/*
 *---------------------------
 * A program which accept file name and mode from user and open that file in specified mode.
 * Author: Sneha YC
 *---------------------------
 */
 #include<stdio.h>
 #include<fcntl.h>
 #include<string.h>
 
 int main(int argc, char *argv[])
 {
 	
 	int fd = 0;
 	int mode = 0;
 	
 	if(argc != 3)
 	{
 		printf("Invalid number of arguments\n");
 		return -1;
 	}
 	
 	if(strcmp(argv[2],"Read") == 0)
 	{
 		mode = O_RDONLY;
 	}
 	else if(strcmp(argv[2],"Write") == 0)
 	{
 		mode = O_WRONLY;
 	}
 	else
 	{
 		mode = O_RDONLY;
 	}
 	
 	fd = open(argv[1],mode);
 	if(fd == -1)
 	{
 		printf("Unable to open file\n");
 		return -1;
 	}
 	else
 	{
 		printf("File is successfully opened with fd: %d\n",fd);
 	}
 	return 0;
 }
