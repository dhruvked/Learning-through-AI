# ⚡ Level 47 Study Guide: Greedy Algorithms (Activity Selection & Fractional Knapsack)

> **Goal**: Master **Greedy Algorithms** — the strategy of making the **locally optimal choice** at each step to find a global optimum!

---

## ⚡ What is a Greedy Algorithm?

A **Greedy Algorithm** builds a solution step-by-step by always choosing the option that looks **best right now** (locally optimal choice), without ever looking back or undoing past decisions!

### Greedy vs Dynamic Programming vs Backtracking:
* **Dynamic Programming**: Solves ALL subproblems and compares them (guaranteed optimal, but takes more memory).
* **Greedy**: Picks the single BEST choice at each step immediately! (Ultra fast, $O(N \log N)$ or $O(N)$!).

---

## 🎯 Example 1: Activity Selection Problem

Suppose you are booking a single conference room for $N = 6$ activities. Each activity has a **Start Time** and **Finish Time**.
Goal: Select the **maximum number of non-overlapping activities**!

```text
Activity:     A1    A2    A3    A4    A5    A6
Start Time:    1     3     0     5     8     5
Finish Time:   2     4     6     7     9     9
```

### The Greedy Choice Property:
> *"Always pick the activity that FINISHES EARLIEST!"*

### Why finish-time sorting works:
Finishing early leaves the **maximum possible remaining time** for future activities!

1. **Sort activities by Finish Time**: $A1 (2), A2 (4), A3 (6), A4 (7), A5 (9), A6 (9)$.
2. Select $A1$ (finishes at 2).
3. Next compatible activity is $A2$ (starts at 3 $\ge$ 2, finishes at 4).
4. Next compatible activity is $A4$ (starts at 5 $\ge$ 4, finishes at 7).
5. Next compatible activity is $A5$ (starts at 8 $\ge$ 7, finishes at 9).

Max Activities Selected: **4** ($A1, A2, A4, A5$) 🚀!

---

## 🎒 Example 2: Fractional Knapsack Problem

Unlike **0/1 Knapsack** (where items cannot be split), in **Fractional Knapsack**, you CAN break items into fractions! (e.g. Gold Dust, Flour, Oil).

### The Greedy Choice Property:
> *"Sort items by Value-to-Weight Ratio ($v_i / w_i$) in descending order!"*

```text
Item 1: W=10, V=60  => Ratio = $6/kg
Item 2: W=20, V=100 => Ratio = $5/kg
Item 3: W=30, V=120 => Ratio = $4/kg

Knapsack Capacity W = 50 kg
```

1. Take ALL of Item 1 ($10\text{ kg}$, value = $\$60$, remaining cap = $40\text{ kg}$).
2. Take ALL of Item 2 ($20\text{ kg}$, value = $\$100$, remaining cap = $20\text{ kg}$).
3. Take **Fraction ($20/30 = 2/3$)** of Item 3 ($20\text{ kg}$, value = $\$80$).

Total Value Stolen: $\$60 + \$100 + \$80 = \mathbf{\$240}$!

---

## 📊 Summary Comparison

| Algorithm Type | Decision Strategy | Guaranteed Optimal? | Time Complexity |
| :--- | :--- | :--- | :--- |
| **0/1 Knapsack (DP)** | Tries 2 choices (include/exclude) | YES ✅ | $O(N \times W)$ |
| **Fractional Knapsack (Greedy)** | Sorts by ratio ($v_i / w_i$) | YES ✅ | **$O(N \log N)$** 🚀 |
| **Activity Selection (Greedy)** | Sorts by Finish Time | YES ✅ | **$O(N \log N)$** 🚀 |

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
What is the core decision strategy of a **Greedy Algorithm**?
* A) Backtrack to undo past decisions.
* B) Make the locally optimal choice at each step without ever undoing it.
* C) Generate all subsets.

---

### Question 2:
In the **Activity Selection Problem**, by which property MUST you sort activities to maximize the number of non-overlapping activities?
* A) Ascending order of Start Time.
* B) Ascending order of Finish Time (earliest finish first).
* C) Descending order of Activity Duration.

---

### Question 3:
Why can the **Fractional Knapsack Problem** be solved using a Greedy Algorithm, whereas the **0/1 Knapsack Problem** requires Dynamic Programming?
* A) Because items in Fractional Knapsack can be split into fractions, allowing us to greedily pack highest value-per-kg items first without leaving empty space gaps.
* B) Fractional Knapsack only works with 2 items.
* C) 0/1 Knapsack uses strings.
