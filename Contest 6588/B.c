#include <stdio.h>

// Calcula a área do círculo pela medida de raio recebida.
int main() {
    float raio, pi = 3.14159;
    scanf("%f", &raio);
    printf("A=%.4f \n", (raio*raio*pi));

    return 0;
}
