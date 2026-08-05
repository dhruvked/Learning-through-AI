#include <stdio.h>
#include <stdlib.h>

int main() {
    // TASK 1: Allocate a dynamic array of 3 integers on the heap using malloc.
    int *arr = (int *)malloc(3 * sizeof(int));

    // Store values 10, 20, 30
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    // TASK 2: Resize the array to hold 5 integers using realloc!
    // Hint: arr = (int *)realloc(arr, 5 * sizeof(int));
    arr= (int *)realloc(arr, 5*sizeof(int));

    // TASK 3: Add values 40 and 50 to arr[3] and arr[4].
    arr[3]=40;arr[4]=50;
    // TASK 4: Print all 5 elements using a for loop.
    for(int i = 0; i<5;i++){
        printf("%d\n",arr[i]);
    }
    // TASK 5: Free the dynamic array using free(arr).
    free(arr);
    
    return 0;
}
