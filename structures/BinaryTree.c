/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "BinaryTree.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty binary binaryTree.
BinaryTree* new_BinaryTree()
{
    BinaryTree *binaryTree = malloc(sizeof (BinaryTree));

    if (binaryTree != NULL)
    {
        binaryTree->root = NULL;
    }

    return binaryTree;
}

/**-----------------------------------------------------
                    Structure destruction
 -----------------------------------------------------*/

 // Disposes a binary binaryTree.
void dispose_BinaryTree(BinaryTree *_binaryTree)
{
    if (_binaryTree == NULL) return;

    if (_binaryTree->root != NULL)
    {
        unsigned int length = length_BinaryTree(_binaryTree);

        Node *nodes[length];

        nodes[0] = _binaryTree->root;

        for (int i = 1; i < length; i++)
        {
            nodes[i] = NULL;
        }

        for (int i = 0; i < length; i++)
        {
            int j = 0;

            while (j < length && nodes[j] != NULL) j++;

            if (j < length)
            {
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
        }

        for (int i = 0; i < length; i++)
        {
            dispose_Node(nodes[i]);
        }
    }

    free(_binaryTree);

    return;
}

/**-----------------------------------------------------
                    Inserting nodes
 -----------------------------------------------------*/

//  Adds an element inside the binary binaryTree based on its index.
void addTo_BinaryTree(BinaryTree *_binaryTree, Node *_node)
{
    if (_binaryTree == NULL) return;

    if (_binaryTree->root == NULL)
    {
        _binaryTree->root = _node;_binaryTree->root;
    }
    else
    {
        Node *prev = _binaryTree->root;
        Node *aux = _binaryTree->root;

        while (aux != NULL)
        {
            prev = aux;
            aux = (_node->index < aux->index) ? aux->nextL : aux->nextR;
        }

        if (_node->index < prev->index)
        {
            prev->nextL = _node;
        }
        else
        {
            prev->nextR = _node;
        }
    }

    return;
}

/**-----------------------------------------------------
                    Structure info
 -----------------------------------------------------*/

//  Returns the number of leaves in a binary tree.
unsigned int length_BinaryTree(BinaryTree *_binaryTree)
{
    if (_binaryTree == NULL) return 0;
    if (_binaryTree->root == NULL) return 0;

    unsigned int length = 0;

    Node *root = _binaryTree->root;
    Node **nodes = realloc(root, sizeof (Node*));

    if (nodes != NULL)
    {
        length++;

        for (int i = 0; i < length; i++)
        {
            if (nodes[i]->nextL != NULL)
            {
                //length++;
            }

            //if (nodes[i]->nextR != NULL)
            //{
            //    length++;
            //    nodes = realloc(nodes, length * sizeof(Node));
            //    nodes[length - 1] = nodes[i]->nextR;
            //}
        }
    }

    return length;
}

//  Returns the height of the binary tree.
unsigned int height_BinaryTree(BinaryTree *_binaryTree)
{
    if (_binaryTree == NULL) return 0;
    if (_binaryTree->root == NULL) return 0;

    unsigned int height = 0;

    //  TODO

    return height;
}

//  Prints all the elements of the binary binaryTree.
void print_BinaryTree(BinaryTree *_binaryTree)
{
    if (_binaryTree == NULL) return;

    if (_binaryTree->root != NULL)
    {
        printf("---------\n");
        printf("|Count  |-");
        printf("[%i]\n", length_BinaryTree(_binaryTree));
        printf("---------\n");
    }

    return;
}
