#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

struct MinHeap
{
    int arr[MAX_CAPACITY];
    int size;
};

// Utility function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertHeap(struct MinHeap *heap, int value)
{
    if (heap->size == MAX_CAPACITY)
    {
        printf("Heap Overflow\n");
        return;
    }

    // 1. Insert at the end
    heap->arr[heap->size] = value;
    heap->size++;

    // 2. Heapify-Up!
    int i = heap->size - 1;
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (heap->arr[i] < heap->arr[parent])
        {
            swap(&heap->arr[i], &heap->arr[parent]);
            i = parent; // 👈 Move i up to parent position
        }
        else
        {
            break;
        }
    }
}

int extractMin(struct MinHeap *heap)
{
    if (heap->size == 0)
    {
        printf("Empty heap\n");
        return -1;
    }

    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1]; // Move last element to root
    heap->size--;                             // Shrink size

    // Heapify-Down!
    int i = 0;
    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i; // Assume parent i is smallest

        // Check if left child is smaller
        if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        {
            smallest = left;
        }

        // Check if right child is smaller than current smallest
        if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        {
            smallest = right;
        }

        // If a smaller child was found, swap and move down!
        if (smallest != i)
        {
            swap(&heap->arr[i], &heap->arr[smallest]);
            i = smallest; // Move i down to swapped child's slot
        }
        else
        {
            break; // Min-Heap property is satisfied!
        }
    }
    printf("Min: %d\n", min);
    return min;
}

int main()
{
    struct MinHeap heap;
    heap.size = 0;

    // Challenge:
    // 1. Insert 50, 30, 20, 15, 10 into Min-Heap.
    // 2. Extract Min (Expected: 10).
    // 3. Extract Min (Expected: 15).
    // 4. Extract Min (Expected: 20).
    insertHeap(&heap, 50);
    insertHeap(&heap, 30);
    insertHeap(&heap, 20);
    insertHeap(&heap, 15);
    insertHeap(&heap, 10);
    extractMin(&heap);
    extractMin(&heap);
    extractMin(&heap);
    return 0;
}
