/*
A eleição para representante do seu bairro, que atualmente usam o voto eletrônico, entrou numa discussão sem fim, sobre se a eleição poderia ser burlada ou não. E o grupo do WhatsApp da sua família resolveu parar de dar "Bom dia" e entrou na onda da discussão.

Para aliviar os ânimos, você resolve mostrar como a contagem no computador funciona, deixando seu código aberto para todos verem o que está ocorrendo. Mostre o processo de contagem dos votos de uma eleição escrevendo uma função para computar as duas chapas mais votadas (a eleição do bairro ainda está no 1º turno).

Considerando que há 10 chapas na eleição, identificadas com os números de 1 a 10, e que todos os votos foram válidos (estão no intervalo de 1 a 10), escreva uma função que recebe uma sequência de votos (números de 1 a 10) e computa as duas chapas mais votadas. A assinatura da sua função deve ser:

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted);

Escreva um programa que utilize esta função. Seu programa deve receber como entrada um valor inteiro N seguido de N valores inteiros positivos. Cada valor representando uma chapa da eleição. O programa deve, em seguida, imprimir as chapas mais votadas, sendo a primeira a mais votada.

Obs: É garantido, nos casos de teste, que não haja empates entre os primeiros colocados (sempre haverá um vencedor e um vice). Portanto, tranquilize sua família que isso não é um bug do software :-). É apenas uma característica dos dados tratados.
*/




#include <stdio.h>

