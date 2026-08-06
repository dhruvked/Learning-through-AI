#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Task 1: Push item onto Linked List Stack (Insert at Head!)
void push(struct Node **topRef, int value)
{
    // Write your code here!
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = *topRef;
    *topRef = newNode;
}

// Task 2: Pop item from Linked List Stack (Delete from Head & return value!)
int pop(struct Node **topRef)
{
    // Write your code here!
    if (*topRef == NULL)
    {
        printf("Empty Stack\n");
        return -1;
    }

    struct Node *temp = *topRef;
    int val = temp->data;
    *topRef = (*topRef)->next;
    free(temp);

    printf("Freed element: %d\n", val);
    return val;
}

// Task 3: Peek top item
int peek(struct Node *top)
{
    if (top == NULL)
    {
        printf("Empty Stack\n");
        return -1;
    }
    printf("Peek: %d\n", top->data);
    return top->data;
}

int isEmpty(struct Node *top)
{
    return top == NULL;
}

int main()
{
    struct Node *top = NULL;

    // Challenge:
    // 1. Push 10, 20, 30 onto stack.
    // 2. Print peek(top) (Expected: 30).
    // 3. Pop item and print (Expected: 30).
    // 4. Print peek(top) (Expected: 20).
    // 5. Pop remaining items.
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    peek(top);
    pop(&top);
    peek(top);
    pop(&top);
    pop(&top);
    return 0;
}
