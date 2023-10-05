#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    if (n > 5 && n < 80)
    {
        printf("V\n");
    }
    else if(n > -10 && n < -1)
    {
        printf("F\n");
    }
    
    return 0;
}