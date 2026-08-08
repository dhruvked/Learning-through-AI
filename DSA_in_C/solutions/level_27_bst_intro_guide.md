# 🌲 Level 27 Study Guide: Binary Search Trees (BST Fundamentals)

> **Goal**: Transition from linear data structures (Arrays, Linked Lists) to **Non-Linear Hierarchical Data Structures**: **Binary Search Trees (BST)**.

---

## 🌲 What is a Binary Search Tree (BST)?

A **Binary Search Tree** is a node-based tree structure where every node has at most **two children** (`left` and `right`).

### The BST Invariant Rule (Golden Rule):
For EVERY node in the tree:
1. All values in the **left subtree** must be **SMALLER** than the node's value.
2. All values in the **right subtree** must be **GREATER** than the node's value.

```text
                     [ 50 ]  <-- Root Node
                    /      \
             [ 30 ]          [ 70 ]
            /      \        /      \
       [ 20 ]    [ 40 ]  [ 60 ]    [ 80 ]
```

---

## ⚙️ Node Structure in C

Unlike a Linked List node which has `next`, a BST node has two pointers: `left` and `right`:

```c
struct TreeNode {
    int data;
    struct TreeNode *left;  // Pointer to left child (smaller values)
    struct TreeNode *right; // Pointer to right child (larger values)
};
```

---

## 🎨 Step-by-Step Example: Building a BST

Let's insert these numbers into an empty BST in order: **`[50, 30, 70, 20, 40]`**

1. **Insert 50**: Tree is empty $\rightarrow$ `50` becomes the **Root**.
   ```text
        [ 50 ]
   ```

2. **Insert 30**: Compare `30` with `50`. Since `30 < 50`, insert to the **Left** of `50`.
   ```text
        [ 50 ]
       /
   [ 30 ]
   ```

3. **Insert 70**: Compare `70` with `50`. Since `70 > 50`, insert to the **Right** of `50`.
   ```text
        [ 50 ]
       /      \
   [ 30 ]    [ 70 ]
   ```

4. **Insert 20**: Compare with `50` (`< 50` $\rightarrow$ Left to `30`). Compare with `30` (`20 < 30` $\rightarrow$ Left to `30`).
   ```text
        [ 50 ]
       /      \
   [ 30 ]    [ 70 ]
   /
 [ 20 ]
   ```

5. **Insert 40**: Compare with `50` (`< 50` $\rightarrow$ Left to `30`). Compare with `30` (`40 > 30` $\rightarrow$ Right to `30`).
   ```text
        [ 50 ]
       /      \
   [ 30 ]    [ 70 ]
   /    \
 [ 20 ] [ 40 ]
   ```

---

## ⚡ Why BSTs are Powerful: $\mathcal{O}(\log N)$ Search Speed

Searching in a balanced BST behaves just like **Binary Search**! At every step, you eliminate half of the tree:

* **Balanced BST Search Time**: $\mathcal{O}(\log N)$
* **Array Search Time**: $\mathcal{O}(N)$

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
In a valid Binary Search Tree, where do values **smaller** than a node always go?
* A) In the `right` subtree
* B) In the `left` subtree
* C) They can go anywhere

---

### Question 2:
What is the maximum number of child nodes any node in a **Binary** Tree can have?
* A) 1
* B) 2
* C) Infinite

---

### Question 3:
If you search for the number `40` in the example BST above, which path of nodes do you visit starting from the root `50`?
* A) `50` $\rightarrow$ `70` $\rightarrow$ `80`
* B) `50` $\rightarrow$ `30` $\rightarrow$ `40`
* C) `50` $\rightarrow$ `20` $\rightarrow$ `40`
