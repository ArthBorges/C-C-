/*Leia os valores correspondentes à base e altura de um triângulo e calcule e mostre a
área do mesmo. Lembre-se que área = (base ∗ altura)/2. */

#include <stdio.h>

int main()
{
    float base, high, area;
    printf("Informe os valores de base e altura:\n");
    scanf("%f %f", &base, &high);

    area = (base * high) / 2;
    printf("Area = %.2f\n", area);
    return 0;
}
