#include <stdio.h>

int main(){
    int n;

    scanf("%d", &n);

    float alunos_medias[n][2];

    for(int i = 0; i < n; i++){
        scanf("%f", &alunos_medias[i][0]);
        scanf("%f", &alunos_medias[i][1]);
    }

    float aprovados[n][2], recuperacao[n][2], reprovados[n][2];
    int num_apro = 0, num_rec = 0, num_reprov = 0;


    for(int i = 0; i < n; i++){
        float numero = alunos_medias[i][0];
        float media = alunos_medias[i][1];

        if(media >= 7.0){
            aprovados[num_apro][0] = numero;
            aprovados[num_apro][1] = media;
            num_apro++;
        }
        else if(media >= 5.0){
            recuperacao[num_rec][0] = numero;
            recuperacao[num_rec][1] = media;
            num_rec++;
        }
        else{
            reprovados[num_reprov][0] = numero;
            reprovados[num_reprov][1] = media;
            num_reprov++;
        }
    }


    printf("Aprovados: ");
    for(int i = 0; i < num_apro; i++){
        if(i == num_apro - 1) printf("%.0f (%.1f)", aprovados[i][0], aprovados[i][1]);
        else printf("%.0f (%.1f), ", aprovados[i][0], aprovados[i][1]);
    }

    printf("\n");

    printf("Recuperação: ");
    for(int i = 0; i < num_rec; i++){
        if(i == num_rec - 1) printf("%.0f (%.1f)", recuperacao[i][0], recuperacao[i][1]);
        else printf("%.0f (%.1f), ", recuperacao[i][0], recuperacao[i][1]);    }

    printf("\n");

    printf("Reprovados: ");
    for(int i = 0; i < num_reprov; i++){
        if(i == num_reprov - 1) printf("%.0f (%.1f)", reprovados[i][0], reprovados[i][1]);
        else printf("%.0f (%.1f), ", reprovados[i][0], reprovados[i][1]);
    }

    printf("\n");

    return 0;
}