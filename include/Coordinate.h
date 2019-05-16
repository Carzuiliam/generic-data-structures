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

    int row;
    int col;

    struct Coordinate *nextRow;
    struct Coordinate *nextCol;
}
Coordinate;

/**-----------------------------------------------------
                    Functions prototypes
 -----------------------------------------------------*/

Coordinate* new_Coordinate(int _row, int _col);
Coordinate* new_CharCoordinate(int _row, int _col, char _value);
Coordinate* new_FloatCoordinate(int _row, int _col, float _value);
Coordinate* new_IntCoordinate(int _row, int _col, int _value);

void dispose_Coordinate(Coordinate *coord);

void setAsChar_Coordinate(Coordinate *_coord, char _value);
void setAsFloat_Coordinate(Coordinate *_coord, float _value);
void setAsInt_Coordinate(Coordinate *_coord, int _value);

void print_Coordinate(Coordinate *coord);
