#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 10

int solutionCount = 0;

// Helper: Print N-Queens Board
void printBoard(int board[MAX_N][MAX_N], int N)
{
    printf("Solution #%d:\n", solutionCount);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
            {
                printf(" Q ");
            }
            else
            {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Task 1: Safety Check for placing a Queen at (row, col)
bool isSafe(int board[MAX_N][MAX_N], int row, int col, int N)
{
    // 1. Check vertical column above
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // 2. Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // 3. Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

// Task 2: Recursive Backtracking N-Queens Solver Engine
void solveNQueens(int board[MAX_N][MAX_N], int row, int N)
{
    // BASE CASE: All Queens placed!
    if (row >= N)
    {
        solutionCount++;      // 1. Count solution
        printBoard(board, N); // 2. Print board
        return;
    }
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col, N))
        {
            board[row][col] = 1;             // 👈 1. CHOOSE
            solveNQueens(board, row + 1, N); // 👈 2. EXPLORE
            board[row][col] = 0;             // 👈 3. UN-CHOOSE (Backtrack!)
        }
    }
}

int main()
{
    int N = 4; // 4-Queens Challenge
    int board[MAX_N][MAX_N] = {0};

    printf("===========================================\n");
    printf("      N-QUEENS BACKTRACKING SOLVER         \n");
    printf("===========================================\n\n");

    solutionCount = 0;
    solveNQueens(board, 0, N);

    printf("Total Solutions for N=%d: %d\n", N, solutionCount);

    return 0;
}
