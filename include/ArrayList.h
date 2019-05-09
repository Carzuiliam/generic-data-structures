/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

//  Defines a new array list, with generic elements.
typedef struct ArrayList
{
    int lenght;
    struct ArrayElement *start;
}
ArrayList;

//  Lists the function prototypes.
ArrayList* new_ArrayList();

void dispose_ArrayList(ArrayList *_arrayList);

void addFirst_ArrayList(ArrayList *_arrayList, ArrayElement *_arrayElement);
void addAt_ArrayList(ArrayList *_arrayList, ArrayElement *_arrayElement, int _index);
void addLast_ArrayList(ArrayList *_arrayList, ArrayElement *_arrayElement);

void removeFirst_ArrayList(ArrayList *_arrayList);
void removeAt_ArrayList(ArrayList *_arrayList, int _index);
void removeLast_ArrayList(ArrayList *_arrayList);

void print_ArrayList(ArrayList *_arrayList);
