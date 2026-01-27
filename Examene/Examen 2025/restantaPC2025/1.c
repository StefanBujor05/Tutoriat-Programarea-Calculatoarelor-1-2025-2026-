/// 216(10)=0000.0000.1101.1000(2)
/// -137(10)=1111.1111.0111.0111(2)
#include <stdio.h>

void print_binary(int n) {
    int num_bits = sizeof(int) * 8;
    for (int i = num_bits - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
        if (i % 4 == 0 && i != 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int a = 216;
    int b = -137;
    print_binary(a);
    print_binary(b);
    return 0;
}