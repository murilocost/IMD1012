#include <stdio.h>

int resultado_jogada(char matriz[3][3], int x, int y, char simbolo){
    //Diagonais abaixo
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if((x == y && matriz[0][0] == simbolo && matriz[1][1] == simbolo && matriz[2][2 == simbolo]) ||
            (x + y == 2 && matriz[0][2] == simbolo && matriz[1][1] == simbolo && matriz[2][0] == simbolo)) return 1;
        }
    }

    //Linhas abaixo
    for (int i = 0; i < 3; i++){
        if(matriz[0][y] == simbolo && matriz[1][y] == simbolo && matriz[2][y] == simbolo) return 1;
    }

    //Colunas abaixo
    for (int i  = 0; i < 3; i++){
        if(matriz[x][0] == simbolo && matriz[x][1] == simbolo && matriz[x][2] == simbolo) return 1;
    }
}

int main(){
    char tabuleiro[3][3];
    int jogadas;
    int X, Y, i;
    char SIMB;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            scanf(" %c", &tabuleiro[i][j]);
        }
    }

    scanf("%d", &jogadas);
/*
    i = 0;

    while(i < jogadas){
        scanf("%d %d %c", &X, &Y, &SIMB);


        X = X - 1;
        Y = Y - 1;

        if (tabuleiro[X][Y] == '.'){
            if ((tabuleiro[X--][Y--] == SIMB && tabuleiro[X++][Y++] == SIMB) || (tabuleiro[X++][Y--] == SIMB && tabuleiro[X--][Y++] == SIMB) ||
            //elemento central acima
             (tabuleiro[X++][Y] == SIMB && tabuleiro[X--][Y] == SIMB) || (tabuleiro[X][Y++] == SIMB && tabuleiro[X][Y--] == SIMB) ||
             //elementos na linha do meio ou coluna do meio acima
             (tabuleiro[X++][Y] == SIMB && tabuleiro[X + 2][Y] == SIMB) || (tabuleiro[X][Y++] == SIMB && tabuleiro[X][Y + 2] == SIMB) ||
             //elementos na primeira linha ou primeira coluna acima
             (tabuleiro[X--][Y] == SIMB && tabuleiro[X - 2][Y] == SIMB) || (tabuleiro[X][Y--] == SIMB && tabuleiro[X][Y - 2] == SIMB) ||
             //elementos na ultima linha ou coluna acima
             (tabuleiro[X++][Y++] == SIMB && tabuleiro[X + 2][Y + 2] == SIMB) || (tabuleiro[X--][Y++] == SIMB && tabuleiro[X - 2][Y + 2] == SIMB) ||
             //elementos no canto do lado esquerdo acima
             (tabuleiro[X--][Y--] == SIMB && tabuleiro[X - 2][Y - 2] == SIMB) || (tabuleiro[X++][Y--] == SIMB && tabuleiro[X + 2][Y - 2] == SIMB)
             //elementos no canto do lado direito acima
             ) printf("Boa jogada, vai vencer!\n");
             else printf("Continua o jogo.\n");
        }
        else printf("Jogada inválida!\n");

        i++;
    }
*/

for (int i = 0; i < jogadas; i++){
    scanf("%d %d %c", &X, &Y, &SIMB);

    X -= 1;
    Y -= 1;

    if (tabuleiro[X][Y] != '.') printf("Jogada inválida!\n");
    else{
        tabuleiro[X][Y] = SIMB;
        if(resultado_jogada(tabuleiro, X, Y, SIMB)) printf("Boa jogada, vai vencer!\n");
        else printf("Continua o jogo.\n");
        tabuleiro[X][Y] = '.';
    }
}


    return 0;
}