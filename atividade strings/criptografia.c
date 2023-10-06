#include <stdio.h>
#include <string.h>

void tamanho_K(char texto[], int vec_chave[], int chave){
    int i=0, aux =0;

    //COLOCAR OS 4 PRIMEIROS NÚMEROS NO VETOR
    //MILHAR
    vec_chave[0]= chave / 1000;
    //CENTENA
    vec_chave[1]= (chave % 1000) / 100;
    //DEZENA
    vec_chave[2]= (chave % 100) / 10;
    //UNIDADE
    vec_chave[3]= (chave % 10);

    //COLOCAR O NUMERO NO RESTO VETOR DE ACORDO COM O TAMANHO DO VETOR TEXTO
    for (i = 4; i < strlen(texto); i++){
        vec_chave[i] = vec_chave[aux];
        aux++;

        if(aux>= 4){
            aux=0;
        }
    }
    
}

int invalido(int vetor[], const char S[], char entrada[], int T){
    int i=0, j=0, control=1, res=0;

    //CASO TENHA LETRAS MINUSCULAS
    for (i = 0; i < T; i++){
        for (j = 0; j < 40; j++){
            if(entrada[i] == S[j]){
                control++;
            }
        }
    }
    if(control < T){
        printf("Caractere invalido na entrada!\n");
        return 0;
    }
    //CASO K TENHA MAIS DE 4 DIGITOS
    if(vetor[0] >= 10){
        printf("Chave invalida!\n");
        return 0;
    }
    else{
        return 1;
    }
    
}

char cifragem(int key[], const char S[], char mensagem[], int tamanho){
    int i=0, j=0, indice=0;
    char C[200]={0};

    for (i = 0; i < tamanho; i++){
        for (j = 0; j < 40; j++){
            if(mensagem[i] == S[j]){
                //CASO A SOMA SEJA MAIOR QUE O INDICE DO VETOR
                if(j + key[i]>=40){
                    indice = j + key[i]- 40;
                }
                //CASO A SOMA ESTEJA DENTRO DOS LIMITES DO VETOR
                else{
                    indice = j + key[i];
                }
                C[i] = S[indice];
            }
        }
    }
    //IMPRIMIR A STRING
    return printf("%s", C);

}

int main(){
    const char S[]=
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};
    int k, K[200]={0}, i=0, tam=0, controle=0;
    char P[200]={0};

    //LER VALOR DE K
    scanf(" %d\n", &k);

    //LER MENSAGEM
    fgets(P, 200, stdin);

    //AJUSTAR O TAMANHO DE K DE ACORDO COM A QUANTIDADE DE CARACTERES DE P
    tamanho_K(P, K, k);

    tam = strlen(P);

    //CHAMAR A FUNÇÃO PARA VER SE A ENTRADA É INVÁLIDA
    controle = invalido(K, S, P, tam);

    if(controle ==1){
        cifragem(K, S, P, tam);
    }

    return 0;
}