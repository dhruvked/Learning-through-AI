#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 3
#define HASH_SIZE 10

// Doubly Linked List Node for LRU Cache
typedef struct Node
{
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

// LRU Cache Struct combining Hash Map array and Dummy Head/Tail DLL
typedef struct
{
    int capacity;
    int count;
    Node *head;                 // Dummy Head
    Node *tail;                 // Dummy Tail
    Node *hashTable[HASH_SIZE]; // Simple direct/bucket map pointers
} LRUCache;

// Helper: Create a new DLL Node
Node *createNode(int key, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Helper: Initialize LRU Cache with Dummy Head and Tail
LRUCache *createCache(int capacity)
{
    LRUCache *cache = (LRUCache *)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->count = 0;

    cache->head = createNode(0, 0);
    cache->tail = createNode(0, 0);

    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;

    for (int i = 0; i < HASH_SIZE; i++)
    {
        cache->hashTable[i] = NULL;
    }

    return cache;
}

// Helper: Add Node right after Dummy Head (Most Recently Used position)
void addNodeToHead(LRUCache *cache, Node *node)
{
    node->next = cache->head->next;
    node->prev = cache->head;
    cache->head->next->prev = node;
    cache->head->next = node;
}

// Helper: Remove an existing node from DLL
void removeNode(Node *node)
{
    Node *prevNode = node->prev;
    Node *nextNode = node->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
}

// Helper: Move an existing node to Head (Mark as Most Recently Used)
void moveToHead(LRUCache *cache, Node *node)
{
    removeNode(node);
    addNodeToHead(cache, node);
}

// Helper: Pop the Least Recently Used node (Right before Dummy Tail)
Node *popTail(LRUCache *cache)
{
    Node *res = cache->tail->prev;
    removeNode(res);
    return res;
}

// Task 1: LRU Get Key in O(1) Constant Time
int lruGet(LRUCache *cache, int key)
{
    struct Node *node = cache->hashTable[key % HASH_SIZE];
    if (node == NULL)
    {
        return -1;
    }
    moveToHead(cache, node);
    return node->value;
}

// Task 2: LRU Put Key-Value in O(1) Constant Time (Evicting Tail if Full)
void lruPut(LRUCache *cache, int key, int value)
{
    struct Node *node = cache->hashTable[key % HASH_SIZE];
    if (node != NULL)
    {
        node->value = value;
        moveToHead(cache, node);
        return;
    }
    Node *newNode = createNode(key, value);
    cache->hashTable[key % HASH_SIZE] = newNode;
    addNodeToHead(cache, newNode);
    cache->count++;
    if (cache->count > cache->capacity)
    {
        Node *tailNode = popTail(cache);
        cache->hashTable[tailNode->key % HASH_SIZE] = NULL;
        free(tailNode);
        cache->count--;
    }
}

int main()
{
    LRUCache *cache = createCache(CAPACITY);

    printf("--- Testing LRU Cache (Capacity = 3) ---\n");
    lruPut(cache, 1, 100);
    lruPut(cache, 2, 200);
    lruPut(cache, 3, 300);

    printf("Get(1): %d (Expected: 100)\n", lruGet(cache, 1)); // Key 1 becomes MRU

    lruPut(cache, 4, 400); // Cache is full! Evicts Key 2 (Least Recently Used)

    printf("Get(2): %d (Expected: -1 - Evicted!)\n", lruGet(cache, 2));
    printf("Get(3): %d (Expected: 300)\n", lruGet(cache, 3));
    printf("Get(4): %d (Expected: 400)\n", lruGet(cache, 4));

    return 0;
}
