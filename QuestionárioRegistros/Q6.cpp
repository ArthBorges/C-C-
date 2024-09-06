#include <stdio.h>
#include <string.h>

struct data
{
    int d;
    int m;
    int a;
};

int dias(data d);


int main(void)
{
    // declaração das variáveis
    data datainf;
    int res;

    // leitura dos dados de entrada
    scanf("%d/%d/%d", &datainf.d, &datainf.m, &datainf.a);

    // processamento
    if (datainf.m <= 2)
    {
        datainf.a -= 1;
    }
    if (datainf.m <= 2)
    {
        datainf.m += 13;
    }
    else
    {
        datainf.m += 1;
    }

    res = dias(datainf);
    
    // saída
    switch (res)
    {
    case 0:
        printf("Domingo\n");
        break;
    case 1:
        printf("Segunda\n");
        break;
    case 2:
        printf("Terca-feira\n");
        break;
    case 3:
        printf("Quarta-feira\n");
        break;
    case 4:
        printf("Quinta-feira\n");
        break;
    case 5:
        printf("Sexta-feira\n");
        break;
    case 6:
        printf("Sabado\n");
        break;
    default:
        break;
    }

    return 0;
}

int dias(data d)
{
    int N, D;
    N = ((1461 * d.a) / 4) + ((153 * d.m) / 5) + d.d;
    D = (N - 621049) % 7;
    
    return D;
}