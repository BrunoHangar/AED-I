#include <stdio.h>
#include <string.h>
#define MAX 50

// Programa que usa a lógica da Cifra de César para decodificar mensagens, com o 

void DecoderCifraCesar(char str1[], int val) {
    int i;
    char ABC[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char strFinal[MAX];
    int tam = strlen(str1);
    
    
    int k = val;
    while (k <= 26) {
        for (i = 0; i < tam; i++) {
            strFinal[i] = ABC[k];
            k += val;
        }
    }
    printf("%s\n", strFinal);
}
    
    
int main() {
    int qtd, val, i;
    char str1[MAX], str2[MAX];
    
    scanf("%d", &qtd);
    
    i = 0;
    while (i < qtd) {
        scanf("%s", str1);
        scanf("%d", &val);
        DecoderCifraCesar(str1, val);
        i++;
    }
    
    
    return 0;
}