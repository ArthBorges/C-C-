#include <stdio.h>

struct tipoData
{
    int dia;
    int mes;
    int ano;
};

float calculaDias(tipoData &data);

int main()
{
    tipoData d1, d2;
    float dias1, dias2;
    scanf("%d/%d/%d %d/%d/%d", &d1.dia, &d1.mes, &d1.ano, &d2.dia, &d2.mes, &d2.ano);

    dias1 = calculaDias(d1);
    dias2 = calculaDias(d2);

    dias1 -= dias2;
    if (dias1 < 0)
    {
        dias1 *= -1;
    }
    
    printf("%.0f\n", dias1);

    return 0;
}

float calculaDias(tipoData &data)
{
    float qtd_dias;
    if (data.mes <= 2)
    {
        data.ano -= 1;
    }
    if (data.mes <= 2)
    {
        data.mes += 13;
    }
    else
    {
        data.mes += 1;
    }

    qtd_dias = ((1461 * data.ano) / 4 + (153 * data.mes) / 5) + data.dia;
    return qtd_dias;
}