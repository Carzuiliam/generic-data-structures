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

//  Prints a node.
void print_Node(Node *_node)
{
    if (_node == NULL) return;

    switch (_node->type)
    {
        case N_CHAR:
            {
                printf("(#i)[%c]", _node->index, _node->value.c);
            }
            break;

        case N_FLOAT:
            {
                printf("(#i)[%.2f]", _node->index,  _node->value.f);
            }
            break;

        case N_INTEGER:
            {
                printf("(#i)[%i]", _node->index,  _node->value.i);
            }
            break;

        case N_STRING:
            {
                printf("(#i)[%s]", _node->index,  _node->value.s);
            }
            break;
    }

    return;
}
