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

 // Runs an example of a list.
void example_List()
{
    List *list = new_List();

    addFirst_List(list, new_IntElement(1));
    addLast_List(list, new_CharElement('w'));
    addLast_List(list, new_FloatElement(2.0f));
    addLast_List(list, new_IntElement(3));
    addLast_List(list, new_CharElement('x'));
    addLast_List(list, new_CharElement('y'));
    addLast_List(list, new_StringElement("four"));
    addLast_List(list, new_CharElement('z'));
    addLast_List(list, new_IntElement(5));
    addLast_List(list, new_FloatElement(6.5f));

    print_List(list);

    removeAt_List(list, 1);

    print_List(list);

    dispose_List(list);

    return;
}

//  Runs an example of a matrix.
void example_Matrix()
{
    Matrix *matrix = new_Matrix(NUM_ROWS, NUM_COLS);

    addTo_Matrix(matrix, new_FloatCoordinate(0, 1, 3.0f));
    addTo_Matrix(matrix, new_IntCoordinate(0, 4, 7));
    addTo_Matrix(matrix, new_CharCoordinate(0, 2, 'y'));
    addTo_Matrix(matrix, new_FloatCoordinate(1, 2, 4.2f));
    addTo_Matrix(matrix, new_IntCoordinate(1, 0, 1));
    addTo_Matrix(matrix, new_CharCoordinate(1, 1, 'z'));
    addTo_Matrix(matrix, new_FloatCoordinate(2, 2, 2.1f));
    addTo_Matrix(matrix, new_IntCoordinate(3, 3, 10));
    addTo_Matrix(matrix, new_CharCoordinate(0, 0, 'x'));
    addTo_Matrix(matrix, new_FloatCoordinate(0, 3, 1.23));
    addTo_Matrix(matrix, new_IntCoordinate(2, 0, 17));
    addTo_Matrix(matrix, new_CharCoordinate(3, 4, 'w'));

    print_Matrix(matrix);
    printT_Matrix(matrix);

    removeAt_Matrix(matrix, 3, 4);

    print_Matrix(matrix);
    printT_Matrix(matrix);

    dispose_Matrix(matrix);
}

int main()
{
    example_Matrix();

    return 0;
}
