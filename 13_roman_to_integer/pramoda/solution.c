#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char* s) {
    //                            0,   1, 2, 3, 4, 5, 6, 7, 8,  9,   10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21
    static const int lut[22] = {100, 500, 0, 0, 0, 0, 1, 0, 0, 50, 1000,  0,  0,  0,  0,  0,  0,  0,  0,  5,  0, 10};

    int length = strlen(s);
    int num = 0;
    int last_num = 0;
    for (int i = length - 1; i >= 0; --i) {
        int n = lut[(s[i] - 'C')];
        num += (n < last_num) ? -n : n;
        last_num = n;
    }
    return num;
}

int main() {
    char s[100] = "MCMXCIV";
    printf("%d\n", romanToInt(s));
    return 0;
	
}
