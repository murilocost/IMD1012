#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    switch(n%2){
        case 0: printf("Par\n"); break;
        default: printf("Impar\n"); break;
    }
    return 0;
}