#include <stdio.h>

int main(){
    char mapa[6][6];
    
    int movimentos, x, y;
    char comandos;

    int fora = 0, detectado = 0;

    int i, j;

    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            scanf(" %c", &mapa[i][j]);
        }
    }

    scanf("%d", &movimentos);
    scanf("%d %d", &x, &y);
    x--;
    y--;

    for(i = 0; i < movimentos; i++){
        scanf("%c", &comandos);

        switch(comandos){
            case 'D': y++; break;
            case 'E': y--; break;
            case 'B': x++; break;
            case 'C': x--; break;
        }

        if(x < 0 || y < 0 || x > 5 || y > 5){
        fora = 1; break;
        }
        else{
            if( x > 0 && mapa[x--][y] == 'v'){
            detectado = 1; break;
            }
            else if( x < 5 && mapa[x++][y] == '^'){
            detectado = 1; break;
            }
            else if( y > 0 && mapa[x][y--] == '>'){
                detectado = 1; break;
            }
            else if( y < 5 && mapa [x][y++] == '<'){
                detectado = 1; break;
            }
        }
    }

    if(fora) printf("Movimento invalido.\n");
    else if(detectado) printf("Freeze!\n");
    else printf("Tal qual um Ninja...\n");

    return 0;
}