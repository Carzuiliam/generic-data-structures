/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#pragma once

/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

typedef struct Matrix
{
    int length;

    unsigned int rows;
    unsigned int cols;

    struct Coordinate *row[NUM_ROWS];
    struct Coordinate *col[NUM_COLS];
}
Matrix;

/**-----------------------------------------------------
                    Functions prototypes
 -----------------------------------------------------*/

Matrix* new_Matrix(unsigned int _rows, unsigned int _cols);
void dispose_Matrix(Matrix *_matrix);

void addTo_Matrix(Matrix *_matrix, Coordinate *_coordinate);

void print_Matrix(Matrix *_matrix);
void printT_Matrix(Matrix *_matrix);

