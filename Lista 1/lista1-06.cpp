/*Leia a dimensão do raio de um círculo e calcule e mostre a área do mesmo. Lembre-se
que área = (pi ∗ raio2). */

#include <stdio.h>

int main()
{
    float raio, area;
    printf("Informe o raio:\n");
    scanf("%f", &raio);

    area = 3.14 * (raio * raio);
    printf("Area = %.2f\n", area);
    return 0;
}
