/*
 *---------------------------
 * A program which accept file name and write string in that file.
 * Author: Sneha Yogesh Choudhari
 *---------------------------
 */
 #include<stdio.h>
 #include<fcntl.h>
 #include<unistd.h>
 #include<string.h>
 
 int main(int argc, char *argv[])
 {
 	int fd = 0;
	char str[20] = "Hello World";
	
	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	
	fd = open(argv[1],O_WRONLY);
	
	if(fd == -1)
	{
		printf("Unable to open file\n");
	}
	
	write(fd,str,strlen(str));

 	return 0;
 }
