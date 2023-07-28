/*
 *---------------------------
 * A program which is used to demonstrate concept of I/O redirection.
 * Description: 
 * Author: Sneha YC
 *---------------------------
 */

#include<stdio.h>

int main(int argc, char * argv[])
{
	int iNo1 = 0, iNo2 = 0;
	int iAns = 0;
	
	scanf("%d",&iNo1);
	scanf("%d",&iNo2);
	
	iAns = iNo1 + iNo2;
	
	printf("Addition is: %d\n",iAns);
	
	return 0;
}
