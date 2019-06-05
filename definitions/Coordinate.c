/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "Coordinate.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty matrix coordinate.
Coordinate* new_Coordinate(unsigned int _i, unsigned int _j)
{
    Coordinate *coord = malloc(sizeof (Coordinate));

    if (coord != NULL)
    {
        coord->i = _i;
        coord->j = _j;
        coord->nextI = NULL;
        coord->nextJ = NULL;
    }

    return coord;
}

//  Creates a char coordinate.
Coordinate* new_CharCoordinate(unsigned int _i, unsigned int _j, char _value)
{
    Coordinate *coord = malloc(sizeof (Coordinate));

    if (coord != NULL)
    {
        coord->i = _i;
        coord->j = _j;
        coord->type = C_CHAR;
        coord->value.c = _value;
        coord->nextI = NULL;
        coord->nextJ = NULL;
    }

    return coord;
}

//  Creates a float coordinate.
Coordinate* new_FloatCoordinate(unsigned int _i, unsigned int _j, float _value)
{
    Coordinate *coord = malloc(sizeof (Coordinate));

    if (coord != NULL)
    {
        coord->i = _i;
        coord->j = _j;
        coord->type = C_FLOAT;
        coord->value.f = _value;
        coord->nextI = NULL;
        coord->nextJ = NULL;
    }

    return coord;
}

//  Creates an integer coordinate.
Coordinate* new_IntCoordinate(unsigned int _i, unsigned int _j, int _value)
{
    Coordinate *coord = malloc(sizeof (Coordinate));

    if (coord != NULL)
    {
        coord->i = _i;
        coord->j = _j;
        coord->type = C_INTEGER;
        coord->value.i = _value;
        coord->nextI = NULL;
        coord->nextJ = NULL;
    }

    return coord;
}

//  Creates a string coordinate.
Coordinate* new_StringCoordinate(unsigned int _i, unsigned int _j, char *_value)
{
    Coordinate *coord = malloc(sizeof (Coordinate));

    if (coord != NULL)
    {
        coord->i = _i;
        coord->j = _j;
        coord->type = C_STRING;
        coord->value.s = _value;
        coord->nextI = NULL;
        coord->nextJ = NULL;
    }

    return coord;
}

/**-----------------------------------------------------
                    Structure destruction
 -----------------------------------------------------*/

 //  Disposes the matrix coordinate.
void dispose_Coordinate(Coordinate *_coord)
{
    if (_coord == NULL) return;

    _coord->nextI = NULL;
    _coord->nextJ = NULL;

    free(_coord);

    return;
}

/**-----------------------------------------------------
                    Basic operations
 -----------------------------------------------------*/

//  Adds a new coordinate which contains a char as a value.
void setAsChar_Coordinate(Coordinate *_coord, char _value)
{
    if (_coord == NULL) return;

    _coord->type = C_CHAR;
    _coord->value.c = _value;

    return;
}

//  Adds a new coordinate which contains a float as a value.
void setAsFloat_Coordinate(Coordinate *_coord, float _value)
{
    if (_coord == NULL) return;

    _coord->type = C_FLOAT;
    _coord->value.f = _value;

    return;
}

//  Adds a new coordinate which contains a int as a value.
void setAsInt_Coordinate(Coordinate *_coord, int _value)
{
    if (_coord == NULL) return;

    _coord->type = C_INTEGER;
    _coord->value.i = _value;

    return;
}

//  Adds a new coordinate which contains an string as a value.
void setAsString_Coordinate(Coordinate *_coord, char *_value)
{
    if (_coord == NULL) return;

    _coord->type = C_STRING;
    _coord->value.s = _value;

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
        case C_CHAR:
            {
                printf("%7c", coord->value.c);
            }
            break;

        case C_FLOAT:
            {
                printf("%7.2f", coord->value.f);
            }
            break;

        case C_INTEGER:
            {
                printf("%7i", coord->value.i);
            }
            break;

        case C_STRING:
            {
                int index = 0;

                while (coord->value.s[index] != '\0') index++;

                if (index < 6)
                {
                    printf("%7s", coord->value.s);
                }
                else
                {
                    for (int pos = 0; pos < 6; pos++)
                    {
                        printf("%c", coord->value.s[pos]);
                    }

                    printf(".");
                }
            }
            break;
    }

    return;
}
