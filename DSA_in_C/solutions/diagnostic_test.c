/*
 * 🧪 DSA in C — Diagnostic Placement Test
 * 
 * Instructions:
 * Write your solutions for Questions 1 & 2 in C below.
 * You can compile and test them locally using gcc, or simply write your code here.
 */

#include <stdio.h>
#include <stdlib.h>

// ============================================================================
// QUESTION 1: Swap Two Integers Using Pointers
// Write a function `swap(int *a, int *b)` that swaps the values of two integers.
// ============================================================================
void swap(int *a, int *b) {
    // Write your code here
}


// ============================================================================
// QUESTION 2: Reverse an Array In-Place
// Write a function `reverse_array(int *arr, int size)` that reverses an array
// of integers in-place without allocating a new array.
// ============================================================================
void reverse_array(int *arr, int size) {
    // Write your code here
}


// ============================================================================
// Main function to test your implementations locally (optional)
// ============================================================================
int main() {
    printf("=== Testing Swap ===\n");
    int x = 10, y = 20;
    printf("Before: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After:  x = %d, y = %d\n\n", x, y);

    printf("=== Testing Reverse Array ===\n");
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    reverse_array(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
