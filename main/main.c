/**-----------------------------------------------------
                    Program includes
 -----------------------------------------------------*/

#define     NUM_ROWS    4
#define     NUM_COLS    5

#include    <stdio.h>
#include    <stdlib.h>

#include    "../structures/Element.c"
#include    "../structures/Coordinate.c"
#include    "../structures/Node.c"

#include    "../lists/SingleList.c"
#include    "../stacks/SingleStack.c"
#include    "../matrices/Matrix.c"
#include    "../trees/Tree.c"

/**-----------------------------------------------------
                    Main function
 -----------------------------------------------------*/

 // Runs an example of a single list.
void example_SingleList()
{
    SingleList *list = new_SingleList();

    addFirst_SingleList(list, new_IntElement(1));
    addLast_SingleList(list, new_CharElement('w'));
    addLast_SingleList(list, new_FloatElement(2.0f));
    addLast_SingleList(list, new_IntElement(3));
    addLast_SingleList(list, new_CharElement('x'));
    addLast_SingleList(list, new_CharElement('y'));
    addLast_SingleList(list, new_StringElement("four"));
    addLast_SingleList(list, new_CharElement('z'));
    addLast_SingleList(list, new_IntElement(5));
    addLast_SingleList(list, new_FloatElement(6.5f));

    print_SingleList(list);
    dispose_SingleList(list);

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
    addTo_Matrix(matrix, new_StringCoordinate(2, 2, "Again"));
    addTo_Matrix(matrix, new_IntCoordinate(3, 3, 10));
    addTo_Matrix(matrix, new_CharCoordinate(0, 0, 'x'));
    addTo_Matrix(matrix, new_FloatCoordinate(0, 3, 1.23));
    addTo_Matrix(matrix, new_IntCoordinate(2, 0, 17));
    addTo_Matrix(matrix, new_StringCoordinate(3, 4, "Hello"));

    print_Matrix(matrix);
    printT_Matrix(matrix);
    dispose_Matrix(matrix);

    return;
}

//  Runs an example of a tree.
void example_Tree()
{
    Tree *tree = new_Tree();

    addTo_Tree(tree, new_CharNode(1, 'x'));

    dispose_Tree(tree);

    return;
}

int main()
{
    example_SingleList();

    return 0;
}
