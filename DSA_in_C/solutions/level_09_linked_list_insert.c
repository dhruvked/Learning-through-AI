#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Write a function to insert a new node at the FRONT (Head) of the list
void insertAtHead(struct Node **headRef, int newData) {
    // Write your code here!
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;

    *headRef = newNode;
}

// Write a function to print the linked list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}



int main() {
    struct Node *head = NULL;

    // Challenge:
    // 1. Call insertAtHead(&head, 30);
    // 2. Call insertAtHead(&head, 20);
    // 3. Call insertAtHead(&head, 10);
    // 4. Call printList(head); (Expected output: 10 -> 20 -> 30 -> NULL)
    // 5. Free all allocated nodes.
    insertAtHead(&head, 30);
    insertAtHead(&head, 20);
    insertAtHead(&head, 10);
    printList(head);
    free(head->next->next);
    free(head->next);
    free(head);

    return 0;
}
