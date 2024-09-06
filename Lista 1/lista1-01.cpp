/*Leia o número de matrícula do funcionário, o número de horas trabalhadas mensais, o
valor que ele recebe por hora e o número de filhos. Calcular e escrever o salário deste
funcionário, sendo que cada filho acrescenta 10% no salário do funcionário.*/

#include <stdio.h>

int main()
{
    int mat, horas, filhos;
    float valor_ph, salario, qtd_aumento, total;

    printf("Informe matrícula, horas trabalhadas, valor recebido por hora e número de filhos.\n");
    scanf("%d %d %f %d", &mat, &horas, &valor_ph, &filhos);

    salario = valor_ph * horas;
    float pct = filhos * 0.1;
    qtd_aumento = pct * salario;
    total = salario + qtd_aumento;

    printf("O salário do funcionário foi de: %.2f\n", total);
    return 0;
}
