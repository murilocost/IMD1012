#include <stdio.h>
#include <stdlib.h>

void bubble_sort (int array[], int x) {
  
 for (int i = 0; i < x-1; i++) {
    for (int j = i; j < x-1; j++) {
      if (array[i] > array[j]) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
            }
        }
    }
}

int main(){
    int *inteiros;
    int cont = 1;

    inteiros = calloc(1, sizeof(int));

    while (scanf("%d ", &inteiros[cont - 1]) != EOF){
        cont++;
        inteiros = realloc(inteiros, sizeof(int) * cont);
    }

    bubble_sort(inteiros, cont);

    for (int i = 0; i < cont - 1; i++){
        printf("%d ", inteiros[i]);
    }

    return 0;
}
