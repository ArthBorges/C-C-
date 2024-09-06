/*Leia um valor correspondente ao salário mínimo seguido de um valor correspondente
ao salário de determinado funcionário e calcule e mostre a quantidade de salários
mínimos que ganha esse funcionário.*/

#include <stdio.h>

int main()
{
    float s_min, s_fun, diff;
    printf("Informe o salário mínimo e o salário do funcionário:\n");
    scanf("%f %f", &s_min, &s_fun);

    diff = s_fun / s_min;

    if (diff < 2)
    {
        printf("O salário recebido pelo funcionário equivale a %.2f salário mínimo.\n", diff);
    }
    else
    {
        printf("O salário recebido pelo funcionário equivale a %.2f salários mínimos.\n", diff);
    }
    return 0;
}
