/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#pragma once

/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

typedef struct Tree
{
    unsigned int lenght;
    struct Node *root;
}
Tree;

/**-----------------------------------------------------
                    Functions prototypes
 -----------------------------------------------------*/

Tree* new_Tree();
void dispose_Tree(Tree*);

void addTo_Tree(Tree*, Node*);
