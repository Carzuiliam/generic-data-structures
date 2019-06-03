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
        singleList->lenght = 0;
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
        _singleList->lenght++;
    }
    else
    {
        Element *aux = _singleList->start;

        _singleList->start = _element;
        _element->next = aux;
        _singleList->lenght++;
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
        _singleList->lenght++;
    }
    else
    {
        Element *aux = _singleList->start;

        while (aux->next != NULL) aux = aux->next;

        aux->next = _element;
        _singleList->lenght++;
    }

    return;
}

//  Adds an element at the specific index of the single list.
void addAt_SingleList(SingleList *_singleList, Element *_element, unsigned int _index)
{
    if (_singleList == NULL || _element == NULL) return;
    if (_index > _singleList->lenght) return;

    if (_index == 0)
    {
        addFirst_SingleList(_singleList, _element);
    }
    else if (_index == _singleList->lenght)
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

        _singleList->lenght++;
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
    _singleList->lenght--;

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
        _singleList->lenght--;

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
        _singleList->lenght--;

        dispose_Element(aux);
    }

    return;
}

//  Removes an element at the specific index of the single list.
void removeAt_SingleList(SingleList *_singleList, unsigned int _index)
{
    if (_singleList == NULL) return;
    if (_singleList->start == NULL) return;
    if (_index > _singleList->lenght - 1) return;

    if (_index == 0)
    {
        removeFirst_SingleList(_singleList);
    }
    else if (_index == _singleList->lenght - 1)
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
        _singleList->lenght--;

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
    if (_index > _singleList->lenght - 1) return NULL;

    if (_index == 0)
    {
        return getFirst_SingleList(_singleList);
    }
    else if (_index == _singleList->lenght - 1)
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
    printf("|Length |-[%d]\n", _singleList->lenght);
    printf("---------\n");

    return;
}
