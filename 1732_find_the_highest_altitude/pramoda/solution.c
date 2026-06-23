#include <stdio.h>
#include <stdlib.h>

int largestAltitude(int* gain, int gainSize) {
    int max = gain[0];
    for (int i = 0; i < gainSize - 1; ++i) {
        gain[i + 1] += gain[i];
        if (gain[i + 1] > max) max = gain[i + 1];
    }

    return max > 0 ? max : 0;
}

int main() {
    int gain[] = {52,-91,72};
    printf("%d\n", largestAltitude(gain, 3));

    return 0;
}