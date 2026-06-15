#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// yes the custom stack implementation is required
typedef struct {
    int *arr;
    int size;
    int top;
} Stack;

Stack *new() {
    Stack *stack = malloc(sizeof(Stack));
    stack->arr = calloc(100, sizeof(int));
    stack->size = 100;
    stack->top = -1;
    return stack;
}

void push(Stack *stack, int val) {
    if (stack->top == stack->size - 1) {
        stack->size *= 2;
        stack->arr = realloc(stack->arr, stack->size * sizeof(int));
    }
    stack->arr[++stack->top] = val;
}

int pop(Stack *stack) {
    return stack->arr[stack->top--];
}

static inline int max_int(int a, int b) { return a > b ? a : b; }

int longestValidParentheses(char* s) {
    Stack *stack = new();
    int curr_len = 0;
    int max_len = 0;

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            push(stack, curr_len);
            curr_len = 0;
        }
        else if (stack->top < 0) {
            curr_len = 0;
        }
        else {
            curr_len += pop(stack) + 2;
            max_len = max_int(max_len, curr_len);
        }
    }

    return max_len;
}

int main() {

    printf("%d\n", longestValidParentheses("(())"));

    return 0;
}