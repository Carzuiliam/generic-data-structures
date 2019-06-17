/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "SparseMatrix.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty sparse matrix.
SparseMatrix* new_SparseMatrix(unsigned int _rows, unsigned int _cols)
{
    SparseMatrix *sparseMatrix = malloc(sizeof (SparseMatrix));

    if (sparseMatrix != NULL)
    {
        sparseMatrix->rows = _rows;
        sparseMatrix->cols = _cols;

        for (int i = 0; i < sparseMatrix->rows; i++)
        {
            sparseMatrix->row[i] = NULL;
        }

        for (int i = 0; i < sparseMatrix->cols; i++)
        {
            sparseMatrix->col[i] = NULL;
        }
    }

    return sparseMatrix;
}

/**-----------------------------------------------------
                    Structure destruction
 -----------------------------------------------------*/

 // Disposes an sparse matrix.
void dispose_SparseMatrix(SparseMatrix *_sparseMatrix)
{
    if (_sparseMatrix == NULL) return;

    for (int i = 0; i < _sparseMatrix->rows; i++)
    {
        if (_sparseMatrix->row[i] != NULL)
        {
            Coordinate *coord = _sparseMatrix->row[i];
            Coordinate *aux = _sparseMatrix->row[i]->nextJ;

            while (aux != NULL)
            {
                dispose_Coordinate(coord);

                coord = aux;
                aux = aux->nextJ;
            }

            dispose_Coordinate(coord);
            dispose_Coordinate(aux);
        }

        for (int i = 0; i < _sparseMatrix->rows; i++)
        {
            _sparseMatrix->row[i] = NULL;
        }

        for (int i = 0; i < _sparseMatrix->cols; i++)
        {
            _sparseMatrix->col[i] = NULL;
        }
    }

    free(_sparseMatrix);

    return;
}

/**-----------------------------------------------------
                    Inserting coordinates
 -----------------------------------------------------*/

//  Adds an element to the sparse matrix.
void addTo_SparseMatrix(SparseMatrix *_sparseMatrix, Coordinate *_coordinate)
{
    if (_sparseMatrix == NULL || _coordinate == NULL) return;
    if (_coordinate->i >= _sparseMatrix->rows) return;
    if (_coordinate->j >= _sparseMatrix->cols) return;

    Coordinate *coordI = _sparseMatrix->row[_coordinate->i];
    Coordinate *coordJ = _sparseMatrix->col[_coordinate->j];

    if (coordI == NULL)
    {
        _sparseMatrix->row[_coordinate->i] = _coordinate;
    }
    else
    {
        if (_coordinate->j < coordI->j)
        {
            _coordinate->nextJ = coordI;
            _sparseMatrix->row[_coordinate->i] = _coordinate;
        }
        else if (_coordinate->j == coordI->j)
        {
            _coordinate->nextJ = coordI->nextJ;
            _sparseMatrix->row[_coordinate->i] = _coordinate;
        }
        else if (coordI->nextJ == NULL)
        {
            coordI->nextJ = _coordinate;
        }
        else
        {
            Coordinate *prev = coordI;
            coordI = coordI->nextJ;

            while (coordI != NULL && coordI->j < _coordinate->j)
            {
                prev = coordI;
                coordI = coordI->nextJ;
            }

            _coordinate->nextJ = prev->nextJ;
            prev->nextJ = _coordinate;
        }
    }

    if (coordJ == NULL)
    {
        _sparseMatrix->col[_coordinate->j] = _coordinate;
    }
    else
    {
        if (_coordinate->i < coordJ->i)
        {
            _coordinate->nextI = coordJ;
            _sparseMatrix->col[_coordinate->j] = _coordinate;
        }
        else if (_coordinate->i == coordJ->i)
        {
            _coordinate->nextI = coordJ->nextI;
            _sparseMatrix->col[_coordinate->j] = _coordinate;
        }
        else if (coordJ->nextI == NULL)
        {
            coordJ->nextI = _coordinate;
        }
        else
        {
            Coordinate *prev = coordJ;
            coordJ = coordJ->nextI;

            while (coordJ != NULL && coordJ->i < _coordinate->i)
            {
                prev = coordJ;
                coordJ = coordJ->nextI;
            }

            _coordinate->nextI = prev->nextI;
            prev->nextI = _coordinate;
        }
    }

    if (coordI != NULL && coordI->j == _coordinate->j)
    {
        dispose_Coordinate(coordI);
    }

    if (coordJ != NULL && coordJ->i == _coordinate->i)
    {
        dispose_Coordinate(coordJ);
    }

    return;
}

/**-----------------------------------------------------
                    Removing coordinates
 -----------------------------------------------------*/

