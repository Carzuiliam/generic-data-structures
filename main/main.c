/**-----------------------------------------------------
                    Program includes
 -----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "../libraries/ArrayElement.c"
#include "../libraries/ArrayList.c"

/**-----------------------------------------------------
                    Main function
 -----------------------------------------------------*/

// The entry point of the application.
void main()
{
    ArrayList *list = new_ArrayList();

    ArrayElement *elem1 = new_ArrayElement();
    ArrayElement *elem2 = new_ArrayElement();

    elem1->value = (int *)20;
    elem2->value = (int *)10;

    addTo_ArrayList(list, elem1);
    addTo_ArrayList(list, elem2);

    print_ArrayList(list);

    return;
}
