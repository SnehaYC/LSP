/*
 *---------------------------
 * A program which accept file name from user which contains information of employee, we have to read all contents from that file.
 * Author: Sneha YC
 *---------------------------
 */
 #include<stdio.h>
 #include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[])
{
    char fname[20];
    int fd = 0, icnt=0, ret=0;
	char ch[1]={'\0'};
	 if(argc != 2)
	{
		 printf("Insufficient arguments\n");
		 return -1;
	}
	
    fd = open(argv[1],O_RDONLY);
	printf("Student Information:\n");
	printf("Roll No:\t");
	
	while((ret = read(fd,ch,sizeof(ch))) != 0)
	{
		
		if(ch[0]=='\n')
		{
			icnt +=1;
			if(icnt ==1)
			{
				printf("Marks:\t");
			}
			else if(icnt==2){
				printf("Age:\t");
			}
			else{
				printf("Name:\t");
			}
			
			continue;
		}
		else
		{
			printf("%s", ch);
		}
		 memset(ch, 0, sizeof(ch));
	}
	
    close(fd);

    return 0;
}
