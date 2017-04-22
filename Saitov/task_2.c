#include <stdio.h>
#include <stdlib.h>

struct numbers {
    int** nums;
    int count;
};

void WriteInFile (int** nums, int count, FILE* output){
    int i=0;
    if(count>0){
            while(nums[count-1][i]){
        fputc(nums[count-1][i],output);
        i++;}
        WriteInFile(nums, count-1, output);

    }
}

FILE* openfile(FILE* file){
    char fname [50];
    while (file == NULL){
        printf(" Error opening file\n Enter a new filename or file path (Example: file.dat or C:\\\\Users\\\\Desktop\\\\file.dat):");
        scanf("%s", fname);
        file=fopen(fname, "rb");
    }
    return file;
}

struct numbers ReadNums (FILE* file){
    int i, count=0, end, tmp, prevsign=(int) NULL;
    int** nums=NULL;
    struct numbers array;

    nums=(int**) malloc (sizeof(int*));
    while(!feof(file)){
            i=0;
            end=0;
            nums[count]=(int*) malloc (sizeof(int));
    while (end!=1 && !feof(file)){
            nums[count][i] = fgetc(file);
            putchar (nums[count][i]);
        if(nums[count][i]!='\n' && nums[count][i]!='\0' && nums[count][i]!=' ' &&  !feof(file)) {
                end=0;
                i++;
         nums[count]=(int*) realloc (nums[count], sizeof(int)*(i+2));}
        else {
            tmp=nums[count][i];
                nums[count][i]=prevsign;
                prevsign=tmp;
            end=1;
        }
    }
        nums[count][i+1]=(int) NULL;
        count++;
        nums = (int**) realloc (nums , sizeof(int*) * (count+1));

    }
    array.nums=nums;
    array.count=count;
    return array;
}

int main (void){

    int i;
    struct numbers array;
    FILE *file=NULL, *output;
    file=fopen("file.txt", "rb");

    if(file == NULL)
    file=openfile(file);

    array=ReadNums(file);
    fclose(file);

    output=fopen("output.txt", "w");
    WriteInFile(array.nums, array.count, output);
    printf("\nFile is created!");

    for(i=0;i!=array.count;i++)
    free(array.nums[i]);
    free(array.nums);

        return 0;
}



