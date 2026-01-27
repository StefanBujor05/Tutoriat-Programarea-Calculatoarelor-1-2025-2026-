#include <stdio.h>

#define MACRODEF_1(x) x + 2*(x)
#define MACRODEF_2(x) (x + 2*x)

int main() { 
    int x;

    x=1; 
    int y1 = MACRODEF_1(2*x); 
    printf ("%d %d \n", y1, x);

    x=2; 
    int y2 = MACRODEF_1(x-1); 
    printf ("%d %d \n", y2, x);

    x=3; 
    int y3 = MACRODEF_1(x++); 
    printf ("%d %d \n", y3, x);

    x=4; 
    int y4 = MACRODEF_2(x+3); 
    printf ("%d %d \n", y4, x);

    x=5; 
    int y5 = MACRODEF_2(x++); 
    printf ("%d %d \n", y5, x);
}