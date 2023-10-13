#include <stdio.h>
#include <string.h>

typedef struct{ // Estrutura para armazenar os dados pessoais
    char nome[40];
    int idade;
    char sexo;
} Pessoa;

Pessoa cadastraPessoa(char name[40], int old, char sex){ // Função de estrutura para entrada de dados
    Pessoa cadastro;

        strcpy(cadastro.nome, name);
        cadastro.idade = old;
        cadastro.sexo = sex;

    return cadastro;
}

void inserir(int *qnt, Pessoa pessoas[(*qnt)++], Pessoa pessoa_nova){ // Função que insere a pessoa cadastrada no vetor de pessoas
    pessoas[(*qnt)] = pessoa_nova;
}

void deletaPessoa(int *qnt, Pessoa pessoa[(*qnt)++], Pessoa pessoa_delete){ // Função que altera os dados da pessoa cadastrada caso bata com a desejada para deleção
    for (int i = 0; i < *qnt; i++){
        if (strcmp(pessoa[i].nome, pessoa_delete.nome) == 0 && pessoa[i].idade == pessoa_delete.idade && pessoa[i].sexo == pessoa_delete.sexo){
             for (int j = i; j < *qnt - 1; j++) {
                pessoa[j] = pessoa[j + 1];
            }
            (*qnt)--;
            i--;
        }
    }
}

void imprimePessoas(int contador, Pessoa pessoa[contador]){ // Função que imprime as pessoas cadastradas remanescentes no vetor de pessoas
    for (int i = 0; i < contador; i++){
        if (pessoa[i].sexo == 'M' || pessoa[i].sexo == 'F' || pessoa[i].sexo == N) // Condição estabelecida restringindo ao character atribuido ao dado de sexo da pessoa cadastrada remanescente no vetor
            printf("%s,%d,%c\n", pessoa[i].nome, pessoa[i].idade, pessoa[i].sexo);
    }
}

int main(){
    char opcao;
    int quantidade = 0;

    Pessoa pessoas[100];

    do {
        scanf(" %c\n", &opcao);

        if (opcao == 'i'){
            char name[40];
            int old;
            char sex;
            int len;

            fgets(name, 40, stdin);
            len = strlen(name);
            name[len-1] = '\0';
            scanf("%d %c\n", &old, &sex);

            Pessoa pessoa_nova = cadastraPessoa(name, old, sex);
            inserir(&quantidade, pessoas, pessoa_nova);
            quantidade++;
        }
        else if (opcao == 'd'){
            char namedel[40];
            int olddel;
            char sexdel;
            int len;

            fgets(namedel, 40, stdin);
            len = strlen(namedel);
            namedel[len-1] = '\0';
            scanf("%d %c\n", &olddel, &sexdel);

            Pessoa pessoa_delete = cadastraPessoa(namedel, olddel, sexdel);
            deletaPessoa(&quantidade, pessoas, pessoa_delete);
            quantidade--;
        }
        else if (opcao == 'p'){
            imprimePessoas(quantidade, pessoas);
            break;
        }
    } while (opcao != 'p'); // Loop para inserir a quantidade de pessoas desejada pelo programa

    return 0;
}