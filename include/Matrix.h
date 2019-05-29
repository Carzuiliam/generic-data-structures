/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#pragma once

/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

typedef struct Matrix
{
    unsigned int length;

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

void removeAt_Matrix(Matrix *_matrix, unsigned int _i, unsigned int _j);

Coordinate* getAt_Matrix(Matrix *_matrix, unsigned int _i, unsigned int _j);

void print_Matrix(Matrix *_matrix);
void printT_Matrix(Matrix *_matrix);

