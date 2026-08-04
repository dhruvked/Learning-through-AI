#include <stdio.h>
#include <stdlib.h> // Needed for malloc() and free()

// Define a custom Student data structure
struct Student {
    int id;
    int score;
};

int main() {
    // TASK 1: Allocate memory on the heap for ONE Student struct using malloc.
    // Hint: struct Student *s = (struct Student *)malloc(sizeof(struct Student));
    struct Student *s = (struct Student *)malloc(sizeof(struct Student));

    // TASK 2: Set student id to 101 and score to 95 using arrow operator (->).
    // Write your code here!

    // TASK 3: Print student id and score.
    
    // TASK 4: Free the allocated memory using free(s).
    
    return 0;
}
