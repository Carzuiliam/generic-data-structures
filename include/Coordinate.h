/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

typedef struct Coordinate
{
    enum C_Type
    {
        C_FLOAT,
        C_INTEGER
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
Coordinate* new_FloatCoordinate(int _row, int _col, float _value);
Coordinate* new_IntCoordinate(int _row, int _col, int _value);

void dispose_Coordinate(Coordinate *coord);

void setAsFloat_Coordinate(Coordinate *coord, float _value);
void setAsInt_Coordinate(Coordinate *coord, int _value);

void print_Coordinate(Coordinate *coord);
