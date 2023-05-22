#include <stdio.h>
#include <math.h>

//Calcula as raízes de Delta (Bháskara) dado valores a, b e c, fornecidos pelo usuário
int main() {
    double A, B, C;
    float delta, R1, R2;
    scanf("%lf %lf %lf", &A, &B, &C);
    delta = (B*B)-(4*A*C);

    R1 = (-B+(sqrt(delta)))/(2*A);
    R2 = (-B-(sqrt(delta)))/(2*A);
   
    if (delta < 0 || A == 0) {
        printf("Impossivel calcular");
    } else {
        printf("R1 = %.5lf", R1);
        printf("\nR2 = %.5lf", R2);
    }
    return 0;
}
