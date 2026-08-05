#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    // Challenge:
    // 1. Allocate 2 nodes ('head' and 'second') on the heap.
    // 2. Assign head->data = 10 and link head to second.
    // 3. Assign second->data = 20 and terminate the list with NULL.
    // 4. Print both node values using the head pointer.
    // 5. Free all allocated memory.

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));

    head->data=10;head->next=second;

    second->data=20; second->next=NULL;

    printf("%d\n%d\n", head->data, head->next->data);
    free(head->next);
    free(head);


    return 0;
}
