/**-----------------------------------------------------
                    Program includes
 -----------------------------------------------------*/

#define     NUM_ROWS    4
#define     NUM_COLS    5

#include    <stdio.h>
#include    <stdlib.h>
#include    "../libraries/Element.c"
#include    "../libraries/Coordinate.c"
#include    "../libraries/List.c"
#include    "../libraries/Stack.c"
#include    "../libraries/Matrix.c"

/**-----------------------------------------------------
                    Main function
 -----------------------------------------------------*/

int main()
{
    Matrix *matrix = new_Matrix(NUM_ROWS, NUM_COLS);

    addTo_Matrix(matrix, new_CharCoordinate(0, 0, 'x'));
    addTo_Matrix(matrix, new_FloatCoordinate(0, 1, 3.0f));
    addTo_Matrix(matrix, new_IntCoordinate(0, 4, 7));
    addTo_Matrix(matrix, new_CharCoordinate(0, 2, 'y'));
    addTo_Matrix(matrix, new_FloatCoordinate(1, 2, 4.2f));
    addTo_Matrix(matrix, new_IntCoordinate(1, 0, 1));
    addTo_Matrix(matrix, new_CharCoordinate(1, 1, 'z'));
    addTo_Matrix(matrix, new_FloatCoordinate(2, 2, 2.1f));
    addTo_Matrix(matrix, new_IntCoordinate(3, 3, 10));

    print_Matrix(matrix);

    removeAt_Matrix(matrix, 2, 2);

    print_Matrix(matrix);
    dispose_Matrix(matrix);

    return 0;
}
