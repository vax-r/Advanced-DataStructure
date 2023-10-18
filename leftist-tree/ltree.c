#include "ltree.h"


// swap two tree, still room for improvements
void swap (struct tree_node **a, struct tree_node **b)
{
    struct tree_node **tmp = a;
    a = b;
    b = tmp;
}

// Initialization of a Ltree
void Init (Ltree *t, int value)
{
    t->root = calloc(1, sizeof(struct tree_node));
    t->root->data = value;
    t->root->shortest = 1;
    t->root->leftChild = NULL;
    t->root->rightChild = NULL;
}

// Meld Ltree a and Ltree b into a single tree
struct tree_node *Meld(struct tree_node *a, struct tree_node *b)
{
    if (!b)
        return a;
    
    if (a->data > b->data) {
        struct tree_node *tmp = a;
        a = b;
        b = tmp;
    }
    
    if (!a->rightChild)
        a->rightChild = b;
    else
        a->rightChild = Meld(a->rightChild, b);

    if (!a->leftChild || a->leftChild->shortest < a->rightChild->shortest) {
        struct tree_node *tmp = a->leftChild;
        a->leftChild = a->rightChild;
        a->rightChild = tmp;
    }

    if (!a->rightChild)
        a->shortest = 1;
    else
        a->shortest = a->rightChild->shortest + 1;
    return a;
}

void Insert (Ltree *t, int value)
{
    struct tree_node *new_node = calloc(1, sizeof(struct tree_node));
    new_node->data = value;
    new_node->shortest = 1;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    t->root = Meld(t->root, new_node);
}

int DeleteMin(Ltree *t)
{
    int result = t->root->data;
    t->root = Meld(t->root->leftChild, t->root->rightChild);
    return result;
}

int GetMin(Ltree *t)
{
    return t->root->data;
}

void DFS(struct tree_node *a)
{
    if (!a)
        return;
    printf("%d, shortest = %d\n", a->data, a->shortest);
    DFS(a->leftChild);
    DFS(a->rightChild);
}