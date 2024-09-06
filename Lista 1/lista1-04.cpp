/*Leia o valor de um depósito e o valor da taxa de juros, calcule e mostre o valor do
rendimento e o valor total depois do rendimento.*/

#include <stdio.h>

int main()
{
    float dep, taxa, rend, tot;
    printf("Digite o valor do depósito e taxa de juros:\n");
    scanf("%f %f", &dep, &taxa);

    rend = dep *(taxa / 100);
    tot = dep + rend;

    printf("Valor do rendimento: %.2f\nTotal pós rendimento: %.2f\n", rend, tot);
    return 0;
}
