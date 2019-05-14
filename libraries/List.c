/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "../include/List.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty array list.
List* new_List()
{
    List *list = (List*) malloc(sizeof (List));

    if (list != NULL)
    {
        list->lenght = 0;
        list->start = NULL;
    }

    return list;
}

/**-----------------------------------------------------
                    Structure destruction
 -----------------------------------------------------*/

void dispose_List(List *_list)
{
    if (_list == NULL) return;

    if (_list->start != NULL)
    {
        Element *elem = _list->start;
        Element *aux = _list->start->next;

        while (aux != NULL)
        {
            free(elem);

            elem = aux;
            aux = aux->next;
        }

        free(elem);
    }

    free(_list);

    return;
}

/**-----------------------------------------------------
                    Inserting nodes
 -----------------------------------------------------*/

//  Adds an element at the start of the array list.
void addFirst_List(List *_list, Element *_element)
{
    if (_list == NULL || _element == NULL) return;

    if (_list->start == NULL)
    {
        _list->start = _element;
        _list->lenght++;

    }
    else
    {
        Element *aux = _list->start;

        _list->start = _element;
        _element->next = aux;
        _list->lenght++;
    }

    return;
}

//  Adds an element at the specific index of the array list.
void addAt_List(List *_list, Element *_element, int _index)
{
    if (_list == NULL || _element == NULL) return;
    if (_index < 0 || _index > _list->lenght) return;

    if (_index == 0)
    {
        addFirst_List(_list, _element);
    }
    else if (_index == _list->lenght)
    {
        addLast_List(_list, _element);
    }
    else
    {
        Element *pos = _list->start;

        for (int i = 0; i < (_index - 1); i++)
        {
            pos = pos->next;
        }

        _element->next = pos->next;
        pos->next = _element;

        _list->lenght++;
    }

    return;
}

//  Adds an element at the end of the array list.
void addLast_List(List *_list, Element *_element)
{
    if (_list == NULL || _element == NULL) return;

    if (_list->start == NULL)
    {
        _list->start = _element;
        _list->lenght++;
    }
    else
    {
        Element *aux = _list->start;

        while (aux->next != NULL) aux = aux->next;

        aux->next = _element;
        _list->lenght++;
    }

    return;
}

/**-----------------------------------------------------
                    Removing nodes
 -----------------------------------------------------*/

//  Removes the element at the start of the array list.
void removeFirst_List(List *_list)
{
    if (_list == NULL) return;
    if (_list->start == NULL) return;

    Element *aux = _list->start;

    _list->start = _list->start->next;
    _list->lenght--;

    dispose_Element(aux);

    return;
}

//  Removes an element at the specific index of the array list.
void removeAt_List(List *_list, int _index)
{
    if (_list == NULL) return;
    if (_index < 0 || _index > _list->lenght - 1) return;

    if (_index == 0)
    {
        removeFirst_List(_list);
    }
    else if (_index == _list->lenght - 1)
    {
        removeLast_List(_list);
    }
    else
    {
        Element *prev = NULL;
        Element *aux = _list->start;

        for (int i = 0; i < _index; i++)
        {
            prev = aux;
            aux = aux->next;
        }

        prev->next = aux->next;
        _list->lenght--;

        dispose_Element(aux);
    }

    return;
}

//  Removes the element at the end of the array list.
void removeLast_List(List *_list)
{
    if (_list == NULL) return;
    if (_list->start == NULL) return;

    if (_list->start->next == NULL)
    {
        Element *aux = _list->start->next;

        _list->start = NULL;
        _list->lenght--;

        dispose_Element(aux);
    }
    else
    {
        Element *prev = _list->start;
        Element *aux = _list->start->next;

        while (aux->next != NULL)
        {
            prev = aux;
            aux = aux->next;
        }

        prev->next = NULL;
        _list->lenght--;

        dispose_Element(aux);
    }

    return;
}

/**-----------------------------------------------------
                    Finding nodes
 -----------------------------------------------------*/

//  Returns the element at the start of the array list.
Element* getFirst_List(List *_list)
{
    if (_list == NULL) return NULL;

    return _list->start;
}

//  Returns an element at the specific index of the array list.
Element* getAt_List(List *_list, int _index)
{
    if (_list == NULL) return NULL;
    if (_index < 0 || _index > _list->lenght - 1) return NULL;

    if (_index == 0)
    {
        return getFirst_List(_list);
    }
    else if (_index == _list->lenght - 1)
    {
        return getLast_List(_list);
    }
    else
    {
        Element *aux = _list->start;

        for (int i = 0; i < _index; i++)
        {
            aux = aux->next;
        }

        return aux;
    }
}

//  Returns the element at the end of the array list.
Element* getLast_List(List *_list)
{
    if (_list == NULL) return NULL;
    if (_list->start == NULL) return NULL;

    if (_list->start->next == NULL)
    {
        return _list->start;
    }
    else
    {
        Element *aux = _list->start;

        while (aux->next != NULL)
        {
            aux = aux->next;
        }

        return aux;
    }
}

/**-----------------------------------------------------
                    Structure info
 -----------------------------------------------------*/

//  Prints all the elements of the array list.
void print_List(List *_list)
{
    if (_list == NULL) return;

    Element *aux = _list->start;

    printf("---------\n");
    printf("|Elem(s)|-");

    while (aux != NULL)
    {
        print_Element(aux);

        aux = aux->next;

        if (aux != NULL) printf("-");
    }

    printf("\n");
    printf("|Length |-[%d]\n", _list->lenght);
    printf("---------\n");

    return;
}
