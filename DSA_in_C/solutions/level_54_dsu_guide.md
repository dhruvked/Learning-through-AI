# 🌐 Level 54 Study Guide: Disjoint Set Union (DSU / Union-Find)

> **Goal**: Master **Disjoint Set Union (DSU)** — the essential data structure for tracking connected components in social networks, dynamic network connectivity, and Kruskal's Minimum Spanning Tree algorithm!

---

## 🌐 What is Disjoint Set Union (DSU)?

A **Disjoint Set Union (DSU)** data structure maintains a collection of non-overlapping (disjoint) sets. It supports two core operations:

1. **`find(i)`**: Determines which set element $i$ belongs to by returning the representative **root** of its set.
2. **`unionSets(i, j)`**: Merges the set containing $i$ and the set containing $j$ into a single set.

---

## ⚡ The 2 Essential Optimizations of DSU

Without optimizations, DSU trees can degrade into a long linked list ($O(N)$ depth). With these 2 optimizations, operations run in **$O(\alpha(N))$ near-constant time** (less than 5 steps for trillions of elements!).

### 1. Path Compression 🚀
When performing `find(i)`, re-attach every node along the path **directly to the root**!
```c
int findRoot(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = findRoot(parent, parent[i]); // Path Compression!
}
```

```text
BEFORE Path Compression:         AFTER Path Compression:
       (0)                              (0)
        |                              / | \
       (1)                           (1)(2)(3)
        |
       (2)
        |
       (3)
```

---

### 2. Union by Rank / Size ⚖️
Always attach the **shorter tree under the root of the taller tree** to prevent the tree height from growing unnecessarily!

```c
void unionSets(int parent[], int rank[], int i, int j) {
    int rootI = findRoot(parent, i);
    int rootJ = findRoot(parent, j);

    if (rootI != rootJ) {
        if (rank[rootI] < rank[rootJ]) {
            parent[rootI] = rootJ;
        } else if (rank[rootI] > rank[rootJ]) {
            parent[rootJ] = rootI;
        } else {
            parent[rootJ] = rootI;
            rank[rootI]++;
        }
    }
}
```

---

## 📊 Complexity Comparison

| DSU Implementation | `find()` | `unionSets()` | Overall Complexity |
| :--- | :--- | :--- | :--- |
| **Naive Trees** | $O(N)$ 🐢 | $O(N)$ 🐢 | $O(N)$ |
| **With Path Compression & Union by Rank** | **$O(\alpha(N)) \approx O(1)$** 🚀 | **$O(\alpha(N)) \approx O(1)$** 🚀 | **Near Constant Time!** |

*($\alpha(N)$ is the Inverse Ackermann Function, which is $\le 4$ for all realistic values of $N$!)*

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
What does **Path Compression** do during a `findRoot(i)` operation in DSU?
* A) Deletes the tree.
* B) Flattens the tree by re-attaching all nodes along the search path directly to the root node, making future lookups $O(1)$.
* C) Reverses all edges.

---

### Question 2:
How do we determine if two elements $A$ and $B$ belong to the **same connected set**?
* A) Compare their indices ($A == B$).
* B) Check if `findRoot(parent, A) == findRoot(parent, B)` (both share the exact same root!).
* C) Multiply their values.

---

### Question 3:
What is the purpose of **Union by Rank** in DSU?
* A) To sort the elements alphabetically.
* B) To always attach the shorter tree under the taller tree's root, preventing the tree depth from growing tall.
* C) To generate random numbers.
