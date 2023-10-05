#include <stdio.h>

int main(){
    float hmetros, hpes;
    float pquilos, plibras;

    printf("Digite o valor da sua altura em metros: ");
    scanf("%f", &hmetros);
    printf("\nDigite o valor do seu peso em quilos: ");
    scanf("%f", &pquilos);

    hpes = hmetros * 3.2808;
    plibras = pquilos * 2.2046;

    printf("Resultado\n Altura em pes: %.1f foot\n Peso em libras: %.1flbs", hpes, plibras);


}