/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

typedef struct Coordinate
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

    int i;
    int j;

    struct Coordinate *nextX;
    struct Coordinate *nextY;
}
Coordinate;

/**-----------------------------------------------------
                    Functions prototypes
 -----------------------------------------------------*/
