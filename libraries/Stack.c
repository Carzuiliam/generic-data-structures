/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "../include/Stack.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty array list.
Stack* new_Stack()
{
    Stack *stack = (Stack*) malloc(sizeof (Stack));

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

void dispose_Stack(Stack *_stack)
{
    if (_stack == NULL) return;

    if (_stack->base != NULL)
    {
        Element *elem = _stack->base;
        Element *aux = _stack->base->next;

        while (aux != NULL)
        {
            free(elem);

            elem = aux;
            aux = aux->next;
        }

        free(elem);
    }

    free(_stack);

    return;
}

/**-----------------------------------------------------
                    Stack tasks
 -----------------------------------------------------*/

//  Pushes an element inside the array stack.
void push_Stack(Stack *_stack, Element *_element)
{
    if (_stack == NULL || _element == NULL) return;

    if (_stack->base == NULL)
    {
        _stack->base = _element;
        _stack->height++;
    }
    else
    {
        Element *aux = _stack->base;

        while (aux->next != NULL) aux = aux->next;

        aux->next = _element;
        _stack->height++;
    }

    return;
}

//  Pushes an element outside the array stack.
void pop_Stack(Stack *_stack)
{
    if (_stack == NULL) return;
    if (_stack->base == NULL) return;

    if (_stack->base->next == NULL)
    {
        Element *aux = _stack->base->next;

        _stack->base = NULL;
        _stack->height--;

        dispose_Element(aux);
    }
    else
    {
        Element *prev = _stack->base;
        Element *aux = _stack->base->next;

        while (aux->next != NULL)
        {
            prev = aux;
            aux = aux->next;
        }

        prev->next = NULL;
        _stack->height--;

        dispose_Element(aux);
    }

    return;
}

//  Peeks an element from the array stack.
Element* peek_Stack(Stack *_stack)
{
    if (_stack == NULL) return NULL;
    if (_stack->base == NULL) return NULL;

    if (_stack->base->next == NULL)
    {
        return _stack->base;
    }
    else
    {
        Element *aux = _stack->base;

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
void print_Stack(Stack *_stack)
{
    if (_stack == NULL) return;

    Element *aux = _stack->base;

    printf("---------\n");
    printf("|Stack  |-");

    while (aux != NULL)
    {
        print_Element(aux);

        aux = aux->next;

        if (aux != NULL) printf("-");
    }

    printf("\n");
    printf("|Height |-[%d]\n", _stack->height);
    printf("---------\n");

    return;
}

