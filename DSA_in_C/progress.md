# 📊 Progress Log — DSA in C

- **Current Level**: Level 32
- **Current Tier**: Tier 2 (🌿 Intermediate)
- **Status**: Level 32 - AVL Trees & Self-Balancing Rotations (Ready to Start)
- **Total XP**: 1040 XP
- **Badges Earned**: 🏆 *First Step*, ⚡ *Input Master*, 🧠 *Logic Master*, 🔁 *Loop Warrior*, 🎯 *Pointer Novice*, 🏗️ *Memory Architect*, 📈 *Vector Master*, 🔗 *Chain Linker*, 🚶‍♂️ *List Navigator*, ⚡ *Head Inserter*, 🏅 *Level 10 Master*, ✂️ *Node Reaper*, ↔️ *Doubly Linked Legend*, 🔄 *Circle Master*, 📚 *Stack Commander*, 🚦 *Queue Commander*, 🔁 *Modulo Master*, 🌊 *Dynamic Flow Master*, 🎯 *LIFO Master*, ⚡ *Complexity Analyst*, 👑 *Tier 1 Grandmaster*, 🔁 *Recursive Mind*, 🎯 *Binary Scout*, 🧼 *Sort Specialist*, 🃏 *Card Dealer*, ⚔️ *Divider & Conqueror*, ⚡ *Quick Swapper*, 🌲 *Tree Planter*, 🌿 *Traversal Master*, 🏔️ *Heap Climber*, 🏅 *1000 XP Legend & BST Architect*, ⛰️ *Heap Master*

---

## 🎯 Active Quest
- **Task**: Master **AVL Trees** and understand Balance Factor (`height(left) - height(right)`) and Left/Right rotations.
- **File**: `DSA_in_C/solutions/level_32_avl_tree_guide.md`

---

## 📜 History & Assessment Log

