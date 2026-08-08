# 🔍 Level 22 Study Guide: Binary Search (Iterative & Recursive)

> **Goal**: Master **Binary Search** ($\mathcal{O}(\log N)$) on sorted arrays and understand why it is so much faster than Linear Search ($\mathcal{O}(N)$).

---

## ⚡ Linear Search vs Binary Search

Imagine searching for a word in a dictionary of 100,000 words:

1. **Linear Search ($\mathcal{O}(N)$)**: Start on page 1, check every single page one-by-one until you find the word. (Worst case: 100,000 steps!).
2. **Binary Search ($\mathcal{O}(\log N)$)**: Open the dictionary right to the middle. If your word comes *after* that page, throw away the left half! Repeat on the right half.
   * **For 100,000 words, Binary Search takes at most 17 steps!** ($2^{17} = 131,072$).

---

## ⚠️ The Golden Rule of Binary Search
Binary Search **ONLY works on SORTED data**! If the array is unsorted, Binary Search fails.

---

## ⚙️ How Binary Search Works (Pointers: `low`, `high`, `mid`)

Given a sorted array: `[2, 5, 8, 12, 16, 23, 38, 56, 72, 91]`, searching for `23`:

1. `low = 0`, `high = 9`.
2. Compute `mid = (low + high) / 2 = (0 + 9) / 2 = 4`. `arr[4] = 16`.
3. Since target `23 > 16`, throw away left half! Set `low = mid + 1 = 5`.
4. Next `mid = (5 + 9) / 2 = 7`. `arr[7] = 56`.
5. Since target `23 < 56`, throw away right half! Set `high = mid - 1 = 6`.
6. Next `mid = (5 + 6) / 2 = 5`. `arr[5] = 23`. **FOUND! 🎉**

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
If an array has $N = 1,000,000$ sorted elements, what is the **maximum number of steps** Binary Search will take to find any element (or declare it not found)?
* A) $1,000,000$ steps
* B) $500,000$ steps
* C) $\approx 20$ steps
* D) $100$ steps

---

### Question 2:
Look at this code for calculating `mid`:
```c
int mid = (low + high) / 2;
```
For extremely large numbers in C, `(low + high)` can cause an **integer overflow** (exceeding $2,147,483,647$).
👉 **Which formula avoids integer overflow?**
* A) `mid = low + (high - low) / 2;`
* B) `mid = high * low / 2;`
* C) `mid = (high - low) / 2;`

---

### Question 3:
If you perform Binary Search on an **unsorted array**, what happens?
* A) It will still find the element in $\mathcal{O}(\log N)$ time.
* B) It may give an incorrect result (e.g. return "Not Found" even if element exists).
* C) The compiler will throw an error.
