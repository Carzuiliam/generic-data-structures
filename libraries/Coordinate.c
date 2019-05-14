/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "../include/Coordinate.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty matrix coordinate.
Coordinate* new_Coordinate()
{
    Coordinate *coord = (Coordinate*) malloc(sizeof (Coordinate));

    if (coord != NULL)
    {
        coord->i = 0;
        coord->j = 0;
        coord->nextX = NULL;
        coord->nextY = NULL;
    }

    return coord;
}

/**-----------------------------------------------------
                    Structure destruction
 -----------------------------------------------------*/

 //  Disposes the matrix coordinate.
void dispose_Coordinate(Coordinate *coord)
{
    if (coord == NULL) return;

    coord->i = 0;
    coord->j = 0;
    coord->nextX = NULL;
    coord->nextY = NULL;

    free(coord);

    return;
}

/**-----------------------------------------------------
                    Basic operations
 -----------------------------------------------------*/

//  Adds a new coordinate which contains a char as a value.
void setAsChar_Coordinate(Coordinate *coord, int _i, int _j, char _value)
{
    if (coord == NULL) return;

    coord->i = _i;
    coord->j = _j;
    coord->type = CHAR;
    coord->value.c = _value;

    return;
}

//  Adds a new coordinate which contains a float as a value.
void setAsFloat_Coordinate(Coordinate *coord, int _i, int _j, float _value)
{
    if (coord == NULL) return;

    coord->i = _i;
    coord->j = _j;
    coord->type = FLOAT;
    coord->value.f = _value;

    return;
}

//  Adds a new coordinate which contains a int as a value.
void setAsInt_Coordinate(Coordinate *coord, int _i, int _j, int _value)
{
    if (coord == NULL) return;

    coord->i = _i;
    coord->j = _j;
    coord->type = INTEGER;
    coord->value.i = _value;

    return;
}

//  Adds a new coordinate which contains a char as a value.
void setAsString_Coordinate(Coordinate *coord, int _i, int _j, char* _value)
{
    if (coord == NULL) return;

    coord->i = _i;
    coord->j = _j;
    coord->type = STRING;
    coord->value.s = _value;

    return;
}

/**-----------------------------------------------------
                    Structure info
 -----------------------------------------------------*/

//  Prints a coordinate.
void print_Coordinate(Coordinate *coord)
{
    if (coord == NULL) return;

    switch (coord->type)
    {
        case CHAR:
            printf("[%c]", coord->value.c);
            break;

        case FLOAT:
            printf("[%.2f]", coord->value.f);
            break;

        case INTEGER:
            printf("[%i]", coord->value.i);
            break;

        case STRING:
            printf("[%s]", coord->value.s);
            break;
    }

    return;
}
