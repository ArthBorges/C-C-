/*Leia três notas e seus respectivos pesos, 
calcule e mostre a média aritmética entre elas. */

#include <stdio.h>

int main()
{
    float n1, n2, n3, media;
    int p1, p2, p3, tot_p;

    printf("Informe as três notas e seus respectivos pesos.\n");
    scanf("%f %f %f %d %d %d", &n1, &n2, &n3, &p1, &p2, &p3);

    tot_p = p1 + p2 + p3;
    media = (n1 * p1) + (n2 * p2) + (n3 * p3);
    media /= tot_p;
    printf("A média aritmética é: %.2f", media);
    return 0;
}
