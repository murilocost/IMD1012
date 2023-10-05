#include <stdio.h>

// CORES: G(Green); Y(Yellow); R(Red).

int calcular_aposta(int coluna, int linha, int matriz[linha][coluna], char cor){
    int somadorVerde = 0, somadorAmarelo = 0, somadorVermelho = 0;
    int verde, amarelo, vermelho;
    char green = 'G', yellow = 'Y', red = 'R';

    verde = (coluna / 3);
    amarelo = (2 * (coluna / 3));
    vermelho = coluna;

    if (cor == green){
        for (int i = 0; i < linha; i++){
            for (int j = 0; j < verde; j++){
                somadorVerde = somadorVerde + matriz[i][j];
            }
        }

        return somadorVerde;
    }
    else if (cor == yellow){
        for (int i = 0; i < linha; i++){
            for (int j = 0; j < verde; j++){
                somadorVerde = somadorVerde + matriz[i][j];
            }
        }

        for (int i = 0; i < linha; i++){
            for (int j = 0; j < amarelo; j++){
                somadorAmarelo = somadorAmarelo + matriz[i][j];
            }
        }

        somadorAmarelo = somadorAmarelo - somadorVerde;

        return somadorAmarelo;
    }
    else if (cor == red){
        for (int i = 0; i < linha; i++){
            for (int j = 0; j < amarelo; j++){
                somadorAmarelo = somadorAmarelo + matriz[i][j];
            }
        }

        for (int i = 0; i < linha; i++){
            for (int j = 0; j < vermelho; j++){
                somadorVermelho = somadorVermelho + matriz[i][j];
            }
        }

        somadorVermelho = somadorVermelho - somadorAmarelo;

        return somadorVermelho;
    }

    return 0;
}


int main(){
    int largura, altura;
    char cor;
    int numero_inicial, aux;
    int resultado;
    
    scanf("%d %d %c", &largura, &numero_inicial, &cor);

    altura = (largura / 3) * 2;
    

    int matriz[altura][largura];

    for (int i =  0; i < altura; i++){
        for (int j = 0; j < largura; j++){
            aux = numero_inicial;
            if (j <= (largura / 3) - 1) matriz[i][j] = aux + 1;
            else if (j <= (2 * largura / 3) - 1) matriz[i][j] = aux + 2;
            else if (j <= largura - 1) matriz[i][j] = aux + 3;
            
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    resultado = calcular_aposta(largura, altura, matriz, cor);

    printf("\n");
    printf("%d\n", resultado);

    return 0;
}