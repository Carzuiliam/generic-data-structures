/**-----------------------------------------------------
                    Program includes
 -----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "../libraries/Element.c"
#include "../libraries/List.c"
#include "../libraries/Stack.c"

/**-----------------------------------------------------
                    Main function
 -----------------------------------------------------*/

int main()
{
    //  Initializing elements.
    List *list = new_List();

    //  Setting an empty element for example.
    Element *elem1 = new_Element();
    setAsInt_Element(elem1, 1);

    //  Adding the empty and others elements to the stack.
    addFirst_List(list, elem1);
    addLast_List(list, new_CharElement('t'));
    addLast_List(list, new_IntElement(3));
    addLast_List(list, new_FloatElement(4.0f));
    addLast_List(list, new_StringElement("five"));

    print_List(list);

    //  Disposing and finishing.
    dispose_List(list);

    return 0;
}
