//Bujor Stefan 2/7/2025 xoxo
#include<stdio.h>
#include<stdlib.h>

int **matrix(int n){ //n x n
    //matricea m
    //alocam n linii
    int **m = (int**)malloc(n*sizeof(int));

    for(int i = 0; i<n; i++){
        //m[i] = (int*)calloc((n-i), sizeof(int));
        m[i] = (int*)malloc((n-i) * sizeof(int));
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-i; j++){
            if(j == 0)m[i][j] = i+1;
            else m[i][j] = j * m[i][j-1];
        }
    printf("\n");
    
    }
    return m;
}

int main(){

    int n;
    scanf("%d", &n);
    int **m = matrix(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-i; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}