/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "../include/Element.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty element.
Element* new_Element()
{
    Element *element = malloc(sizeof (Element));

    if (element != NULL)
    {
        element->next = NULL;
    }

    return element;
}

//  Creates a char element.
Element* new_CharElement(char _value)
{
    Element *element = malloc(sizeof (Element));

    if (element != NULL)
    {
        element->type = E_CHAR;
        element->value.c = _value;
        element->next = NULL;
    }

    return element;
}

//  Creates a float element.
Element* new_FloatElement(float _value)
{
    Element *element = malloc(sizeof (Element));

    if (element != NULL)
    {
        element->type = E_FLOAT;
        element->value.f = _value;
        element->next = NULL;
    }

    return element;
}

//  Creates an integer element.
Element* new_IntElement(int _value)
{
    Element *element = malloc(sizeof (Element));

    if (element != NULL)
    {
        element->type = E_INTEGER;
        element->value.i = _value;
        element->next = NULL;
    }

    return element;
}

//  Creates a string element.
Element* new_StringElement(char* _value)
{
    Element *element = malloc(sizeof (Element));

    if (element != NULL)
    {
        element->type = E_STRING;
        element->value.s = _value;
        element->next = NULL;
    }

    return element;
}

/**-----------------------------------------------------
                    Structure destruction
 -----------------------------------------------------*/

 //  Disposes the element.
void dispose_Element(Element *_element)
{
    if (_element == NULL) return;

    _element->next = NULL;

    free(_element);

    return;
}

/**-----------------------------------------------------
                    Basic operations
 -----------------------------------------------------*/

//  Adds a new element which contains a char as a value.
void setAsChar_Element(Element *_element, char _value)
{
    if (_element == NULL) return;

    _element->type = E_CHAR;
    _element->value.c = _value;

    return;
}

//  Adds a new element which contains a float as a value.
void setAsFloat_Element(Element *_element, float _value)
{
    if (_element == NULL) return;

    _element->type = E_FLOAT;
    _element->value.f = _value;

    return;
}

//  Adds a new element which contains a int as a value.
void setAsInt_Element(Element *_element, int _value)
{
    if (_element == NULL) return;

    _element->type = E_INTEGER;
    _element->value.i = _value;

    return;
}

//  Adds a new element which contains a char as a value.
void setAsString_Element(Element *_element, char *_value)
{
    if (_element == NULL) return;

    _element->type = E_STRING;
    _element->value.s = _value;

    return;
}

/**-----------------------------------------------------
                    Structure info
 -----------------------------------------------------*/

//  Prints an element.
void print_Element(Element *_element)
{
    if (_element == NULL) return;

    switch (_element->type)
    {
        case E_CHAR:
            printf("[%c]", _element->value.c);
            break;

        case E_FLOAT:
            printf("[%.2f]", _element->value.f);
            break;

        case E_INTEGER:
            printf("[%i]", _element->value.i);
            break;

        case E_STRING:
            printf("[%s]", _element->value.s);
            break;
    }

    return;
}
