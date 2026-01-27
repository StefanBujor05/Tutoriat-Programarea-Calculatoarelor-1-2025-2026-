#include <stdio.h>

int main() {
    int x = 10 >> 3 | (6 & 5), y = 3 << 2;
    printf("%d %d %d %d", x, y, x && y, x ^ y);
    return 0;
}