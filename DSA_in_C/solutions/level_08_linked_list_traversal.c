#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Write your traversal function here!
void printList(struct Node *head) {
    // Write a while loop to traverse the list and print each node's data.
    while(head!=NULL){
        printf("%d", head->data);
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Challenge:
    // 1. Create a 3-node linked list (values: 100, 200, 300).
    // 2. Call printList(head) to print all 3 values.
    // 3. Free all 3 nodes properly.

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data=100;head->next=second;second->data=200;second->next=third;third->data=300;third->next=NULL;

    printList(head);
    // free(third);
    // free(second);
    // free(head);

    return 0;
}
