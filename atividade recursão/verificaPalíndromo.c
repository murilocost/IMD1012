#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

    // Fazer um programa que identifica se a frase ou a palavra é um palíndromo ou não por meio de recursão

char *limpaString(char *entrada, int tamanho){
    // Remover os espaços vazios na frase e transformalas em um padrão de letras minusculas, para facilitar a análise
    char auxiliar[tamanho];
    char *resultado;
    int contador = 0;

    for (int i = 0; i < tamanho; i++){
        if(entrada[i] == ' ')
            continue;
        else{
            auxiliar[contador] = tolower(entrada[i]);
            contador++;
        }
    }

    resultado = calloc(strlen(auxiliar), sizeof(char));
    strcpy(resultado, auxiliar);

    return resultado;
}

int isPalindromo(char *palavra, int posicao){
    if (posicao <= strlen(palavra)/2){
        if (palavra[posicao] == palavra[strlen(palavra) - (posicao + 1)])
            isPalindromo(palavra, posicao + 1);
        else 
            return 0;
    }
    else
        return 1;
}

int main(){
    int length;
    char linha[100];
    char *string;

    fgets(linha, 100, stdin);

    length = strlen(linha);
    linha[length] = '\0';

    string = calloc(length, sizeof(char));
    strcpy(string, linha);

    char *stringLimpa;

    stringLimpa = calloc(length, sizeof(char));
    
    stringLimpa = limpaString(string, length);

    if(isPalindromo(stringLimpa, 0)){
        printf("O texto \"%s\" é palíndromo", string);
    }
    else{
        printf("O texto \"%s\" não é palíndromo", string);
    }

    free(string);
    string = NULL;
    free(stringLimpa);
    stringLimpa = NULL;

    return 0;
}