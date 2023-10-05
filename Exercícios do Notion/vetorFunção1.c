#include <stdio.h>

int vetorCheck(){
    int numero;
    int i, j, cont;
    static int vetor[10] = {0};

    for(i = 0; i < 10; i++){
        scanf("%d", &numero);
        vetor[i] = numero;
    }
    cont = vetor[0];
    for(j = 0; j < 10; j++){
        if(vetor[j] < cont){
            cont = vetor[j];
        }
    }

    return cont;
}

int main(){
    printf("\nO menor numero eh %d!\n", vetorCheck());

    return 0;
}