#include <stdio.h>

int main(){
    double temperatura;
    char escala;

    printf("Digite o numero em que a temperatura atual se encontra: ");
    scanf("%lf", &temperatura);

    printf("Digite agora em qual escala essa temperatura se encontra (C, F ou K): ");
    scanf("%s", &escala);

    double tempC, tempF, tempK;

    switch (escala){
        case 'C':
                tempC = temperatura;
                tempF = (temperatura * 1.8) + 32;
                tempK = temperatura + 273;
                break;
        case 'F':
                tempF = temperatura;
                tempC = (temperatura - 32) / 1.8;
                tempK = ((temperatura - 32)/1.8) + 273;
                break;
        case 'K':
                tempK = temperatura;
                tempC = temperatura - 273;
                tempF = ((temperatura - 273) * 1.8) + 32;
                break;
        default:
                printf("Opcao invalida de escala.");
                break;
    }

    printf("Temperatura em Celcius: %.2lf\n", tempC);
    printf("Temperatura em Farenheit: %.2lf\n", tempF);
    printf("Temperatura em Kelvin: %.2lf\n", tempK);

    return 0;
}