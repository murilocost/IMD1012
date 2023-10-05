#include <stdio.h>

int main(){

    char tubaroes[14][64] = {"Tubarao Branco", "Tubarao Martelo", "Tubarao Touro", "Tubarao Baleia", "Tubarao Lixa", "Tubarao Frade", "Tubarao Tigre", "Tubarao Cabeca-Chata", "Tubarao Serra", "Tubarao de Pontas Negras", "Tubarao Raposa", "Tubarao Mako", "Tubarao Bruxa", "Tubarao Azul"};
    int contador[14]={0};
    int i, j, numero;
    int especieDiferentes, tipoTubarao;

    especieDiferentes =0;

    printf("1 - Tubarao Branco\n");
    printf("2 - Tubarao Martelo\n");
    printf("3 - Tubarao Touro\n");
    printf("4 - Tubarao Baleia\n");
    printf("5 - Tubarao Lixa\n");
    printf("6 - Tubarao Frade\n");
    printf("7 - Tubarao Tigre\n");
    printf("8 - Tubarao Cabeca-Chata\n");
    printf("9 - Tubaraao Serra\n");
    printf("10 - Tubarao de Pontas Negras\n");
    printf("11 - Tubarao Raposa\n");
    printf("12 - Tubarao Mako\n");
    printf("13 - Tubarao Bruxa\n");
    printf("14 - Tubarao Azul\n");

    scanf("%d", &numero);

    for(i = 0; i < numero; i++){
        scanf("%d", &tipoTubarao);
        tipoTubarao--;
        if(contador[tipoTubarao] == 0){
            contador[tipoTubarao] = 1;
            especieDiferentes++;
        };
    };

    printf("%d especies diferentes!\n", especieDiferentes);

    for(j = 0; j < 14; j++){
        if(contador[j] != 0){
            printf(tubaroes[j]);
            printf("\n");
        }
    }
    return 0;
}