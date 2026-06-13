#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

void node(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode dummy = {0, NULL};
    dummy.next = head;

    struct ListNode *prev_left = &dummy;

    for (int i = 0; i < left - 1; ++i) {
        prev_left = prev_left->next;
    }

    struct ListNode *current = prev_left->next;
    struct ListNode *prev = NULL;

    for (int i = 0; i < (right - left + 1); ++i) {
        struct ListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    prev_left->next->next = current;
    prev_left->next = prev;

    return dummy.next;
}

int main() {
    struct ListNode *nodes = malloc(5 * sizeof(struct ListNode));

    for (int i = 0; i < 5; ++i) {
        nodes[i].val = i + 1;
        nodes[i].next = (i < 4) ? &nodes[i + 1] : NULL;
    }

    printf("BEFORE:\n");
    node(&nodes[0]);
    printf("\n");

    nodes[0] = *(reverseBetween(&nodes[0], 2, 4));

    printf("AFTER:\n");
    node(&nodes[0]);
    printf("\n");

    return 0;
}