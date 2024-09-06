#include <stdio.h>
#include <stdlib.h>

int busca_bin(int *v, int num, int inicio, int fim);

int main()
{
    int n, *vetor, num, res;
    scanf("%d", &n);
    vetor = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (vetor + i));
    }

    printf("Qual nro deseja procurar no vetor?\n");
    scanf("%d", &num);

    res = busca_bin(vetor, num, 0, n);
    if (res == -1)
    {
        printf("O nro NAO se encontra no vetor\n");
    }
    else
    {
        printf("O nro se encontra na posicao %d do vetor\n", res);
    }

    return 0;
}

int busca_bin(int *v, int num, int inicio, int fim)
{
    int meio;
    if (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (num == v[meio])
        {
            return meio;
        }
        else
        {
            if (num > v[meio])
            {
                return busca_bin(v, num, meio + 1, fim);
            }
            else
            {
                return busca_bin(v, num, inicio, meio - 1);
            }
        }
    }
    return -1;
}