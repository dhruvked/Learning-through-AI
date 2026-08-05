#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue
{
    int items[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q)
{
    return q->rear == MAX - 1;
}

int isEmpty(struct Queue *q)
{
    return q->front == -1 || q->front > q->rear;
}

// Task 1: Enqueue (Add item to the rear of queue)
void enqueue(struct Queue *q, int value)
{
    if (isFull(q) == 1)
    {
        printf("Queue is full");
        return;
    }

    if (isEmpty(q) == 1)
    {
        q->front = 0;
    }
    q->rear = q->rear + 1;
    q->items[q->rear] = value;
}

// Task 2: Dequeue (Remove item from the front of queue and return it)
int dequeue(struct Queue *q)
{
    if (isEmpty(q) == 1)
    {
        printf("Empty Queue");
        return -1;
    }

    q->front = q->front + 1;
    printf("Popped from front: %d\n", q->items[q->front - 1]);
    return q->items[q->front - 1];
}

// Task 3: Get front item without dequeuing
int getFront(struct Queue *q)
{
    printf("Peek from front: %d\n", q->items[q->front]);
    return q->items[q->front];
}

int main()
{
    struct Queue q;
    initQueue(&q);

    // Challenge:
    // 1. Enqueue 10, 20, 30 into queue.
    // 2. Print getFront(&q) (Expected: 10).
    // 3. Dequeue an item and print it (Expected: 10).
    // 4. Print getFront(&q) (Expected: 20).
    // 5. Dequeue remaining items until empty.
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    getFront(&q);
    dequeue(&q);
    getFront(&q);
    dequeue(&q);
    dequeue(&q);
    return 0;
}
