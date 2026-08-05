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
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=newData;
    newNode->next=NULL;
    newNode->prev=NULL;

    if(*headRef==NULL){
        *headRef=newNode;
        return;
    }

    newNode->next=*headRef;
    (*headRef)->prev = newNode;
    *headRef=newNode;
}

// Task 2: Print list forward (from Head to Tail)
void printForward(struct Node *head) {
    // Write your code here!
    if(head==NULL){
        printf("Empty List");
    }

    while(head!=NULL){
        printf("%d\n", head->data);
        head=head->next;
    }
}

// Task 3: Print list backward (from Tail to Head)
void printBackward(struct Node *head) {
    // Write your code here!
    if(head==NULL){
        printf("Empty List");
    }

    while(head->next!=NULL){
        head=head->next;
    }
    while(head!=NULL){
        printf("%d\n", head->data);
        head=head->prev;
    }
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
    insertAtHead(&head, 30);
    insertAtHead(&head, 20);
    insertAtHead(&head, 10);
    printForward(head);
    printBackward(head);
    freeList(&head);
    return 0;
}
