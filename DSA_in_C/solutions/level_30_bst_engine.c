#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Task 1: Insert a node into BST recursively (Return new root pointer)
struct TreeNode *insertNode(struct TreeNode *root, int value)
{
    if (root == NULL)
    {
        struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (root->data > value)
    {
        root->left = insertNode(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = insertNode(root->right, value); // 👈 Fixed typo
    }
    return root; // 👈 Add return root at the bottom!
}
// Task 2: Search for a value in BST (Return pointer to node or NULL if not found)
struct TreeNode *searchNode(struct TreeNode *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        return root;
    }
    if (root->data > target)
    {
        return searchNode(root->left, target);
    }
    if (root->data < target)
    {
        return searchNode(root->right, target);
    }
}

// Task 3: In-Order Traversal (Prints numbers in sorted ascending order)
void inOrderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d, ", root->data);
    inOrderTraversal(root->right);
}

// Task 4: Free entire BST recursively (Post-Order deletion)
void freeTree(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    struct TreeNode *root = NULL;

    // 1. Insert nodes
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);

    // 2. In-Order Traversal
    printf("In-Order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // 3. Search
    struct TreeNode *found = searchNode(root, 40);
    if (found != NULL)
        printf("Search 40: Found! (%d)\n", found->data);
    else
        printf("Search 40: Not Found!\n");

    struct TreeNode *notFound = searchNode(root, 99);
    if (notFound != NULL)
        printf("Search 99: Found! (%d)\n", notFound->data);
    else
        printf("Search 99: Not Found!\n");

    // 4. Free Memory
    freeTree(root);
    return 0;
}
