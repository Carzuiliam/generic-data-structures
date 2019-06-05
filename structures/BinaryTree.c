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

        Node **nodes = malloc(length * sizeof (Node*));

        nodes[0] = _binaryTree->root;

        for (int i = 1; i < length; i++)
        {
            nodes[i] = NULL;
        }

        for (int i = 0; i < length; i++)
        {
            int j = 0;

            while (j < length && nodes[j] != NULL) j++;

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

        for (int i = 0; i < length; i++)
        {
            dispose_Node(nodes[i]);
        }

        _binaryTree->root = NULL;

        free(nodes);
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

    unsigned int length = 1;

    Node **nodes = malloc(sizeof (Node*));

    nodes[0] = _binaryTree->root;

    for (int i = 0; i < length; i++)
    {
        if (nodes[i]->nextL != NULL)
        {
            length++;
            nodes = realloc(nodes, length * sizeof(Node*));
            nodes[length - 1] = nodes[i]->nextL;
        }

        if (nodes[i]->nextR != NULL)
        {
            length++;
            nodes = realloc(nodes, length * sizeof(Node*));
            nodes[length - 1] = nodes[i]->nextR;
        }
    }

    free(nodes);

    return length;
}

//  Returns the height of the binary tree.
unsigned int height_BinaryTree(BinaryTree *_binaryTree)
{
    if (_binaryTree == NULL) return 0;
    if (_binaryTree->root == NULL) return 0;

    unsigned int height = 1;
    unsigned int length = length_BinaryTree(_binaryTree);

    int level[length];
    Node **nodes = malloc(length * sizeof (Node*));

    for (int i = 0; i < length; i++)
    {
        level[i] = -1;
        nodes[i] = NULL;
    }

    level[0] = 1;
    nodes[0] = _binaryTree->root;

    for (int i = 0; i < length; i++)
    {
        int j = 0;

        while (j < length && nodes[j] != NULL) j++;

        if (nodes[i]->nextL != NULL)
        {
            level[j] = level[i] + 1;
            nodes[j] = nodes[i]->nextL;
            j++;
        }

        if (nodes[i]->nextR != NULL)
        {
            level[j] = level[i] + 1;
            nodes[j] = nodes[i]->nextR;
        }
    }

    for (int i = 0; i < length; i++)
    {
        if (height < level[i])
        {
            height = level[i];
        }
    }

    free(nodes);

    return height;
}

//  Prints all the elements of the binary binaryTree.
void print_BinaryTree(BinaryTree *_binaryTree)
{
    if (_binaryTree == NULL) return;

    if (_binaryTree->root != NULL)
    {
        unsigned int length = length_BinaryTree(_binaryTree);
        unsigned int height = height_BinaryTree(_binaryTree);

        printf("---------\n");
        printf("| Count |-");
        printf("[%i]\n", length);
        printf("---------\n");
        printf("|Height |-");
        printf("[%i]\n", height);
        printf("---------\n");
        printf("| Tree  |--\n");
        printf("---------  |\n\n");

        int maxLength = 1;
        int index = 0;

        for (int i = 0; i < height; i++)
        {
            maxLength += maxLength;
        }

        maxLength--;

        Node **nodes = malloc(maxLength * sizeof (Node*));

        for (int i = 0; i < maxLength; i++)
        {
            nodes[i] = NULL;
        }

        nodes[0] = _binaryTree->root;

        for (int i = 0; i < maxLength; i++)
        {
            if (nodes[i] != NULL)
            {
                index++;

                if (index < maxLength)
                {
                    nodes[index] = nodes[i]->nextL;
                }

                index++;

                if (index < maxLength)
                {
                    nodes[index] = nodes[i]->nextR;
                }
            }
            else
            {
                index++;

                if (index < maxLength)
                {
                    nodes[index] = NULL;
                }

                index++;

                if (index < maxLength)
                {
                    nodes[index] = NULL;
                }
            }
        }

        index = 1;
        int factor = 1;
        int spacing = height - 1;

        for (int i = 0; i < maxLength; i++)
        {
            if (nodes[i] != NULL)
            {
                print_Node(nodes[i]);
            }
            else
            {
                printf("[         ]");
            }

            printf(" ");

            if (index == factor)
            {
                spacing--;

                index = 1;
                factor += factor;

                printf("\n");
            }
            else
            {
                index++;
            }
        }

        free(nodes);
    }

    return;
}
