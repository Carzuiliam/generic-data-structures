/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#pragma once

/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

typedef struct BinaryTree
{
    struct Node *root;
}
BinaryTree;

/**-----------------------------------------------------
                    Functions prototypes
 -----------------------------------------------------*/

BinaryTree* new_BinaryTree();
void dispose_Tree(BinaryTree*);

void addTo_BinaryTree(BinaryTree*, Node*);

void removeAt_BinaryTree(BinaryTree*, unsigned int);

unsigned int length_BinaryTree(BinaryTree*);
unsigned int height_BinaryTree(BinaryTree*);
void print_BinaryTree(BinaryTree*);
