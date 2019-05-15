/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

typedef struct Matrix
{
    int numRows;
    int numCols;

    struct Coordinate *rows[NUM_ROWS];
    struct Coordinate *cols[NUM_COLS];
}
Matrix;

/**-----------------------------------------------------
                    Functions prototypes
 -----------------------------------------------------*/

Matrix* new_Matrix(int _numRows, int _numCols);
void dispose_Matrix(Matrix *_matrix);

void addTo_Matrix(Matrix *_matrix, Coordinate *_coordinate);

void print_Matrix(Matrix *_matrix);

