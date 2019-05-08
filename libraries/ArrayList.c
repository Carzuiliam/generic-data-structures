/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "../include/ArrayList.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty array list.
ArrayList* new_ArrayList()
{
    ArrayList *arrayList;

    arrayList = (ArrayList*) malloc(sizeof (ArrayList));
    arrayList->start = NULL;

    return arrayList;
}

/**-----------------------------------------------------
                    Basic operations
 -----------------------------------------------------*/

//  Adds an element to the array list.
void addTo_ArrayList(ArrayList *arrayList, ArrayElement *arrayElement)
{
    if (arrayList == NULL)
    {
        return;
    }
    else if (arrayList->start == NULL)
    {
        arrayList->start = arrayElement;
        return;
    }
    else
    {
        ArrayElement *aux = arrayList->start;

        while (aux->next != NULL) aux = aux->next;

        aux->next = arrayElement;

        return;
    }
}

//  Prints all the elements of the array list.
void print_ArrayList(ArrayList *arrayList)
{
    if (arrayList != NULL)
    {
        printf("|--");

        ArrayElement *aux = arrayList->start;

        while (aux != NULL)
        {
            print_ArrayElement(aux);

            aux = aux->next;

            if (aux != NULL)
            {
                printf("-");
            }
        }

        printf("\n");
    }
}
