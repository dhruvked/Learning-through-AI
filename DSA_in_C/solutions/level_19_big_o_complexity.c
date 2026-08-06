#include <stdio.h>

// Function 1: O(1) Constant Time
void func1(int n) {
    printf("Value: %d\n", n);
}

// Function 2: O(N) Linear Time
void func2(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

// Function 3: O(N^2) Quadratic Time
void func3(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function 4: O(log N) Logarithmic Time
void func4(int n) {
    for (int i = 1; i < n; i = i * 2) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    printf("func1 Time Complexity: O(1)\n");
    printf("func2 Time Complexity: O(N)\n");
    printf("func3 Time Complexity: O(N^2)\n");
    printf("func4 Time Complexity: O(log N)\n");
    return 0;
}
