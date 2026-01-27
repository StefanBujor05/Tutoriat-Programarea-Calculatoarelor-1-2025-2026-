#include <stdio.h>
#include <stdarg.h>

int findMax(int n, ...) {
    va_list args;
    va_start(args, n);

    int maxVal = va_arg(args, int);

    for (int i = 1; i < n; i++) {
        int current = va_arg(args, int);
        if (current > maxVal) {
            maxVal = current;
        }
    }

    va_end(args);
    return maxVal;
}

int main() {
    int max1 = findMax(3, 10, 20, 5);
    printf("%d\n", max1);
    int max2 = findMax(5, 100, 42, 1, 500, -5);
    printf("%d\n", max2);
    return 0;
}