#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    return dividend / divisor;
}

int main() {
    
    printf("%d", divide(-2147483648, -1));

    return 0;
}