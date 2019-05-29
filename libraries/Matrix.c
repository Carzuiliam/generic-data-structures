/**-----------------------------------------------------
                    Structure includes
 -----------------------------------------------------*/

#include "../include/Matrix.h"

/**-----------------------------------------------------
                    Structure creation
 -----------------------------------------------------*/

//  Creates an empty matrix.
Matrix* new_Matrix(unsigned int _rows, unsigned int _cols)
{
    Matrix *matrix = malloc(sizeof (Matrix));

    if (matrix != NULL)
    {
        matrix->length = 0;
        matrix->rows = _rows;
        matrix->cols = _cols;

        for (int i = 0; i < matrix->rows; i++)
        {
            matrix->row[i] = NULL;
        }

        for (int i = 0; i < matrix->cols; i++)
        {
            matrix->col[i] = NULL;
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

    for (int i = 0; i < _matrix->rows; i++)
    {
        if (_matrix->row[i] != NULL)
        {
            Coordinate *coord = _matrix->row[i];
            Coordinate *aux = _matrix->row[i]->nextJ;

            while (aux != NULL)
            {
                dispose_Coordinate(coord);

                coord = aux;
                aux = aux->nextJ;
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
    if (_coordinate->i >= _matrix->rows) return;
    if (_coordinate->j >= _matrix->cols) return;

    Coordinate *coordI = _matrix->row[_coordinate->i];
    Coordinate *coordJ = _matrix->col[_coordinate->j];

    if (coordI == NULL)
    {
        _matrix->row[_coordinate->i] = _coordinate;
        _matrix->length++;
    }
    else
    {
        if (_coordinate->j < coordI->j)
        {
            _coordinate->nextJ = coordI;
            _matrix->row[_coordinate->i] = _coordinate;
            _matrix->length++;
        }
        else if (_coordinate->j == coordI->j)
        {
            _coordinate->nextJ = coordI->nextJ;
            _matrix->row[_coordinate->i] = _coordinate;
        }
        else if (coordI->nextJ == NULL)
        {
            coordI->nextJ = _coordinate;
            _matrix->length++;
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
            _matrix->length++;
        }
    }

    if (coordJ == NULL)
    {
        _matrix->col[_coordinate->j] = _coordinate;
        _matrix->length++;
    }
    else
    {
        if (_coordinate->i < coordJ->i)
        {
            _coordinate->nextI = coordJ;
            _matrix->col[_coordinate->j] = _coordinate;
            _matrix->length++;
        }
        else if (_coordinate->i == coordJ->i)
        {
            _coordinate->nextI = coordJ->nextI;
            _matrix->col[_coordinate->j] = _coordinate;
        }
        else if (coordJ->nextI == NULL)
        {
            coordJ->nextI = _coordinate;
            _matrix->length++;
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
            _matrix->length++;
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
                    Removing nodes
 -----------------------------------------------------*/

//  Removes an element at a specific position of the matrix.
void removeAt_Matrix(Matrix *_matrix, unsigned int _i, unsigned int _j)
{
    if (_matrix == NULL) return;
    if (_i >= _matrix->rows) return;
    if (_j >= _matrix->cols) return;

    Coordinate *coordI = _matrix->row[_i];
    Coordinate *coordJ = _matrix->col[_j];

    if (coordI == NULL || coordJ == NULL) return;
    if (coordI->j > _j || coordJ->i > _i) return;

    if (coordI->j == _j && coordJ->i == _i)
    {
        Coordinate *aux = coordI;

        _matrix->row[_i] = _matrix->row[_i]->nextJ;
        _matrix->col[_j] = _matrix->col[_j]->nextI;
        _matrix->length--;

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

            _matrix->col[_j] = _matrix->col[_j]->nextI;

            prevI->nextJ = coordI->nextJ;
            _matrix->length--;

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

            _matrix->row[_i] = _matrix->row[_i]->nextJ;

            prevJ->nextI = coordJ->nextI;
            _matrix->length--;

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
            _matrix->length--;

            dispose_Coordinate(aux);
        }
    }

    return;
}

/**-----------------------------------------------------
                    Finding nodes
 -----------------------------------------------------*/

//  Returns a coordinate at the specific position of the matrix.
Coordinate* getAt_Matrix(Matrix *_matrix, unsigned int _i, unsigned int _j)
{
    if (_matrix == NULL) return NULL;
    if (_i >= _matrix->rows) return NULL;
    if (_j >= _matrix->cols) return NULL;

    if (_matrix->row[_i] == NULL || _matrix->col[_j] == NULL) return NULL;

    Coordinate *aux = _matrix->row[_i];

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

//  Prints all the elements of the matrix.
void print_Matrix(Matrix *_matrix)
{
    if (_matrix == NULL) return;

    printf(" Matrix ");

    for (int j = 0; j < _matrix->cols; j++)
    {
        printf("|  %3i  ", j);
    }

    printf("|\n-");

    for (int j = 0; j <= _matrix->cols; j++)
    {
        printf("--------");
    }

    printf("\n");

    for (int i = 0; i < _matrix->rows; i++)
    {
        printf("|  %3i  |", i);

        Coordinate *aux = _matrix->row[i];

        for (int j = 0; j < _matrix->cols; j++)
        {
            if (aux == NULL)
            {
                printf((j < _matrix->cols - 1) ? "      - " : "      -");
            }
            else if (j < aux->j)
            {
                printf((j < _matrix->cols - 1) ? "      - " : "      -");
            }
            else
            {
                print_Coordinate(aux);

                if (j < _matrix->cols - 1)
                {
                    printf(" ");
                }

                aux = aux->nextJ;
            }
        }

        printf("|\n");
    }

    printf("-");

    for (int i = 0; i <= _matrix->cols; i++)
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

    printf(" Matrix ");

    for (int i = 0; i < _matrix->rows; i++)
    {
        printf("|  %3i  ", i);
    }

    printf("|\n-");

    for (int i = 0; i <= _matrix->rows; i++)
    {
        printf("--------");
    }

    printf("\n");

    for (int j = 0; j < _matrix->cols; j++)
    {
        printf("|  %3i  |", j);

        Coordinate *aux = _matrix->col[j];

        for (int i = 0; i < _matrix->rows; i++)
        {
            if (aux == NULL)
            {
                printf((i < _matrix->rows - 1) ? "      - " : "      -");
            }
            else if (i < aux->i)
            {
                printf((i < _matrix->rows - 1) ? "      - " : "      -");
            }
            else
            {
                print_Coordinate(aux);

                if (i < _matrix->rows - 1)
                {
                    printf(" ");
                }

                aux = aux->nextI;
            }
        }

        printf("|\n");
    }

    printf("-");

    for (int j = 0; j <= _matrix->rows; j++)
    {
        printf("--------");
    }

    printf("\n\n");

    return;
}
