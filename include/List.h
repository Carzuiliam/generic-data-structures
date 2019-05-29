/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#pragma once

/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

typedef struct List
{
    unsigned int lenght;
    struct Element *start;
}
List;

/**-----------------------------------------------------
                    Functions prototypes
 -----------------------------------------------------*/

List* new_List();
void dispose_List(List *_list);

void addFirst_List(List *_list, Element *_element);
void addLast_List(List *_list, Element *_element);
void addAt_List(List *_list, Element *_element, unsigned int _index);

void removeFirst_List(List *_list);
void removeLast_List(List *_list);
void removeAt_List(List *_list, unsigned int _index);

Element* getFirst_List(List *_list);
Element* getLast_List(List *_list);
Element* getAt_List(List *_list, unsigned int _index);

void print_List(List *_list);
