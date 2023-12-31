/*
 *---------------------------
 * A program which creates two processes.
 * 	Process1 count number of capital characters from demo.txt file.
 * 	and Process2 count number of capital characters from hello.txt file.
 * 	both the processes writes its count in count.txt file.
 * Author: Sneha YC
 *---------------------------
 */
  
 #include<stdio.h>
 #include<stdlib.h>
 #include<unistd.h>
 #include<fcntl.h>
 
 int main()
 {
	 int iRet1 = 0, iRet2 = 0, status1 = 0, status2 = 0;
	 
	 iRet1 = fork();
	 
	 if(iRet1== 0)
	 {
		 execl("./process1", "capitalchar", "demo.txt" , NULL);
		 printf("The running process id of process1 is %d", getpid());
	 }
	 
	 wait(&status1);
	 
	 iRet2 = fork();
	 if(iRet2 == 0)
	 {
		 execl("./process2", "capitalchar", "hello.txt" , NULL);
		printf("The running process2 id is: %d \n", getpid());
	 }
	 
	 wait(&status2);
	 return 0;
 }
