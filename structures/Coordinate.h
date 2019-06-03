/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#pragma once

/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

typedef struct Coordinate
{
    enum C_Type
    {
        C_CHAR,
        C_FLOAT,
        C_INTEGER,
        C_STRING
    }
    type;

    union C_Value
    {
        char c;
        float f;
        int i;
        char *s;
    }
    value;

    unsigned int i;
    unsigned int j;

    struct Coordinate *nextI;
    struct Coordinate *nextJ;
}
Coordinate;

/**-----------------------------------------------------
                    Functions prototypes
 -----------------------------------------------------*/

Coordinate* new_Coordinate(unsigned int, unsigned int);
Coordinate* new_CharCoordinate(unsigned int, unsigned int, char);
Coordinate* new_FloatCoordinate(unsigned int, unsigned int, float);
Coordinate* new_IntCoordinate(unsigned int, unsigned int, int);
Coordinate* new_StringCoordinate(unsigned int, unsigned int, char*);

void dispose_Coordinate(Coordinate*);

void setAsChar_Coordinate(Coordinate*, char);
void setAsFloat_Coordinate(Coordinate*, float);
void setAsInt_Coordinate(Coordinate*, int);
void setAsString_Coordinate(Coordinate*, char*);

void print_Coordinate(Coordinate*);
