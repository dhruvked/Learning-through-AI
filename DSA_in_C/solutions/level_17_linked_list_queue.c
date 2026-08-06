#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void initQueue(struct Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(struct Queue *q)
{
    return q->front == NULL;
}

// Task 1: Enqueue (Add node to the rear of the linked list)
void enqueue(struct Queue *q, int value)
{
    // Write your code here!
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = q->rear->next;
}

// Task 2: Dequeue (Remove node from the front of the linked list and return its value)
int dequeue(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Empty queue\n");
        return -1;
    }

    struct Node *temp = q->front;
    int val = temp->data; // 1. Save data FIRST

    q->front = q->front->next; // 2. Advance front

    if (q->front == NULL)
    { // 3. If queue became empty, reset rear!
        q->rear = NULL;
    }

    free(temp); // 4. NOW safely free!
    printf("Removed: %d\n", val);
    return val;
}

// Task 3: Display queue
void displayQueue(struct Queue *q)
{
    struct Node *temp = q->front;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Queue q;
    initQueue(&q);

    // Challenge:
    // 1. Enqueue 100, 200, 300.
    // 2. Display queue (Expected: 100 -> 200 -> 300 -> NULL).
    // 3. Dequeue 1 item (Expected popped: 100).
    // 4. Display queue (Expected: 200 -> 300 -> NULL).
    // 5. Dequeue remaining items.

    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    displayQueue(&q);
    dequeue(&q);
    displayQueue(&q);
    dequeue(&q);
    dequeue(&q);

    return 0;
}
