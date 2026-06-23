#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minFromList(int list[], int size) {

    int min = list[0];
    for (int i = 1; i < size; i++) {
        if (list[i] < min) {
            min = list[i];
        }
    }
    return min;
}

int maxNumberOfBalloons(char* text) {

    int count[5] = {0};

    for (int i = 0; i < strlen(text); i++) {
        switch (text[i]) {
            case 'b': count[0]++; break;
            case 'a': count[1]++; break;
            case 'l': count[2]++; break;
            case 'o': count[3]++; break;
            case 'n': count[4]++; break;
        }
    }

    count[2] /= 2;
    count[3] /= 2;

    return minFromList(count, 5);
}

int main() {

    printf("%d\n", maxNumberOfBalloons("nlaebolko"));

    return 0;
}