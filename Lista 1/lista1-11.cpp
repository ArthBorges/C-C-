/*Leia um valor correspondente ao custo de um determinado espetáculo teatral e o preço
do convite individual desse espetáculo e, em seguida, calcule a mostre a quantidade
mínima de convites que devem ser vendidos para custear o espetáculo.*/

#include <stdio.h>

int main()
{
    float custo, convite, total;
    int quantd;

    printf("Informe o custo do espetáculo e o valor do convite:\n");
    scanf("%f %f", &custo, &convite);

    quantd = total = 0;
    while (total < custo)
    {
        total += convite;
        quantd++;
    }

    printf("Serão necessários %d convites para custear o evento!\n", quantd);
    return 0;
}
