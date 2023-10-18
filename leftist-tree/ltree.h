#include <stdlib.h>
#include <stdio.h>

struct tree_node {
    int data; // the data of the node
    struct tree_node *leftChild, *rightChild;
    int shortest; // the shortest path from the node to an external node
};

typedef struct {
    struct tree_node *root;
} Ltree;

#define MAX 100

// Initialization of a Ltree
void Init(Ltree *t, int value);

struct tree_node *Meld(struct tree_node *a, struct tree_node *b);

int GetMin(Ltree *t);

void Insert(Ltree *t, int value);

int DeleteMin(Ltree *t);

void DFS(struct tree_node *a);