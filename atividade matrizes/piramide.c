#include <stdio.h>

//Fazer uma função que leia as linhas da matriz e va adicionando camadas a medida que vai se distanciando da borda.
int estruturaPiramide (int n, int matriz[n][n]){
    int topo = 1;
    int coluna = 0;
    int linha = 0;
    /*
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if( i == 0 || j ==0 || i == fundo || j == fundo) matriz[i][j] = 1;
            else if(i == 1 || j == 1|| i == fundo - 1 || j == fundo - 1) matriz[i][j] = 2;
            else if(i == 2 || j == 2 || i == fundo - 2 || j == fundo - 2) matriz[i][j] = 3;
            else if(i == 3 || j == 3 || i == fundo - 3 || j == fundo - 3) matriz[i][j] = 4;
            else if(i == 4 || j == 4 || i == fundo - 4 || j == fundo - 4) matriz[i][j] = 5;

            
        }
    }
    */
   while (topo <= (n / 2) + 1){
    for (int i = coluna; i < n - coluna; i++){
        matriz[linha][i] = topo;
        matriz[n - linha - 1][i] = topo;
    }

    for (int i = linha + 1; i < n - linha - 1; i++){
        matriz[i][coluna] = topo;
        matriz[i][n - coluna - 1] = topo;
    }

    topo++;
    linha++;
    coluna++;
   }

    return matriz[n][n];
}



int main(){
    int N;

    scanf("%d", &N);

    int piramide[N][N];

    estruturaPiramide(N, piramide);

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf(" %d ", piramide[i][j]);
        }
        printf("\n");
    }


    return 0;
}