| Date | Level | Assessment | Result | Notes |
|------|-------|------------|--------|-------|
| 2026-08-09 | Lvl 31 | Priority Queue / Min-Heap | Passed | Built full Min-Heap engine with array indexing (`2*i+1`, `2*i+2`), Heapify-Up (`(i-1)/2`), and Heapify-Down (+40 XP) |
| 2026-08-08 | Lvl 30 | BST Engine in C | Passed | Built full C BST engine with recursive `insertNode`, `searchNode`, `inOrderTraversal`, and `freeTree` (+40 XP) |
| 2026-08-08 | Lvl 29 | Heaps & Priority Queues | Passed | Mastered Max-Heap/Min-Heap properties, array index formulas (`2*i+1`, `2*i+2`), Heapify-Up/Down, and $O(\log N)$ priority queues (+40 XP) |
| 2026-08-08 | Lvl 28 | Tree Traversals | Passed | Mastered In-Order (sorted output), Pre-Order (tree copy), and Post-Order (safe bottom-up memory deletion) (+40 XP) |
| 2026-08-08 | Lvl 27 | BST Fundamentals | Passed | Mastered `left` (smaller) & `right` (larger) invariant rules, tree node structure, and $O(\log N)$ search paths (+40 XP) |
| 2026-08-08 | Lvl 26 | Quick Sort & Partitioning | Passed | Mastered in-place partitioning, pivot locking, $\mathcal{O}(1)$ space advantage, and $\mathcal{O}(N^2)$ worst case (+40 XP) |
| 2026-08-08 | Lvl 25 | Merge Sort ($O(N \log N)$) | Passed | Mastered Divide & Conquer, $O(N \log N)$ speedup, $O(N)$ extra space, and `low >= high` base case (+40 XP) |
| 2026-08-08 | Lvl 24 | Insertion Sort & Adaptive | Passed | Mastered card-shifting mechanic, 0-loop inner execution for sorted data, and $\mathcal{O}(N)$ best-case (+40 XP) |
| 2026-08-07 | Lvl 23 | Bubble & Selection Sort | Passed | Mastered bubbling max element, Selection Sort swap reduction ($N-1$ swaps), and $\mathcal{O}(N^2)$ (+40 XP) |
| 2026-08-07 | Lvl 22 | Binary Search ($O(\log N)$) | Passed | Mastered `low + (high - low) / 2` overflow fix, $O(\log N)$ speed, and sorted requirement (+40 XP) |
| 2026-08-07 | Lvl 21 | Recursion & Call Stack | Passed | 100% score on Base Cases, Call Stack execution, and $\mathcal{O}(N)$ recursion (+40 XP) |
| 2026-08-06 | Lvl 20 | Tier 1 Final Capstone | Passed | Built real-world Browser History Manager with DLL, back/forward navigation (+60 XP) |
| 2026-08-06 | Lvl 19 | Big-O Complexity Analysis | Passed | 100% score on $\mathcal{O}(1), \mathcal{O}(N), \mathcal{O}(N^2), \mathcal{O}(\log N)$ quiz (+40 XP) |
| 2026-08-06 | Lvl 18 | Linked List Stack | Passed | Mastered dynamic pointer-based LIFO stack with $O(1)$ `push`, `pop`, `peek` (+35 XP) |
| 2026-08-06 | Lvl 17 | Linked List Queue | Passed | Mastered dynamic pointer-based FIFO queue with `enqueue` and `dequeue` (+40 XP) |
| 2026-08-05 | Lvl 16 | Circular Queue (`%`) | Passed | Mastered modulo wrap-around `(rear + 1) % MAX` for 0-shift slot reuse (+40 XP) |
| 2026-08-05 | Lvl 15 | Queue Implementation | Passed | Mastered FIFO queue with `enqueue`, `dequeue`, `getFront`, `isEmpty`, and `isFull` (+35 XP) |
| 2026-08-05 | Lvl 14 | Stack Implementation | Passed | Mastered LIFO stack structure with `push`, `pop`, `peek`, `isEmpty`, and `isFull` (+35 XP) |
| 2026-08-05 | Lvl 13 | Circular Linked List (CLL) | Passed | Mastered self-pointing head, `do-while` traversal, and safe `freeCircular` (+30 XP) |
| 2026-08-05 | Lvl 12 | Doubly Linked List (DLL) | Passed | Mastered `prev` and `next` 2-way pointers, forward & backward traversal (+30 XP) |
| 2026-08-05 | Lvl 11 | Linked List Node Deletion | Passed | Handled head deletion, middle bypass, and `free(i)` (+30 XP) |
| 2026-08-05 | Lvl 10 | Tail Insertion & Search | Passed | Fixed `if(==)` equality, implemented `insertAtTail`, `searchList`, and `freeList` (+30 XP) |
| 2026-08-05 | Lvl 9 | Linked List Head Insertion | Passed | Mastered double pointers (`Node **headRef`) and front insertion (+30 XP) |
| 2026-08-05 | Lvl 8 | Linked List Traversal | Passed | Created `while` loop traversal & combined free pattern (+25 XP) |
| 2026-08-05 | Lvl 7 | Singly Linked List Intro | Passed | Created and linked nodes dynamically (+20 XP) |
| 2026-08-05 | Lvl 6 | Dynamic Array (`realloc`) | Passed | Mastered dynamic memory resizing with `realloc()` (+20 XP) |
| 2026-08-05 | Lvl 5 | Structs & `malloc` | Passed | Mastered `struct`, `malloc`, `->`, and `free()` (+20 XP) |
| 2026-08-05 | Lvl 4 | Pointers & Memory | Passed | Mastered `&` address-of and `*` dereferencing (+20 XP) |
| 2026-08-05 | Lvl 3 | Repetition (`for` loops) | Passed | Mastered `for(int i=1; i<=n; i++)` and loop counters (+20 XP) |
| 2026-08-05 | Lvl 2 | Conditionals (`if/else`) | Passed | Perfect `if / else if / else` logic for positive, negative, and zero (+15 XP) |
| 2026-08-05 | Lvl 1 | User Input (`scanf`) & Math | Passed | Mastered `scanf("%d", &var)`, basic math operators, and formatting (+15 XP) |
| 2026-08-05 | Lvl 1 | Basic Output (`printf`) | Passed | Learned `main`, `printf`, and format specifiers (+10 XP) |
| 2026-08-05 | Lvl 1 | Diagnostic Test | Skipped | Starting from absolute ground 0 |
