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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy = {0, NULL};

    struct ListNode *tail = &dummy;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    tail->next = list1 ? list1 : list2;

    return dummy.next;
}

int main() {
    struct ListNode *l1nodes = malloc(3 * sizeof(struct ListNode));
    struct ListNode *l2nodes = malloc(3 * sizeof(struct ListNode));

    l1nodes[0].val = 1;
    l1nodes[0].next = &l1nodes[1];
    l1nodes[1].val = 2;
    l1nodes[1].next = &l1nodes[2];
    l1nodes[2].val = 4;
    l1nodes[2].next = NULL;

    l2nodes[0].val = 1;
    l2nodes[0].next = &l2nodes[1];
    l2nodes[1].val = 3;
    l2nodes[1].next = &l2nodes[2];
    l2nodes[2].val = 4;
    l2nodes[2].next = NULL;

    struct ListNode *list1 = &l1nodes[0];
    struct ListNode *list2 = &l2nodes[0];

    printf("List 1: "); node(list1); printf("\n");
    printf("List 2: "); node(list2); printf("\n");

    struct ListNode *merged = mergeTwoLists(list1, list2);

    printf("Merged: "); node(merged); printf("\n");

    free(l1nodes);
    free(l2nodes);

    return 0;
}