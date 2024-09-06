/*Leia o salário de um funcionário e uma porcentagem, calcule e mostre o novo salário,
sabendo-se que este sofreu o aumento da porcentagem informada. */

#include <stdio.h>

int main()
{
    float salario, v_reaj, pct, pct_dec;

    printf("Informe o salário e a porcentagem de reajuste.\n");
    scanf("%f %f", &salario, &pct);

    pct_dec = pct / 100;
    printf("%.2f\n", pct_dec);
    v_reaj = salario * pct_dec;
    printf("%.2f\n", v_reaj);
    salario = salario + v_reaj;

    printf("O salário atual é de: %.2f", salario);
    return 0;
}
