/**-----------------------------------------------------
                    Program includes
 -----------------------------------------------------*/

#define     NUM_ROWS    4
#define     NUM_COLS    5

#include    <stdio.h>
#include    <stdlib.h>

#include    "../definitions/Element.c"
#include    "../definitions/Coordinate.c"
#include    "../definitions/Node.c"

#include    "../structures/SingleList.c"
#include    "../structures/SingleStack.c"
#include    "../structures/SparseMatrix.c"
#include    "../structures/BinaryTree.c"

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
    addAt_SingleList(list, new_StringElement("hello"), 5);

    print_SingleList(list);
    dispose_SingleList(list);

    return;
}

void example_SingleStack()
{
    SingleStack *stack = new_SingleStack();

    push_SingleStack(stack, new_IntElement(1));
    push_SingleStack(stack, new_CharElement('w'));
    push_SingleStack(stack, new_FloatElement(2.0f));
    push_SingleStack(stack, new_IntElement(3));
    push_SingleStack(stack, new_CharElement('x'));
    push_SingleStack(stack, new_CharElement('y'));
    push_SingleStack(stack, new_StringElement("four"));
    push_SingleStack(stack, new_CharElement('z'));
    push_SingleStack(stack, new_IntElement(5));
    push_SingleStack(stack, new_FloatElement(6.5f));

    print_SingleStack(stack);
    dispose_SingleStack(stack);

    return;
}

//  Runs an example of a matrix.
void example_SparseMatrix()
{
    SparseMatrix *matrix = new_SparseMatrix(NUM_ROWS, NUM_COLS);

    addTo_SparseMatrix(matrix, new_FloatCoordinate(0, 1, 3.0f));
    addTo_SparseMatrix(matrix, new_IntCoordinate(0, 4, 7));
    addTo_SparseMatrix(matrix, new_CharCoordinate(0, 2, 'y'));
    addTo_SparseMatrix(matrix, new_FloatCoordinate(1, 2, 4.2f));
    addTo_SparseMatrix(matrix, new_IntCoordinate(1, 0, 1));
    addTo_SparseMatrix(matrix, new_CharCoordinate(1, 1, 'z'));
    addTo_SparseMatrix(matrix, new_StringCoordinate(2, 2, "Again"));
    addTo_SparseMatrix(matrix, new_IntCoordinate(3, 3, 10));
    addTo_SparseMatrix(matrix, new_CharCoordinate(0, 0, 'x'));
    addTo_SparseMatrix(matrix, new_FloatCoordinate(0, 3, 1.23));
    addTo_SparseMatrix(matrix, new_IntCoordinate(2, 0, 17));
    addTo_SparseMatrix(matrix, new_StringCoordinate(3, 4, "Hello"));

    print_SparseMatrix(matrix);
    printT_SparseMatrix(matrix);
    dispose_SparseMatrix(matrix);

    return;
}

//  Runs an example of a tree.
void example_BinaryTree()
{
    BinaryTree *tree = new_BinaryTree();

    addTo_BinaryTree(tree, new_CharNode(5, 'x'));
    addTo_BinaryTree(tree, new_IntNode(3, 1));
    addTo_BinaryTree(tree, new_StringNode(9, "test"));
    addTo_BinaryTree(tree, new_CharNode(2, 'a'));
    addTo_BinaryTree(tree, new_IntNode(4, 99));
    addTo_BinaryTree(tree, new_StringNode(15, "end"));
    addTo_BinaryTree(tree, new_StringNode(12, "almost"));
    addTo_BinaryTree(tree, new_FloatNode(1, 1.8f));

    print_BinaryTree(tree);
    //dispose_BinaryTree(tree);

    return;
}

//  The MAIN function.
int main()
{
    example_BinaryTree();
    return 0;
}
