# Generic Data Structures in C

This project shows an example of a data structure with generic types in C.

## Introduction

First of all: *there is no specific implementation for generic types in C*. Only after C++ the concept of generic type were born (using [templates or objects](https://web.eecs.utk.edu/~bvz/cs365/notes/generic-types.html)). But there are *two basic ways* to workaround with this: 

 - The first way is using *empty pointers* (`void *` type), requiring _downcast_ for the desired type before its manipulation. Thought this approach gives more power to the programmer (including to allow the use of functions as functions parameters -- an unthinkable thing on another programming languages), the _downcast_ is extremally unsafe, since the C language does not perform type check during execution time.
 - The second way is using *shared memory structures*, built using the `union` structure, combined with the `enum` structure (which contains the type index). This method is easier to depure than the pointer method, thought requeires certain attention for the programmer to control the value contained by the variable. 

## About this Project

The source codes presented here currently implements, using the `union`/`enum` approach previously described, an example of a single dynamic list.

Using the `union` type, it is possible to allocate multiple variables in a same memory block. For example, consider the following code lines from the file _ArrayElement.c_:

```C
typedef struct ArrayElement
{
    enum Type
    {
        CHAR,
        FLOAT,
        INTEGER,
        STRING
    }
    type;

    union Value
    {
        char c;
        float f;
        int i;
        char *s;
    }
    value;

    struct ArrayElement *next;
}
ArrayElement;
```

This code block defines that, inside an `ArrayElement`, there is a `union` type structure, which contains a `char`, a `float`, an `int`, and a _string_ (`char*`), all of them sharing the same memory block. There is also a `enum` type structure, which contains the value type attached to the `ArrayElement`, and an `ArrayElement *` variable, utilized in the control of the `ArrayList` structure (defined in the _ArrayList.c_ file).

Based on the previous structure, the following code block shows the creation of an `ArrayElement` struct of the `int` type:

```C
//  Creates a new element
ArrayElement *_arrayElement = new_ArrayElement();       

//  Defines the element as an int
_arrayElement->type = INTEGER;

//  Attaches the value
_arrayElement->value.i = 100;                        

//  Initializes the pointer for the next element
_arrayElement->next = NULL;
```

It is necessary to store the variable type because, when the command `_arrayElement->value.i = _value` occurs, a value is not only attached to `i`, but also to `c`, `f`  and `*s`, since the memory block for `value` is shared. This behavior can be observed by, after the above code has been executed, all the following operations are valid from the compiler point-of-view -- even generating inconsistent data:

```C
//  Prints "value" as a char (probably the char corresponding
// to the value 100)
prinf("%c", _arrayElement->value.c);

//  Prints "value" as a float (probably wrong)
prinf("%.2f", _arrayElement->value.f);

//  Prints "value" as an int (the only correct)
prinf("%i", _arrayElement->value.i);

//  Prints "value" as a string (only garbage)
prinf("%s", _arrayElement->value.s);
```

However, if the variable type is available, it is possible to do:

```C
switch (_arrayElement->type)
    {
        case CHAR:
            printf("%c", _arrayElement->value.c);
            break;

        case FLOAT:
            printf("%.2f", _arrayElement->value.f);
            break;

        case INTEGER:
            printf("%i", _arrayElement->value.i);
            break;

        case STRING:
            printf("%s", _arrayElement->value.s);
            break;
    }
```

Which guarantee that the data can be correctly treated.

## Informações Adicionais

Since it is a work in progress, probably I will add more features in the future (e.g. stacks, sparses matrices and trees). Stay tuned!

## Licença de Uso

The available source codes here are under the GNU General Public License, version 3.0 (see the attached `LICENSE` file for more details). Any questions can be submitted to my email: carloswdecarvalho@outlook.com.