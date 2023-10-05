#include <stdio.h>

int main(){
    int vidro, plastico, papel, organicos, metal, eletronicos;
    char coleta;
    int i;

    vidro = 0;
    plastico = 0;
    papel = 0;
    organicos = 0;
    metal = 0;
    eletronicos = 0;

    printf("Digite os dados da coleta abaixo (Maximo permitido: 10 itens). Vidro (V); Plastico (L); Papel (P); Organicos (O); Metal (M); Eletronicos (E)\n");
    

    for(i = 0; i < 10; i++ ){
        scanf("%c", &coleta);

        switch (coleta)
        {
        case 'V': vidro++; break;
        case 'L': plastico++; break;
        case 'P': papel++; break;
        case 'O': organicos++; break;
        case 'M': metal++; break;
        case 'E': eletronicos++; break;
        }
    }

    printf("Resultado da coleta:\n");
    printf("Vidro: %d\n", vidro);
    printf("Plastico: %d\n", plastico);
    printf("Papel: %d\n", papel);
    printf("Organico: %d\n", organicos);
    printf("Metal: %d\n", metal);
    printf("Eletronico: %d\n",eletronicos);

    return 0;
}