#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtTail(struct Node **headRef, int newData) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct Node *last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct Node **headRef) {
    struct Node *current = *headRef;
    struct Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

// Task: Write a function to delete the FIRST node containing 'key'
void deleteNode(struct Node **headRef, int key) {
    if (*headRef == NULL) return; // 1. Empty list check

    struct Node *i = *headRef;

    // 2. Case 1: Head node contains the key
    if (i->data == key) {
        *headRef = i->next; // Move head to 2nd node
        free(i);            // Free old head
        return;
    }

    // 3. Case 2: Key is in middle or tail node
    struct Node *prev = NULL;
    while (i != NULL) {
        if (i->data == key) {
            prev->next = i->next; // Bypass node i
            free(i);              // Free node i from RAM!
            return;
        }
        prev = i;
        i = i->next;
    }
}
int main() {
    struct Node *head = NULL;

    // Build list: 10 -> 20 -> 30 -> 40 -> NULL
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);

    printf("Original list: ");
    printList(head);

    // Challenge:
    // 1. Delete node with value 20.
    // 2. Print list (Expected: 10 -> 30 -> 40 -> NULL).
    // 3. Delete head node (value 10).
    // 4. Print list (Expected: 30 -> 40 -> NULL).
    // 5. Free list.
    deleteNode(&head, 20);
    printList(head);
    deleteNode(&head, 10);
    printList(head);
    freeList(&head);
    return 0;
}
