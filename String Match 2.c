#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100000

// Função para converter a string para letras minúsculas
void Minusculo(char *string) {
    while (*string) {
        *string = tolower(*string);
        string++;
    }
}

//Faz uso da função strstr dentro da biblioteca string.h, que tem sua utilização baseada no algoritmo
// de Boyer-Moore, onde ela busca subtrings dentro de uma string.
int main() {
    char string[MAX], *resultado;

    fgets(string, MAX, stdin);
    string[strcspn(string, "\n")] = '\0';

    // Converte a string para letras minúsculas
    Minusculo(string);

    // Verificar a presença da palavra "zelda" na string
    resultado = strstr(string, "zelda");

    if (resultado != NULL) {
        printf("Link Bolado");
    } else {
        printf("Link Tranquilo");
    }

    return 0;
}
