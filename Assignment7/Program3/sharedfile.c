
#include<stdio.h>
#include "sharedfile.h"

int Addition(int No1,int No2)
{
	int iNo1 = 0, iNo2 = 0;
	int iAns = 0;
	
	printf("Enter first number:\n");
	scanf("%d",&iNo1);
	
	printf("Enter first number:\n");
	scanf("%d",&iNo2);
	
	iAns = iNo1 + iNo2;
	
	printf("Addition is: %d\n",iAns);
}

int Substraction(int No1,int No2)
{
	int iNo1 = 0, iNo2 = 0;
	int iAns = 0;
	
	printf("Enter first number:\n");
	scanf("%d",&iNo1);
	
	printf("Enter first number:\n");
	scanf("%d",&iNo2);
	
	iAns = iNo1 - iNo2;
	
	printf("Substraction is: %d\n",iAns);
}
int Multiplication(int No1,int No2)
{
	int iNo1 = 0, iNo2 = 0;
	int iAns = 0;
	
	printf("Enter first number:\n");
	scanf("%d",&iNo1);
	
	printf("Enter first number:\n");
	scanf("%d",&iNo2);
	
	iAns = iNo1 * iNo2;
	
	printf("Multipilcation is: %d\n",iAns);
}
int Division(int No1,int No2)
{
	int iNo1 = 0, iNo2 = 0;
	int iAns = 0;
	
	printf("Enter first number:\n");
	scanf("%d",&iNo1);
	
	printf("Enter first number:\n");
	scanf("%d",&iNo2);
	
	iAns = iNo1 / iNo2;
	
	printf("Division is: %d\n",iAns);
}
