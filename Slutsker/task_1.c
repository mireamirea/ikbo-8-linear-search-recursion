#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned long int number = 29284;
	short int result = getnumber(number);
	printf("MAX number is %d",result);
	return 0;
}


int getnumber(unsigned long int number)
{
	short int maxNumber = 0;
	short int result = 0;
	
	while (number >0)
	{
		result = number % 10;
		number -=result;
		number /= 10;
		maxNumber = maxNumber < result ? result:maxNumber;
	}
	return maxNumber;
}
