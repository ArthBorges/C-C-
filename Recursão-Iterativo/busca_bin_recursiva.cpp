#include <stdio.h>

int busca(int *v, int ind, int inicio, int fim);

int main()
{
    int v[10], ind, inicio = 0, fim = 9, res;
    printf("Digite um vetor com 10 elementos:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &v[i]);
    }
    printf("Digite o numero a ser buscado no vetor:\n");
    scanf("%d", &ind);

    res = busca(v, ind, inicio, fim);
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

int busca(int *v, int ind, int inicio, int fim)
{
    int meio;
    if (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (ind == v[meio])
        {
            return meio;
        }
        else
        {
            if (ind < v[meio])
            {
                return busca(v, ind, inicio, meio - 1);
            }
            else
            {
                return busca(v, ind, meio + 1, fim);
            }
        }
    }
    return -1;
}