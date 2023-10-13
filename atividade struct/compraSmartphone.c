#include <stdio.h>
#include <string.h>

typedef struct {
    char modelo[40];
    int memoria;
    float processador;
    float camera;
    float bateria;
} Smartphone;

int cadastraSmartphone (int qnt_cadastrada, Smartphone celular[qnt_cadastrada]){
    int len;

    scanf(" %[^\n]", celular[qnt_cadastrada].modelo);

    //fgets(celular[qnt_cadastrada].modelo, 40, stdin);
    //len = strlen(celular[qnt_cadastrada].modelo);
    //celular[qnt_cadastrada].modelo[len-1] = '\0';

    scanf("%d\n%f\n%f\n%f\n", &celular[qnt_cadastrada].memoria, &celular[qnt_cadastrada].processador,&celular[qnt_cadastrada].camera, &celular[qnt_cadastrada].bateria);

    return qnt_cadastrada + 1;
}


int pesquisaSmartphone (int qnt_cadastrada, Smartphone celular[qnt_cadastrada], Smartphone reqMin){
    int encontrados = 0;

    for (int i = 0; i < qnt_cadastrada; i++){
        if (celular[i].memoria >= reqMin.memoria && celular[i].processador >= reqMin.processador && celular[i].camera >= reqMin.camera && celular[i].bateria >= reqMin.bateria){
            encontrados++;
            printf("Modelo: %s\n", celular[i].modelo);
            printf("Memoria: %dGB\n", celular[i].memoria);
            printf("Processador: %.2fGhz\n", celular[i].processador);
            printf("Camera: %.2fMPixels\n", celular[i].camera);
            printf("Bateria: %.2fmA\n", celular[i].bateria);    
            printf("\n");
        }
    }

    return encontrados;
}

int main(){
    char controle;
    int quantia = 0;

    Smartphone celulares[100];

    scanf(" %c", &controle);
    while (controle == 's' || controle != 'n') {
    
        quantia = cadastraSmartphone(quantia, celulares);
        scanf(" %c", &controle);
    }
 
    Smartphone reqMin;

    scanf("%d\n%f\n%f\n%f\n", &reqMin.memoria, &reqMin.processador, &reqMin.camera, &reqMin.bateria);

    int encontrados;
    
    encontrados = pesquisaSmartphone(quantia, celulares, reqMin);


    printf("%d smartphones encontrados.\n", encontrados);


    return 0;
}