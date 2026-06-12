#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    if (s == NULL || strlen(s) == 0) {
        char *res = (char *)malloc(1);
        res[0] = '\0';
        return res;
    }

    int n = strlen(s);

    // Transform string: "abba" -> "^#a#b#b#a#$"
    int tLen = 2 * n + 3;
    char *T = (char *)malloc(tLen);

    T[0] = '^';
    for (int i = 0; i < n; i++) {
        T[2 * i + 1] = '#';
        T[2 * i + 2] = s[i];
    }
    T[2 * n + 1] = '#';
    T[2 * n + 2] = '$';

    int *P = (int *)calloc(tLen, sizeof(int));

    int center = 0, right = 0;
    int maxLen = 0, centerIndex = 0;

    for (int i = 1; i < tLen - 1; i++) {
        int mirror = 2 * center - i;

        if (i < right)
            P[i] = (right - i < P[mirror]) ? (right - i) : P[mirror];

        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;

        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }

        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;

    char *result = (char *)malloc(maxLen + 1);
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    free(T);
    free(P);

    return result;
}

int main() {
    char s[] = "babad";

    char *ans = longestPalindrome(s);

    printf("Longest Palindromic Substring: %s\n", ans);

    free(ans);

    return 0;
}