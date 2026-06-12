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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy = {0, head};

    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummy.next;
}

int main() {
    struct ListNode *nodes = malloc(5 * sizeof(struct ListNode));

    for (int i = 0; i < 5; i++) {
        nodes[i].val = i + 1;
        nodes[i].next = (i < 4) ? &nodes[i + 1] : NULL;
    }

    struct ListNode *head = &nodes[0];
    
    printf("Before removal:\n");
    node(head);
    printf("\n");
    
    head = removeNthFromEnd(head, 2);
    
    printf("After removal:\n");
    node(head);
    printf("\n");

    free(nodes);

    return 0;
}