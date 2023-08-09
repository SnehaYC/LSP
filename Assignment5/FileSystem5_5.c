/*
 *---------------------------
 * A program which accept file name which contains data of all file. we have to create all file again.
 * Author: Sneha YC
 *---------------------------
 */
 #include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
 
 int main(int argc, char *argv[])
{
	int fd = 0, ret=0;
	char ch[1]={'\0'};
	
	if(argc != 2)
	{
		printf("insufficient arguments\n");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file %s\n", argv[1]);
	}
	char file_name_size[10]={'\0'};
	int cnt=0;
	printf("ch1 %s\n", ch);
	while((ret = read(fd,ch,sizeof(ch))) != 0)
	{
		cnt+=1;
		if(cnt==4)
		{
			break;
		}
		if(isdigit(ch[0]))
		{
			
			strcat(file_name_size, ch[0]);
			printf("digit %s\n", ch);
			printf("file_name_size %s\n", file_name_size);
		}
		else
		{
			printf(" char %s\n", ch);
		}
	}
		
}
