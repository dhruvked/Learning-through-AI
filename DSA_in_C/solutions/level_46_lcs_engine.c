#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to return max of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Task 1: Longest Common Subsequence (LCS) Engine in C using 2D DP Tabulation
int lcs(char *S1, char *S2, int m, int n)
{
    int arr[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        arr[i][0] = 0;
    }

    for (int i = 0; i <= n; i++)
    {
        arr[0][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                arr[i][j] = 1 + arr[i - 1][j - 1];
            }
            else
            {
                arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
            }
        }
    }
    return arr[m][n];
}

int main()
{
    char S1[] = "AGGTAB";
    char S2[] = "GXTXAYB";
    int m = strlen(S1); // length = 6
    int n = strlen(S2); // length = 7

    // Expected Output: LCS Length: 4 (Subsequence: "GTAB")
    int lcsLen = lcs(S1, S2, m, n);
    printf("LCS Length: %d\n", lcsLen);

    return 0;
}
