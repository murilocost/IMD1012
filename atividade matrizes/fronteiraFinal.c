#include <stdio.h>

int main(){
    int N, M;

    scanf("%d %d", &N, &M);

    char mapa[N][M];


    for (int i = 0; i < N; i ++){
        for (int j = 0; j < M; j++){
            scanf(" %c", &mapa[i][j]);
        }
    }

    int agua = 0, hostis = 0, vegetacao = 0, deserto = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if(mapa[i][j] == '~') agua++;
            else if(mapa[i][j] == 'X') hostis++;
            else if(mapa[i][j] == '*') vegetacao++;
            else if(mapa[i][j] == '^') deserto++;
        }
    }

    if ((agua >= N * M * 0.50) && (vegetacao >= N * M * 0.20) && hostis == 0) printf("Planeta Classe M\n");
    else if(hostis > 0) printf("Planeta Hostil\n");
    else if(agua >= N * M * 0.85) printf("Planeta Aquático\n");
    else if(deserto >= N * M * 0.60) printf("Planeta Desértico\n");
    else if(vegetacao >= N * M * 0.65) printf("Planeta Selvagem\n");
    else printf("Planeta Inóspito\n");


    return 0;
}