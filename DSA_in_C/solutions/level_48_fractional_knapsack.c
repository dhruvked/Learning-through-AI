#include <stdio.h>
#include <stdlib.h>

struct Item
{
    double weight;
    double value;
};

// Comparator for qsort: Sort items by Value/Weight ratio in DESCENDING order
int compareItems(const void *a, const void *b)
{
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    double ratioA = itemA->value / itemA->weight;
    double ratioB = itemB->value / itemB->weight;

    if (ratioB > ratioA)
        return 1;
    if (ratioB < ratioA)
        return -1;
    return 0;
}

// Task 1: Fractional Knapsack Engine in C (Greedy Strategy)
double fractionalKnapsack(double W, struct Item items[], int n)
{
    qsort(items, n, sizeof(struct Item), compareItems);
    double val = 0.0;
    double w = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (items[i].weight + w > W)
        {
            val = val + ((items[i].value / items[i].weight) * (W - w));
            break;
        }
        val = val + items[i].value;
        w = w + items[i].weight;
    }
    return val;
}

int main()
{
    struct Item items[] = {
        {10, 60},  // Item 1: W=10, V=60  (Ratio = $6/kg)
        {20, 100}, // Item 2: W=20, V=100 (Ratio = $5/kg)
        {30, 120}  // Item 3: W=30, V=120 (Ratio = $4/kg)
    };
    int n = 3;
    double W = 50; // Knapsack Capacity = 50 kg

    // Expected Output: Maximum Value: 240.00
    // (Take ALL of Item 1 (10kg, $60) + ALL of Item 2 (20kg, $100) + 20kg of Item 3 ($80) = $240)

    double maxVal = fractionalKnapsack(W, items, n);
    printf("Maximum Value: %.2f\n", maxVal);

    return 0;
}
