#include "ltree.h"

int main ()
{

    Ltree *my_tree = calloc(1, sizeof(Ltree));
    Init(my_tree, 2);

    // Insert(my_tree, 2);
    Insert(my_tree, 7);
    Insert(my_tree, 50);
    Insert(my_tree, 80);
    Insert(my_tree, 11);
    Insert(my_tree, 13);

    DFS(my_tree->root);


    return 0;
}