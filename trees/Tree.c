/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "Tree.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty tree.
Tree* new_Tree()
{
    Tree *tree = malloc(sizeof (Tree));

    if (tree != NULL)
    {
        tree->lenght = 0;
        tree->root = NULL;
    }

    return tree;
}

/**-----------------------------------------------------
                    Structure destruction
 -----------------------------------------------------*/

void dispose_Tree(Tree *_tree)
{
    if (_tree == NULL) return;

    if (_tree->root != NULL)
    {
        Node *nodes[_tree->lenght];

        nodes[0] = _tree->root;

        for (int i = 0; i < _tree->lenght; i++)
        {
            int j = 0;

            while (nodes[j] != NULL) j++;

            if (nodes[i]->nextL != NULL)
            {
                nodes[j] = nodes[i]->nextL;
                j++;
            }

            if (nodes[i]->nextR != NULL)
            {
                nodes[j] = nodes[i]->nextR;
            }
        }

        for (int i = 0; i < _tree->lenght; i++)
        {
            dispose_Node(nodes[i]);
        }
    }

    free(_tree);

    return;
}

/**-----------------------------------------------------
                    Inserting nodes
 -----------------------------------------------------*/

//  Adds an element inside the tree.
void addTo_Tree(Tree *_tree, Node *_node)
{
    if (_tree == NULL) return;

    if (_tree->root == NULL)
    {
        _tree->root = _node;
        _tree->lenght++;
    }

    return;
}
