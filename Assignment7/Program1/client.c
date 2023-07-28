
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
	void *ptr = NULL;
	
	void (*fptr1)();
	void (*fptr2)();
	void (*fptr3)();
	void (*fptr4)();
	
	ptr = dlopen("/home/sneha/Desktop/Assignments/Assignment7/Program1/library.so",RTLD_LAZY);
	
	if(ptr == NULL)
	{
		printf("Unbale to load library\n");
		return -1;
	}
	
	fptr1 = dlsym(ptr,"Addition");
	fptr2 = dlsym(ptr,"Substraction");
	fptr3 = dlsym(ptr,"Multiplication");
	fptr4 = dlsym(ptr,"Division");
	
	if(fptr1 == NULL)
	{
		printf("Unable to load the process of funtion\n");
		return -1;
	}
	if(fptr2 == NULL)
	{
		printf("Unable to load the process of funtion\n");
		return -1;
	}
	if(fptr3 == NULL)
	{
		printf("Unable to load the process of funtion\n");
		return -1;
	}
	if(fptr4 == NULL)
	{
		printf("Unable to load the process of funtion\n");
		return -1;
	}
	
	fptr1();
	fptr2();
	fptr3();
	fptr4();
	
	return 0;
}

