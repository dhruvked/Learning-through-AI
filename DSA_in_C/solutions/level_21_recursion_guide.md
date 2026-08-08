# 🔄 Level 21 Study Guide: Recursion & Call Stack Fundamentals

> **Goal**: Master how functions call themselves, base cases, and how the CPU Call Stack manages recursive frames.

---

## 💡 What is Recursion?

**Recursion** is a programming technique where a function **calls itself** to solve a smaller version of the exact same problem!

Every valid recursive function MUST have two parts:

1. **Base Case (The Stop Sign 🛑)**: The condition under which the function STOP calling itself and returns a result. (Prevents infinite recursion / Stack Overflow!).
2. **Recursive Step (The Reduction 🔄)**: Calling the function again with a **smaller input** (`n - 1` or `n / 2`).

---

## ⚙️ The CPU Call Stack (How Memory Executes Recursion)

When `factorial(3)` is called, the CPU pushes function call frames onto the **Call Stack**:

```text
  [ factorial(1) ] -> Returns 1  (🛑 Base Case Hit!)
  [ factorial(2) ] -> Waits for factorial(1) to return 1 -> Returns 2 * 1 = 2
  [ factorial(3) ] -> Waits for factorial(2) to return 2 -> Returns 3 * 2 = 6
```

---

## ❓ Interactive Concept Quiz

Answer these 3 questions right here in chat:

### Question 1:
What happens if a recursive function is missing a **Base Case**?
* A) It returns 0 automatically.
* B) It runs forever until the CPU Call Stack runs out of memory (**Stack Overflow**).
* C) It converts into a `for` loop.

---

### Question 2:
Look at this code:
```c
int sum(int n) {
    if (n <= 1) return 1; // Base case
    return n + sum(n - 1); // Recursive step
}
```
👉 **What is `sum(4)`?** ($4 + 3 + 2 + 1 = ?$)

---

### Question 3:
What is the **Time Complexity** of calculating `sum(n)` recursively? ($\mathcal{O}(1)$, $\mathcal{O}(N)$, or $\mathcal{O}(N^2)$?)
