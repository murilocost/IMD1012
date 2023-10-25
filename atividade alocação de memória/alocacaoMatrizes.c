#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nlin, ncol;
    int **mat;
} Matrix;

Matrix *createMatrix(int lin, int col){
    Matrix *mat;

    mat = calloc(1, sizeof(Matrix));

    mat->nlin = lin;    
    mat->ncol = col;

    mat->mat = calloc(1, sizeof(int *));

    for (int i = 0; i < lin; i++){
        mat->mat[i] = calloc(col, sizeof(int));
    }

    return mat;
}

void readMatrix(Matrix *mat){
    for (int i = 0; i < mat->nlin; i++){
        for (int j = 0; j < mat->ncol; j++){
            scanf("%d", &mat->mat[i][j]);
        }
    }
}


void printMatrix(Matrix *mat){
    for (int i = 0; i < mat->nlin; i++){
        for (int j = 0; j < mat->ncol; j++){
            printf("%d ", mat->mat[i][j]);
        }
        printf("\n");
    }
}


void destroyMatrix(Matrix **mat){
    for (int i = 0; i < (*mat)->nlin; i++){
        free((*mat)->mat[i]);
    }

    free((*mat)->mat);
    free(*mat);
    *mat = NULL;
}


int main() {
    int lin, col;
    Matrix* mat;

    scanf("%i %i", &lin, &col);

    mat = createMatrix(lin, col);

    readMatrix(mat);

    printMatrix(mat);

    destroyMatrix(&mat);
 
  
    if (mat == NULL) printf("OK\n");

    return 0;
}
