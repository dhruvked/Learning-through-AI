# 🌐 Level 51 Study Guide: System Design & Advanced Enterprise Data Structures

> **Goal**: Welcome to **Tier 4 (System Design & Enterprise Data Structures)**! Master how high-scale tech companies (Google, Netflix, Amazon) combine data structures to build ultra-fast real-world systems like **LRU Caches** and **Autocomplete Trie Trees**!

---

## 🌐 Tier 4 Overview: Enterprise System Design

In Tier 1, 2, and 3, you mastered individual data structures (Arrays, Linked Lists, Trees, Heaps, Graphs, DP, Backtracking).

In **Tier 4**, you step into the role of a **Software System Architect**! Real-world enterprise systems achieve massive scale by **combining multiple data structures together**!

---

## ⚡ 1. The LRU Cache (Least Recently Used)

When a server receives millions of database queries per second, querying the disk database every time is too slow ($O(\text{disk access})$). Instead, it keeps a **Cache** in fast RAM.

When the cache is full, which item do we evict? The **Least Recently Used (LRU)** item!

### The System Design Challenge:
* `get(key)`: Fetch value in **O(1) Constant Time**.
* `put(key, value)`: Insert key-value pair in **O(1) Constant Time**, evicting the LRU item if capacity is exceeded.

### How to Achieve O(1) for BOTH get() and put()?
> **Combine Hash Map + Doubly Linked List (DLL)!**

```text
                  DOUBLY LINKED LIST (Recency Order)
         [ HEAD ] <--> [ Node A ] <--> [ Node B ] <--> [ TAIL ]
            ^                                             ^
       Most Recent                                   Least Recent (Evict!)
            |
       HASH MAP (O(1) Direct Pointer Lookups)
       "Key A" -> Pointer to Node A
       "Key B" -> Pointer to Node B
```

* **Hash Map**: Provides $O(1)$ direct lookup to find any DLL node.
* **Doubly Linked List**: Allows $O(1)$ node removal and head insertion to maintain recency order!

---

## 🌲 2. Trie Data Structure (Prefix Tree / Autocomplete)

When you type `"app"` into Google, search suggestions like `"apple"`, `"application"`, `"app store"` appear instantly!

Using a standard array or Hash Map would require scanning millions of words ($O(N \times L)$). A **Trie** solves this in **O(L) time** (where $L$ is word length)!

### Trie Node Architecture:
Each Trie node contains an array of 26 pointers (`children[26]`) representing letters `'a'` through `'z'`, and a boolean flag `isEndOfWord`:

```text
                      (root)
                     /      \
                    'a'     'b'
                    /        \
                   'p'       'a'
                  /           \
                 'p' (word)   't' (word)
                /   \
              'l'   'l'
              /       \
            'e'(word) 'i'
                       \
                       'c' ...
```

---

## 📊 Summary Comparison

| System Design Structure | Data Structures Combined | Primary Use Case | Time Complexity |
| :--- | :--- | :--- | :--- |
| **LRU Cache** | Hash Map + Doubly Linked List | Fast RAM Caching with $O(1)$ eviction | **O(1)** `get` & `put` 🚀 |
| **Trie (Prefix Tree)** | Tree of 26-element pointer arrays | Instant Search Autocomplete & Spell Checking | **O(L)** lookup 🚀 |

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
Why does an **LRU Cache** require COMBINING a **Hash Map** and a **Doubly Linked List**?
* A) Because arrays are obsolete.
* B) Hash Map provides $O(1)$ instant key lookup, while Doubly Linked List provides $O(1)$ node removal & head re-ordering for recency tracking.
* C) Because DLLs use less memory.

---

### Question 2:
In an LRU Cache, which node is evicted when the cache reaches max capacity and a new item is inserted?
* A) The node at the Head (Most Recently Used).
* B) The node at the Tail (Least Recently Used).
* C) A random node.

---

### Question 3:
What makes a **Trie (Prefix Tree)** ideal for Google Search Autocomplete compared to a Hash Map?
* A) A Trie groups words by common prefixes, allowing instant retrieval of all words starting with `"app"` by walking down node branches in $O(L)$ time.
* B) A Trie converts characters to floats.
* C) A Trie uses $O(N^2)$ time.
