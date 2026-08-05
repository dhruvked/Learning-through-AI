#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Stack {
    int items[MAX];
    int top;
};

// Initialize stack: set top = -1
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check if stack is full (top == MAX - 1)
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Check if stack is empty (top == -1)
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Task 1: Push item onto stack
void push(struct Stack *s, int value) {
    // Write your code here!
    if(isFull(s)==1){
        printf("Stack is full");
        return;
    }
    
    s->top=s->top+1;
    s->items[s->top]=value;
}

// Task 2: Pop item from stack (return popped value, or -1 if empty)
int pop(struct Stack *s) {
    // Write your code here!
    if(isEmpty(s)==1){
        printf("Stack is Empty");
        return -1;
    }

    s->top=s->top-1;
    printf("Pop:%d", s->items[s->top+1]);
    return s->items[s->top+1];
}

// Task 3: Peek top item (return top value without popping, or -1 if empty)
int peek(struct Stack *s) {
    if(isEmpty(s)==1){
        printf("Stack is Empty");
        return -1;
    }
    
    printf("Peek:%d", s->items[s->top]);
    return s->items[s->top];
}

int main() {
    struct Stack s;
    initStack(&s);

    // Challenge:
    // 1. Push 10, 20, 30 onto stack.
    // 2. Print peek(&s) (Expected: 30).
    // 3. Pop an item and print it (Expected: 30).
    // 4. Print peek(&s) (Expected: 20).
    // 5. Pop remaining items until empty.
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    peek(&s);
    while(s.top!=-1){
        pop(&s);
    }
    return 0;
}
