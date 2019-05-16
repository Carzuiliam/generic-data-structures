/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "../include/Matrix.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty matrix.
Matrix* new_Matrix(int _numRows, int _numCols)
{
    Matrix *matrix = malloc(sizeof (Matrix));

    if (matrix != NULL)
    {
        matrix->nonZeros = 0;
        matrix->numRows = _numRows;
        matrix->numCols = _numCols;

        for (int i = 0; i < matrix->numRows; i++)
        {
            matrix->rows[i] = NULL;
        }

        for (int i = 0; i < matrix->numCols; i++)
        {
            matrix->cols[i] = NULL;
        }
    }

    return matrix;
}

/**-----------------------------------------------------
                    Structure destruction
 -----------------------------------------------------*/

void dispose_Matrix(Matrix *_matrix)
{
    if (_matrix == NULL) return;

    for (int i = 0; i < _matrix->numRows; i++)
    {
        if (_matrix->rows[i] != NULL)
        {
            Coordinate *coord = _matrix->rows[i];
            Coordinate *aux = _matrix->rows[i]->nextCol;

            while (aux != NULL)
            {
                dispose_Coordinate(coord);

                coord = aux;
                aux = aux->nextCol;
            }

            dispose_Coordinate(coord);
        }
    }

    free(_matrix);

    return;
}

/**-----------------------------------------------------
                    Inserting nodes
 -----------------------------------------------------*/

//  Adds an element to the matrix.
void addTo_Matrix(Matrix *_matrix, Coordinate *_coordinate)
{
    if (_matrix == NULL || _coordinate == NULL) return;
    if (_coordinate->row < 0 || _coordinate->row >= _matrix->numRows) return;
    if (_coordinate->col < 0 || _coordinate->col >= _matrix->numCols) return;

    Coordinate *coordR = _matrix->rows[_coordinate->row];
    Coordinate *coordC = _matrix->cols[_coordinate->col];

    if (coordR == NULL)
    {
        _coordinate->nextCol = NULL;
        _matrix->rows[_coordinate->row] = _coordinate;
        _matrix->nonZeros++;
    }
    else
    {
        Coordinate *prev = coordR;

        while (coordR->nextCol != NULL && coordR->col <= _coordinate->col)
        {
            prev = coordR;
            coordR = coordR->nextCol;
        }

        if (coordR->col < _coordinate->col)
        {
            _coordinate->nextCol = NULL;
            coordR->nextCol = _coordinate;
        }
        else if (coordR->col == _coordinate->col)
        {
            _coordinate->nextCol = coordR->nextCol;
            prev->nextCol = _coordinate;
        }
        else
        {
            _coordinate->nextCol = coordR;
            prev->nextCol = _coordinate;
        }

        _matrix->nonZeros++;
    }

    if (coordC == NULL)
    {
        _coordinate->nextRow = NULL;
        _matrix->cols[_coordinate->col] = _coordinate;
        _matrix->nonZeros++;
    }
    else
    {
        Coordinate *prev = coordC;

        while (coordC->nextRow != NULL && coordC->row <= _coordinate->row)
        {
            prev = coordC;
            coordC = coordC->nextRow;
        }

        if (coordC->row < _coordinate->row)
        {
            _coordinate->nextRow = NULL;
            coordC->nextRow = _coordinate;
        }
        else if (coordC->row == _coordinate->row)
        {
            _coordinate->nextRow = coordC->nextRow;
            prev->nextRow = _coordinate;
        }
        else
        {
            _coordinate->nextRow = coordC;
            prev->nextRow = _coordinate;
        }

        _matrix->nonZeros++;
    }

    if (coordR != NULL && coordR->col == _coordinate->col)
    {
        dispose_Coordinate(coordR);
    }

    if (coordC != NULL && coordC->row == _coordinate->row)
    {
        dispose_Coordinate(coordC);
    }

    return;
}

/**-----------------------------------------------------
                    Removing nodes
 -----------------------------------------------------*/

//  Removes an element at the specific index of the matrix.
void removeAt_Matrix(Matrix *_matrix, int _row, int _col)
{
    if (_matrix == NULL) return;
    if (_row < 0 || _row >= _matrix->numRows) return;
    if (_col < 0 || _col >= _matrix->numCols) return;

    return;
}

/**-----------------------------------------------------
                    Structure info
 -----------------------------------------------------*/

//  Prints all the elements of the matrix.
void print_Matrix(Matrix *_matrix)
{
    if (_matrix == NULL) return;

    printf(" Matrix ");

    for (int j = 0; j < _matrix->numCols; j++)
    {
        printf("|  %3i  ", j);
    }

    printf("|\n-");

    for (int j = 0; j <= _matrix->numCols; j++)
    {
        printf("--------");
    }

    printf("\n");

    for (int i = 0; i < _matrix->numRows; i++)
    {
        printf("|  %3i  |", i);

        Coordinate *aux = _matrix->rows[i];

        for (int j = 0; j < _matrix->numCols; j++)
        {
            if (aux == NULL)
            {
                printf((j < _matrix->numCols - 1) ? "      - " : "      -");
            }
            else if (j < aux->col)
            {
                printf((j < _matrix->numCols - 1) ? "      - " : "      -");
            }
            else
            {
                print_Coordinate(aux);

                if (j < _matrix->numCols - 1)
                {
                    printf(" ");
                }

                aux = aux->nextCol;
            }
        }

        printf("|\n");
    }

    printf("-");

    for (int i = 0; i <= _matrix->numCols; i++)
    {
        printf("--------");
    }

    printf("\n\n");

    return;
}

//  Prints all the elements of the matrix, but transposed.
void printT_Matrix(Matrix *_matrix)
{
    if (_matrix == NULL) return;

    printf(" Matr_T ");

    for (int i = 0; i < _matrix->numRows; i++)
    {
        printf("|  %3i  ", i);
    }

    printf("|\n-");

    for (int i = 0; i <= _matrix->numRows; i++)
    {
        printf("--------");
    }

    printf("\n");

    for (int j = 0; j < _matrix->numCols; j++)
    {
        printf("|  %3i  |", j);

        Coordinate *aux = _matrix->cols[j];

        for (int i = 0; i < _matrix->numRows; i++)
        {
            if (aux == NULL)
            {
                printf((i < _matrix->numRows - 1) ? "      - " : "      -");
            }
            else if (i < aux->row)
            {
                printf((i < _matrix->numRows - 1) ? "      - " : "      -");
            }
            else
            {
                print_Coordinate(aux);

                if (i < _matrix->numRows - 1)
                {
                    printf(" ");
                }

                aux = aux->nextRow;
            }
        }

        printf("|\n");
    }

    printf("-");

    for (int i = 0; i <= _matrix->numRows; i++)
    {
        printf("--------");
    }

    printf("\n\n");

    return;
}
