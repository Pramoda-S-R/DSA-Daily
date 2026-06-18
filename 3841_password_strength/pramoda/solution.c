#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int passwordStrength(char* password) {
    bool seen[94] = {0};

    size_t size = strlen(password);
    int score = 0;
    for (size_t i = 0; i < size; ++i) {
        int diff = password[i] - '!';

        if (seen[diff]) continue;
        if (password[i] >= 'a' && password[i] <= 'z') score += 1;
        if (password[i] >= 'A' && password[i] <= 'Z') score += 2;
        if (password[i] >= '0' && password[i] <= '9') score += 3;
        switch (password[i]) {
        case '!':
        case '@':
        case '#':
        case '$':
            score += 5;
            break;
        default: break;
        }
        seen[diff] = true;;
    }

    return score;
}

int main() {

    printf("%d\n", passwordStrength("aA1!"));

    return 0;
}