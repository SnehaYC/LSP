/*
 *---------------------------
 * A program in which creates new process which is responsible to write all file names which are present on desktop in demo file which should be created newly.
 * Author: Sneha YC
 *---------------------------
 */
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<unistd.h>
 #include<fcntl.h>
 
 int main()
 {
	 int iRet = 0, status = 0;
	 
	 iRet = fork();
	 
	 if(iRet == 0)
	 {
		 execl("./FileNames", NULL);
	 }
	 else
	 {
		printf("The running process id is: %d \n", getpid());
	 }
	 
	 wait(&status);
	 return 0;
 }
