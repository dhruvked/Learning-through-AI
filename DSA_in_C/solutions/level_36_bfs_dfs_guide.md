# 🌊 Level 36 Study Guide: Graph Traversals (BFS vs DFS)

> **Goal**: Master the 2 fundamental Graph Traversal strategies: **Breadth-First Search (BFS)** and **Depth-First Search (DFS)**.

---

## 🌊 1. Breadth-First Search (BFS): "Layer by Layer"

### How it works:
* Starts at a source node and explores **all immediate neighbors first** (Layer 1), then all neighbors of neighbors (Layer 2)...
* **Data Structure Used**: **QUEUE (FIFO)**!
* **Visited Array**: Uses a `visited[]` boolean array to avoid getting stuck in infinite loops/cycles.

```text
       ( 0 )
      /     \
   ( 1 )   ( 2 )
   /   \     \
 (3)   (4)   (5)

BFS Traversal Order:  0 -> 1 -> 2 -> 3 -> 4 -> 5
(Layer 0 -> Layer 1 -> Layer 2)
```

* 💡 **KILLER FEATURE**: BFS **ALWAYS finds the SHORTEST PATH** (fewest number of edges) in an unweighted graph! (Used in GPS navigation, social networks for "degrees of separation").

---

## 🌲 2. Depth-First Search (DFS): "Explore as Deep as Possible"

### How it works:
* Starts at a source node and explores **as far down a single path as possible** before backtracking!
* **Data Structure Used**: **STACK (LIFO)** or **RECURSION**!
* **Visited Array**: Also uses a `visited[]` array to track visited nodes.

```text
       ( 0 )
      /     \
   ( 1 )   ( 2 )
   /   \     \
 (3)   (4)   (5)

DFS Traversal Order:  0 -> 1 -> 3 -> 4 -> 2 -> 5
(Goes deep down left branch 0->1->3 first, then backtracks!)
```

* 💡 **KILLER FEATURE**: DFS is used for **Maze Solving**, **Cycle Detection in Graphs**, and **Topological Sorting**.

---

## 📊 Comparison Table

| Feature | Breadth-First Search (BFS) 🌊 | Depth-First Search (DFS) 🌲 |
| :--- | :--- | :--- |
| **Traversal Order** | Level-by-level / Layer-by-layer | Deep dive down a path first |
| **Data Structure** | **Queue (FIFO)** | **Stack / Recursion (LIFO)** |
| **Time Complexity** | **O(V + E)** | **O(V + E)** |
| **Best Used For** | **Shortest Path** in unweighted graphs | **Maze Solving / Cycle Detection** |

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
Which Data Structure powers **Breadth-First Search (BFS)** to explore nodes level-by-level?
* A) Stack (LIFO)
* B) Queue (FIFO)
* C) Binary Heap

---

### Question 2:
Which graph traversal algorithm guarantees finding the **Shortest Path** (fewest number of edges) between two locations in an unweighted graph?
* A) Depth-First Search (DFS)
* B) Breadth-First Search (BFS)
* C) Linear Search

---

### Question 3:
Why do both BFS and DFS require a **`visited[]` array** during graph traversal?
* A) To sort the node values in ascending order.
* B) To prevent re-visiting nodes and getting trapped in infinite loops/cycles.
* C) To calculate the array size.
