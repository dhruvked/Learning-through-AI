# 🔑 Level 33 Study Guide: Hashing & Hash Tables (Collision Resolution)

> **Goal**: Master **Hash Tables** and understand how **Hash Functions** (`hash(key) % SIZE`) achieve O(1) Instant Search Speed, and how to resolve **Collisions** (Separate Chaining vs Open Addressing).

---

## 🔑 What is a Hash Table?

A **Hash Table** is a data structure that maps **Keys to Values** (like a dictionary, phonebook, or JSON object).

### Why Hash Tables are Revolutionary:
* **Array Search Time**: O(N) Linear Search or O(log N) Binary Search.
* **Hash Table Search Time**: **O(1) Constant Instant Time** 🚀!

---

## ⚙️ The Hash Function & Modulo Trick

How do we convert a key (like integer `key = 105` or string `"Alice"`) into an array index?

We use a **Hash Function**:
$$\text{index} = \text{hash}(\text{key}) \% \text{TABLE\_SIZE}$$

### Example (`TABLE_SIZE = 10`):
* `key = 25` $\rightarrow$ `25 % 10 = index 5`
* `key = 42` $\rightarrow$ `42 % 10 = index 2`
* `key = 99` $\rightarrow$ `99 % 10 = index 9`

---

## 💥 What is a Collision?

A **Collision** happens when two DIFFERENT keys produce the **EXACT SAME INDEX**!

### Example:
* `key1 = 25` $\rightarrow$ `25 % 10 = index 5`
* `key2 = 35` $\rightarrow$ `35 % 10 = index 5` 💥 **COLLISION at index 5!**

---

## 🛡️ The 2 Main Collision Resolution Strategies

### 1. Separate Chaining (Linked Lists at each Bucket) 🔗
Each slot in the Hash Table array stores a **Head Pointer to a Linked List**!
If two keys map to the same index, they are simply chained together into the same linked list.

```text
Index 0: NULL
Index 1: NULL
Index 2: [ Key: 42 ] -> NULL
Index 5: [ Key: 25 ] -> [ Key: 35 ] -> NULL  <-- Chained together!
Index 9: [ Key: 99 ] -> NULL
```

* **Pros**: Never runs out of space, handles high load factors gracefully.
* **Standard C Implementation**: Used in production systems!

---

### 2. Open Addressing (Linear Probing) 🏃‍♂️
If a collision occurs at index `i`, search for the **next open slot** at `i+1`, `i+2`, `i+3`...

```text
Index 5: [ Key: 25 ]
Index 6: [ Key: 35 ]  <-- Placed in next open slot because index 5 was full!
```

* **Pros**: No pointers or linked lists needed (all stored in flat array).
* **Cons**: Can cause **Clustering** (long chains of occupied slots).

---

## 📊 Performance Summary

| Operation | Average Case Time | Worst Case (All keys collide) |
| :--- | :--- | :--- |
| **Search Key** | **O(1)** ⚡ | O(N) (Degenerates into single Linked List) |
| **Insert Key** | **O(1)** ⚡ | O(N) |
| **Delete Key** | **O(1)** ⚡ | O(N) |

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
If `TABLE_SIZE = 7` and `key = 22`, at which array index will the hash function `key % TABLE_SIZE` store the item?
* A) Index 1 (because `22 % 7 = 1`)
* B) Index 3
* C) Index 7

---

### Question 2:
What is a **Collision** in a Hash Table?
* A) When a memory pointer points to NULL.
* B) When two different keys generate the exact same array index from the Hash Function.
* C) When the Hash Table runs out of memory.

---

### Question 3:
How does **Separate Chaining** resolve collisions?
* A) By deleting the old key and replacing it with the new key.
* B) By storing a Linked List at each array index so multiple keys at the same index are chained together.
* C) By resizing the table automatically.
