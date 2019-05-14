/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

typedef struct List
{
    int lenght;
    struct Element *start;
}
List;

/**-----------------------------------------------------
                    Functions prototypes
 -----------------------------------------------------*/

List* new_List();
void dispose_List(List *_list);

void addFirst_List(List *_list, Element *_element);
void addAt_List(List *_list, Element *_element, int _index);
void addLast_List(List *_list, Element *_element);

void removeFirst_List(List *_list);
void removeAt_List(List *_list, int _index);
void removeLast_List(List *_list);

Element* getFirst_List(List *_list);
Element* getAt_List(List *_list, int _index);
Element* getLast_List(List *_list);

void print_List(List *_list);
