
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
	void *ptr = NULL;
	
	void (*fptr1)();
	
	
	ptr = dlopen("/home/sneha/Desktop/Assignments/Assignment7/Program2/library.so",RTLD_LAZY);
	
	if(ptr == NULL)
	{
		printf("Unbale to load library\n");
		return -1;
	}
	
	fptr1 = dlsym(ptr,"main");
	
	if(fptr1 == NULL)
	{
		printf("Unable to load the process of funtion\n");
		return -1;
	}
	
	fptr1();
	
	return 0;
}