//  Removes an element at a specific position of the sparse matrix.
void removeAt_SparseMatrix(SparseMatrix *_sparseMatrix, unsigned int _i, unsigned int _j)
{
    if (_sparseMatrix == NULL) return;
    if (_i >= _sparseMatrix->rows) return;
    if (_j >= _sparseMatrix->cols) return;

    Coordinate *coordI = _sparseMatrix->row[_i];
    Coordinate *coordJ = _sparseMatrix->col[_j];

    if (coordI == NULL || coordJ == NULL) return;
    if (coordI->j > _j || coordJ->i > _i) return;

    if (coordI->j == _j && coordJ->i == _i)
    {
        Coordinate *aux = coordI;

        _sparseMatrix->row[_i] = _sparseMatrix->row[_i]->nextJ;
        _sparseMatrix->col[_j] = _sparseMatrix->col[_j]->nextI;

        dispose_Coordinate(aux);
    }
    else if (coordJ->i == _i)
    {
        Coordinate *prevI = NULL;

        while (coordI != NULL && coordI->j < _j)
        {
            prevI = coordI;
            coordI = coordI->nextJ;
        }

        if (coordI != NULL && coordI->j == _j)
        {
            Coordinate *aux = coordI;

            _sparseMatrix->col[_j] = _sparseMatrix->col[_j]->nextI;
            prevI->nextJ = coordI->nextJ;

            dispose_Coordinate(aux);
        }
    }
    else if (coordI->j == _j)
    {
        Coordinate *prevJ = NULL;

        while (coordJ != NULL && coordJ->i < _i)
        {
            prevJ = coordJ;
            coordJ = coordJ->nextI;
        }

        if (coordJ != NULL && coordJ->i == _i)
        {
            Coordinate *aux = coordJ;

            _sparseMatrix->row[_i] = _sparseMatrix->row[_i]->nextJ;
            prevJ->nextI = coordJ->nextI;

            dispose_Coordinate(aux);
        }
    }
    else
    {
        Coordinate *prevI = NULL;
        Coordinate *prevJ = NULL;

        while (coordI != NULL && coordI->j < _j)
        {
            prevI = coordI;
            coordI = coordI->nextJ;
        }

        while (coordJ != NULL && coordJ->i < _i)
        {
            prevJ = coordJ;
            coordJ = coordJ->nextI;
        }

        if (coordI != NULL && coordJ != NULL &&
            coordI->j == _j && coordJ->i == _i)
        {
            Coordinate *aux = coordI;

            prevI->nextJ = coordI->nextJ;
            prevJ->nextI = coordJ->nextI;

            dispose_Coordinate(aux);
        }
    }

    return;
}

/**-----------------------------------------------------
                    Finding coordinates
 -----------------------------------------------------*/

//  Returns a coordinate at the specific position of the sparse matrix.
Coordinate* getAt_SparseMatrix(SparseMatrix *_sparseMatrix, unsigned int _i, unsigned int _j)
{
    if (_sparseMatrix == NULL) return NULL;
    if (_i >= _sparseMatrix->rows) return NULL;
    if (_j >= _sparseMatrix->cols) return NULL;

    if (_sparseMatrix->row[_i] == NULL || _sparseMatrix->col[_j] == NULL) return NULL;

    Coordinate *aux = _sparseMatrix->row[_i];

    while (aux != NULL && aux->j < _j)
    {
        aux = aux->nextJ;
    }

    if (aux == NULL || aux->j > _j)
    {
        aux = new_IntCoordinate(_i, _j, 0);
    }

    return aux;
}

/**-----------------------------------------------------
                    Structure info
 -----------------------------------------------------*/

//  Prints all the elements of the sparse matrix.
void print_SparseMatrix(SparseMatrix *_sparseMatrix)
{
    printf(" Matrix ");

    if (_sparseMatrix == NULL)
    {
        printf("|       |\n");
        printf("-----------------\n");
        printf("|       |(null) |\n");
        printf("-----------------\n\n");
    }
    else
    {
        for (int j = 0; j < _sparseMatrix->cols; j++)
        {
            printf("|  %3i  ", j);
        }

        printf("|\n-");

        for (int j = 0; j <= _sparseMatrix->cols; j++)
        {
            printf("--------");
        }

        printf("\n");

        for (int i = 0; i < _sparseMatrix->rows; i++)
        {
            printf("|  %3i  |", i);

            Coordinate *aux = _sparseMatrix->row[i];

            for (int j = 0; j < _sparseMatrix->cols; j++)
            {
                if (aux == NULL)
                {
                    printf((j < _sparseMatrix->cols - 1) ? "      - " : "      -");
                }
                else if (j < aux->j)
                {
                    printf((j < _sparseMatrix->cols - 1) ? "      - " : "      -");
                }
                else
                {
                    print_Coordinate(aux);

                    if (j < _sparseMatrix->cols - 1)
                    {
                        printf(" ");
                    }

                    aux = aux->nextJ;
                }
            }

            printf("|\n");
        }

        printf("-");

        for (int i = 0; i <= _sparseMatrix->cols; i++)
        {
            printf("--------");
        }

        printf("\n\n");
    }

    return;
}

//  Prints all the elements of the sparse matrix, but transposed.
void printT_SparseMatrix(SparseMatrix *_sparseMatrix)
{
    printf(" Matrix ");

    if (_sparseMatrix == NULL)
    {
        printf("|       |\n");
        printf("-----------------\n");
        printf("|       |(null) |\n");
        printf("-----------------\n\n");
    }
    else
    {
        for (int i = 0; i < _sparseMatrix->rows; i++)
        {
            printf("|  %3i  ", i);
        }

        printf("|\n-");

        for (int i = 0; i <= _sparseMatrix->rows; i++)
        {
            printf("--------");
        }

        printf("\n");

        for (int j = 0; j < _sparseMatrix->cols; j++)
        {
            printf("|  %3i  |", j);

            Coordinate *aux = _sparseMatrix->col[j];

            for (int i = 0; i < _sparseMatrix->rows; i++)
            {
                if (aux == NULL)
                {
                    printf((i < _sparseMatrix->rows - 1) ? "      - " : "      -");
                }
                else if (i < aux->i)
                {
                    printf((i < _sparseMatrix->rows - 1) ? "      - " : "      -");
                }
                else
                {
                    print_Coordinate(aux);

                    if (i < _sparseMatrix->rows - 1)
                    {
                        printf(" ");
                    }

                    aux = aux->nextI;
                }
            }

            printf("|\n");
        }

        printf("-");

        for (int j = 0; j <= _sparseMatrix->rows; j++)
        {
            printf("--------");
        }

        printf("\n\n");
    }

    return;
}
