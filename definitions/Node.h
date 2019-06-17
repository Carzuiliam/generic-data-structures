/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#pragma once

/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

 typedef struct Node
{
    enum N_Type
    {
        N_CHAR,
        N_FLOAT,
        N_INTEGER,
        N_STRING
    }
    type;

    union N_Value
    {
        char c;
        float f;
        int i;
        char *s;
    }
    value;

    int index;

    struct Node *nextL;
    struct Node *nextR;
}
Node;

/**-----------------------------------------------------
                    Functions prototypes
 -----------------------------------------------------*/

Node* new_Node(int);
Node* new_CharNode(int, char);
Node* new_FloatNode(int, float);
Node* new_IntNode(int, int);
Node* new_StringNode(int, char*);

void dispose_Node(Node*);

void setAsChar_Node(Node*, char);
void setAsFloat_Node(Node*, float);
void setAsInt_Node(Node*, int);
void setAsString_Node(Node*, char*);

unsigned int length_Node(Node*);
unsigned int height_Node(Node*);
void print_Node(Node*);
