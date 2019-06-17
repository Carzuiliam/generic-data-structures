/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "Node.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty node.
Node* new_Node(int _index)
{
    Node *node = malloc(sizeof (Node));

    if (node != NULL)
    {
        node->index = 0;
        node->nextL = NULL;
        node->nextR = NULL;
    }

    return node;
}

//  Creates a char node.
Node* new_CharNode(int _index, char _value)
{
    Node *node = malloc(sizeof (Node));

    if (node != NULL)
    {
        node->index = _index;
        node->type = N_CHAR;
        node->value.c = _value;
        node->nextL = NULL;
        node->nextR = NULL;
    }

    return node;
}

//  Creates a float node.
Node* new_FloatNode(int _index, float _value)
{
    Node *node = malloc(sizeof (Node));

    if (node != NULL)
    {
        node->index = _index;
        node->type = N_FLOAT;
        node->value.f = _value;
        node->nextL = NULL;
        node->nextR = NULL;
    }

    return node;
}

//  Creates an integer node.
Node* new_IntNode(int _index, int _value)
{
    Node *node = malloc(sizeof (Node));

    if (node != NULL)
    {
        node->index = _index;
        node->type = N_INTEGER;
        node->value.i = _value;
        node->nextL = NULL;
        node->nextR = NULL;
    }

    return node;
}

//  Creates a string node.
Node* new_StringNode(int _index, char *_value)
{
    Node *node = malloc(sizeof (Node));

    if (node != NULL)
    {
        node->index = _index;
        node->type = N_STRING;
        node->value.s = _value;
        node->nextL = NULL;
        node->nextR = NULL;
    }

    return node;
}

/**-----------------------------------------------------
                    Structure destruction
 -----------------------------------------------------*/

 //  Disposes the node.
void dispose_Node(Node *_node)
{
    if (_node == NULL) return;

    _node->nextL = NULL;
    _node->nextR = NULL;

    free(_node);

    return;
}

/**-----------------------------------------------------
                    Basic operations
 -----------------------------------------------------*/

//  Adds a new node which contains a char as a value.
void setAsChar_Node(Node *_node, char _value)
{
    if (_node == NULL) return;

    _node->type = N_CHAR;
    _node->value.c = _value;

    return;
}

//  Adds a new node which contains a float as a value.
void setAsFloat_Node(Node *_node, float _value)
{
    if (_node == NULL) return;

    _node->type = N_FLOAT;
    _node->value.f = _value;

    return;
}

//  Adds a new node which contains a int as a value.
void setAsInt_Node(Node *_node, int _value)
{
    if (_node == NULL) return;

    _node->type = N_INTEGER;
    _node->value.i = _value;

    return;
}

//  Adds a new node which contains a char as a value.
void setAsString_Node(Node *_node, char *_value)
{
    if (_node == NULL) return;

    _node->type = N_STRING;
    _node->value.s = _value;

    return;
}

/**-----------------------------------------------------
                    Structure info
 -----------------------------------------------------*/

//  Returns the number of leaves that are descendants of a specific node.
unsigned int length_Node(Node *_node)
{
    if (_node == NULL) return 0;

    unsigned int length = 1;

    Node **nodes = malloc(sizeof (Node*));

    nodes[0] = _node;

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

//  Returns the height of a specific node.
unsigned int height_Node(Node *_node)
{
    if (_node == NULL) return 0;

    unsigned int height = 1;
    unsigned int length = length_Node(_node);

    int level[length];
    Node **nodes = malloc(length * sizeof (Node*));

    for (int i = 0; i < length; i++)
    {
        level[i] = -1;
        nodes[i] = NULL;
    }

    level[0] = 1;
    nodes[0] = _node;

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

//  Prints a node.
void print_Node(Node *_node)
{
    if (_node == NULL) return;

    switch (_node->type)
    {
        case N_CHAR:
            {
                printf("[#%2i: %4c]", _node->index, _node->value.c);
            }
            break;

        case N_FLOAT:
            {
                printf("[#%2i: %4.2f]", _node->index,  _node->value.f);
            }
            break;

        case N_INTEGER:
            {
                printf("[#%2i: %4i]", _node->index,  _node->value.i);
            }
            break;

        case N_STRING:
            {
                int index = 0;

                while (_node->value.s[index] != '\0') index++;

                if (index < 4)
                {
                    printf("[#%2i: %4s]", _node->index,  _node->value.s);
                }
                else
                {
                    printf("[#%2i: ", _node->index);

                    for (int pos = 0; pos < 3; pos++)
                    {
                        printf("%c", _node->value.s[pos]);
                    }

                    printf(".]");
                }
            }
            break;
    }

    return;
}
