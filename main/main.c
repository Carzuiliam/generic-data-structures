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

int main()
{
    //  Initializing elements.
    ArrayList *list = new_ArrayList();

    ArrayElement *elem1 = new_ArrayElement();
    ArrayElement *elem2 = new_ArrayElement();
    ArrayElement *elem3 = new_ArrayElement();
    ArrayElement *elem4 = new_ArrayElement();
    ArrayElement *elem5 = new_ArrayElement();

    //  Defining elements.
    setAsChar_ArrayElement(elem1, 'x');
    setAsFloat_ArrayElement(elem2, 2.1f);
    setAsFloat_ArrayElement(elem3, 3.6f);
    setAsFloat_ArrayElement(elem4, 4.9f);
    setAsFloat_ArrayElement(elem5, 5.3f);

    //  Adding elements to the list.
    addLast_ArrayList(list, elem1);
    addLast_ArrayList(list, elem2);
    addLast_ArrayList(list, elem3);
    addLast_ArrayList(list, elem4);
    addLast_ArrayList(list, elem5);

    //  Finishing and disposing.
    print_ArrayList(list);
    dispose_ArrayList(list);

    return 0;
}
