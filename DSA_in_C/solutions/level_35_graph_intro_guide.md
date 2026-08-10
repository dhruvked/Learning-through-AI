# 🕸️ Level 35 Study Guide: Graph Representation (Adjacency Matrix vs Adjacency List)

> **Goal**: Master **Graphs** (Vertices $V$, Edges $E$) and compare **Adjacency Matrix** vs **Adjacency List** representations.

---

## 🕸️ What is a Graph?

A **Graph** is a non-linear network of interconnected objects:
* **Vertices ($V$) / Nodes**: The objects (e.g. Cities, Users, Web Pages).
* **Edges ($E$) / Links**: The connections between objects (e.g. Highways, Friendships, Hyperlinks).

```text
    ( 0: New York ) <========> ( 1: London )
           ^                         ^
           |                         |
           v                         v
    ( 3: Tokyo )    <========> ( 2: Paris )
```

---

## 📊 The 2 Ways to Represent Graphs in Memory

### 1. Adjacency Matrix (2D Array `matrix[V][V]`) 🔲

A 2D grid where `matrix[u][v] = 1` if an edge exists between node `u` and node `v`, or `0` if no edge exists.

```text
     0   1   2   3
0  [ 0,  1,  0,  1 ]
1  [ 1,  0,  1,  0 ]
2  [ 0,  1,  0,  1 ]
3  [ 1,  0,  1,  0 ]
```

* **Pros**: O(1) Instant edge lookup (`matrix[u][v] == 1`).
* **Cons**: Uses **O(V^2) Memory**! If you have 1,000,000 cities with only 2 connections each, you waste 1 Trillion matrix slots storing zeros!

---

### 2. Adjacency List (Array of Linked Lists `adjList[V]`) 🔗

An array of size $V$, where each index `adjList[u]` points to a **Linked List** of all neighboring nodes directly connected to `u`!

```text
adjList[0] -> [ 1 ] -> [ 3 ] -> NULL
adjList[1] -> [ 0 ] -> [ 2 ] -> NULL
adjList[2] -> [ 1 ] -> [ 3 ] -> NULL
adjList[3] -> [ 0 ] -> [ 2 ] -> NULL
```

* **Pros**: Uses **O(V + E) Memory**! Only stores actual existing connections.
* **Standard C Implementation**: Used in Google Maps, Facebook Social Graphs, and Routing Protocols!

---

## 📊 Performance Comparison

| Feature | Adjacency Matrix | Adjacency List |
| :--- | :--- | :--- |
| **Memory / Space Complexity** | **O(V^2)** 🐢 (Wastes memory on sparse graphs) | **O(V + E)** ⚡ (Ultra memory efficient!) |
| **Edge Existence Check (`u <-> v`)** | **O(1)** ⚡ | O(degree of u) |
| **Find All Neighbors of Node `u`** | O(V) (Must scan full row) | **O(degree of u)** ⚡ |
| **Best Used For** | **Dense Graphs** (almost all pairs connected) | **Sparse Graphs** (most real-world graphs!) |

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
What are the two core building blocks that make up a Graph?
* A) Head and Tail
* B) Vertices (Nodes) and Edges (Connections)
* C) Keys and Values

---

### Question 2:
Why is an **Adjacency List** preferred over an Adjacency Matrix for real-world graphs (like Facebook or Google Maps)?
* A) Adjacency List uses O(V + E) memory instead of wasting O(V^2) memory on non-existent connections.
* B) Adjacency List uses no pointers.
* C) Adjacency Matrix cannot store numbers.

---

### Question 3:
If a graph has $V = 1,000$ vertices, how many slots does an **Adjacency Matrix** allocate in RAM?
* A) $1,000$ slots
* B) $1,000,000$ slots ($V \times V = 1000 \times 1000$)
* C) $2,000$ slots
