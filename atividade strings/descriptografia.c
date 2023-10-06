#include <stdio.h>
#include <string.h>

void decifrar(int key[], char texto[], const char S[]){
    int i=0, j=0, k=0, indice=0;
    char C[200]={0};

    for (i = 0; i < strlen(texto); i++){
        for (j = 0; j < 40; j++){
            if(texto[i]== S[j]){
                if(j- key[i]<0){
                    indice= j- key[i] +40;
                }
                else{
                    indice = j- key[i];
                }
                C[i] = S[indice];
            }
        }
        
    }

    for (k = 0; k < 4; k++){
        printf("%d", key[k]);
    }
    printf("\n");
    
    printf("%s", C);
    
}

void ordem(int ordem, int chave[], char mensagem[], const char S[]){
    int K[200]={0}, i=0, aux=0;

    if(ordem==4){
        K[0] = chave[0];	
		K[1]= chave[1];
	    K[2]=chave[2];
		K[3]=chave[3];
    }
    else if(ordem==1){
        K[0] = chave[3];	
		K[1]= chave[0];
	    K[2]=chave[1];
		K[3]=chave[2];
    }
    else if(ordem==2){
        K[0] = chave[2];	
		K[1]= chave[3];
	    K[2]=chave[0];
		K[3]=chave[1];
    }
    else if(ordem==3){
        K[0] = chave[1];	
		K[1]= chave[2];
	    K[2]=chave[3];
		K[3]=chave[0];
    }
    //COLOCAR O NUMERO NO RESTO VETOR DE ACORDO COM O TAMANHO DO VETOR TEXTO
    for (i = 4; i < strlen(mensagem); i++){
        K[i] = K[aux];
        aux++;

        if(aux>= 4){
            aux=0;
        }
    }

    decifrar(K, mensagem, S);
    
}

void chave(char cripto[], const char S[], int original[]){
    int i=0, j=0, inicio=0, final=8, a=0, k=0, control=0, aux=0, m=0, p=0, tamanho=0, posicao=0;
    int K[8] ={0};
    
    //CALCULO DO TAMANHO DA STRING 
    tamanho = (int)strlen(cripto) -9;

    for (p = 0; p < tamanho; p++){
        //VERIFICAR DE ONDE COMEÇA E TERMINA A CHAVE
        if(posicao ==4){
            posicao =0;
        }
        //CASO AINDA NÃO TENHA ENCONTRADO A CHAVE
        if(m != 1){
            for (i = inicio; i < final; i++){
                for (j = 0; j < 40; j++){
                    //ENCONTRAR A POSIÇÃO DA LETRA CRIPTOGRAFADA NO VETOR S
                    if(cripto[i] == S[j]){
                        a = j;
                    }
                }
                //COLOCAR EM K A DISTANCIA ENTRE O CRIPTOGRAFADO E KP
                K[aux] = a - original[aux];
                //CASO A DISTANCIA SEJA NEGATIVA
                if(a - original[aux] < 0){
                    K[aux] = a-original[aux] +40;
                }
                aux++;
            }
            //ATUALIZAÇÃO PARA O PRÓXIMO LOOP
            aux=0;
            //LOOP PARA VERIFICAR SE A CHAVE ESTÁ CORRETA
            for (k = 0; k < 4; k++){
                if(K[k] == K[k+4]){
                    control++;
                }
            }
            //CASO OS QUATRO PARES DE VALORES SEJAM COMPATÍVEIS PARA PARAR O LOOP INTERNO
            if(control == 4){
                m =1;
            }
            //ATUALIZAÇÃO DO LOOP
            else{
                inicio++;
                final++;
                a=0;
                //RESETAR CONTROLE
                control =0;
            }
        }
        //ATUALIZAÇÃO DA POSIÇÃO
        posicao++;
    }

    if(m != 1){
        printf("Mensagem nao e da Resistencia!");
    }
    else{
        ordem(posicao, K, cripto, S);
    }
    
}

int main(){
    const char S[]=
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};
    const char KP[] =
    {'Q', 'U', 'E', ' ', 'A', ' ', 'F', 'O', '\0'};
    char C[200]={0};
    int kp[9]={0}, i=0, j=0;

    //ENCONTRAR A POSIÇÃO DA LETRA DE KP NO VETOR S
    for (i = 0; i < 8; i++){
        for (j = 0; j < 40; j++){
            if(KP[i] == S[j]){
                kp[i] = j;
            }
        }
    }
    //LER MENSAGEM CIFRADA
    fgets(C, 200, stdin);
    
    //CHAMAR A FUNÇÃO QUE DECIFRA A MENSAGEM CRIPTOGRAFADA
    chave(C, S, kp);

    return 0;
}