#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void rek(FILE *out , char **str, int n);


int main()
{
    FILE *in = fopen("C:\\proekti\\recursia\\zad2\\zad2.txt", "r");
    char **str, tmp[255];
    
	int n = 0,i,j=0,max=255;
    
    str = (char**)malloc(max*sizeof(char*));
 	for(i=0;i<max;i++){
 		str[i]=(char*)malloc(255*sizeof(char));
	}
    
	while (!feof(in))
    {
        fgets(str[j],255,in);
        n++;
        
        printf("%s",str[j]);
        j++;
    }
	
	 	
 	n--;
 	
    FILE *out = fopen("C:\\proekti\\recursia\\zad2\\zad2w.txt" , "w");
    
   	rek(out , str , n);

    return 0;
}
    

void rek(FILE *out ,char **str,int n){
	
	
	if (n < 0)
	{
		return ;
	}
	
	else{
		fputs(str[n] , out);
		fputs("\n", out);
		n--;
		rek(out ,str , n);
	}
		
}


