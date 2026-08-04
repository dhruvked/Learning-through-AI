#include <stdio.h>

int main() {
    int val = 42;
    int *ptr = &val; // Pointer 'ptr' holds the memory address of 'val'

    // TASK 1: Print the value of 'val' directly (using val).
    printf("%d\n",val);
    // TASK 2: Print the value of 'val' INDIRECTLY through 'ptr' (using dereferencing '*').
    printf("%d\n",*ptr);
    
    
    *ptr=100;
    // TASK 3: Change the value of 'val' to 100 by assigning through '*ptr'!
    printf("%d",*ptr);

    printf("Updated val: %d\n", val);

    return 0;
}
