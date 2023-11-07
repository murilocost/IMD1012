#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int montaMatriz(char **matriz) {
    int aux = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf(" %c", &matriz[i][j]);
            if (matriz[i][j] == '*')
                aux++;
        }
    }

    return aux;
}

void procuraVazios(char **matriz, int *X, int *Y, int numVazios) {
    int pos = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (matriz[i][j] == '*') {
                X[pos] = i;
                Y[pos] = j;
                pos++;
            }
        }
    }
}

int submatriz(char **mat, int x, int y, char a) {
    for (int i = x - (x % 3); i < x - (x % 3) + 3; i++) {
        for (int j = y - (y % 3); j < y - (y % 3) + 3; j++) {
            if (mat[i][j] == a)
                return 1;
        }
    }
    return 0;
}

int linha(char **mat, int x, char a) {
    for (int j = 0; j < 9; j++)
        if (mat[x][j] == a)
            return 1;
    return 0;
}

int coluna(char **mat, int y, char a) {
    for (int i = 0; i < 9; i++)
        if (mat[i][y] == a)
            return 1;
    return 0;
}

void imprimeTabuleiro(char **matriz) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int completaTabuleiro(char **matriz, int *X, int *Y, int numVazios, int aux) {
    int posX, posY;

    if (numVazios - aux == 0)
        return 1;
    else {
        for (int i = 1; i < 10; i++) {
            posX = X[aux];
            posY = Y[aux];

            if (!submatriz(matriz, posX, posY, i + '0') && !linha(matriz, posX, i + '0') && !coluna(matriz, posY, i + '0')) {
                matriz[posX][posY] = i + '0';
                if (!completaTabuleiro(matriz, X, Y, numVazios, aux + 1))
                    matriz[posX][posY] = '*';
                else
                    return 1;
            }
        }
    }

    return 0;
}

int main(){
    char **tabuleiro;

    tabuleiro = calloc(9, sizeof(char*));
    
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            tabuleiro[i] = calloc(9, sizeof(int));
        }
    }

    int *X, *Y;
    int vazios;

    vazios = montaMatriz(tabuleiro);

    X = calloc(vazios, sizeof(int));
    Y = calloc(vazios, sizeof(int));

    procuraVazios(tabuleiro, X, Y, vazios);

    if(completaTabuleiro(tabuleiro, X, Y, vazios, 0))
        imprimeTabuleiro(tabuleiro);
    else
        printf("Não tem solução!\n");


    return 0;
}