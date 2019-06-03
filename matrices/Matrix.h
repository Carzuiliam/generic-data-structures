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

Matrix* new_Matrix(unsigned int, unsigned int);
void dispose_Matrix(Matrix*);

void addTo_Matrix(Matrix*, Coordinate*);

void removeAt_Matrix(Matrix*, unsigned int, unsigned int);

Coordinate* getAt_Matrix(Matrix*, unsigned int, unsigned int);

void print_Matrix(Matrix*);
void printT_Matrix(Matrix*);

