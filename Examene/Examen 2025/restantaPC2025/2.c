#include <stdio.h>

int main() {
    int n=3, m=4, x=1;int a[n][m], i, j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++) {
            a[i][j] = x;
            x++;
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
    i=2;
    for (j=0; j<m; j++)
        printf("%d ", *(*(a+i)+j));

    printf("\n%d %d", (*(a))[2], (*(a+1))[2]);
    return 0;
}