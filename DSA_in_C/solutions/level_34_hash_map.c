#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 7

struct Node
{
    int key;
    int value;
    struct Node *next;
};

struct HashTable
{
    struct Node *buckets[TABLE_SIZE];
};

// Hash function: Compute index from key
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

// Task 1: Insert key-value pair into Hash Table using Separate Chaining (Insert at Head of bucket)
void insertHash(struct HashTable *ht, int key, int value)
{
    int index = hashFunction(key);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;

    // 1. Point newNode->next to current bucket head (whether NULL or existing Node!)
    newNode->next = ht->buckets[index];

    // 2. Point bucket head to newNode!
    ht->buckets[index] = newNode;
}

int searchHash(struct HashTable *ht, int key)
{
    int index = hashFunction(key); // 👈 Calculate index!

    struct Node *i = ht->buckets[index];
    while (i != NULL)
    {
        if (i->key == key)
        {
            return i->value; // Found!
        }
        i = i->next;
    }
    return -1; // Not found
}

// Task 3: Free entire Hash Table memory cleanly
void freeHashTable(struct HashTable *ht)
{
    // Write your code here!
    int i = 0;
    while (i < TABLE_SIZE)
    {
        struct Node *j = ht->buckets[i];
        while (j != NULL)
        {
            struct Node *temp = j;
            j = j->next;
            free(temp);
        }
        i++;
    }
}

int main()
{
    struct HashTable ht;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        ht.buckets[i] = NULL;
    }

    // Challenge:
    // 1. Insert (key: 10, val: 100), (key: 17, val: 200), (key: 24, val: 300)
    //    Notice: 10 % 7 = 3, 17 % 7 = 3, 24 % 7 = 3 (ALL 3 COLLIDE AT INDEX 3!).
    // 2. Search for key 17 (Expected: 200).
    // 3. Search for key 99 (Expected: -1 / Not Found).
    // 4. Free Hash Table memory.
    insertHash(&ht, 10, 100);
    insertHash(&ht, 17, 200);
    insertHash(&ht, 24, 300);
    printf("Search Key 17: %d\n", searchHash(&ht, 17));
    printf("Search Key 99: %d\n", searchHash(&ht, 99));
    freeHashTable(&ht);
    return 0;
}
