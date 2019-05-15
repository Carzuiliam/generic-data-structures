/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "../include/Coordinate.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty matrix coordinate.
Coordinate* new_Coordinate(int _row, int _col)
{
    Coordinate *coord = malloc(sizeof (Coordinate));

    if (coord != NULL)
    {
        coord->row = _row;
        coord->col = _col;
        coord->nextRow = NULL;
        coord->nextCol = NULL;
    }

    return coord;
}

//  Creates a float coordinate.
Coordinate* new_FloatCoordinate(int _row, int _col, float _value)
{
    Coordinate *coord = malloc(sizeof (Coordinate));

    if (coord != NULL)
    {
        coord->row = _row;
        coord->col = _col;
        coord->type = C_FLOAT;
        coord->value.f = _value;
        coord->nextRow = NULL;
        coord->nextCol = NULL;
    }

    return coord;
}

//  Creates an integer coordinate.
Coordinate* new_IntCoordinate(int _row, int _col, int _value)
{
    Coordinate *coord = malloc(sizeof (Coordinate));

    if (coord != NULL)
    {
        coord->row = _row;
        coord->col = _col;
        coord->type = C_INTEGER;
        coord->value.i = _value;
        coord->nextRow = NULL;
        coord->nextCol = NULL;
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

    coord->nextRow = NULL;
    coord->nextCol = NULL;

    free(coord);

    return;
}

/**-----------------------------------------------------
                    Basic operations
 -----------------------------------------------------*/

//  Adds a new coordinate which contains a float as a value.
void setAsFloat_Coordinate(Coordinate *coord, float _value)
{
    if (coord == NULL) return;

    coord->type = C_FLOAT;
    coord->value.f = _value;

    return;
}

//  Adds a new coordinate which contains a int as a value.
void setAsInt_Coordinate(Coordinate *coord, int _value)
{
    if (coord == NULL) return;

    coord->type = C_INTEGER;
    coord->value.i = _value;

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
        case C_FLOAT:
            printf("%6.2f", coord->value.f);
            break;

        case C_INTEGER:
            printf("%6i", coord->value.i);
            break;
    }

    return;
}
