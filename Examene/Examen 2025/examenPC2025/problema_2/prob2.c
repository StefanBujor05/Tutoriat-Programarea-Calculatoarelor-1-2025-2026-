#include<stdio.h>
#include<stdlib.h>

int main(){

    char nume_fisier[15] = "file2.txt";
    //scanf("%s", &nume_fisier);

    FILE* fptr = fopen(nume_fisier, "r");
    if(fptr == NULL){
        perror("file 1 not found!");
        exit(0);
    }

    FILE* fptr_out = fopen("output_2.txt", "w+");
    if(fptr_out == NULL){
        perror("file not created!");
        exit(0);
    }

    char c;

    while((c = fgetc(fptr)) != EOF){
        if(c >= '0' && c <= '9'){
            fprintf(fptr_out, "%c, %d\n", c, c);
            printf("yup ");
        }
    }


    fclose(fptr);
    fclose(fptr_out);
    return 0;
}