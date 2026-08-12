# 🧬 Level 45 Study Guide: Longest Common Subsequence (LCS)

> **Goal**: Master **Longest Common Subsequence (LCS)** — the foundational algorithm behind `git diff`, DNA sequence comparison, and spell checkers!

---

## 🧬 What is a Subsequence?

A **Subsequence** is a sequence derived by deleting 0 or more characters from a string **without changing the relative order** of the remaining characters.

### Example:
String: `"ABCDE"`
* Subsequences: `"ACE"`, `"ABD"`, `"BDE"`, `"ABCDE"`.
* NOT Subsequences: `"CA"` (order reversed!), `"ED"`.

---

## 💥 The LCS Problem Scenario

Given two strings $S1$ and $S2$, find the **length of their longest common subsequence**.

### Example:
* $S1 =$ `"AGGTAB"`
* $S2 =$ `"GXTXAYB"`

The longest common sequence present in both is **`"GTAB"`**, so the LCS Length is **4**!

---

## ⚙️ The 2D DP State Transitions (`dp[i][j]`)

Let `dp[i][j]` be the LCS length of substring $S1[0..i-1]$ and $S2[0..j-1]$:

### 1. MATCH CASE ($S1[i-1] == S2[j-1]$) 🎯
The current characters match! Add 1 to the diagonal parent:
$$\text{dp}[i][j] = 1 + \text{dp}[i-1][j-1]$$

### 2. MISMATCH CASE ($S1[i-1] \neq S2[j-1]$) ❌
The characters don't match! Take the maximum between ignoring the character from $S1$ OR ignoring the character from $S2$:
$$\text{dp}[i][j] = \max\Big(\text{dp}[i-1][j], \;\; \text{dp}[i][j-1]\Big)$$

---

## 🖼️ 2D DP Table Visual Trace

$S1 =$ `"ABCD"`, $S2 =$ `"ACBD"`:

```text
       ""   A   C   B   D
""   [  0,  0,  0,  0,  0 ]
A    [  0,  1,  1,  1,  1 ]  (Match 'A'!)
B    [  0,  1,  1,  2,  2 ]  (Match 'B'!)
C    [  0,  1,  2,  2,  2 ]  (Match 'C'!)
D    [  0,  1,  2,  2,  3 ]  (Match 'D'!)
```

LCS Length sitting at `dp[4][4]` is **3** (`"ABD"` or `"ACD"`).

---

## 📊 Complexity Comparison

| Approach | Strategy | Time Complexity | Space Complexity |
| :--- | :--- | :--- | :--- |
| **Naive Recursion** | Checks all $2^N$ subsequences | **O(2^(m+n))** 🐢 | O(m + n) |
| **2D DP Tabulation** | Fills $m \times n$ table | **O(m * n)** 🚀 | **O(m * n)** |

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
What is the difference between a Substring and a Subsequence?
* A) A Substring must be contiguous (consecutive characters), whereas a Subsequence can skip characters as long as relative order is maintained.
* B) Subsequences are always backwards.
* C) They are identical.

---

### Question 2:
When comparing character $S1[i-1]$ and $S2[j-1]$ in LCS, what formula do you use when the characters **MATCH** ($S1[i-1] == S2[j-1]$)?
* A) `dp[i][j] = dp[i-1][j-1]`
* B) `dp[i][j] = 1 + dp[i-1][j-1]`
* C) `dp[i][j] = 0`

---

### Question 3:
When characters **DO NOT MATCH** ($S1[i-1] \neq S2[j-1]$), how does LCS handle the transition?
* A) `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`
* B) Reset table to 0.
* C) Multiply by 2.
