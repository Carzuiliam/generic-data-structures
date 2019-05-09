/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "../include/ArrayElement.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty array element.
ArrayElement* new_ArrayElement()
{
    ArrayElement *arrayElement =
        (ArrayElement*) malloc(sizeof (ArrayElement));

    if (arrayElement != NULL)
    {
        arrayElement->next = NULL;
    }

    return arrayElement;
}

/**-----------------------------------------------------
                    Structure destruction
 -----------------------------------------------------*/

 //  Disposes the array element.
void dispose_ArrayElement(ArrayElement *_arrayElement)
{
    if (_arrayElement == NULL) return;

    _arrayElement->next = NULL;

    free(_arrayElement);

    return;
}

/**-----------------------------------------------------
                    Basic operations
 -----------------------------------------------------*/

//  Adds a new element which contains a char as a value.
void setAsChar_ArrayElement(ArrayElement *_arrayElement, char _value)
{
    if (_arrayElement == NULL) return;

    _arrayElement->type = CHAR;
    _arrayElement->value.c = _value;

    return;
}

//  Adds a new element which contains a float as a value.
void setAsFloat_ArrayElement(ArrayElement *_arrayElement, float _value)
{
    if (_arrayElement == NULL) return;

    _arrayElement->type = FLOAT;
    _arrayElement->value.f = _value;

    return;
}

//  Adds a new element which contains a int as a value.
void setAsInt_ArrayElement(ArrayElement *_arrayElement, int _value)
{
    if (_arrayElement == NULL) return;

    _arrayElement->type = INTEGER;
    _arrayElement->value.i = _value;

    return;
}

//  Adds a new element which contains a char as a value.
void setAsString_ArrayElement(ArrayElement *_arrayElement, char* _value)
{
    if (_arrayElement == NULL) return;

    _arrayElement->type = STRING;
    _arrayElement->value.s = _value;

    return;
}

/**-----------------------------------------------------
                    Structure info
 -----------------------------------------------------*/

//  Prints an array list.
void print_ArrayElement(ArrayElement *_arrayElement)
{
    if (_arrayElement == NULL) return;

    switch (_arrayElement->type)
    {
        case CHAR:
            printf("[%c]", _arrayElement->value.c);
            break;

        case FLOAT:
            printf("[%.2f]", _arrayElement->value.f);
            break;

        case INTEGER:
            printf("[%i]", _arrayElement->value.i);
            break;

        case STRING:
            printf("[%s]", _arrayElement->value.s);
            break;
    }

    return;
}
