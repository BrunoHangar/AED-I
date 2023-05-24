#include <stdio.h>
#include <string.h>
#define MAX 50

void Combinador(char str1[], char str2[]) {
    int i, j;
    char strFinal[MAX];
    int tam = strlen(str1);
    
    for (i = 0; i < tam; i++) {
        for (j = i; j < tam; j++) {    
            strFinal[i] = str1[i];
            strFinal[j + 1] = str2[i];
        }
        //if ( i )
    }
    printf("%s\n", strFinal);
    
}

int main() {
    char str1[MAX], str2[MAX];
    int i = 0, X;
    
    scanf("%d", &X);
    
    while (i < X) {
        scanf("%s", str1);
        scanf("%s", str2);
        
        //printf("%s %s\n", str1, str2);
        Combinador(str1, str2);
        i++;
    }
    

    return 0;
}
