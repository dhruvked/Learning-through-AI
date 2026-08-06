#include <stdio.h>
#include <stdlib.h>

// Tier 1 Final Capstone Project: Browser History Manager (using Doubly Linked List)

struct Page
{
    int pageID; // Page ID / URL ID
    struct Page *prev;
    struct Page *next;
};

// Task 1: Visit a new page (Insert at current position and clear forward history)
void visitPage(struct Page **currentRef, int newPageID)
{
    // Write your code here!
    struct Page *newPage = (struct Page *)malloc(sizeof(struct Page));
    newPage->pageID = newPageID;
    newPage->prev = NULL;
    newPage->next = NULL;
    if (*currentRef == NULL)
    {
        *currentRef = newPage;
        return;
    }
    // 1. Free any forward history if it exists!
    struct Page *forward = (*currentRef)->next;
    while (forward != NULL)
    {
        struct Page *temp = forward->next;
        free(forward);
        forward = temp;
    }

    (*currentRef)->next = newPage;
    newPage->prev = (*currentRef);
    *currentRef = newPage;
}

// Task 2: Go Back in history (move current pointer to prev, or return 0 if at start)
int goBack(struct Page **currentRef)
{
    if (*currentRef == NULL)
    {
        printf("Empty pages");
        return -1;
    }
    if ((*currentRef)->prev == NULL)
    {
        printf("No previous page");
        return 0;
    }
    *currentRef = (*currentRef)->prev;
    printf("Returned to page: %d\n", (*currentRef)->pageID);
    return (*currentRef)->pageID;
}

// Task 3: Go Forward in history (move current pointer to next, or return 0 if at end)
int goForward(struct Page **currentRef)
{
    if (*currentRef == NULL)
    {
        printf("Empty pages");
        return -1;
    }
    if ((*currentRef)->next == NULL)
    {
        printf("No next page");
        return 0;
    }
    *currentRef = (*currentRef)->next;
    printf("Returned to page: %d\n", (*currentRef)->pageID);
    return (*currentRef)->pageID;
}

// Task 4: Free entire browser history from start to end
void freeHistory(struct Page **currentRef)
{
    if (*currentRef == NULL)
    {
        printf("Empty pages");
        return;
    }
    struct Page *i = (*currentRef)->next;
    while (i != NULL)
    {
        struct Page *temp = i->next;
        free(i);
        i = temp;
    }
    i = (*currentRef)->prev;
    while (i != NULL)
    {
        struct Page *temp = i->prev;
        free(i);
        i = temp;
    }
    free(*currentRef);
}

void displayHistory(struct Page *current)
{
    if (current == NULL)
    {
        printf("Empty History\n");
        return;
    }

    // 1. Walk back to the very first page
    struct Page *temp = current;
    while (temp->prev != NULL)
    {
        temp = temp->prev;
    }

    // 2. Print forward from start to end
    printf("Browser History: ");
    while (temp != NULL)
    {
        if (temp == current)
        {
            printf("[%d*] -> ", temp->pageID); // Marks active page with *
        }
        else
        {
            printf("%d -> ", temp->pageID);
        }
        temp = temp->next;
    }
    printf("END\n");
}

int main()
{
    struct Page *current = NULL;
    visitPage(&current, 101);
    visitPage(&current, 102);
    visitPage(&current, 103);
    goBack(&current);
    goBack(&current);
    goForward(&current);
    visitPage(&current, 104);
    displayHistory(current);
    freeHistory(&current);
    // Challenge:
    // 1. Visit page 101, 102, 103.
    // 2. Go back twice -> current should be page 101.
    // 3. Go forward once -> current should be page 102.
    // 4. Visit new page 104 -> page 103 should be replaced as forward history!
    // 5. Free all history memory.

    return 0;
}
