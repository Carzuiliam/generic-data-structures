/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#pragma once

/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

typedef struct Element
{
    enum E_Type
    {
        E_CHAR,
        E_FLOAT,
        E_INTEGER,
        E_STRING
    }
    type;

    union E_Value
    {
        char c;
        float f;
        int i;
        char *s;
    }
    value;

    struct Element *next;
}
Element;

/**-----------------------------------------------------
                    Functions prototypes
 -----------------------------------------------------*/

Element* new_Element();
Element* new_CharElement(char);
Element* new_FloatElement(float);
Element* new_IntElement(int);
Element* new_StringElement(char*);

void dispose_Element(Element*);

void setAsChar_Element(Element*, char);
void setAsFloat_Element(Element*, float);
void setAsInt_Element(Element*, int);
void setAsString_Element(Element*, char*);

void print_Element(Element*);
