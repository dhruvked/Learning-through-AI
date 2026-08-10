# ⚖️ Level 32 Study Guide: AVL Trees & Self-Balancing Rotations

> **Goal**: Master **AVL Trees** and understand how **Self-Balancing Rotations** guarantee O(log N) search performance even when data is inserted in sorted order!

---

## ⚖️ The Problem with Standard BSTs: Skewed Trees!

Suppose you insert pre-sorted numbers `[10, 20, 30, 40, 50]` into a standard BST:

```text
  Standard BST (Skewed Tree):
   [ 10 ]
        \
         [ 20 ]
              \
               [ 30 ]
                    \
                     [ 40 ]
                          \
                           [ 50 ]
```

Notice:
* The tree degenerated into a simple **Linked List**!
* Search time degrades from O(log N) to **O(N) Linear Time** 🐢!

---

## 🌳 The AVL Solution: Balance Factor

An **AVL Tree** is a self-balancing BST named after inventors **A**ldelson-**V**elsky and **L**andis.

### The Balance Factor Formula:
$$\text{Balance Factor (BF)} = \text{Height}(\text{Left Subtree}) - \text{Height}(\text{Right Subtree})$$

* **AVL Invariant Rule**: For EVERY node, the Balance Factor MUST be **-1, 0, or +1**.
* If BF becomes **+2** or **-2**, the tree is UNBALANCED! An automatic **Rotation** is triggered to restore balance!

---

## 🔄 The 4 Rotation Types

When a node becomes unbalanced (BF = +2 or -2), we perform a 1-step or 2-step rotation:

### 1. Left-Left Case (LL) $\rightarrow$ Perform **Single Right Rotation**
```text
      [ 30 ] (BF = +2)                   [ 20 ]
     /                                  /      \
  [ 20 ]               ===>         [ 10 ]    [ 30 ]
  /
[ 10 ]
```

---

### 2. Right-Right Case (RR) $\rightarrow$ Perform **Single Left Rotation**
```text
  [ 10 ] (BF = -2)                       [ 20 ]
        \                               /      \
         [ 20 ]        ===>          [ 10 ]    [ 30 ]
              \
               [ 30 ]
```

---

### 3. Left-Right Case (LR) $\rightarrow$ **Left Rotate Child, then Right Rotate Parent**
```text
    [ 30 ] (BF = +2)            [ 30 ]
   /                           /                        [ 20 ]
[ 10 ]          ===>        [ 20 ]      ===>           /      \
      \                    /                        [ 10 ]    [ 30 ]
       [ 20 ]            [ 10 ]
```

---

### 4. Right-Left Case (RL) $\rightarrow$ **Right Rotate Child, then Left Rotate Parent**
```text
  [ 10 ] (BF = -2)           [ 10 ]
        \                          \                    [ 20 ]
         [ 30 ]         ===>        [ 20 ]   ===>      /      \
        /                                 \         [ 10 ]    [ 30 ]
     [ 20 ]                              [ 30 ]
```

---

## ⚡ AVL Tree Performance Guarantee

| Data Structure | Best Search Time | Worst Search Time (Sorted Data) |
| :--- | :--- | :--- |
| **Standard BST** | O(log N) | **O(N)** 🐢 (Degenerates into Linked List!) |
| **AVL Tree** | **O(log N)** | **O(log N)** 🚀 (Guaranteed by Rotations!) |

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
What is the valid range for the **Balance Factor** (`height(left) - height(right)`) of any node in an AVL Tree?
* A) Must be 0 only
* B) Must be -1, 0, or +1
* C) Must be positive only

---

### Question 2:
What happens when you insert pre-sorted numbers `[1, 2, 3, 4, 5]` into a **standard (non-self-balancing) BST**?
* A) It forms a perfectly balanced tree of height 3.
* B) It degenerates into a single long line (Linked List) with O(N) worst-case search speed.
* C) The compiler throws an error.

---

### Question 3:
If a node becomes Right-Right heavy (RR case with Balance Factor = -2), which single rotation restores balance?
* A) Single Right Rotation
* B) Single Left Rotation
* C) No rotation needed
