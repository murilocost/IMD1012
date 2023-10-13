#include <stdio.h>
#include <string.h>

// Definição do tipo estruturado Time
struct Time {
    char nome[100];
    int gols_marcados;
    int gols_sofridos;
};

// Função para trocar dois elementos do tipo Time
void trocar(struct Time *a, struct Time *b) {
    struct Time temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;

    // Entrada do número n de times 
    scanf("%d", &n);

    // Aloca um vetor de times com tamanho n
    struct Time times[n];

    // Lê as informações dos times
    for (int i = 0; i < n; i++) {
        scanf(" %99[^\n]", times[i].nome);
        while ((getchar()) != '\n');
        scanf("%d", &times[i].gols_marcados);
        scanf("%d", &times[i].gols_sofridos);
    }

    // Implementação do Bubble Sort para ordenar por gols marcados (decrescente)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (times[j].gols_marcados < times[j + 1].gols_marcados) {
                trocar(&times[j], &times[j + 1]);
            }
        }
    }

    // Exibe as informações dos times ordenados
    for (int i = 0; i < n; i++) {
        printf("%d - %s\n Gols marcados: %d\nGols sofridos: %d\n", times[i].nome, times[i].gols_marcados, times[i].gols_sofridos);
    }

    return 0;
}