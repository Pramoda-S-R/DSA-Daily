#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    while (s[i] != '\0') {
        if (isspace(s[i])) {
            i++;
            continue;
        }
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') sign = -1;
            i++;
        }
        if (!isdigit(s[i])) return 0;
        int num = 0;
        while (isdigit(s[i])) {
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (s[i] - '0') > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            };
            num = num * 10 + (s[i] - '0');
            i++;
        }
        return num * sign;
    }
    return 0;
}

int main() {

    printf("%d\n", myAtoi("42"));
    printf("%d\n", myAtoi("   -042"));
    printf("%d\n", myAtoi("1337c0d3"));
    printf("%d\n", myAtoi("0-1"));
    printf("%d\n", myAtoi("words and 987"));
    printf("%d\n", myAtoi("-+12"));
    printf("%d\n", myAtoi("-2147483648"));

    return 0;
}