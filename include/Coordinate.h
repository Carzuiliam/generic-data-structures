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
        C_INTEGER
    }
    type;

    union C_Value
    {
        char c;
        float f;
        int i;
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

Coordinate* new_Coordinate(unsigned int _i, unsigned int _j);
Coordinate* new_CharCoordinate(unsigned int _i, unsigned int _j, char _value);
Coordinate* new_FloatCoordinate(unsigned int _i, unsigned int _j, float _value);
Coordinate* new_IntCoordinate(unsigned int _i, unsigned int _j, int _value);

void dispose_Coordinate(Coordinate *coord);

void setAsChar_Coordinate(Coordinate *_coord, char _value);
void setAsFloat_Coordinate(Coordinate *_coord, float _value);
void setAsInt_Coordinate(Coordinate *_coord, int _value);

void print_Coordinate(Coordinate *coord);
