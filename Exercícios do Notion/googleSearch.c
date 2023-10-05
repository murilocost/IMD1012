#include <stdio.h>

#define NTXT 100
#define TAMTXT 101

void fechamento_base(int posicao, char base[][TAMTXT]){
    int tamanho;

    fgets(base[posicao], TAMTXT, stdin);

    tamanho = strlen(base[posicao]);

    base[posicao][tamanho - 1] = '\0';
}

void sugestoes(char* str, int tamanho, char base[][TAMTXT]){
    int tam_sugestao, sugestoes = 0;

    for (int i  = 0; i < tamanho; i++){
        int sugerir = 1;

        int tam_atual = strlen(base[i]);
        tam_sugestao = strlen(str);

        if(tam_atual < tam_sugestao) continue;

        for (int j = 0; j < tam_sugestao; j++){
            if(str[j] != base[i][j]){
                sugerir = 0;
                break;
            }
        }

        if(sugerir){
            printf("Você quis dizer %s?\n", base[i]);
            sugestoes++;
        }

        if(sugestoes == 0) printf("Sem recomendações.\n");

    }
}

int main(){
    char consultas[NTXT][TAMTXT] = {0};
    char string[TAMTXT];
    int inicial, novas;

    scanf("%d\n", &inicial);

    for (int i = 0; i < inicial; i++){
        fechamento_base(i, consultas);
    }

    scanf("%d\n", &novas);

    for (int i = 0; i < novas; i++){
        fgets(string, TAMTXT, stdin);

        sugestoes(string, inicial, consultas);
    }

    return 0;
}