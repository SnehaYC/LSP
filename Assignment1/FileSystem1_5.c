/*
 *---------------------------
 * A program which accept file name and number of bytes from user and read that number of bytes data from file.
 * Author: Sneha Yogesh Choudhari
 *---------------------------
 */
 #include<stdio.h>
 #include<fcntl.h>
 
 int main(int argc, char *argv[])
 {
 	int fd = 0;
	int iRet = 0;
	
	char *Buffer = NULL;
	
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;	
	}
	
	Buffer = (char *)malloc(sizeof(atoi(argv[2])));
	
	iRet = read(fd,Buffer,atoi(argv[2]));
	
	if(iRet == 0)
	{
		printf("Unable to read data from file\n");
		return -1;	
	}
	
	printf("Data from file is : \n");
	
	write(1, Buffer, iRet);
	
	printf("\n");
 	
 	return 0;
 }
