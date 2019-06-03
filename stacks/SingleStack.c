/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "SingleStack.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty stack.
SingleStack* new_SingleStack()
{
    SingleStack *stack = malloc(sizeof (SingleStack));

    if (stack != NULL)
    {
        stack->height = 0;
        stack->base = NULL;
    }

    return stack;
}

/**-----------------------------------------------------
                    Structure destruction
 -----------------------------------------------------*/

void dispose_SingleStack(SingleStack *_singleStack)
{
    if (_singleStack == NULL) return;

    if (_singleStack->base != NULL)
    {
        Element *elem = _singleStack->base;
        Element *aux = _singleStack->base->next;

        while (aux != NULL)
        {
            dispose_Element(elem);

            elem = aux;
            aux = aux->next;
        }

        dispose_Element(elem);
    }

    free(_singleStack);

    return;
}

/**-----------------------------------------------------
                    Stack tasks
 -----------------------------------------------------*/

//  Pushes an element inside the stack.
void push_SingleStack(SingleStack *_singleStack, Element *_element)
{
    if (_singleStack == NULL || _element == NULL) return;

    if (_singleStack->base == NULL)
    {
        _singleStack->base = _element;
        _singleStack->height++;
    }
    else
    {
        Element *aux = _singleStack->base;

        while (aux->next != NULL) aux = aux->next;

        aux->next = _element;
        _singleStack->height++;
    }

    return;
}

//  Pushes an element outside the stack.
void pop_SingleStack(SingleStack *_singleStack)
{
    if (_singleStack == NULL) return;
    if (_singleStack->base == NULL) return;

    if (_singleStack->base->next == NULL)
    {
        Element *aux = _singleStack->base->next;

        _singleStack->base = NULL;
        _singleStack->height--;

        dispose_Element(aux);
    }
    else
    {
        Element *prev = _singleStack->base;
        Element *aux = _singleStack->base->next;

        while (aux->next != NULL)
        {
            prev = aux;
            aux = aux->next;
        }

        prev->next = NULL;
        _singleStack->height--;

        dispose_Element(aux);
    }

    return;
}

//  Peeks an element from the stack.
Element* peek_SingleStack(SingleStack *_singleStack)
{
    if (_singleStack == NULL) return NULL;
    if (_singleStack->base == NULL) return NULL;

    if (_singleStack->base->next == NULL)
    {
        return _singleStack->base;
    }
    else
    {
        Element *aux = _singleStack->base;

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

//  Prints all the elements of the stack.
void print_SingleStack(SingleStack *_singleStack)
{
    if (_singleStack == NULL) return;

    Element *aux = _singleStack->base;

    printf("---------\n");
    printf("|Stack  |-");

    while (aux != NULL)
    {
        print_Element(aux);

        aux = aux->next;

        if (aux != NULL) printf("-");
    }

    printf("\n");
    printf("|Height |-[%d]\n", _singleStack->height);
    printf("---------\n");

    return;
}

