/**-----------------------------------------------------
                    Program includes
 -----------------------------------------------------*/

#define NUM_ROWS    4
#define NUM_COLS    5

#include <stdio.h>
#include <stdlib.h>

#include "../libraries/Element.c"
#include "../libraries/Coordinate.c"

#include "../libraries/List.c"
#include "../libraries/Stack.c"
#include "../libraries/Matrix.c"

/**-----------------------------------------------------
                    Main function
 -----------------------------------------------------*/

int main()
{
    Matrix *matrix = new_Matrix(NUM_ROWS, NUM_COLS);

    addTo_Matrix(matrix, new_IntCoordinate(0, 0, 10));
    addTo_Matrix(matrix, new_IntCoordinate(1, 1, 1));
    addTo_Matrix(matrix, new_FloatCoordinate(2, 2, 2.0f));
    addTo_Matrix(matrix, new_FloatCoordinate(3, 3, 3.5f));
    addTo_Matrix(matrix, new_FloatCoordinate(3, 4, 4.9f));

    print_Matrix(matrix);
    dispose_Matrix(matrix);

    return 0;
}
