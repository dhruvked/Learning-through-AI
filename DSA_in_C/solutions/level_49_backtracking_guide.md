# 👑 Level 49 Study Guide: Backtracking Intro & N-Queens Problem

> **Goal**: Master **Backtracking** — the systematic technique for exploring all possible solution branches by **trying a choice, exploring deeper recursively, and UNDOING the choice** when a dead-end is reached!

---

## 👑 What is Backtracking?

**Backtracking** is an algorithmic technique for solving constraint-satisfaction problems (like Sudoku, N-Queens, Maze solving, and Subsets).

### The Golden 3-Step Framework of Backtracking:
1. **Choose**: Make a tentative placement/decision (e.g. place a Queen in `board[row][col] = 1`).
2. **Explore**: Recurse deeper to solve the remaining problem (`solveNQueens(board, row + 1)`).
3. **Un-choose (Backtrack)**: If the recursive path hit a dead end, **UNDO the decision** (`board[row][col] = 0`) so other choices can be tried!

---

## 👸 The N-Queens Problem

Place $N$ Queens on an $N \times N$ chessboard such that **no two queens attack each other**!
Recall: A queen can attack horizontally, vertically, and diagonally in any direction!

```text
4-Queens Solution Example:

.  Q  .  .   (Row 0, Col 1)
.  .  .  Q   (Row 1, Col 3)
Q  .  .  .   (Row 2, Col 0)
.  .  Q  .   (Row 3, Col 2)
```

---

## 🛡️ The `isSafe` Conflict Check

Because we place **one Queen per Row** (`row` goes from `0` to `N-1`), we NEVER have horizontal conflicts!
We only need to check 3 directions above the current cell `(row, col)`:

1. **Vertical Column Check** (Straight up): Check if any queen is in the same `col` in preceding rows.
2. **Upper-Left Diagonal Check** (`row - 1, col - 1`): Move up and left until off the board.
3. **Upper-Right Diagonal Check** (`row - 1, col + 1`): Move up and right until off the board.

```c
bool isSafe(int board[N][N], int row, int col) {
    // 1. Check vertical column above
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1) return false;

    // 2. Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;

    // 3. Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1) return false;

    return true;
}
```

---

## 🔄 Backtracking Code Pattern

```c
bool solveNQueens(int board[N][N], int row) {
    // BASE CASE: All Queens placed successfully!
    if (row >= N) return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; // 1. CHOOSE

            if (solveNQueens(board, row + 1)) // 2. EXPLORE
                return true;

            board[row][col] = 0; // 3. UN-CHOOSE (BACKTRACK)
        }
    }

    return false; // Dead-end reached
}
```

---

## 📊 Summary Comparison

| Algorithm Strategy | Approach | Typical Time Complexity |
| :--- | :--- | :--- |
| **Dynamic Programming** | Caches overlapping subproblems | $O(N \times W)$ or $O(N^2)$ |
| **Greedy** | Picks single best choice at each step | $O(N \log N)$ |
| **Backtracking** | Explores branches & UNDOES bad paths | **$O(N!)$** (Prunes invalid paths!) |

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
What is the defining 3rd step of **Backtracking** that distinguishes it from basic recursion?
* A) Terminating the main program.
* B) Un-choosing / Undoing the choice (`board[row][col] = 0`) when a dead-end is reached so other paths can be tried.
* C) Sorting the array.

---

### Question 2:
In the N-Queens `isSafe()` function, why do we ONLY need to check the column and upper diagonals above `row`?
* A) Because Queens can only attack downwards.
* B) Because we place Queens row-by-row from top to bottom, so no Queens exist in rows below `row` yet!
* C) Because diagonal moves are illegal.

---

### Question 3:
What is the minimum board size $N$ for which the N-Queens problem has a valid solution?
* A) $N = 1$ and $N \ge 4$ (For $N=2$ and $N=3$, no valid placement exists!).
* B) $N = 2$.
* C) $N = 3$.
