#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

int suma(int n, ...){
    va_list lista;
    va_start(lista, n);

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum+=va_arg(lista, int);
    }
    va_end(lista);
    return sum;
}

int main(){

    int a = suma(5, 1, 3, 5, 7, 9); //A B C D E F G
    printf("%d ", a);
    return 0;
}