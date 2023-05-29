#include <stdio.h>
#include <string.h>

#define MAX 51

// Decodifica a mensagem usando a lógica da Cifra de César, considerando o deslocamento dos caracteres
void DecodificaCifraCesar(char str1[], int desloc) {
    int i;
    int tam = strlen(str1);
    
    for (i = 0; i < tam; i++) {
        // Deslocamento reverso para a esquerda
        int ascii = str1[i] - 'A';
        int novoAscii = (ascii - desloc + 26) % 26;
        str1[i] = novoAscii + 'A';
    }
}

int main() {
    int qtd;
    scanf("%d", &qtd);
    getchar(); // Para consumir o caractere de nova linha após a leitura de N

    while (qtd--) {
        char str1[MAX];
        int desloc;
        scanf("%s", str1);
        scanf("%d", &desloc);
        getchar(); // Para consumir o caractere de nova linha após a leitura do deslocamento

        DecodificaCifraCesar(str1, desloc);
        printf("%s\n", str1);
    }

    return 0;
}
