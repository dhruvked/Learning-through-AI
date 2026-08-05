#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct CircularQueue
{
    int items[MAX];
    int front;
    int rear;
};

void initQueue(struct CircularQueue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Check if circular queue is full
int isFull(struct CircularQueue *q)
{
    return (q->rear + 1) % MAX == q->front;
}

// Check if circular queue is empty
int isEmpty(struct CircularQueue *q)
{
    return q->front == -1;
}

// Task 1: Enqueue using modulo arithmetic
void enqueue(struct CircularQueue *q, int value)
{
    // Write your code here!

    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }

    if (isEmpty(q) == 1)
    {
        q->front = 0;
        q->rear = 0;
        q->items[0] = value;
        return;
    }

    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}

// Task 2: Dequeue using modulo arithmetic
int dequeue(struct CircularQueue *q)
{
    if (isEmpty(q) == 1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) // 👈 Use double '=='
    {
        q->front = -1;
        q->rear = -1; // 👈 Assign = -1
        printf("Popped from front: %d\n", item);
        return item;
    }

    q->front = (q->front + 1) % MAX;
    printf("Popped from front: %d\n", item);
    return item;
}

// Task 3: Display all elements in circular order
void displayQueue(struct CircularQueue *q)
{
    // Write your code here!
    int counter = q->front;
    while (counter != q->rear)
    {
        printf("%d -> ", q->items[counter]);
        counter = (counter + 1) % MAX;
    }
    printf("%d -> linked to first element", q->items[counter]);
}

int main()
{
    struct CircularQueue q;
    initQueue(&q);

    // Challenge:
    // 1. Enqueue 10, 20, 30, 40.
    // 2. Dequeue 2 items (10 and 20 freed!).
    // 3. Enqueue 50 and 60 (reusing slots 0 and 1 via modulo!).
    // 4. Display queue.
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 50);
    enqueue(&q, 60);
    displayQueue(&q);

    return 0;
}
