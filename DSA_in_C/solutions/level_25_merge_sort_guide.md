# ⚔️ Level 25 Study Guide: Merge Sort (Divide & Conquer)

> **Goal**: Master **Merge Sort** ($\mathcal{O}(N \log N)$) and understand how Divide & Conquer algorithms shatter the $\mathcal{O}(N^2)$ speed barrier.

---

## ⚔️ The Divide & Conquer Strategy

Unlike Bubble, Selection, or Insertion Sort which take $\mathcal{O}(N^2)$ time, **Merge Sort** uses a 3-step strategy:

1. **Divide**: Split the array into two equal halves down the middle (`mid = low + (high - low) / 2`).
2. **Conquer**: Recursively sort both halves down to 1-element base cases.
3. **Combine (Merge)**: Merge the two sorted halves into a single sorted array!

---

## 🎨 Step-by-Step Example of Merge Sort

Let's sort the array: **`[38, 27, 43, 3, 9, 82, 10]`**

### Step 1: Divide (Splitting Phase)
Keep splitting the array into halves until every sub-array has only 1 element:

```text
                     [ 38, 27, 43, 3, 9, 82, 10 ]
                                 /  \
                   [ 38, 27, 43, 3 ]   [ 9, 82, 10 ]
                        /     \           /    \
                   [ 38, 27 ] [ 43, 3 ] [ 9, 82 ] [ 10 ]
                    /   \      /   \     /   \       |
                  [38] [27]  [43] [3]  [9]  [82]   [10]  <-- Base Cases!
```

---

### Step 2 & 3: Conquer & Merge (Combining Phase)

Now merge pairs of sorted sub-arrays back together by picking the smallest element from each half:

#### 1. Merge `[38]` and `[27]`:
Compare `38` vs `27` $\rightarrow$ `27` is smaller $\rightarrow$ Result: **`[27, 38]`**

#### 2. Merge `[43]` and `[3]`:
Compare `43` vs `3` $\rightarrow$ `3` is smaller $\rightarrow$ Result: **`[3, 43]`**

#### 3. Merge `[27, 38]` and `[3, 43]`:
* Compare `27` vs `3` $\rightarrow$ Pick `3`
* Compare `27` vs `43` $\rightarrow$ Pick `27`
* Compare `38` vs `43` $\rightarrow$ Pick `38`
* Remaining: `43`
* Result: **`[3, 27, 38, 43]`**

#### 4. Merge `[9]` and `[82]`:
Result: **`[9, 82]`**

#### 5. Merge `[9, 82]` and `[10]`:
Result: **`[9, 10, 82]`**

#### 6. Final Merge of `[3, 27, 38, 43]` and `[9, 10, 82]`:
* Compare `3` vs `9` $\rightarrow$ Pick `3`
* Compare `27` vs `9` $\rightarrow$ Pick `9`
* Compare `27` vs `10` $\rightarrow$ Pick `10`
* Compare `27` vs `82` $\rightarrow$ Pick `27`
* Compare `38` vs `82` $\rightarrow$ Pick `38`
* Compare `43` vs `82` $\rightarrow$ Pick `43`
* Remaining: `82`
* **Final Sorted Array**: 🎉 **`[3, 9, 10, 27, 38, 43, 82]`**

---

## ⚡ Why Merge Sort is Guaranteed $\mathcal{O}(N \log N)$

* **Splitting Tree Depth**: Halving an array of size $N$ takes $\log_2 N$ levels of recursion.
* **Merging Work**: Merging elements across each level takes $\mathcal{O}(N)$ comparisons.
* **Total Time**: $\mathcal{O}(N) \times \text{levels } (\log N) = \mathbf{\mathcal{O}(N \log N)}$!

| Array Size $N$ | $\mathcal{O}(N^2)$ Sorts (Bubble/Selection) | $\mathcal{O}(N \log N)$ Merge Sort | Speedup Factor |
| :--- | :--- | :--- | :--- |
| **$N = 1000$** | $1,000,000$ steps | $\approx 10,000$ steps | **100x faster!** 🚀 |
| **$N = 1,000,000$** | $1,000,000,000,000$ steps | $\approx 20,000,000$ steps | **50,000x faster!** ⚡ |

---

## 📊 Merge Sort Trade-off: Space Complexity

While Merge Sort is super fast, it requires **extra temporary memory (scratch space)** to merge the two sorted halves.

* **Time Complexity**: Always $\mathcal{O}(N \log N)$ (Worst, Average, Best Case).
* **Space Complexity**: $\mathcal{O}(N)$ extra space (due to temporary sub-arrays).

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
What is the Worst-Case Time Complexity of Merge Sort?
* A) $\mathcal{O}(N)$
* B) $\mathcal{O}(N \log N)$
* C) $\mathcal{O}(N^2)$

---

### Question 2:
Why does Merge Sort require $\mathcal{O}(N)$ Extra Space Complexity?
* A) It uses a single loop.
* B) It needs temporary buffer arrays to merge the two sorted halves back together.
* C) It runs on the CPU Call Stack.

---

### Question 3:
What is the Base Case that stops Merge Sort from splitting a sub-array further?
* A) When `low >= high` (sub-array has 1 element or 0 elements).
* B) When the array is completely full.
* C) When `mid == 0`.
