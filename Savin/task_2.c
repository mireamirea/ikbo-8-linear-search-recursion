#include <stdio.h>
#include <stdlib.h>



#define INIT_SIZE 5
#define INCREASE 3


void recursion (float * array, int i);


FILE * fp;



int main () {
	
	float * array;
	int i = 0, size = INIT_SIZE;
	
	
	array = (float *)malloc(size * sizeof(float));
	
	
	/* Errors cheking */
	
	if ((fp = fopen("Initial data.txt", "r")) == NULL) {
		
        printf("Error\n");
        return 0;
    }
	
	
	/* Reading file */
	
	while (!feof(fp)) {
		
		fscanf(fp, "%f", &array[i]);
		printf("%.2f \n", array[i]);
		i++;
		
		
		/* Resize */
		
		if (i == size) {
			
			size += INCREASE;
			array = realloc(array, size * sizeof(float));
			
		}
	
	
	}
	
	
	fclose(fp);
	
	
	/* Recursion of write in file */
	
	fp = fopen("Final data.txt", "w");
	recursion(array, i - 1);
	
	
	/* Freeing of memory */
	
	fclose(fp);
	free(array);
	
	
	return 0;
}



void recursion(float * array, int i) {	
	
	
	fprintf(fp, "%.2f \n", array[i]);
	i--;
	
	if (i >= 0) {
	
		recursion(array, i);
	}

}



