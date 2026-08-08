# 🏔️ Level 29 Study Guide: Heaps & Priority Queues (Min-Heap / Max-Heap)

> **Goal**: Master **Binary Heaps** and understand how trees can be represented cleanly inside a **single flat Array** without any pointers!

---

## 🏔️ What is a Heap?

A **Heap** is a special Complete Binary Tree that satisfies the **Heap Property**:

1. **Max-Heap**: Every parent node is **GREATER THAN OR EQUAL TO** its children. (Largest element is always at the Root!).
2. **Min-Heap**: Every parent node is **LESS THAN OR EQUAL TO** its children. (Smallest element is always at the Root!).

```text
       Max-Heap                        Min-Heap
        [ 90 ]                          [ 10 ]
       /      \                        /      \
    [ 70 ]    [ 80 ]                [ 30 ]    [ 20 ]
   /    \                          /    \
[ 20 ] [ 40 ]                   [ 50 ] [ 60 ]
```

---

## ⚡ The Array Representation Trick (No Pointers Needed!)

Because a Heap is a **Complete Binary Tree** (filled level-by-level), we don't need `left` and `right` struct pointers! We store the tree inside a simple 1D Array `arr[]`!

For any element at index `i`:
* **Left Child Index**: `2 * i + 1`
* **Right Child Index**: `2 * i + 2`
* **Parent Index**: `(i - 1) / 2`

### Visual Example:
```text
Tree:           [ 90 ] (idx 0)
               /      \
       (idx 1) [70]   [80] (idx 2)
              /    \
      (idx 3)[20]  [40] (idx 4)

Array: [ 90, 70, 80, 20, 40 ]
Index:    0   1   2   3   4
```

Verify the math:
* For `i = 0` (90): Left Child = 2(0)+1 = 1 (70). Right Child = 2(0)+2 = 2 (80).
* For `i = 1` (70): Left Child = 2(1)+1 = 3 (20). Right Child = 2(1)+2 = 4 (40).

---

## 🎨 Step-by-Step Examples: Insertion & Extraction

### Example 1: Inserting `95` into a Max-Heap (Heapify-Up / Percolate Up)

Suppose we have Max-Heap: `[90, 70, 80, 20, 40]`

1. **Step 1: Add new item `95` at the end of the array (at index 5).**
   ```text
   Array: [ 90, 70, 80, 20, 40, 95 ]
   Index:    0   1   2   3   4   5
   ```
2. **Step 2: Compare `95` (idx 5) with its parent `80` (idx 2).**
   * Since `95 > 80`, swap `95` and `80`!
   ```text
   Array: [ 90, 70, 95, 20, 40, 80 ]
   Index:    0   1   2   3   4   5
   ```
3. **Step 3: Compare `95` (idx 2) with its parent `90` (idx 0).**
   * Since `95 > 90`, swap `95` and `90`!
   ```text
   Array: [ 95, 70, 90, 20, 40, 80 ]
   Index:    0   1   2   3   4   5
   ```
4. **`95` is now at the Root! Total time: O(log N).**

---

### Example 2: Extracting Max (Removing Root `95`) (Heapify-Down / Percolate Down)

Suppose we want to remove the largest priority item `95` from `[95, 70, 90, 20, 40, 80]`:

1. **Step 1: Overwrite Root `95` with the LAST element `80`, and shrink array size.**
   ```text
   Array: [ 80, 70, 90, 20, 40 ]  (95 is removed!)
   Index:    0   1   2   3   4
   ```
2. **Step 2: Compare `80` (Root) with its children: Left `70` (idx 1) and Right `90` (idx 2).**
   * The largest child is `90` (idx 2).
   * Since `90 > 80`, swap `80` and `90`!
   ```text
   Array: [ 90, 70, 80, 20, 40 ]
   Index:    0   1   2   3   4
   ```
3. **Step 3: Compare `80` (idx 2) with its children (none exist!). Stop!**
4. **The Heap is restored! Total time: O(log N).**

---

## 🚦 Real-World Application: Priority Queue

In a normal Queue (FIFO), elements leave in order of arrival.

In a **Priority Queue** (powered by a Heap):
* Every element has a **priority level**.
* `pop()` always removes the **highest priority item** (Root of the Heap) in O(log N) time!
* Used in **Operating System Process Schedulers**, **Emergency Room Triage**, and **Dijkstra's Shortest Path Algorithm**.

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
In a **Max-Heap**, where is the absolute maximum element always located?
* A) At index 0 (the Root node)
* B) At the last index of the array
* C) In the left child of index 1

---

### Question 2:
If a node is stored at index `i = 3` in a Heap array, at which index is its **Left Child** located?
* A) `i + 1 = 4`
* B) `2 * i + 1 = 7`
* C) `2 * i + 2 = 8`

---

### Question 3:
What is the Time Complexity to insert or extract the root element from a Heap with $N$ elements?
* A) O(1)
* B) O(log N)
* C) O(N^2)
