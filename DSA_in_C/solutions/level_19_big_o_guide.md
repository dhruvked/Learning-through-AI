# ⏱️ Level 19 Study Guide: Big-O Time & Space Complexity

> **Goal**: Understand how code performance scales as input size $N$ grows from $10$ to $1,000,000$.

---

## 📊 What is Big-O Notation?

Big-O Notation describes the **worst-case scenario** for how much **Time** (number of execution steps) or **Space** (memory allocated) an algorithm needs relative to the size of the input $N$.

---

## 🚀 The 4 Main Time Complexities (Fastest to Slowest)

### 1. $\mathcal{O}(1)$ — Constant Time ⚡ (Fastest)
* **What it means**: Execution time is **always identical**, regardless of whether $N = 10$ or $N = 10,000,000$.
* **Pattern**: No loops! Direct variable assignments, math calculations, array index lookups, stack `push`/`pop`.
* **Example**:
  ```c
  int getFirstElement(int arr[], int n) {
      return arr[0]; // Always takes 1 step!
  }
  ```

---

### 2. $\mathcal{O}(\log N)$ — Logarithmic Time 📈 (Very Fast)
* **What it means**: Every time the loop runs, the problem size is **halved** (or multiplied by 2).
* **Pattern**: Loop counter is multiplied or divided by 2 (`i = i * 2` or `n = n / 2`).
* **Example**:
  ```c
  void binarySearchEffect(int n) {
      for (int i = 1; i < n; i = i * 2) {
          printf("%d ", i); // For N=16, runs only 4 times! (2^4 = 16)
      }
  }
  ```

---

### 3. $\mathcal{O}(N)$ — Linear Time 🚶‍♂️ (Fair / Standard)
* **What it means**: Execution time grows **in direct 1-to-1 proportion** with input size $N$. If $N$ doubles, time doubles.
* **Pattern**: A single loop running from $0$ to $N$.
* **Example**:
  ```c
  void printAll(int arr[], int n) {
      for (int i = 0; i < n; i++) {
          printf("%d ", arr[i]); // Runs exactly N times
      }
  }
  ```

---

### 4. $\mathcal{O}(N^2)$ — Quadratic Time 🐢 (Slow)
* **What it means**: Execution time grows **quadratically**. If $N = 10$, steps = $100$. If $N = 1,000$, steps = $1,000,000$!
* **Pattern**: Nested loops where both outer and inner loops depend on $N$.
* **Example**:
  ```c
  void printGrid(int n) {
      for (int i = 0; i < n; i++) {       // Outer loop runs N times
          for (int j = 0; j < n; j++) {   // Inner loop runs N times
              printf("*");
          }
      } // Total operations = N * N = N^2
  }
  ```

---

## 📊 Quick Comparison Table

| Big-O | Name | $N = 10$ Steps | $N = 1,000$ Steps | Performance |
| :--- | :--- | :--- | :--- | :--- |
| $\mathcal{O}(1)$ | Constant | $1$ step | $1$ step | 🏎️ Ultra Fast |
| $\mathcal{O}(\log N)$ | Logarithmic | $\approx 3$ steps | $\approx 10$ steps | 🚀 Super Fast |
| $\mathcal{O}(N)$ | Linear | $10$ steps | $1,000$ steps | 🚶 Good |
| $\mathcal{O}(N^2)$ | Quadratic | $100$ steps | $1,000,000$ steps | 🐢 Slow |

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 4 questions right here in chat:

### Question 1:
```c
void mystery1(int arr[], int n) {
    int sum = arr[0] + arr[1] + 100;
    printf("%d\n", sum);
}
```
👉 **What is the Time Complexity of `mystery1`?** ($\mathcal{O}(1)$, $\mathcal{O}(\log N)$, $\mathcal{O}(N)$, or $\mathcal{O}(N^2)$?)

---

### Question 2:
```c
void mystery2(int n) {
    for (int i = 0; i < n; i++) {
        printf("Hello ");
    }
}
```
👉 **What is the Time Complexity of `mystery2`?**

---

### Question 3:
```c
void mystery3(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d, %d)\n", i, j);
        }
    }
}
```
👉 **What is the Time Complexity of `mystery3`?**

---

### Question 4:
```c
void mystery4(int n) {
    while (n > 1) {
        n = n / 2;
    }
}
```
👉 **What is the Time Complexity of `mystery4`?**
