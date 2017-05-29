#include <stdio.h>
#include <stdlib.h>



int maxNum (unsigned long long int a);



int main () {
	
	unsigned long long int a, max;
	
	
	printf("Enter the number: \n");
	scanf("%lld", &a);
	
	max =  maxNum(a);
	
	printf("max =  %d", max);
	
	
	return 0;
}



int maxNum (unsigned long long int a) {
	
	unsigned long long int ten = 10;
	int k = 0, max = 0;
	
	while (k == 0) {
		
		if (max < a%ten * 10 / ten ) {
			
			max = a%ten * 10 / ten;
		}
		
 		ten *= 10;
		
		
		/* Exit from cycle */
		
		if (a / (ten/10) == 0) {
			
			k = 1;
		}
		
		
	}
	
	
	return max;
}



