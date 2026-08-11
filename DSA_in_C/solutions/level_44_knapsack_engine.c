#include <stdio.h>
#include <stdlib.h>

// Helper function to return max of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Task 1: 0/1 Knapsack Engine in C using 2D DP Tabulation
int knapsack(int W, int wt[], int val[], int n)
{
    // Write your code here!
    int arr[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i][0] = 0;
    }

    for (int i = 0; i <= W; i++)
    {
        arr[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i] > j)
            {
                arr[i][j] = arr[i - 1][j];
            }
            else
            {
                arr[i][j] = max(arr[i - 1][j], val[i] + arr[i - 1][j - wt[i]]);
            }
        }
    }

    return arr[n][W];
}

int main()
{
    // Challenge:
    // N = 4 items
    // Knapsack Capacity W = 7 kg
    int val[] = {0, 1, 4, 5, 7}; // 1-indexed values (val[1]=1, val[2]=4, val[3]=5, val[4]=7)
    int wt[] = {0, 1, 3, 4, 5};  // 1-indexed weights (wt[1]=1, wt[2]=3, wt[3]=4, wt[4]=5)
    int n = 4;
    int W = 7;

    // Expected Output: Maximum Knapsack Value: 9
    // (Item 2: wt 3, val 4 + Item 3: wt 4, val 5 => total wt 7, total val 9)

    int maxVal = knapsack(W, wt, val, n);
    printf("Maximum Knapsack Value: %d\n", maxVal);

    return 0;
}
