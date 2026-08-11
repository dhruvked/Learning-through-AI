# 🎒 Level 43 Study Guide: 0/1 Knapsack Problem (Classic DP)

> **Goal**: Master the #1 most asked Dynamic Programming interview question: **The 0/1 Knapsack Problem**!

---

## 🎒 The Problem Scenario

You are a thief breaking into a vault with a knapsack of max capacity **$W = 7\text{ kg}$**.

There are $N = 4$ items available:
* **Item 1**: Weight = $1\text{ kg}$, Value = $\$1$
* **Item 2**: Weight = $3\text{ kg}$, Value = $\$4$
* **Item 3**: Weight = $4\text{ kg}$, Value = $\$5$
* **Item 4**: Weight = $5\text{ kg}$, Value = $\$7$

**Rules**:
* **0/1**: You cannot take a fraction of an item! You either **TAKE IT (1)** or **LEAVE IT (0)**.
* **Goal**: Maximize total value without exceeding capacity $W$.

---

## ⚖️ The 0/1 Decision Logic

For every item $i$ with weight $w_i$ and value $v_i$, sitting with remaining capacity $w$:

### Case 1: Item is TOO HEAVY ($w_i > w$)
* You CANNOT take it. You must **Exclude** it:
$$\text{dp}[i][w] = \text{dp}[i-1][w]$$

### Case 2: Item FITS ($w_i \le w$)
You have 2 choices. Pick the **MAXIMUM** value between them:
1. **Exclude Item $i$**: Take value from $\text{dp}[i-1][w]$.
2. **Include Item $i$**: Gain value $v_i$ + optimal value of remaining capacity $\text{dp}[i-1][w - w_i]$.

$$\text{dp}[i][w] = \max\Big(\text{dp}[i-1][w], \;\; v_i + \text{dp}[i-1][w - w_i]\Big)$$

---

## 📊 The 2D DP Table (`dp[i][w]`)

Rows represent items $0..N$, Columns represent capacity $0..W$:

```text
Item \ Cap  0   1   2   3   4   5   6   7
-----------------------------------------
Item 0     0   0   0   0   0   0   0   0
Item 1     0   1   1   1   1   1   1   1   (W=1, V=1)
Item 2     0   1   1   4   5   5   5   5   (W=3, V=4)
Item 3     0   1   1   4   5   6   6   9   (W=4, V=5)
Item 4     0   1   1   4   5   7   8   9   (W=5, V=7)
```

Notice: At `dp[4][7]`, the optimal max value is **$9** (Item 2 + Item 3 = $3+4 = 7\text{ kg}$, Value = $4+5 = \$9$).

---

## ⚡ Performance Summary

| Approach | Strategy | Time Complexity | Space Complexity |
| :--- | :--- | :--- | :--- |
| **Naive Recursion** | Explores all $2^N$ subsets | **O(2^N)** 🐢 | O(N) |
| **2D DP Tabulation** | Fills $N \times W$ grid | **O(N * W)** 🚀 | **O(N * W)** |

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
What does **"0/1"** stand for in the 0/1 Knapsack Problem?
* A) Floating point weights only.
* B) Binary choice: You either take an item completely (1) or leave it completely (0).
* C) Binary Search.

---

### Question 2:
If item $i$ has weight $w_i = 5\text{ kg}$ and remaining knapsack capacity is $w = 3\text{ kg}$, what option MUST you choose?
* A) Include it anyway.
* B) Exclude it (because $w_i > w$) and take the optimal value from `dp[i-1][w]`.
* C) Cut item $i$ in half.

---

### Question 3:
What is the time complexity of 2D DP Tabulation for the 0/1 Knapsack Problem with $N$ items and capacity $W$?
* A) O(N * W)
* B) O(2^N)
* C) O(N log N)
