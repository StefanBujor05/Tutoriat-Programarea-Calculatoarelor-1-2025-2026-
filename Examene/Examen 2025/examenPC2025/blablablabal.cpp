//
// Created by bujor on 11/3/2025.
//
#include<stdio.h>
#include <string.h>
char polinom[100];

int polinomFinal[200];
int grad = 0;
int main(){

    fgets(polinom, 100, stdin);

    for (int i = 0; i < strlen(polinom); i++) {
        char semn;
        int coef, putere;
        semn = polinom[i];
        i++;
        coef = polinom[i] - '0';
        i+=3;
        putere = polinom[i] - '0';
        if (semn == '-')coef*=(-1);
        polinomFinal[putere] = coef;

        grad++;
    }

    for (int i = 0; i < grad-1; i++) {
        printf("(%d *x^%d) +", polinomFinal[i], i);
    }


return 0;

}