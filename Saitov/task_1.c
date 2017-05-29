#include <stdio.h>

int findMax (int a, int t){
if (a>0){
int residue=a % 10;
a=(a-residue)/10;
if (residue>t) t=residue;
return (findMax(a, t));
}
   else return t;
}

int main()
{
int a=228;
printf("The largest figure in the number:%d", findMax(a, 0));
    return 0;
}
