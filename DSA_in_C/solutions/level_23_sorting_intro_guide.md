# 🫧 Level 23 Study Guide: Elementary Sorting (Bubble Sort & Selection Sort)

> **Goal**: Master how **Bubble Sort** and **Selection Sort** rearrange unsorted data into ascending order in $\mathcal{O}(N^2)$ time.

---

## 🧼 1. Bubble Sort: "Float the Heaviest Item to the Top"

### How it works:
* Compare adjacent pairs `arr[j]` and `arr[j+1]`.
* If `arr[j] > arr[j+1]`, **swap them**!
* After Pass 1, the **largest item** "bubbles up" to the very end of the array.
* Repeat $N-1$ times.

### Code Pattern:
```c
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {          // Outer loop (Passes)
        for (int j = 0; j < n - i - 1; j++) {  // Inner loop (Pairs)
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

* **Time Complexity**: Worst Case $\mathcal{O}(N^2)$, Best Case (Optimized) $\mathcal{O}(N)$.
* **Space Complexity**: $\mathcal{O}(1)$ (In-place sorting).

---

## 🎯 2. Selection Sort: "Find the Minimum & Swap to Front"

### How it works:
* Find the **smallest element** in the unsorted portion of the array.
* **Swap** it with the first unsorted position.
* Repeat for the next position.

### Code Pattern:
```c
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; // Assume current position is minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update index of smallest item found
            }
        }
        // Swap smallest item into position i
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
```

* **Time Complexity**: Always $\mathcal{O}(N^2)$ (even if array is already sorted!).
* **Space Complexity**: $\mathcal{O}(1)$ (In-place sorting).

---

## 📊 Comparison Table

| Sorting Algorithm | Best Case Time | Worst Case Time | Number of Swaps |
| :--- | :--- | :--- | :--- |
| **Bubble Sort** | $\mathcal{O}(N)$ (Optimized) | $\mathcal{O}(N^2)$ | Many swaps (every out-of-order pair) |
| **Selection Sort** | $\mathcal{O}(N^2)$ | $\mathcal{O}(N^2)$ | At most $N-1$ swaps (1 swap per pass) |

---

## ❓ Interactive Quiz: Test Your Understanding!

Answer these 3 questions right here in chat:

### Question 1:
After **Pass 1** of Bubble Sort on `[5, 1, 4, 2, 8]`, which element is guaranteed to be in its final sorted position at the end of the array?
* A) 1
* B) 5
* C) 8

---

### Question 2:
Which sorting algorithm performs **fewer swaps** in total?
* A) Bubble Sort (swaps continuously on adjacent pairs)
* B) Selection Sort (swaps only once per outer pass after finding min)

---

### Question 3:
What is the Worst-Case Time Complexity for both Bubble Sort and Selection Sort?
* A) $\mathcal{O}(1)$
* B) $\mathcal{O}(\log N)$
* C) $\mathcal{O}(N^2)$
