#include <stdio.h>

int main(){
    int a, b, resultado;
    char operacao;

    printf("Digite da seguinte forma na calculadora: (Numero) [Operacao (+ || - || / || *)] (Numero)\n");

    do{
        scanf("%d %c %d", &a, &operacao, &b);
        if (operacao == '+')
        {
            resultado = a + b;
            printf("%d\n", resultado);
        }
        else if (operacao == '-')
        {
            resultado = a - b;
            printf("%d\n", resultado);
        }
        else if (operacao == '*')
        {
            resultado = a * b;
            printf("%d\n", resultado);
        }
        else if (operacao == '/')
        {
            if(b == 0){
                printf("Error!\n");
            }
            else{
            resultado = a / b;
            printf("%d\n", resultado);
            }
        }
    }while (operacao != 'F');

    printf("Calculadora encerrada.\n");

    return 0;
}