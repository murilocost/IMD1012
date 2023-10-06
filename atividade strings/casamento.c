#include <stdio.h>
#include <string.h>

   // Tá com mal funcionamento. 
   // Só atende a uma das exigências do LOP.
   // Precisa swr corrigido.

void procuraPadrao(char *texto, char *padrao){
    int i = 0, j = 0, l = 0;
    char teste[strlen(padrao)];

    for (i = 0; i < strlen(texto); i++){
        if(texto[i] == padrao[j]){
            for (int k = i; k < strlen(padrao) + i; k++){
                if(texto[k] == padrao[j]){
                    teste[l] = texto[k];
                    j++;
                    l++;
                    if(l == strlen(padrao)){
                        for(int a = 0; a < strlen(teste); a++){
                            printf("%c ", teste[a]);
                        }
                        printf("sim\n");
                        return printf("Achei o padrão no índice %d\n", i);
                    }
                }
                else{
                    printf("%s não\n", teste);
                    break;
                }
            }
        }
        else printf("%c não\n", texto[i]);
    }
    printf("Não achei padrão\n");
}


int main(){
    char texto[51];
    char padrao[51];

    scanf("%s", texto);
    scanf("%s", padrao);

    procuraPadrao(texto, padrao);
}