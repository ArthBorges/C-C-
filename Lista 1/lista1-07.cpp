/*Leia um valor correspondente a uma medida em pés, e mostre as conversões para:
polegadas, jardas e milhas, sabendo que: 1 pé = 12 polegadas; 1 jarda = 3 pés; 1 milha
= 1.760 jardas.*/

#include <stdio.h>

int main()
{
    float pes, pol, jar, mil;
    printf("Informe uma medida em pés:\n");
    scanf("%f", &pes);

    pol = pes * 12;
    jar = pes / 3;
    mil = jar / 1760;

    printf("%.2f Pés equivale a:\n%.2f Polegadas\n%.2f Jardas\n%.2f Milhas\n", pes, pol, jar, mil);
    return 0;
}
