#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51

// Função responsável por remover todas as consoantes da string
void RemoveConsoante(char risada[]) {
    int i, j = 0, tam;
    tam = strlen(risada);
    
    for (i = 0; i < tam; i++) {
        if (risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u') {
            risada[j] = risada[i];
            j++;
        }
    }
    risada[j] = '\0'; //Adiciona caractere nulo no final da string para indicar seu fim
}

// Função que verifica se a string é simétrica
void IsSimetrica(char risada[]) {
    char aux1[MAX], aux2[MAX];
    int i, j, tam;
    tam = strlen(risada);
    
    for (i = 0; i < tam -1; i++) {
        aux1[i] = risada[i];
        aux2[i] = risada[tam - 1 - i];
    }
    aux1[i] = '\0'; //Adiciona caractere nulo no final de ambas strings para indicar seu fim
    aux2[i] = '\0';
    
    if (strcmp(aux1, aux2) == 0)
        printf("S\n");
    else
        printf("N\n");
}

int main() {
    char risada[MAX];
    
    fgets(risada, MAX, stdin);
    RemoveConsoante(risada);
    IsSimetrica(risada);
    
    return 0;
}