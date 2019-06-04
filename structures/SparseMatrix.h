/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#pragma once

/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

typedef struct SparseMatrix
{
    unsigned int rows;
    unsigned int cols;

    struct Coordinate *row[NUM_ROWS];
    struct Coordinate *col[NUM_COLS];
}
SparseMatrix;

/**-----------------------------------------------------
                    Functions prototypes
 -----------------------------------------------------*/

SparseMatrix* new_SparseMatrix(unsigned int, unsigned int);
void dispose_SparseMatrix(SparseMatrix*);

void addTo_SparseMatrix(SparseMatrix*, Coordinate*);

void removeAt_SparseMatrix(SparseMatrix*, unsigned int, unsigned int);

Coordinate* getAt_SparseMatrix(SparseMatrix*, unsigned int, unsigned int);

void print_Matrix(SparseMatrix*);
void printT_Matrix(SparseMatrix*);

