/*
Uma categoria de jogos muito popular são os jogos de estratégia e simulação. Desde simulações esportivas a simuladores de cidades, o jogador precisa balancear a gestão de recursos para ter sucesso. Um jogo que trouxe uma inovação nesse gênero foi o The Sims: ao invés de gerenciar uma cidade ou um time, o jogador passa a gerenciar uma pessoa e suas necessidades básicas do dia à dia: alimentação, sono, estudo, diversão… A gestão de recursos tem como objetivo deixar o personagem feliz e pronto para alcançar seus objetivos: um novo emprego, construir uma família, comprar uma nova casa, etc…

Mesmo sendo uma franquia de sucesso, a Electronic Arts ainda quer testar e balancear o jogo. E até um programador iniciante pode ajudar!

Você vai escrever um programa que testa apenas uma parte da funcionalidade do sistema: o processamento de ações do jogo. O seu programa irá ler um conjunto de informações no seguinte formato:

- Uma linha com 5 valores inteiros representando os atributos do Sim. Os cinco atributos são:

Fome: o quanto o Sim precisa comer;
Sede: o quanto o Sim precisa beber água;
Banheiro: o quanto o Sim precisa ir ao banheiro;
Sono: o quanto o Sim precisa dormir;
Tédio: o quanto o Sim precisa de diversão.
    Cada um desses atributos é representado por um valor inteiro que vai de 0 a 100. 0 é o menor valor possível, e causa o Game Over do jogo. Ao longo do jogo, os valores não podem passar dessa faixa.

- Uma linha com um valor inteiro X, indicando quantas ações serão enviadas para a simulação. As ações causam mudanças nos atributos listados acima, da seguinte forma:

comer: ação que aumenta o atributo Fome em 30 e reduz o atributo Banheiro em 15;
beber: ação que aumenta o atributo Sede em 30 e reduz o atributo Banheiro em 20;
dormir: ação que aumenta Sono em 80, aumenta Tédio em 30 e reduz o restante dos atributos em 30;
se aliviar: ação que aumenta o banheiro em 100;
jogar videogame: aumenta Tédio em 80 e reduz o restante em 20.
- X linhas, cada uma contendo um comando em string, indicando a ação a ser simulada, da mesma forma como descritos na lista acima.

Um exemplo de entrada para esse programa seria:

100 100 100 100 100 

5

comer

beber

dormir

jogar videogame

comer

Para cada ação simulada, o programa fará a atualização dos atributos de acordo com o previsto. Além disso, como cada ação gasta um tempo, os atributos que não forem diretamente afetados pela ação diminuem em 5 a cada ação simulada.

O seu programa executará as simulações, e a cada ação realiza a atualização dos atributos. Caso algum dos atributos fique com um valor maior que zero e menor igual a 15, você deve emitir uma mensagem de alerta no seguinte formato:

“Alerta: ATRIBUTO está com valor baixo”, onde ATRIBUTO é o nome de um dos cinco atributos listados acima.

No caso de algum dos atributos chegar ao valor 0, o seu programa deve informar o Game Over e encerrar a simulação. Para cada atributo existe uma mensagem específica, de acordo com os modelos abaixo:

Fome: “Game Over! Morreu de fome”
Sede: “Game Over! Morreu de sede”
Banheiro: “Game Over! Morreu apertado…”
Sono: “Game Over! Morreu dormindo…”
Tédio: “Game Over! Morreu deprimido…”
Para o exemplo de entrada anterior, o seu programa geraria a seguinte saída:

Alerta: banheiro está com valor baixo

Game Over! Morreu apertado...

Status final:

Fome: 75

Sede: 45

Banheiro: 0

Sono: 75

Tédio: 95

A equipe da Electronic Arts já desenvolveu a parte inicial do código para você, a qual você não pode alterar por questões autorais da empresa. No código inicial, parte da leitura da entrada já é realizada (os atributos iniciais e a quantidade de ações). Você precisará completar a programação desenvolvendo duas funções:

- simula_sims: uma função que recebe os cinco atributos do Sim, lê um comando da entrada padrão, executa a simulação do comando e retorna o valor de 1 caso o Sim esteja vivo ou 0 caso ele esteja morto. Essa função também é responsável por realizar as impressões do programa.

- imprime_relatorio: uma função que imprime o status final do Sim, com os valores de cada atributo.

Observe atentamente os exemplos de entrada e saída para observar a formatação desejada para a impressão.

O código abaixo é o ponto inicial da sua implementação. Observe atentamente o uso das funções simula_sims e imprime_relatorio na função main, para fazer as assinaturas das funções corretamente.

int main(){
    int fome, sede, banheiro, sono, tedio;
    int acoes;
    scanf("%d %d %d %d %d", &fome, &sede, &banheiro, &sono, &tedio);
    scanf("%d", &acoes);
    for(int i = 0; i<acoes; i++){
        int ret = simula_sims(&fome, &sede, &banheiro, &sono, &tedio);
        if(ret == 0) break;
    }
    imprime_relatorio(fome, sede, banheiro, sono, tedio);
    return 0;
}
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void atualiza_status(int *fome, int *sede, int *banheiro, int *sono, int *tedio, int upfome, int upsede, int upbanheiro, int upsono, int uptedio);
int simula_sims(int *fome, int *sede, int *banheiro, int *sono, int *tedio);
int testa_fim(int *fome, int *sede, int *banheiro, int *sono, int *tedio);
void limita_atributos(int *fome, int *sede, int *banheiro, int *sono, int *tedio);
void imprime_relatorio(int fome, int sede, int banheiro, int sono, int tedio);

int main(){
    int fome, sede, banheiro, sono, tedio;
    int acoes;
    
    scanf("%d %d %d %d %d", &fome, &sede, &banheiro, &sono, &tedio);
    scanf("%d", &acoes);
    
    for(int i = 0; i < acoes; i++){
        int ret = simula_sims(&fome, &sede, &banheiro, &sono, &tedio);
        if(ret == 0) break;
    }
    
    imprime_relatorio(fome, sede, banheiro, sono, tedio);
    return 0;
}

void atualiza_status(int *fome, int *sede, int *banheiro, int *sono, int *tedio, int upfome, int upsede, int upbanheiro, int upsono, int uptedio){
    *fome += upfome;
    *sede += upsede;
    *banheiro += upbanheiro;
    *sono += upsono;
    *tedio += uptedio;
}

int simula_sims(int *fome, int *sede, int *banheiro, int *sono, int *tedio){
    char comando[30];
    
    scanf(" %[^\n]", comando);
    
    if(strcmp(comando, "comer") == 0)
        atualiza_status(fome, sede, banheiro, sono, tedio, 30, -5, -15, -5, -5);
    else if (strcmp(comando, "beber") == 0)
        atualiza_status(fome, sede, banheiro, sono, tedio, -5, 30, -20, -5, -5);
    else if (strcmp(comando, "dormir") == 0)
        atualiza_status(fome, sede, banheiro, sono, tedio, -30, -30, -30, 80, 30);
    else if (strcmp(comando, "se aliviar") == 0)
        atualiza_status(fome, sede, banheiro, sono, tedio, -5, -5, 100, -5, -5);
    else 
        atualiza_status(fome, sede, banheiro, sono, tedio, -20, -20, -20, -20, 80);
    
    limita_atributos(fome, sede, banheiro, sono, tedio);
    
    return testa_fim(fome, sede, banheiro, sono, tedio);
}

int testa_fim(int *fome, int *sede, int *banheiro, int *sono, int *tedio){
    int vivo = 1;
    
    if(*fome <= 0){
        vivo = 0;
        printf("Game Over! Morreu de fome\n");
    }
    if(*sede <= 0){
        vivo = 0;
        printf("Game Over! Morreu de sede\n");
    }
    if(*banheiro <= 0){
        vivo = 0;
        printf("Game Over! Morreu apertado...\n");
    }
    if(*sono <= 0){
        vivo = 0;
        printf("Game Over! Morreu dormindo...\n");
    }
    if(*tedio <= 0){
        vivo = 0;
        printf("Game Over! Morreu deprimido...\n");
    }
    
    if (!vivo) return vivo;
    if (*fome <= 15) printf("Alerta: fome está com valor baixo\n");
    if (*sede <= 15) printf("Alerta: sede está com valor baixo\n");
    if (*banheiro <= 15) printf("Alerta: banheiro está com valor baixo\n");
    if (*sono <= 15) printf("Alerta: sono está com valor baixo\n");
    if (*tedio <= 15) printf("Alerta: tédio está com valor baixo\n");
    
    return vivo;
}

void limita_atributos(int *fome, int *sede, int *banheiro, int *sono, int *tedio){
    if(*fome > 100) *fome = 100;
    if(*sede > 100) *sede = 100;
    if(*banheiro > 100) *banheiro = 100;
    if(*sono > 100) *sono = 100;
    if(*tedio > 100) *tedio = 100;
}

void imprime_relatorio(int fome, int sede, int banheiro, int sono, int tedio){
    printf("Status final: \n");
    printf("Fome: %d\nSede: %d\nBanheiro: %d\nSono: %d\nTédio: %d\n", fome, sede, banheiro, sono, tedio);
}