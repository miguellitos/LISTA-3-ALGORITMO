#include <stdio.h>
#include <math.h>

int main() {
    int t;
    double A, i, V = 0.0;
    scanf("%d", &t);
    scanf("%lf", &A);
    scanf("%lf", &i);

    for(int mes = 1; mes <= t; mes++) {
        V = (V + A) * (1 + i);
        printf("Montante ao fim do mes %d: R$ %.2lf\n", mes, V);
    }

    return 0;
}