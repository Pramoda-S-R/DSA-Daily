#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int catalan(int n) {
    long long c = 1;

    for (int i = 0; i < n; i++) {
        c = c * (2 * n - i) / (i + 1);
    }

    return c / (n + 1);
}

void backtrack(int open_count, int closed_count, int n, char* path, char** res, int* returnSize) {
    if (open_count == n && closed_count == n) {
        res[(*returnSize)++] = strdup(path);
        return;
    }
    if (open_count < n) {
        path[open_count + closed_count] = '(';
        backtrack(open_count + 1, closed_count, n, path, res, returnSize);
    }
    if (closed_count < open_count) {
        path[open_count + closed_count] = ')';
        backtrack(open_count, closed_count + 1, n, path, res, returnSize);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int catalan_n = catalan(n);
    char** res = calloc(catalan_n, sizeof(char*));
    char* path = calloc((n * 2) + 1, sizeof(char));
    *returnSize = 0;

    backtrack(0, 0, n, path, res, returnSize);

    free(path);
    return res;
}

int main() {

    int n = 8;
    int returnSize = 0;
    char** res = generateParenthesis(n, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", res[i]);
        free(res[i]);
    }

    printf("%d\n", catalan(8));

    free(res);
    return 0;
}