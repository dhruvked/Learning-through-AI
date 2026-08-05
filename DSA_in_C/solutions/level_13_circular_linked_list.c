#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Task 1: Insert node into Circular Linked List
void insertInCircular(struct Node **headRef, int newData) {
    // Write your code here!
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=newData;
    newNode->next=*headRef;

    if(*headRef==NULL){
        newNode->next=newNode;
        *headRef=newNode;
        return;
    }

    struct Node* i= *headRef;
    while(i->next!=*headRef){
        i=i->next;
    }
    i->next=newNode;
}

void printCircular(struct Node *head) {
    if (head == NULL) {
        printf("Empty List");
        return; // 
    }

    struct Node* fixed = head; 
    do {
        printf("%d\n", head->data); // 
        head = head->next;
    } while (head != fixed);
}

void freeCircular(struct Node **headRef) {
    if (*headRef == NULL) return;

    struct Node *head = *headRef;
    struct Node *current = head->next;
    struct Node *next;

    while (current != head) {
        next = current->next; // 1. Save next BEFORE freeing!
        free(current);        // 2. Free current node
        current = next;       // 3. Move forward
    }

    free(head);     // 4. Free head node
    *headRef = NULL; // 5. Set head to NULL safely
}

int main() {
    struct Node *head = NULL;

    // Challenge:
    // 1. Insert 30, 20, 10 into circular list.
    // 2. Call printCircular(head); (Expected output: 10 -> 20 -> 30 -> (back to 10))
    // 3. Free circular list.
    insertInCircular(&head, 30);
    insertInCircular(&head, 20);
    insertInCircular(&head, 10);

    printCircular(head);
    freeCircular(&head);
    return 0;
}
