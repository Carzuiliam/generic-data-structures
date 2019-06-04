/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "SingleList.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty single list.
SingleList* new_SingleList()
{
    SingleList *singleList = malloc(sizeof (SingleList));

    if (singleList != NULL)
    {
        singleList->start = NULL;
    }

    return singleList;
}

/**-----------------------------------------------------
                    Structure destruction
 -----------------------------------------------------*/

 // Disposes a single list.
void dispose_SingleList(SingleList *_singleList)
{
    if (_singleList == NULL) return;

    if (_singleList->start != NULL)
    {
        Element *elem = _singleList->start;
        Element *aux = _singleList->start->next;

        while (aux != NULL)
        {
            dispose_Element(elem);

            elem = aux;
            aux = aux->next;
        }

        dispose_Element(elem);
    }

    free(_singleList);

    return;
}

/**-----------------------------------------------------
                    Inserting elements
 -----------------------------------------------------*/

//  Adds an element at the start of the single list.
void addFirst_SingleList(SingleList *_singleList, Element *_element)
{
    if (_singleList == NULL || _element == NULL) return;

    if (_singleList->start == NULL)
    {
        _singleList->start = _element;
    }
    else
    {
        Element *aux = _singleList->start;

        _singleList->start = _element;
        _element->next = aux;
    }

    return;
}

//  Adds an element at the end of the single list.
void addLast_SingleList(SingleList *_singleList, Element *_element)
{
    if (_singleList == NULL || _element == NULL) return;

    if (_singleList->start == NULL)
    {
        _singleList->start = _element;
    }
    else
    {
        Element *aux = _singleList->start;

        while (aux->next != NULL) aux = aux->next;

        aux->next = _element;
    }

    return;
}

//  Adds an element at the specific index of the single list.
void addAt_SingleList(SingleList *_singleList, Element *_element, unsigned int _index)
{
    if (_singleList == NULL || _element == NULL) return;
    if (_index > length_SingleList(_singleList)) return;

    if (_index == 0)
    {
        addFirst_SingleList(_singleList, _element);
    }
    else if (_index == length_SingleList(_singleList))
    {
        addLast_SingleList(_singleList, _element);
    }
    else
    {
        Element *pos = _singleList->start;

        for (int i = 0; i < (_index - 1); i++)
        {
            pos = pos->next;
        }

        _element->next = pos->next;
        pos->next = _element;
    }

    return;
}

/**-----------------------------------------------------
                    Removing elements
 -----------------------------------------------------*/

//  Removes the element at the start of the single list.
void removeFirst_SingleList(SingleList *_singleList)
{
    if (_singleList == NULL) return;
    if (_singleList->start == NULL) return;

    Element *aux = _singleList->start;

    _singleList->start = _singleList->start->next;

    dispose_Element(aux);

    return;
}

//  Removes the element at the end of the single list.
void removeLast_SingleList(SingleList *_singleList)
{
    if (_singleList == NULL) return;
    if (_singleList->start == NULL) return;

    if (_singleList->start->next == NULL)
    {
        Element *aux = _singleList->start->next;

        _singleList->start = NULL;

        dispose_Element(aux);
    }
    else
    {
        Element *prev = _singleList->start;
        Element *aux = _singleList->start->next;

        while (aux->next != NULL)
        {
            prev = aux;
            aux = aux->next;
        }

        prev->next = NULL;

        dispose_Element(aux);
    }

    return;
}

//  Removes an element at the specific index of the single list.
void removeAt_SingleList(SingleList *_singleList, unsigned int _index)
{
    if (_singleList == NULL) return;
    if (_singleList->start == NULL) return;
    if (_index > length_SingleList(_singleList)) return;

    if (_index == 0)
    {
        removeFirst_SingleList(_singleList);
    }
    else if (_index == length_SingleList(_singleList) - 1)
    {
        removeLast_SingleList(_singleList);
    }
    else
    {
        Element *prev = NULL;
        Element *aux = _singleList->start;

        for (int i = 0; i < _index; i++)
        {
            prev = aux;
            aux = aux->next;
        }

        prev->next = aux->next;

        dispose_Element(aux);
    }

    return;
}

/**-----------------------------------------------------
                    Finding elements
 -----------------------------------------------------*/

//  Returns the element at the start of the single list.
Element* getFirst_SingleList(SingleList *_singleList)
{
    if (_singleList == NULL) return NULL;
    return _singleList->start;
}

//  Returns the element at the end of the single list.
Element* getLast_SingleList(SingleList *_singleList)
{
    if (_singleList == NULL) return NULL;
    if (_singleList->start == NULL) return NULL;

    if (_singleList->start->next == NULL)
    {
        return _singleList->start;
    }
    else
    {
        Element *aux = _singleList->start;

        while (aux->next != NULL)
        {
            aux = aux->next;
        }

        return aux;
    }
}

//  Returns an element at the specific index of the single list.
Element* getAt_SingleList(SingleList *_singleList, unsigned int _index)
{
    if (_singleList == NULL) return NULL;
    if (_index > length_SingleList(_singleList) - 1) return NULL;

    if (_index == 0)
    {
        return getFirst_SingleList(_singleList);
    }
    else if (_index == length_SingleList(_singleList) - 1)
    {
        return getLast_SingleList(_singleList);
    }
    else
    {
        Element *aux = _singleList->start;

        for (int i = 0; i < _index; i++)
        {
            aux = aux->next;
        }

        return aux;
    }
}

/**-----------------------------------------------------
                    Structure info
 -----------------------------------------------------*/

//  Returns the length of the single list.
unsigned int length_SingleList(SingleList *_singleList)
{
    if (_singleList == NULL) return 0;
    if (_singleList->start == NULL) return 0;

    unsigned int length = 0;

    Element *elem = _singleList->start;

    while (elem != NULL)
    {
        elem = elem->next;
        length++;
    }

    return length;
}

//  Prints all the elements of the single list.
void print_SingleList(SingleList *_singleList)
{
    if (_singleList == NULL) return;

    Element *aux = _singleList->start;

    printf("---------\n");
    printf("|Elem(s)|-");

    while (aux != NULL)
    {
        print_Element(aux);

        aux = aux->next;

        if (aux != NULL) printf("-");
    }

    printf("\n");
    printf("|Length |-[%d]\n", length_SingleList(_singleList));
    printf("---------\n");

    return;
}
