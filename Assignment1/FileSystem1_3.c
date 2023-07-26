/*
 *---------------------------
 * A program which accept file name and mode from user and that program check whether our process can access that file in accepted mode or not.
 * Author: Sneha Yogesh Choudhari
 *---------------------------
 */
 #include<stdio.h>
 #include<fcntl.h>
 #include<string.h>
 #include<unistd.h>
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
 		mode = R_OK;
 	}
 	else if(strcmp(argv[2],"Write") == 0)
 	{
 		mode = W_OK;
 	}
 	else if(strcmp(argv[2],"Execute") == 0)
 	{
 		mode = X_OK;
 	}
 	
 	if(access(argv[1],mode) < 0)
 	{
 		printf("Unable to access file..\n");
 		return -1;
 	}
 	else
 	{
 		printf("You can access file in this mode..\n",fd);
 	}
 	return 0;
 }
