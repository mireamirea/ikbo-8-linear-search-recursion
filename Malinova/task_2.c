#include <stdio.h>

void reverse_flow(FILE *fileIn, FILE *fileOut){
    float str;
    if(feof(fileIn) == 0){
        fscanf(fileIn, "%f", &str);
        if(feof(fileIn) == 0){
            reverse_flow(fileIn, fileOut);
            fprintf(fileOut, "%f\n", str);
        }
    }
}

int main(){
    FILE *in;
    in = fopen("in.txt", "r");
    FILE *out;
    out = fopen("out.txt", "w");
    int i = 1;
    char filename[255];
    while(i!= 0){
        if (in == NULL){
            printf("File name: ");
            scanf("%s", filename);
            in = fopen(filename, "r");
        }
        else
            i = 0;
    }
    reverse_flow(in, out);
    fclose(in);
    fclose(out);
    return 0;
}
