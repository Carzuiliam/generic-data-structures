/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#pragma once

/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

typedef struct SingleList
{
    struct Element *start;
}
SingleList;

/**-----------------------------------------------------
                    Functions prototypes
 -----------------------------------------------------*/

SingleList* new_SingleList();
void dispose_SingleList(SingleList*);

void addFirst_SingleList(SingleList*, Element*);
void addLast_SingleList(SingleList*, Element*);
void addAt_SingleList(SingleList*, Element*, unsigned int);

void removeFirst_SingleList(SingleList*);
void removeLast_SingleList(SingleList*);
void removeAt_SingleList(SingleList*, unsigned int);

Element* getFirst_SingleList(SingleList*);
Element* getLast_SingleList(SingleList*);
Element* getAt_SingleList(SingleList*, unsigned int);

unsigned int length_SingleList(SingleList*);
void print_List(SingleList*);
