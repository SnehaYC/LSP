/*
 *---------------------------
 * A program which writes structure in the file. Structure should contains information of student.
 * Author: Sneha YC
 *---------------------------
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

struct student
{
	int age;
	int rollNo;
	float marks;
	char *name;
};

int main(int argc, char *argv)
{
	struct student sobj;
	struct student sobj2;
	int fd = 0, ret =0, size = 0, fd1=0;
    char fname[20];

    printf("Enter the file name :\t");
    scanf("%s", &fname);
	
	fd =creat(fname, 0777);
	if(fd == -1)
	{
		printf("Unable to open file with fd %d\n", fd);
		return -1;
	}
	printf("Enter maximum length of name: \t");
    scanf("%d", &size);

    
    sobj.name = (char*)malloc(size * sizeof(char));

	printf("Enter student name:\t");
    scanf("%s", sobj.name);
	
	printf("Enter roll no:\t");
	scanf("%d", &sobj.rollNo);
	
	printf("Enter marks:\t ");
    scanf("%f", &sobj.marks);
	
	printf("Enter age:\t ");
    scanf("%d", &sobj.age);
	
	write(fd, &sobj, sizeof(sobj));
	close(fd);
	
	fd1 = open(fname, O_RDONLY);
	if(fd1 == -1)
	{
		printf("Unable to open %s file\n", fname);
		return -1;
	}
	
	ret = read(fd1, &sobj2, sizeof(sobj2));
	if(ret !=0)
	{
		printf("Student Information: \n");
		printf("Name: %s\n", sobj2.name);
		printf("Roll no: %d\n", sobj2.rollNo);
		printf("Age: %d\n", sobj2.age);
		printf("Marks: %f\n", sobj2.marks);
	}
	close(fd1);
	return 0;
	
}
