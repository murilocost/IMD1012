#include <stdio.h>
#include <stdlib.h>

    // Faça o Pac-Man (C) coletar todas as bolinhas "." do mapa represenatado pela matriz utilizando backtraking

typedef struct {
    int ln, cl;
    char **matriz;
} Matrix;

Matrix *criaMatriz(int lin, int col){
    Matrix *aux;

    aux = calloc(1, sizeof(Matrix));

    aux->ln = lin;
    aux->cl = col;

    aux->matriz = (char**)calloc(lin, sizeof(char*));

    for (int i = 0; i < lin; i++){
        aux->matriz[i] = calloc(col, sizeof(char));
    }

    return aux;
}

void leituraMatriz(Matrix *mapa){
    for (int i = 0; i < (mapa->ln); i++){
        for (int j = 0; j < (mapa->cl); j++){
            scanf(" %c", &mapa->matriz[i][j]);
        }
    }
}

void imprimeMapa(Matrix *mapa){
    for (int i = 0; i < (mapa->ln); i++){
        for (int j = 0; j < (mapa->cl); j++){
            printf("%c", mapa->matriz[i][j]);
        }
        printf("\n");
    }
}

void destroyMatrix(Matrix **m) {
  for (int i=0; i<((*m)->ln); i++) {
    (*m)->matriz[i] = NULL;
    free((*m)->matriz[i]);
  }
  
  free((*m)->matriz);
  (*m)->matriz = NULL;

  free(*m);
  *m = NULL;
}


int contaBolinha(Matrix *mapa, int x, int y){
    int cont = 0;

    if (x - 1 >= 0 && mapa->matriz[x-1][y] == '.'){
        mapa->matriz[x-1][y] = ' ';
        cont += (1 + contaBolinha(mapa, x - 1, y));
    }
    if (y - 1 >= 0 && mapa->matriz[x][y-1] == '.'){
        mapa->matriz[x][y-1] = ' ';
        cont += (1 + contaBolinha(mapa, x, y - 1));
    }
    if (x + 1 < (mapa->ln) && mapa->matriz[x + 1][y] == '.'){
        mapa->matriz[x + 1][y] = ' ';
        cont += (1 + contaBolinha(mapa, x + 1, y));
    }
    if (y + 1 < (mapa->cl) && mapa->matriz[x][y + 1] == '.'){
        mapa->matriz[x][y + 1] = ' ';
        cont += (1 + contaBolinha(mapa, x, y + 1));
    }
    
    return cont;
}

int main(){
    int linha, coluna;
    Matrix* mapa;

    scanf("%i %i", &linha, &coluna);

    mapa = criaMatriz(linha, coluna);


    leituraMatriz(mapa);

    int posX, posY, bolinhas = 0;

    for (int i = 0; i < mapa->ln; i++){
        for (int j  = 0; j < mapa->cl; j++){
            if (mapa->matriz[i][j] == 'C'){
                posX = i;
                posY = j;
            }
        }
    }
    
    bolinhas = contaBolinha(mapa, posX, posY);

    printf("Total de bolinhas devoradas: %d\n", bolinhas);
    printf("Mapa final:\n");

    imprimeMapa(mapa);

    destroyMatrix(&mapa);

    return 0;
}