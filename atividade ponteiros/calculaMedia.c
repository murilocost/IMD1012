/*
Crie um programa que tenha apenas uma função com assinatura void calcular_media (int *A, int *B), além da principal, que receberá como parâmetros dois ponteiros contendo os endereços de A e B. O programa deverá identificar qual das duas variáveis possui o maior e o menor valor para realizar as seguintes operações:

Após identificado a variável de menor valor, calcular a média dos valores de A e B (média = (A+B) / 2) e armazenar o resultado na variável que contém o menor valor. Por exemplo, caso a variável A seja 2 e a variável B seja 4, a média deverá ser salva na variável A.
Como se trata da divisão de dois inteiros, queremos saber se houve resto dessa divisão. Portanto, o programa deverá armazenar o resto da divisão na variável na variável de maior valor. Por exemplo, caso a média tenha sido armazenada na variável A, o resto deverá ser armazenado na variável B.

Entradas:

Dois números inteiros A e B.

-2

4

Saídas:

imprimir os novos valores de A e B.

A = 1

B = 0
*/




#include <stdio.h>

void calculaMedia(int *A, int *B){
    int media, resto;

    if (*A < *B){
        media = (*A + *B) / 2;
        resto = (*A + *B) % 2;

        *A = media;
        *B = resto;
    } else if (*B < *A){
        media = (*A + *B) / 2;
        resto = (*A + *B) % 2;

        *A = resto;
        *B = media;
    }
}

int main(){
    int a, b; // Variáveis que serão calculadas as mèdias

    scanf("%d %d", &a, &b);

    calculaMedia(&a, &b); // função responsável pelo calculo dá media imposta

    printf("A = %d\n", a);
    printf("B = %d\n", b);


    return 0;
}