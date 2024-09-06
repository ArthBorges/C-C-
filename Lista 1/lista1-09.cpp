/*Leia o ano de nascimento de uma pessoa e o ano atual, calcule e mostre: a) a idade
dessa pessoa; b) quantos anos essa pessoa terá em 2034.*/

#include <stdio.h>

int main()
{
    int ano_n, ano_a, idade, idade_f, diff;
    printf("Informe seu ano de nascimento e o ano atual:\n");
    scanf("%d %d", &ano_n, &ano_a);

    idade = ano_a - ano_n;
    diff = 2034 - ano_a;
    idade_f = idade + diff;

    printf("Idade: %d\nIdade em 2034: %d\n", idade, idade_f);
    return 0;
}
