# 🗺️ Level 38 Study Guide: Shortest Path (Dijkstra's Algorithm)

> **Goal**: Master **Dijkstra's Algorithm** for finding the shortest path in a **Weighted Graph** (like Google Maps calculating driving time!).

---

## 🗺️ Why BFS is Not Enough for Weighted Graphs

* **BFS** finds the shortest path by counting the **number of edges / hops**.
* But in real-world graphs (like road networks), edges have **Weights / Costs** (e.g., Distance in km, Traffic time in minutes).

```text
               [ 1 ]
             /   |   \
        10m /    |1m  \ 10m
           /     |     \
    ( A ) ------+------+------> ( B )
                 100m (Direct highway with heavy traffic!)
```

* **BFS Path**: $A \rightarrow B$ (1 edge = 100 minutes) 🐢
* **Dijkstra Path**: $A \rightarrow 1 \rightarrow B$ (2 edges = $10 + 10 = 20\text{ minutes}$) 🚀

---

## ⚙️ How Dijkstra's Algorithm Works

Dijkstra uses **Greedy Choice + Edge Relaxation**:

### 1. Distance Array (`dist[]`)
* Initialize `dist[start] = 0` and all other `dist[v] = INFINITY (999999)`.

### 2. Priority Queue (Min-Heap)
* Always extract the unvisited node with the **SMALLEST tentative distance** (`dist[u]`).

### 3. Edge Relaxation Step ⚡
For every neighbor `v` of node `u`:
$$\text{if } dist[u] + weight(u, v) < dist[v]:$$
$$\text{Update } dist[v] = dist[u] + weight(u, v)$$

---

## 🖼️ Step-by-Step Tracing Example

Suppose Graph with Source $A$:
* Edge $A \rightarrow B$ (weight 4)
* Edge $A \rightarrow C$ (weight 2)
* Edge $C \rightarrow B$ (weight 1)

```text
Initial Distances:  dist[A]=0,  dist[B]=INF,  dist[C]=INF

Step 1: Extract min node A (dist=0).
        - Relax neighbor B: dist[A]+4 = 4 < INF  => dist[B] = 4
        - Relax neighbor C: dist[A]+2 = 2 < INF  => dist[C] = 2
        Updated Distances:  dist[A]=0,  dist[B]=4,  dist[C]=2

Step 2: Extract min unvisited node C (dist=2).
        - Relax neighbor B: dist[C]+1 = 2+1 = 3 < 4  => dist[B] = 3 (SHORTCUT FOUND!)
        Final Distances:    dist[A]=0,  dist[B]=3,  dist[C]=2
```

---

## 📊 Time Complexity

| Implementation | Time Complexity |
| :--- | :--- |
| **Simple Array Scan** | $O(V^2)$ |
| **Min-Heap (Priority Queue)** | **$O((V + E) \log V)$** 🚀 (Standard Production Implementation) |

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
Why can't standard **BFS** be used to find the shortest path on a **Weighted Graph** (where edges have distance/time costs)?
* A) BFS cannot traverse graphs with more than 3 nodes.
* B) BFS counts the number of edges (hops), ignoring edge weights/costs.
* C) BFS only works on trees.

---

### Question 2:
What is **Edge Relaxation** in Dijkstra's Algorithm?
* A) Deleting edges from the graph.
* B) Checking if traveling through current node $u$ to neighbor $v$ (`dist[u] + weight`) is shorter than neighbor $v$'s current distance (`dist[v]`), and updating it if shorter.
* C) Resetting all node weights to zero.

---

### Question 3:
Which Data Structure allows Dijkstra's Algorithm to achieve optimal **O((V + E) log V)** performance by always extracting the node with the smallest distance?
* A) Min-Heap (Priority Queue)
* B) Circular Queue
* C) Stack
