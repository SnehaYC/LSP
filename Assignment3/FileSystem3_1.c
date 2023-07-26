/*
 *---------------------------
 * A program which accept two file names from user and copy the contents of an existing file into newly created file.
 * Author: Sneha Yogesh Choudhari
 *---------------------------
 */
 #include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
	int fdSource = 0;
	int fdDest = 0;
	int iRet = 0;
	
	char Buffer[BLOCKSIZE] = {'\0'};
	
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return 0;
	}
	
	fdSource = open(argv[1],O_RDONLY);
	
	if(fdSource == -1)
	{
		printf("unable to open source file\n");
		return -1;
	}
	
	fdDest = creat(argv[2],0777);	
	
	if(fdDest == -1)
	{
		printf("Unable to create destination file\n");
		close(fdSource);
		return -1;
	}
	
	while((iRet = read(fdSource,Buffer,sizeof(Buffer))) != 0)
	{
		write(fdDest,Buffer,iRet);
		memset(Buffer,0,sizeof(Buffer));
	}
	
	close(fdSource);
	close(fdDest);
	
	return 0;
}
