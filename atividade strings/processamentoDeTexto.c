#include<stdio.h>
#include <string.h>

void constroiStrLista(int posicao, char lista[][10]) {
  int len;
  fgets(lista[posicao], 10, stdin);
  len = strlen(lista[posicao]);
  lista[posicao][len-1] = '\0';
}

void lePalavra(char palavra[100]) {
  int len;
  fgets(palavra, 100, stdin);
  len = strlen(palavra);
  palavra[len-1] = '\0';
}

void retiraComeco(char palavra[100], int len, int firstLetra) {
  char aux;
  for (int i=0; i<len; i++) {
    aux = palavra[firstLetra];
    palavra[i] = aux;
    firstLetra++;
    if(i==len-1) {
        palavra[i+1] = '\0';
    }
  }
}

void comparaPalavra(int n, int m, char pref[][10], char suf[][10], char palavra[100]) {
  int i, len, tamanhoPalavra;
  tamanhoPalavra = strlen(palavra);
  // verificando os prefixos com a palavra dada
  for (i = 0; i<n; i++) {
    len = strlen(pref[i]);
    if (strncmp(pref[i], palavra, len) == 0) {
      retiraComeco(palavra, tamanhoPalavra - len + 1,len);
      break;
    }
  }
  tamanhoPalavra = strlen(palavra);
  // verificado os sufixos
  for (i=0; i<m; i++) {
    len = strlen(suf[i]);
    if (strstr(palavra, suf[i]) != NULL) {
      palavra[tamanhoPalavra-len] = '\0';
      break;
    }
  }
}

int main(){
  int n, m;
  char prefixo[10] = {0}, sufixo[10] = {0};
  
  // criando uma lista com prefixos
  scanf("%d\n", &n);
  char prefixos[n][10];
  for (int i=0; i<n; i++) {
    constroiStrLista(i, prefixos);
  }
  
  // criando uma lista com sufixos
  scanf("%d\n", &m);
  char sufixos[m][10];
  for (int i=0; i<m; i++) {
    constroiStrLista(i, sufixos);
  }

  // lendo as palavras
  char palavra[100] = {0}, parada[100] = "-1";
  int check, tamanho;
  lePalavra(palavra);
  tamanho = strlen(palavra);
  check = strcmp(palavra, parada);
  if (check != 0) {
    do {
    comparaPalavra(n, m, prefixos, sufixos, palavra);
    printf("%s\n", palavra);
    lePalavra(palavra);
    check = strcmp(palavra, parada);
    } while (check != 0);
  }
  return 0;
}