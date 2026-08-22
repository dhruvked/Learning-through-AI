#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie Node Definition
typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

// Helper: Create a new Trie Node initialized with NULL children and false isEndOfWord
TrieNode *createTrieNode()
{
    TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
    newNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Task 1: Insert a word into the Trie Engine
void insertTrie(TrieNode *root, const char *word)
{
    // Write your code here!
    TrieNode *curr = root;
    for (int i = 0; i < strlen(word); i++)
    {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL)
        {
            curr->children[index] = createTrieNode();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

// Task 2: Search if exact word exists in the Trie
bool searchTrie(TrieNode *root, const char *word)
{
    TrieNode *curr = root;
    for (int i = 0; i < strlen(word); i++)
    {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL)
        {
            return false;
        }
        curr = curr->children[index];
    }
    return curr->isEndOfWord;
}

// Task 3: Check if any word starts with the given Prefix (Autocomplete check)
bool startsWithPrefix(TrieNode *root, const char *prefix)
{
    TrieNode *curr = root;
    for (int i = 0; i < strlen(prefix); i++)
    {
        int index = prefix[i] - 'a';
        if (curr->children[index] == NULL)
        {
            return false;
        }
        curr = curr->children[index];
    }
    return true;
}

int main()
{
    TrieNode *root = createTrieNode();

    printf("--- Testing Autocomplete Trie Engine ---\n");
    insertTrie(root, "apple");
    insertTrie(root, "app");
    insertTrie(root, "application");
    insertTrie(root, "bat");

    printf("Search 'app': %s (Expected: Found)\n", searchTrie(root, "app") ? "Found" : "Not Found");
    printf("Search 'apple': %s (Expected: Found)\n", searchTrie(root, "apple") ? "Found" : "Not Found");
    printf("Search 'appl': %s (Expected: Not Found)\n", searchTrie(root, "appl") ? "Found" : "Not Found");

    printf("StartsWithPrefix 'appl': %s (Expected: Yes)\n", startsWithPrefix(root, "appl") ? "Yes" : "No");
    printf("StartsWithPrefix 'bat': %s (Expected: Yes)\n", startsWithPrefix(root, "bat") ? "Yes" : "No");
    printf("StartsWithPrefix 'cat': %s (Expected: No)\n", startsWithPrefix(root, "cat") ? "Yes" : "No");

    return 0;
}
