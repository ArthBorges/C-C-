#include <stdio.h>

#define MAX 15

struct tipoEletro
{
    char nome[MAX];
    float potencia;
    float tempo;
};

int main()
{
    tipoEletro lista[5];
    float gasto_total = 0, gasto_relativo = 0, dias;

    for (int i = 0; i < 5; i++)
    {
        scanf("%s\n %f\n %f", lista[i].nome, &lista[i].potencia, &lista[i].tempo);
        gasto_total += lista[i].potencia * lista[i].tempo;
    }

    scanf("%f", &dias);
    gasto_total = gasto_total * dias;
    printf("%.2f\n", gasto_total);

    for (int i = 0; i < 5; i++)
    {
        gasto_relativo = (lista[i].potencia * lista[i].tempo * dias) / gasto_total * 100;
        printf("%.2f\n", gasto_relativo);
    }
    
    return 0;
}
