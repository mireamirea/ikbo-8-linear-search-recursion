#include <stdio.h>

int MaxNumber(unsigned long int a){
    int max = 0;
    int residue = 0;
    while (a > 0){
        residue = a % 10;
        a = (a - residue) / 10;
        max = residue > max ? residue : max;
    }
    return max;
}

int main(){
    unsigned long int x = 1877860;
    int result = MaxNumber(x);
    printf ("%d\n", result);
    return 0;
}
