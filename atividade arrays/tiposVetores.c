#include <stdio.h>
#include <stdlib.h>

int isLegal(int vetor[], int n){
    int i;
    for(i = 1; i < n; i++){
        int diferenca = abs( vetor[i] - vetor [i - 1]);
        if(diferenca % 2 != 0) return 0;
    }
    return 1;
}

int main(){
    int n;
    
    scanf("%d", &n);

    int vetor[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    if(isLegal(vetor, n)) printf("Legal\n");
    else printf("Chato\n");
    
    return 0;
}