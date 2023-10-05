#include <stdio.h>

int main(){
    int num1, num2;
    int i, j, aux, primos;

    scanf("%d %d", &num1, &num2);

    if(num1 > num2){
        aux = num1;
        num1 = num2;
        num2 = aux;
    }

    for(i = num1; i <= num2; i++){
        primos = 0;
        for(j = 2; j < num1; j++){
            if(num1 % j == 0){
                primos++;
            }
        }
        if(primos == 0 && i != 1){
            printf("%d\n", i);
        }

    }
    return 0;
}