void compute_votes(int n, int votes[n], int *segundo, int *primeiro){
    int um, dois, tres, quatro, cinco, seis, sete, oito, nove, dez;

    um = dois = tres = quatro = cinco = seis = sete = oito = nove = dez = 0;

    for (int i = 0; i < n; i++){  // Loop para percorrer os votos e coletar seus dados
        switch (votes[i]){  // Condicional para identificar qual número foi votado
            case 1: um++; break;
            case 2: dois++; break;
            case 3: tres++; break;
            case 4: quatro++; break;
            case 5: cinco++; break;
            case 6: seis++; break;
            case 7: sete++; break;
            case 8: oito++; break;
            case 9: nove++; break;
            case 10: dez++; break;
            default: break;
        }
    }

    // Condicionais para definir o número ganhador e o segundo lugar

    if (um > dois && um > tres && um > quatro && um > cinco && um > seis && um > sete && um > oito && um > nove && um > dez){
        *primeiro = 1;

        if (dois > tres && dois > quatro && dois > cinco && dois > seis && dois > sete && dois > oito && dois > nove && dois > dez) *segundo = 2;
        else if (tres > dois && tres > quatro && tres > cinco && tres > seis && tres > sete && tres > oito && tres > nove && tres > dez) *segundo = 3;
        else if (quatro > dois && quatro > tres && quatro > cinco && quatro > seis && quatro > sete && quatro > oito && quatro > nove && quatro > dez) *segundo = 4;
        else if (cinco > dois && cinco > quatro && cinco > tres && cinco > seis && cinco > sete && cinco > oito && cinco > nove && cinco > dez) *segundo = 5;
        else if (seis > dois && seis > quatro && seis > cinco && seis > tres && seis > sete && seis > oito && seis > nove && seis > dez) *segundo = 6;
        else if (sete > dois && sete > quatro && sete > cinco && sete > seis && sete > tres && sete > oito && sete > nove && sete > dez) *segundo = 7;
        else if (oito > dois && oito > quatro && oito > cinco && oito > seis && oito > sete && oito > tres && oito > nove && oito > dez) *segundo = 8;
        else if (nove > dois && nove > quatro && nove > cinco && nove > seis && nove > sete && nove > oito && nove > tres && nove > dez) *segundo = 9;
        else if (dez > dois && dez > quatro && dez > cinco && dez > seis && dez > sete && dez > oito && dez > nove && dez > tres) *segundo = 10;       
    }
    else if (dois > um && dois > tres && dois > quatro && dois > cinco && dois > seis && dois > sete && dois > oito && dois > nove && dois > dez){
        *primeiro = 2;

        if (um > tres && um > quatro && um > cinco && um > seis && um > sete && um > oito && um > nove && um > dez) *segundo = 1;
        else if (tres > um && tres > quatro && tres > cinco && tres > seis && tres > sete && tres > oito && tres > nove && tres > dez) *segundo = 3;
        else if (quatro > um && quatro > tres && quatro > cinco && quatro > seis && quatro > sete && quatro > oito && quatro > nove && quatro > dez) *segundo = 4;
        else if (cinco > um && cinco > quatro && cinco > tres && cinco > seis && cinco > sete && cinco > oito && cinco > nove && cinco > dez) *segundo = 5;
        else if (seis > um && seis > quatro && seis > cinco && seis > tres && seis > sete && seis > oito && seis > nove && seis > dez) *segundo = 6;
        else if (sete > um && sete > quatro && sete > cinco && sete > seis && sete > tres && sete > oito && sete > nove && sete > dez) *segundo = 7;
        else if (oito > um && oito > quatro && oito > cinco && oito > seis && oito > sete && oito > tres && oito > nove && oito > dez) *segundo = 8;
        else if (nove > um && nove > quatro && nove > cinco && nove > seis && nove > sete && nove > oito && nove > tres && nove > dez) *segundo = 9;
        else if (dez > um && dez > quatro && dez > cinco && dez > seis && dez > sete && dez > oito && dez > nove && dez > tres) *segundo = 10;
    }
    else if (tres > um && tres > dois && tres > quatro && tres > cinco && tres > seis && tres > sete && tres > oito && tres > nove && tres > dez){
        *primeiro = 3;
        if (um > dois && um > quatro && um > cinco && um > seis && um > sete && um > oito && um > nove && um > dez) *segundo = 1;
        else if (dois > um && dois > quatro && dois > cinco && dois > seis && dois > sete && dois > oito && dois > nove && dois > dez) *segundo = 2;
        else if (quatro > um && quatro > dois && quatro > cinco && quatro > seis && quatro > sete && quatro > oito && quatro > nove && quatro > dez) *segundo = 4;
        else if (cinco > um && cinco > quatro && cinco > dois && cinco > seis && cinco > sete && cinco > oito && cinco > nove && cinco > dez) *segundo = 5;
        else if (seis > um && seis > quatro && seis > cinco && seis > dois && seis > sete && seis > oito && seis > nove && seis > dez) *segundo = 6;
        else if (sete > um && sete > quatro && sete > cinco && sete > seis && sete > dois && sete > oito && sete > nove && sete > dez) *segundo = 7;
        else if (oito > um && oito > quatro && oito > cinco && oito > seis && oito > sete && oito > dois && oito > nove && oito > dez) *segundo = 8;
        else if (nove > um && nove > quatro && nove > cinco && nove > seis && nove > sete && nove > oito && nove > dois && nove > dez) *segundo = 9;
        else if (dez > um && dez > quatro && dez > cinco && dez > seis && dez > sete && dez > oito && dez > nove && dez > dois) *segundo = 10;
    }
    else if (quatro > um && quatro > dois && quatro > tres && quatro > cinco && quatro > seis && quatro > sete && quatro > oito && quatro > nove && quatro > dez){
        *primeiro = 4;
        if (dois > tres && dois > um && dois > cinco && dois > seis && dois > sete && dois > oito && dois > nove && dois > dez) *segundo = 2;
        else if (tres > dois && tres > um && tres > cinco && tres > seis && tres > sete && tres > oito && tres > nove && tres > dez) *segundo = 3;
        else if (um > dois && um > tres && um > cinco && um > seis && um > sete && um > oito && um > nove && um > dez) *segundo = 1;
        else if (cinco > dois && cinco > um && cinco > tres && cinco > seis && cinco > sete && cinco > oito && cinco > nove && cinco > dez) *segundo = 5;
        else if (seis > dois && seis > um && seis > cinco && seis > tres && seis > sete && seis > oito && seis > nove && seis > dez) *segundo = 6;
        else if (sete > dois && sete > um && sete > cinco && sete > seis && sete > tres && sete > oito && sete > nove && sete > dez) *segundo = 7;
        else if (oito > dois && oito > um && oito > cinco && oito > seis && oito > sete && oito > tres && oito > nove && oito > dez) *segundo = 8;
        else if (nove > dois && nove > um && nove > cinco && nove > seis && nove > sete && nove > oito && nove > tres && nove > dez) *segundo = 9;
        else if (dez > dois && dez > um && dez > cinco && dez > seis && dez > sete && dez > oito && dez > nove && dez > tres) *segundo = 10;
    }
    else if (cinco > um && cinco > dois && cinco > quatro && cinco > tres && cinco > seis && cinco > sete && cinco > oito && cinco > nove && cinco > dez){
        *primeiro = 5;

        if (dois > tres && dois > quatro && dois > um && dois > seis && dois > sete && dois > oito && dois > nove && dois > dez) *segundo = 2;
        else if (tres > dois && tres > quatro && tres > um && tres > seis && tres > sete && tres > oito && tres > nove && tres > dez) *segundo = 3;
        else if (quatro > dois && quatro > tres && quatro > um && quatro > seis && quatro > sete && quatro > oito && quatro > nove && quatro > dez) *segundo = 4;
        else if (um > dois && um > quatro && um > tres && um > seis && um > sete && um > oito && um > nove && um > dez) *segundo = 1;
        else if (seis > dois && seis > quatro && seis > um && seis > tres && seis > sete && seis > oito && seis > nove && seis > dez) *segundo = 6;
        else if (sete > dois && sete > quatro && sete > um && sete > seis && sete > tres && sete > oito && sete > nove && sete > dez) *segundo = 7;
        else if (oito > dois && oito > quatro && oito > um && oito > seis && oito > sete && oito > tres && oito > nove && oito > dez) *segundo = 8;
        else if (nove > dois && nove > quatro && nove > um && nove > seis && nove > sete && nove > oito && nove > tres && nove > dez) *segundo = 9;
        else if (dez > dois && dez > quatro && dez > um && dez > seis && dez > sete && dez > oito && dez > nove && dez > tres) *segundo = 10;
    }
    else if (seis > um && seis > dois && seis > quatro && seis > cinco && seis > tres && seis > sete && seis > oito && seis > nove && seis > dez){
        *primeiro = 6;

        if (dois > tres && dois > quatro && dois > cinco && dois > um && dois > sete && dois > oito && dois > nove && dois > dez) *segundo = 2;
        else if (tres > dois && tres > quatro && tres > cinco && tres > um && tres > sete && tres > oito && tres > nove && tres > dez) *segundo = 3;
        else if (quatro > dois && quatro > tres && quatro > cinco && quatro > um && quatro > sete && quatro > oito && quatro > nove && quatro > dez) *segundo = 4;
        else if (cinco > dois && cinco > quatro && cinco > tres && cinco > um && cinco > sete && cinco > oito && cinco > nove && cinco > dez) *segundo = 5;
        else if (um > dois && um > quatro && um > cinco && um > tres && um > sete && um > oito && um > nove && um > dez) *segundo = 1;
        else if (sete > dois && sete > quatro && sete > cinco && sete > um && sete > tres && sete > oito && sete > nove && sete > dez) *segundo = 7;
        else if (oito > dois && oito > quatro && oito > cinco && oito > um && oito > sete && oito > tres && oito > nove && oito > dez) *segundo = 8;
        else if (nove > dois && nove > quatro && nove > cinco && nove > um && nove > sete && nove > oito && nove > tres && nove > dez) *segundo = 9;
        else if (dez > dois && dez > quatro && dez > cinco && dez > um && dez > sete && dez > oito && dez > nove && dez > tres) *segundo = 10;
    }
    else if (sete > um && sete > dois && sete > quatro && sete > cinco && sete > seis && sete > tres && sete > oito && sete > nove && sete > dez){
        *primeiro = 7;

        if (dois > tres && dois > quatro && dois > cinco && dois > seis && dois > um && dois > oito && dois > nove && dois > dez) *segundo = 2;
        else if (tres > dois && tres > quatro && tres > cinco && tres > seis && tres > um && tres > oito && tres > nove && tres > dez) *segundo = 3;
        else if (quatro > dois && quatro > tres && quatro > cinco && quatro > seis && quatro > um && quatro > oito && quatro > nove && quatro > dez) *segundo = 4;
        else if (cinco > dois && cinco > quatro && cinco > tres && cinco > seis && cinco > um && cinco > oito && cinco > nove && cinco > dez) *segundo = 5;
        else if (seis > dois && seis > quatro && seis > cinco && seis > tres && seis > um && seis > oito && seis > nove && seis > dez) *segundo = 6;
        else if (um > dois && um > quatro && um > cinco && um > seis && um > tres && um > oito && um > nove && um > dez) *segundo = 1;
        else if (oito > dois && oito > quatro && oito > cinco && oito > seis && oito > um && oito > tres && oito > nove && oito > dez) *segundo = 8;
        else if (nove > dois && nove > quatro && nove > cinco && nove > seis && nove > um && nove > oito && nove > tres && nove > dez) *segundo = 9;
        else if (dez > dois && dez > quatro && dez > cinco && dez > seis && dez > um && dez > oito && dez > nove && dez > tres) *segundo = 10;
    }
    else if (oito > dois && oito > quatro && oito > cinco && oito > seis && oito > sete && oito > tres && oito > nove && oito > dez){
        *primeiro = 8;
        if (dois > tres && dois > quatro && dois > cinco && dois > seis && dois > sete && dois > um && dois > nove && dois > dez) *segundo = 2;
        else if (tres > dois && tres > quatro && tres > cinco && tres > seis && tres > sete && tres > um && tres > nove && tres > dez) *segundo = 3;
        else if (quatro > dois && quatro > tres && quatro > cinco && quatro > seis && quatro > sete && quatro > um && quatro > nove && quatro > dez) *segundo = 4;
        else if (cinco > dois && cinco > quatro && cinco > tres && cinco > seis && cinco > sete && cinco > um && cinco > nove && cinco > dez) *segundo = 5;
        else if (seis > dois && seis > quatro && seis > cinco && seis > tres && seis > sete && seis > um && seis > nove && seis > dez) *segundo = 6;
        else if (sete > dois && sete > quatro && sete > cinco && sete > seis && sete > tres && sete > um && sete > nove && sete > dez) *segundo = 7;
        else if (um > dois && um > quatro && um > cinco && um > seis && um > sete && um > tres && um > nove && um > dez) *segundo = 1;
        else if (nove > dois && nove > quatro && nove > cinco && nove > seis && nove > sete && nove > um && nove > tres && nove > dez) *segundo = 9;
        else if (dez > dois && dez > quatro && dez > cinco && dez > seis && dez > sete && dez > um && dez > nove && dez > tres) *segundo = 10; 

    }
    else if (nove > um && nove > dois && nove > quatro && nove > cinco && nove > seis && nove > sete && nove > oito && nove > tres && nove > dez){
        *primeiro = 9;

        if (dois > tres && dois > quatro && dois > cinco && dois > seis && dois > sete && dois > oito && dois > um && dois > dez) *segundo = 2;
        else if (tres > dois && tres > quatro && tres > cinco && tres > seis && tres > sete && tres > oito && tres > um && tres > dez) *segundo = 3;
        else if (quatro > dois && quatro > tres && quatro > cinco && quatro > seis && quatro > sete && quatro > oito && quatro > um && quatro > dez) *segundo = 4;
        else if (cinco > dois && cinco > quatro && cinco > tres && cinco > seis && cinco > sete && cinco > oito && cinco > um && cinco > dez) *segundo = 5;
        else if (seis > dois && seis > quatro && seis > cinco && seis > tres && seis > sete && seis > oito && seis > um && seis > dez) *segundo = 6;
        else if (sete > dois && sete > quatro && sete > cinco && sete > seis && sete > tres && sete > oito && sete > um && sete > dez) *segundo = 7;
        else if (oito > dois && oito > quatro && oito > cinco && oito > seis && oito > sete && oito > tres && oito > um && oito > dez) *segundo = 8;
        else if (um > dois && um > quatro && um > cinco && um > seis && um > sete && um > oito && um > tres && um > dez) *segundo = 1;
        else if (dez > dois && dez > quatro && dez > cinco && dez > seis && dez > sete && dez > oito && dez > um && dez > tres) *segundo = 10;

    }
    else if (dez > um && dez > dois && dez > quatro && dez > cinco && dez > seis && dez > sete && dez > oito && dez > nove && dez > tres){
        *primeiro = 10;
        if (dois > tres && dois > quatro && dois > cinco && dois > seis && dois > sete && dois > oito && dois > nove && dois > um) *segundo = 2;
        else if (tres > dois && tres > quatro && tres > cinco && tres > seis && tres > sete && tres > oito && tres > nove && tres > um) *segundo = 3;
        else if (quatro > dois && quatro > tres && quatro > cinco && quatro > seis && quatro > sete && quatro > oito && quatro > nove && quatro > um) *segundo = 4;
        else if (cinco > dois && cinco > quatro && cinco > tres && cinco > seis && cinco > sete && cinco > oito && cinco > nove && cinco > um) *segundo = 5;
        else if (seis > dois && seis > quatro && seis > cinco && seis > tres && seis > sete && seis > oito && seis > nove && seis > um) *segundo = 6;
        else if (sete > dois && sete > quatro && sete > cinco && sete > seis && sete > tres && sete > oito && sete > nove && sete > um) *segundo = 7;
        else if (oito > dois && oito > quatro && oito > cinco && oito > seis && oito > sete && oito > tres && oito > nove && oito > um) *segundo = 8;
        else if (nove > dois && nove > quatro && nove > cinco && nove > seis && nove > sete && nove > oito && nove > tres && nove > um) *segundo = 9;
        else if (um > dois && um > quatro && um > cinco && um > seis && um > sete && um > oito && um > nove && um > tres) *segundo = 1;

    }

}

int main(){
    int quantidade; // Tamanho desejado do vetor
    int ganhador, vice;
    
    scanf("%d", &quantidade);  // Número de votos que irão ser inseridos

    int votos[quantidade]; // Vetor criado com o tamanho para quantidade de votos desejados

    for (int i = 0; i < quantidade; i++){  // Loop para inserir os votos no array a ser computado
        scanf("%d", &votos[i]);
    }

    compute_votes(quantidade, votos, &vice, &ganhador);  // Função que computa os votos e define as variáveis ganhador e vice pela referência do endereço de memoria

    printf("Ganhador => %d\nVice => %d", ganhador, vice);  // Impressão do número vencedor e o seu vice

    return 0;
}