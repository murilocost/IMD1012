#include <stdio.h>

    // Fazer uma função recursiva para transformar os números inteiros da entrada em números binários

void binario(int num){
    if (num > 0){
        binario(num / 2);
        printf("%d", num % 2);
    }
    else printf("0");
}

int main(){
    int num;

    scanf("%d", &num);

    binario(num);

    return 0;
}