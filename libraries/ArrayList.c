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
    ArrayList *arrayList =
        (ArrayList*) malloc(sizeof (ArrayList));

    if (arrayList != NULL)
    {
        arrayList->lenght = 0;
        arrayList->start = NULL;
    }

    return arrayList;
}

/**-----------------------------------------------------
                    Structure destruction
 -----------------------------------------------------*/

void dispose_ArrayList(ArrayList *_arrayList)
{
    if (_arrayList == NULL) return;

    if (_arrayList->start != NULL)
    {
        ArrayElement *elem = _arrayList->start;
        ArrayElement *aux = _arrayList->start->next;

        while (aux != NULL)
        {
            free(elem);

            elem = aux;
            aux = aux->next;
        }

        free(elem);
    }

    free(_arrayList);

    return;
}

/**-----------------------------------------------------
                    Inserting nodes
 -----------------------------------------------------*/

//  Adds an element at the start of the array list.
void addFirst_ArrayList(ArrayList *_arrayList, ArrayElement *_arrayElement)
{
    if (_arrayList == NULL || _arrayElement == NULL) return;

    if (_arrayList->start == NULL)
    {
        _arrayList->start = _arrayElement;
        _arrayList->lenght++;

    }
    else
    {
        ArrayElement *aux = _arrayList->start;

        _arrayList->start = _arrayElement;
        _arrayElement->next = aux;
        _arrayList->lenght++;
    }

    return;
}

//  Adds an element at the specific index of the array list.
void addAt_ArrayList(ArrayList *_arrayList, ArrayElement *_arrayElement, int _index)
{
    if (_arrayList == NULL || _arrayElement == NULL) return;
    if (_index < 0 || _index > _arrayList->lenght) return;

    if (_index == 0)
    {
        addFirst_ArrayList(_arrayList, _arrayElement);
    }
    else if (_index == _arrayList->lenght)
    {
        addLast_ArrayList(_arrayList, _arrayElement);
    }
    else
    {
        ArrayElement *pos = _arrayList->start;

        for (int i = 0; i < (_index - 1); i++)
        {
            pos = pos->next;
        }

        _arrayElement->next = pos->next;
        pos->next = _arrayElement;

        _arrayList->lenght++;
    }

    return;
}

//  Adds an element at the end of the array list.
void addLast_ArrayList(ArrayList *_arrayList, ArrayElement *_arrayElement)
{
    if (_arrayList == NULL || _arrayElement == NULL) return;

    if (_arrayList->start == NULL)
    {
        _arrayList->start = _arrayElement;
        _arrayList->lenght++;
    }
    else
    {
        ArrayElement *aux = _arrayList->start;

        while (aux->next != NULL) aux = aux->next;

        aux->next = _arrayElement;
        _arrayList->lenght++;
    }

    return;
}

/**-----------------------------------------------------
                    Removing nodes
 -----------------------------------------------------*/

//  Removes the element at the start of the array list.
void removeFirst_ArrayList(ArrayList *_arrayList)
{
    if (_arrayList == NULL) return;
    if (_arrayList->start == NULL) return;

    ArrayElement *aux = _arrayList->start;

    _arrayList->start = _arrayList->start->next;
    _arrayList->lenght--;

    dispose_ArrayElement(aux);

    return;
}

//  Adds an element at the specific index of the array list.
void removeAt_ArrayList(ArrayList *_arrayList, int _index)
{
    if (_arrayList == NULL) return;
    if (_index < 0 || _index > _arrayList->lenght - 1) return;

    if (_index == 0)
    {
        removeFirst_ArrayList(_arrayList);
    }
    else if (_index == _arrayList->lenght - 1)
    {
        removeLast_ArrayList(_arrayList);
    }
    else
    {
        ArrayElement *prev = NULL;
        ArrayElement *aux = _arrayList->start;

        for (int i = 0; i < _index; i++)
        {
            prev = aux;
            aux = aux->next;
        }

        prev->next = aux->next;
        _arrayList->lenght--;

        dispose_ArrayElement(aux);
    }

    return;
}

//  Removes the element at the end of the array list.
void removeLast_ArrayList(ArrayList *_arrayList)
{
    if (_arrayList == NULL) return;
    if (_arrayList->start == NULL) return;

    if (_arrayList->start->next == NULL)
    {
        ArrayElement *aux = _arrayList->start->next;

        _arrayList->start = NULL;
        _arrayList->lenght--;

        dispose_ArrayElement(aux);
    }
    else
    {
        ArrayElement *prev = _arrayList->start;
        ArrayElement *aux = _arrayList->start->next;

        while (aux->next != NULL)
        {
            prev = aux;
            aux = aux->next;
        }

        prev->next = NULL;
        _arrayList->lenght--;

        dispose_ArrayElement(aux);
    }

    return;
}

/**-----------------------------------------------------
                    Structure info
 -----------------------------------------------------*/

//  Prints all the elements of the array list.
void print_ArrayList(ArrayList *_arrayList)
{
    if (_arrayList == NULL) return;

    ArrayElement *aux = _arrayList->start;

    printf("---------\n");
    printf("|Elem(s)|-");

    while (aux != NULL)
    {
        print_ArrayElement(aux);

        aux = aux->next;

        if (aux != NULL) printf("-");
    }

    printf("\n");
    printf("|Length |-[%d]\n", _arrayList->lenght);
    printf("---------\n");

    return;
}
