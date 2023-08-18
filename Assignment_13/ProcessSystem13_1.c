/* 
 * A program which creates two process as reader and writer and that processes should communicate with each other using FIFO.
 * Author: SnehaYC
 *
 */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	
	int fd = 0;
	char buf1[100], buf2[100];
	
	char * myfifo = "mypipe";
	
	mkfifo(myfifo, 0666);
	
	 while (1)
     {
		fd = open("mypipe",  O_WRONLY );
		if(fd == -1)
		{
			printf("Unable to open file\n");
			return -1;
		}
	
		fgets(buf2, 100, stdin);
	
		write(fd, buf2, strlen(buf2));
	
		close(fd);
		
		
		 fd = open(myfifo, O_RDONLY);
		 read(fd, buf1, sizeof(buf1));
		 printf("Client: %s\n", buf1);
        close(fd);
	}
	
	return 0;
}

