/*
Crie um registro com as informações de uma chapa. O registro deve conter três campos: um número inteiro com o identificador da chapa, uma string para o nome da chapa e, por fim, um inteiro para a quantidade de votos da chapa.

Escreva então, uma função para computar as duas chapas mais votadas (a eleição do bairro ainda está no 1º turno). Sua função deve receber como parâmetro uma sequência (array) com os votos de uma urna (valores inteiros) e um array com os dados das chapas (registro criado anteriormente). Sua função deverá alterar os dados dos registros no array e indicar (referenciar) os dois mais votados, bem como retornar a quantidade de votos válidos, ou seja a quantidade de identificadores pertecentes a uma das chapas.

Assim, a assinatura da sua função deve ser:

int compute_votes(
  int num_votes, int votes[num_votes],
  int num_parties, Party parties[num_parties],
  Party *most_voted, Party *second_most_voted
);

Escreva um programa que utilize esta função. Seu programa deve receber inicialmente um valor N, com a quantidade de chapas, seguido de N linhas. Cada linha contém um valor inteiro, com o identificador da chapa, e uma string (sem espaços em branco) com o nome da chapa. Depois, o programa receberá um valor M, com a quantidade de votos, seguido de M valores inteiros positivos. Cada valor representando uma chapa da eleição. O programa deve, em seguida, imprimir a quantidade de votos que cada chapa obteve, a quantidade de votos válidos e os dados referentes às duas chapas mais votadas.

​Obs: É garantido, nos casos de teste, que não haja empates entre os primeiros colocados (sempre haverá um vencedor e um vice). Portanto, tranquilize sua família que isso não é um bug do software :-). É apenas uma característica dos dados tratados.
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char *nome;
    int numVotos;
} Chapa;

Chapa cadastraChapa(){
    char name[101];
    Chapa cadastro;

    scanf("%d %s\n", &cadastro.id, name);
    cadastro.nome = calloc(strlen(name), sizeof(char));
    strcpy(cadastro.nome, name);
    cadastro.numVotos = 0;

    return cadastro;
}

int compute_votes(int num_votes, int votes[num_votes], int nChapas, Chapa chapa[nChapas], Chapa *most_voted, Chapa *second_most_voted){
    int valido = 0;
    int totalValidos = 0;

    // Contagem dos votos
    for (int i = 0; i < num_votes; i++){
        for (int j = 0; j < nChapas; j++){
            if (votes[i] == chapa[j].id){
                valido = 1;
                chapa[j].numVotos++;
            }
        }
        if (valido){
            totalValidos++;
            valido = 0;
        }
    }

    // Computando o vencedor e o vice
    int aux1 = 0;
    int aux2 = 0;

    for (int i = 0; i < nChapas; i++){
        if (chapa[i].numVotos > aux1){
            *second_most_voted = *most_voted;
            *most_voted = chapa[i];
            aux2 = aux1;
            aux1 = chapa[i].numVotos;
        }
        else if (chapa[i].numVotos > aux2){
            *second_most_voted = chapa[i];
            aux2 = chapa[i].numVotos;
        }
    }

    return totalValidos;
}

int main(){
    int numChapas;

    scanf("%d\n", &numChapas);

    Chapa chapas[numChapas];

    for (int i = 0; i < numChapas; i++){
        chapas[i] = cadastraChapa();
    }

    int numVotos;

    scanf("%d\n", &numVotos);

    int votos[numVotos];

    for (int i = 0; i < numVotos; i++){
        scanf("%d ", &votos[i]);
    }

    Chapa *vencedora, *vice;
    double porcentagem;
    int validos;

    vencedora = calloc(1, sizeof(Chapa));
    vice = calloc(1, sizeof(Chapa));

    validos = compute_votes(numVotos, votos, numChapas, chapas, vencedora, vice);

    // Impressão do resultado

    porcentagem = vencedora->numVotos * 100.00 / validos;

    printf("VENCEDOR: %s (%d votos = %.2lf%%)\n", vencedora->nome, vencedora->numVotos, porcentagem);

    porcentagem = vice->numVotos * 100.00 / validos;

    printf("VICE: %s (%d votos = %.2lf%%)\n", vice->nome, vice->numVotos, porcentagem);

    return 0;
}