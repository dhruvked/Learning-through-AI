#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

void initQueue(struct Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(struct Queue *q) {
    return q->front == NULL;
}

// Task 1: Enqueue (Add node to the rear of the linked list)
void enqueue(struct Queue *q, int value) {
    // Write your code here!
}

// Task 2: Dequeue (Remove node from the front of the linked list and return its value)
int dequeue(struct Queue *q) {
    // Write your code here!
    return -1;
}

// Task 3: Display queue
void displayQueue(struct Queue *q) {
    struct Node *temp = q->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    // Challenge:
    // 1. Enqueue 100, 200, 300.
    // 2. Display queue (Expected: 100 -> 200 -> 300 -> NULL).
    // 3. Dequeue 1 item (Expected popped: 100).
    // 4. Display queue (Expected: 200 -> 300 -> NULL).
    // 5. Dequeue remaining items.

    return 0;
}
