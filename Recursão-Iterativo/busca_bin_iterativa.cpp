#include <stdio.h>

int busca(int *v, int ind, int fim);

int main()
{
    int v[10], ind, fim = 9, res;
    printf("Digite um vetor com 10 elementos:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &v[i]);
    }
    printf("Digite o numero a ser buscado no vetor:\n");
    scanf("%d", &ind);

    res = busca(v, ind, fim);
    if (res == -1)
    {
        printf("Numero nao encontrado\n");
    }
    else
    {
        printf("O numero esta na posicao %d do vetor\n", res);
    }

    return 0;
}

int busca(int *v, int ind, int fim)
{
    int inicio = 0;
    int meio = (inicio + fim) / 2;

    while (inicio <= fim)
    {
        if (ind == v[meio])
        {
            return meio;
        }
        else
        {
            if (ind < v[meio])
            {
                fim = meio - 1;
            }
            else
            {
                inicio = meio + 1;
            }
        }
        meio = (inicio + fim) / 2;
    }
    return -1;
}