#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int main() {
    int N = -1, M = -1, soma;
    char junta[30];
    int i, j;
    
    // Executa até ler 0 na entrada de dados
    while (N != 0 && M != 0) {
        scanf("%d", &N);
        scanf("%d", &M);
        soma = N + M;
        // 'sprintf' faz a conversão de um valor de inteiros para uma sequência de digitos na variável 'junta'
        sprintf(junta, "%d", soma);
        
        // Retira todos os elementos '0' da string
        for (i = 0; i < MAX - 1; i++) {
            if (junta[i] == '0') {
                for (j = i; j < MAX - 1; j++) {
                    junta[j] = junta[j + 1];
                }
                junta[MAX - 1] = '\0'; // Adiciona o caractere nulo no final da string
                i--; // Decrementa o índice para verificar novamente o elemento atual
            }
        }
        // Imprime e saída de dados
        if(soma != 0)
            printf("%s\n", junta);
    }
    return 0;
}
