#include<stdio.h>

int* pos(void* array, void* x, int len, int dim, int (*comp)(const void*, const void*)){

    char *p = (char*)array; // float - 8 octeti, char - 1 octet
    for(int i = 0; i < len; i++){
        if(comp(x, p+i*dim)) return (void*)(p+i*dim);
    }
    return NULL;
}

int compInt(const void* a, const void* b){
    return *(int*)a == *(int*)b;
    // 1. void *a --> int* a
    // 2. &a --> valoarea la care pointeaza a
}

int compChar(const void* a, const void* b){
    return *(char*)a == *(char*)b;
}

int main(void){

    int array[] = {4, 2, 3, 6, 9};
    int len = 5;
    int x = 6;
    int *ptr = (int*)pos(array, &x, len, sizeof(int), compInt);
    printf("%d", ptr-array);
    return 0;
}