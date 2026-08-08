# ⚡ Level 26 Study Guide: Quick Sort (Partitioning & In-Place Sorting)

> **Goal**: Master **Quick Sort** ($\mathcal{O}(N \log N)$ average) and understand how **Pivot Selection** and **In-Place Partitioning** make it the fastest general-purpose sorting algorithm in C/C++.

---

## ⚡ What is Quick Sort?

Like Merge Sort, **Quick Sort** is a Divide & Conquer algorithm. 

However, instead of using extra buffer arrays like Merge Sort ($\mathcal{O}(N)$ space), Quick Sort sorts **in-place ($\mathcal{O}(1)$ extra space)** by picking a **Pivot element** and rearranging the array around it!

---

## ⚙️ The Partitioning Strategy (Lomuto Partition)

1. **Pick a Pivot**: Select one element (e.g. the last element `arr[high]`).
2. **Partition**: Rearrange the array so that:
   * All elements **less than the pivot** are moved to the **left** of the pivot.
   * All elements **greater than the pivot** are moved to the **right** of the pivot.
3. **Recurse**: Recursively Quick Sort the left sub-array and right sub-array!

---

## 🎨 Step-by-Step Visual Example of Quick Sort

Let's sort the array: **`[10, 80, 30, 90, 40, 50, 70]`**

### Step 1: Pick Pivot = 70 (Last Element)

We want to partition `[10, 80, 30, 90, 40, 50]` around **`70`**:

* Compare `10` with `70` $\rightarrow$ `10 < 70` (Move to left side)
* Compare `80` with `70` $\rightarrow$ `80 > 70` (Stays on right side)
* Compare `30` with `70` $\rightarrow$ `30 < 70` (Swap `30` to left side!)
* Compare `90` with `70` $\rightarrow$ `90 > 70` (Stays on right side)
* Compare `40` with `70` $\rightarrow$ `40 < 70` (Swap `40` to left side!)
* Compare `50` with `70` $\rightarrow$ `50 < 70` (Swap `50` to left side!)

Now place **`70`** right into its final correct index between the left and right groups!

```text
  Left Group (< 70)       Pivot      Right Group (> 70)
  [ 10, 30, 40, 50 ]     [ 70 ]        [ 90, 80 ]
```

Notice: **`70` is now in its permanent sorted spot!** We never need to move `70` again.

---

### Step 2: Recurse on Left and Right Sub-arrays

1. Quick Sort left sub-array: **`[10, 30, 40, 50]`** (Pivot = `50`).
2. Quick Sort right sub-array: **`[90, 80]`** (Pivot = `80`).

---

## 📊 Quick Sort vs Merge Sort Comparison

| Feature | Merge Sort | Quick Sort |
| :--- | :--- | :--- |
| **Average Time Complexity** | $\mathcal{O}(N \log N)$ | $\mathcal{O}(N \log N)$ ⚡ (Faster constants!) |
| **Worst-Case Time Complexity** | $\mathcal{O}(N \log N)$ | $\mathcal{O}(N^2)$ (If bad pivot selected!) |
| **Extra Space Complexity** | $\mathcal{O}(N)$ (Requires buffer arrays) | $\mathcal{O}(1)$ (In-place sorting!) |
| **C Standard Library Function** | Rare | **`qsort()`** in `<stdlib.h>`! |

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
What is the primary advantage of Quick Sort over Merge Sort?
* A) Quick Sort requires $\mathcal{O}(1)$ extra space (sorts in-place) while Merge Sort requires $\mathcal{O}(N)$ extra buffer memory.
* B) Quick Sort runs in $\mathcal{O}(1)$ time.
* C) Quick Sort does not use recursion.

---

### Question 2:
What happens if you always pick the **worst possible pivot** (e.g. picking the maximum element on an already sorted array)?
* A) Time complexity degrades to $\mathcal{O}(N^2)$.
* B) Time complexity improves to $\mathcal{O}(1)$.
* C) The algorithm crashes.

---

### Question 3:
After a Partition step places the Pivot element into its index, does the Pivot element ever need to move again?
* A) Yes, it keeps moving in every pass.
* B) No, the Pivot is locked into its permanent final sorted position!
