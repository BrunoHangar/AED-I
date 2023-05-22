#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100000

// Função para verificar se a palavra "zelda" está presente na string
int StringMatch(char *string) {
    char *word = "zelda";
    int length = strlen(string);
    int wordLength = strlen(word);
    
    // Convertendo a palavra "zelda" para letras minúsculas
    char lowercaseWord[wordLength + 1];
    for (int i = 0; i < wordLength; i++) {
        lowercaseWord[i] = tolower(word[i]);
    }
    lowercaseWord[wordLength] = '\0';
    
    // Percorre a string para fazer a comparação
    for (int i = 0; i < length; i++) {
        // Convertendo o caractere atual para letras minúsculas
        char lowercaseChar = tolower(string[i]);
        
        // Verificando se há correspondência
        if (lowercaseChar == lowercaseWord[0]) {
            int j;
            for (j = 1; j < wordLength; j++) {
                if (tolower(string[i + j]) != lowercaseWord[j]) {
                    break;
                }
            }
            if (j == wordLength) {
                return 1; // A palavra "zelda" foi encontrada
            }
        }
    }
    return 0; // A palavra "zelda" não foi encontrada
}

int main() {
    char string[MAX];
    
    fgets(string, MAX, stdin);
    
    // Removendo o caractere de nova linha (\n) da string
    string[strcspn(string, "\n")] = '\0';
    
    // Verificando a presença da palavra "zelda" na string
    int Verificador = StringMatch(string);
    
    // Exibindo a mensagem correspondente
    if (Verificador) {
        printf("Link Bolado\n");
    } 
    else {
        printf("Link Tranquilo\n");
    }
    
    return 0;
}
