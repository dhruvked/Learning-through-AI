# 🌿 Level 28 Study Guide: Tree Traversals (In-Order, Pre-Order, Post-Order)

> **Goal**: Master the 3 Depth-First Search (DFS) Tree Traversals: **In-Order**, **Pre-Order**, and **Post-Order**.

---

## 🌿 What is Tree Traversal?

Unlike an Array or Linked List which has only 1 way to walk from start to finish, a **Tree** has multiple branches!

**Tree Traversal** means visiting every single node in a tree exactly once.

The 3 Depth-First Traversals differ ONLY in **when you process/print the Root Node**:

```text
  1. Pre-Order   :  [ Root ] -> [ Left ] -> [ Right ]   (Pre = Root First!)
  2. In-Order    :  [ Left ] -> [ Root ] -> [ Right ]   (In  = Root In-between!)
  3. Post-Order  :  [ Left ] -> [ Right ] -> [ Root ]   (Post = Root Last!)
```

---

## 🎨 Visual Walkthrough Example

Consider this Binary Search Tree:

```text
         [ 50 ]
        /      \
    [ 30 ]    [ 70 ]
    /    \
 [ 20 ] [ 40 ]
```

---

### 1. In-Order Traversal (`Left -> Root -> Right`)
* Visit Left subtree recursively, print Root, visit Right subtree recursively.

```c
void inOrder(struct TreeNode *root) {
    if (root == NULL) return;
    inOrder(root->left);        // 1. Left
    printf("%d ", root->data);  // 2. Root
    inOrder(root->right);       // 3. Right
}
```
* **Output**: `20, 30, 40, 50, 70`
* 💡 **MAGIC RULE**: In-Order traversal of a BST **ALWAYS prints numbers in PERFECT SORTED ASCENDING ORDER**! 🎉

---

### 2. Pre-Order Traversal (`Root -> Left -> Right`)
* Print Root first, then visit Left subtree, then visit Right subtree.

```c
void preOrder(struct TreeNode *root) {
    if (root == NULL) return;
    printf("%d ", root->data);  // 1. Root
    preOrder(root->left);       // 2. Left
    preOrder(root->right);      // 3. Right
}
```
* **Output**: `50, 30, 20, 40, 70`
* 💡 **USE CASE**: Used to **clone / duplicate a tree** or serialize a tree to a file!

---

### 3. Post-Order Traversal (`Left -> Right -> Root`)
* Visit Left subtree, visit Right subtree, then process Root last.

```c
void postOrder(struct TreeNode *root) {
    if (root == NULL) return;
    postOrder(root->left);      // 1. Left
    postOrder(root->right);     // 2. Right
    printf("%d ", root->data);  // 3. Root
}
```
* **Output**: `20, 40, 30, 70, 50`
* 💡 **USE CASE**: Used to **safely delete / `free()` a tree** from bottom-up leaves to root without losing child pointers!

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
Which Tree Traversal is guaranteed to print all values of a BST in **perfect sorted ascending order**?
* A) Pre-Order
* B) In-Order
* C) Post-Order

---

### Question 2:
Which Tree Traversal should you use to safely **free/delete** a tree from memory without losing child pointers?
* A) Post-Order (deletes children first before deleting the parent node!)
* B) Pre-Order
* C) In-Order

---

### Question 3:
What is the Time Complexity of performing an In-Order traversal on a tree with $N$ nodes?
* A) $\mathcal{O}(1)$
* B) $\mathcal{O}(\log N)$
* C) $\mathcal{O}(N)$ (Visits every node exactly once)
