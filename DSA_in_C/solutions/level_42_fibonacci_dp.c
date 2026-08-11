#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

// Array for Top-Down Memoization
long long memo[MAX_N];

// Task 1: Top-Down Memoized Fibonacci (O(N) Time)
long long fibMemo(int n)
{
    if (memo[n] != -1)
        return memo[n];

    if (n == 0 || n == 1)
        return n;

    memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
    return memo[n];
}

// Task 2: Bottom-Up Tabulated Fibonacci (O(N) Time, Iterative)
long long fibTab(int n)
{
    long long arr[MAX_N];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

int main()
{
    // Initialize memo array to -1
    for (int i = 0; i < MAX_N; i++)
    {
        memo[i] = -1;
    }

    // Challenge:
    // 1. Calculate fibMemo(45) -> Expected: 1134903170
    // 2. Calculate fibTab(50)  -> Expected: 12586269025

    printf("Memoized Fib(45): %lld\n", fibMemo(45));
    printf("Tabulated Fib(50): %lld\n", fibTab(50));

    return 0;
}
