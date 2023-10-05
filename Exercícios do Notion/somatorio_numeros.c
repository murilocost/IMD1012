#include <stdio.h>

// O programa vai ler números, e caso o número lido for inteiro não positivo, ele informará a somatória dos número lidos anteriormente.

int main(){
    int numero, somatoria;
    somatoria = 0;

    printf("||Digite qualquer numero que venha a sua mente, contudo, precisa ser inteiro positivo. Caso seja menor ou igual a zero, o programa informara a somatoria dos numeros digitados antes||\n");

    scanf("%d", &numero);

    while(numero > 0){
        somatoria += numero;

        scanf("%d", &numero);

    }

    printf("A somatoria dos numeros lidos eh exatamente: %d\n", somatoria);

    return 0;
}