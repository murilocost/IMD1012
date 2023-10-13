#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[201];
    int vitorias;
    int empates;
    int derrotas;
    int gols_feitos;
    int gols_sofridos;
} Time;

Time cadastraTime(char entrada[210]){
    Time aux;

    fgets(entrada, 210, stdin);
    strcpy(aux.nome, strtok(entrada, ";"));
    sscanf(strtok(NULL, "/n"), "%d %d %d %d %d", &aux.vitorias, &aux.empates, &aux.derrotas, &aux.gols_feitos, &aux.gols_sofridos);

    return aux;
}

void organizaTabela(int quantidade, Time time[quantidade]){
    Time aux;
    int pontosA, pontosB;
    int saldoA, saldoB;

    for (int i = 0; i < quantidade; i++){
        for (int j = 1; j < quantidade; j++){
            pontosA = time[j - 1].vitorias * 3 + time[j - 1].empates;
            pontosB = time[j].vitorias * 3 + time[j].empates;
            saldoA = time[j - 1].gols_feitos - time[j - 1].gols_sofridos;
            saldoB = time[j].gols_feitos - time[j].gols_sofridos;

            if (pontosA < pontosB){
                aux = time[j - 1];
                time[j - 1] = time[j];
                time[j] = aux;
            }
            else if (pontosA == pontosB && time[j - 1].vitorias < time[j].vitorias){
                aux = time[j - 1];
                time[j - 1] = time[j];
                time[j] = aux;
            }
            else if (pontosA == pontosB && time[j - 1].vitorias == time[j].vitorias && saldoA < saldoB){
                aux = time[j - 1];
                time[j - 1] = time[j];
                time[j] = aux;
            }
        }
    }
}

void imprimirTabela(int quantia, Time time[quantia]){
    int pontos, jogos, saldoGols;

    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");
    
    for (int i = 0; i < quantia; i++){
        pontos = time[i].vitorias * 3 + time[i].empates;
        jogos = time[i].vitorias + time[i].empates + time[i].derrotas;
        saldoGols = time[i].gols_feitos - time[i].gols_sofridos;

        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d\n", time[i].nome, pontos, jogos, time[i].vitorias, time[i].empates, time[i].derrotas, time[i].gols_feitos, time[i].gols_sofridos, saldoGols);
    }
}

void imprimeLibertadores(int quantia, Time time[quantia]){

    printf("Times na zona da libertadores:\n");

    for (int i = 0; i < 6; i++){
        printf("%s\n", time[i].nome);
    }
}

void imprimeRebaixados(int quantia, Time time[quantia]){
    printf("Times rebaixados:\n");

    for (int i = quantia - 1; i > quantia - 5; i--){
        printf("%s\n", time[i].nome);
    }
}

int main(){
    int contador;

    scanf("%d\n", &contador);

    Time times[contador];
    char entrada[210];

    for (int i = 0; i < contador; i++){
        times[i] = cadastraTime(entrada);
    }

    organizaTabela(contador, times);

    imprimirTabela(contador, times);
    printf("\n");
    imprimeLibertadores(contador, times);
    printf("\n");
    imprimeRebaixados(contador, times);

    return 0;
}