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
    ArrayElement *arrayElement;

    arrayElement = (ArrayElement*) malloc(sizeof (ArrayElement));
    arrayElement->next = NULL;

    return arrayElement;
}

/**-----------------------------------------------------
                    Basic operations
 -----------------------------------------------------*/

//  Prints an array list.
void print_ArrayElement(ArrayElement *arrayElement)
{
    if (arrayElement != NULL)
    {
        printf("[%d]", arrayElement->value);
    }
}
