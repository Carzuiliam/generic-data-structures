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
                    Removing nodes
 -----------------------------------------------------*/

//  Removes an element at the specific index of the binary tree.
void removeAt_BinaryTree(BinaryTree *_binaryTree, unsigned int _index)
{
    if (_binaryTree == NULL) return;
    if (_binaryTree->root == NULL) return;

    if (_binaryTree->root->index == _index)
    {
        Node *aux = _binaryTree->root;

        if (aux->nextL == NULL && aux->nextR == NULL)
        {
            _binaryTree->root = NULL;
        }
        else if (aux->nextL == NULL)
        {
            _binaryTree->root = aux->nextR;
        }
        else if (aux->nextR == NULL)
        {
            _binaryTree->root = aux->nextL;
        }
        else
        {
            if ((_index - aux->nextL->index) <
                (aux->nextR->index - _index))
            {
                Node *node = aux->nextL;

                _binaryTree->root = aux->nextL;

                while (node->nextR != NULL)
                {
                    node = node->nextR;
                }

                node->nextR = aux->nextR;
            }
            else
            {
                Node *node = aux->nextR;

                _binaryTree->root = aux->nextR;

                while (node->nextL != NULL)
                {
                    node = node->nextL;
                }

                node->nextL = aux->nextL;
            }
        }

        dispose_Node(aux);
    }
    else
    {
        Node *prev = _binaryTree->root;
        Node *aux = _binaryTree->root;

        while (aux != NULL && aux->index != _index)
        {
            prev = aux;
            aux = (aux->index > _index) ? aux->nextL : aux->nextR;
        }

        if (aux != NULL)
        {
            if (aux->nextL == NULL && aux->nextR == NULL)
            {
                if (prev->nextL == aux)
                {
                    prev->nextL = NULL;
                }
                else
                {
                    prev->nextR = NULL;
                }
            }
            else if (aux->nextL == NULL)
            {
                prev->nextL = aux->nextR;
            }
            else if (aux->nextR == NULL)
            {
                prev->nextR = aux->nextL;
            }
            else
            {
                if (prev->nextL == aux)
                {
                    Node *node = aux->nextR;

                    prev->nextL = aux->nextR;

                    while (node->nextL != NULL)
                    {
                        node = node->nextL;
                    }

                    node->nextL = aux->nextL;
                }
                else
                {
                    Node *node = aux->nextL;

                    prev->nextR = aux->nextL;

                    while (node->nextR != NULL)
                    {
                        node = node->nextR;
                    }

                    node->nextR = aux->nextR;
                }
            }

            dispose_Node(aux);
        }
    }
}

/**-----------------------------------------------------
                    Structure info
 -----------------------------------------------------*/

//  Returns the number of leaves in a binary tree.
unsigned int length_BinaryTree(BinaryTree *_binaryTree)
{
    if (_binaryTree == NULL) return 0;

    return length_Node(_binaryTree->root);
}

//  Returns the height of the binary tree.
unsigned int height_BinaryTree(BinaryTree *_binaryTree)
{
    if (_binaryTree == NULL) return 0;

    return height_Node(_binaryTree->root);
}

//  Prints all the elements of the binary binaryTree.
void print_BinaryTree(BinaryTree *_binaryTree)
{
    if (_binaryTree == NULL)
    {
        printf("---------\n");
        printf("| Count |-[0]\n");
        printf("---------\n");
        printf("|Height |-[0]\n");
        printf("---------\n");
        printf("| Tree  |-\n");
        printf("--------- |\n");
        printf("       (null)\n\n");
    }
    else if (_binaryTree->root == NULL)
    {
        printf("---------\n");
        printf("| Count |-[0]\n");
        printf("---------\n");
        printf("|Height |-[0]\n");
        printf("---------\n");
        printf("| Tree  |-\n");
        printf("--------- |\n");
        printf("       (empty)\n\n");
    }
    else
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
        printf("| Tree  |-\n");
        printf("--------- |\n\n");

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
        printf("\n");
    }

    return;
}
