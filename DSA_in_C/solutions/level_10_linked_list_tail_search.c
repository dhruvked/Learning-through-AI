#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Task 1: Write a function to insert a node at the TAIL (end) of the list
void insertAtTail(struct Node **headRef, int newData) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=newData;
    newNode->next=NULL;

    if(*headRef==NULL){
        *headRef = newNode;
        return;
    }

    struct Node *last = *headRef;
    while(last->next!=NULL){last = last->next;}

    last->next=newNode;
}

// Task 2: Write a function to search for a target value in the list
// Return 1 if target exists, or 0 if not found.
int searchList(struct Node *head, int target) {
    while(head!=NULL){
        if(head->data==target){return 1;}head=head->next;
    }
    return 0;
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
        next = current->next; // 1. Remember next node
        free(current);        // 2. Free current node
        current = next;       // 3. Move to next node
    }
    
    *headRef = NULL; // 4. Set head in main() to NULL safely!
}

int main() {
    struct Node *head = NULL;

    // Challenge:
    // 1. Call insertAtTail(&head, 10);
    // 2. Call insertAtTail(&head, 20);
    // 3. Call insertAtTail(&head, 30);
    // 4. Call printList(head); (Expected output: 10 -> 20 -> 30 -> NULL)
    // 5. Test searchList(head, 20) -> should return 1 (Found).
    // 6. Test searchList(head, 99) -> should return 0 (Not Found).
    // 7. Free memory.
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    printList(head);
    searchList(head, 20);
    searchList(head, 99);
    freeList(&head);
    return 0;
}
