#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev; // Pointer to previous node in RAM
    struct Node *next; // Pointer to next node in RAM
};

// Task 1: Insert node at front of Doubly Linked List
void insertAtHead(struct Node **headRef, int newData) {
    // Write your code here!
}

// Task 2: Print list forward (from Head to Tail)
void printForward(struct Node *head) {
    // Write your code here!
}

// Task 3: Print list backward (from Tail to Head)
void printBackward(struct Node *head) {
    // Write your code here!
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

int main() {
    struct Node *head = NULL;

    // Challenge:
    // 1. Insert 30, 20, 10 at head.
    // 2. Call printForward(head); (Expected: 10 <-> 20 <-> 30 <-> NULL)
    // 3. Call printBackward(head); (Expected: 30 <-> 20 <-> 10 <-> NULL)
    // 4. Free memory with freeList(&head).

    return 0;
}
