#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
} String;

int main(){
    int aux;
    int num;
    int cont =1;
    String *str;
    char controle[7];

    strcpy(controle, "acabou");

    str = calloc(1, sizeof(String));

    do{
        scanf(" %[^\n]", str[cont - 1].nome);
        aux = strncmp(controle, str[cont - 1].nome, 6);
        cont++;
        str = realloc(str, sizeof(String) * cont);
    } while (aux != 0);

    cont--;
    str = realloc(str, sizeof(String) * cont);

    scanf("%d", &num);
    srand(num);

    int vetor[cont - 1], k = 0, l = 0;

    for (int i = 0; i < cont - 1; i++){
        vetor[i] = 99;
    }

    while (k != cont - 1){
        int j = 0;
        int indice = rand()%(cont - 1);

        if (indice < cont - 1){
            for (int i = 0; i <= l; i++){
                if (indice == vetor[i]) j = 1;
            }
            if (j == 0){
                printf("%s\n", str[indice].nome);
                vetor[l] = indice;
                l++;
                k++;
            } 
        }
    }

    return 0;
}