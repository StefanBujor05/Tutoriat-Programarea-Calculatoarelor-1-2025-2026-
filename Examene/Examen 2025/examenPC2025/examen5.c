#include<stdio.h>
#include<stdlib.h>

//functie care compara vectori
int compArray (void* arr1, void* arr2, size_t elemNum1, size_t elemNum2){

    if(elemNum1 != elemNum2) return -1;

    char* copy1 = (char*)arr1;
    char* copy2 = (char*)arr2;

    for(size_t i = 0; i < elemNum1; i++){
        if(copy1[i] != copy2[i])return -1;
    }
    return 1;
}


int main(){
    
    int arrayInt1[] = {-1, 1,2,3,4,5};
    int arrayInt2[] = {-1, 1,2,3,4,5};

    float arrayFloat1[] = {1.1, 2, 3,4};
    float arrayFloat2[] = {1.1, 2, 3,5};

    char arrayChar1[] = {'a', 'b'};
    char arrayChar2[] = {'a', 'b'};


    printf("%d ",compArray(arrayInt1, arrayInt2, sizeof(arrayInt1), sizeof(arrayInt2)));
    printf("%d ",compArray(arrayFloat2, arrayFloat1, sizeof(arrayFloat2), sizeof(arrayFloat1)));
    printf("%d  ",compArray(arrayChar1, arrayChar2, sizeof(arrayChar1), sizeof(arrayChar2)));
    return 0;
}

