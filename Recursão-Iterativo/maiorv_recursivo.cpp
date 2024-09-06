#include <stdio.h>
#include <stdlib.h>

int maiorvet(int vetor[], int n);

int main()
{
    int n, *vet, maior;
    scanf("%d", &n);

    vet = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (vet + i));
    }

    maior = maiorvet(vet, n);
    printf("Maior: %d\n", maior);

    return 0;
}

int maiorvet(int vetor[], int n)
{
    if (n == 1)
    {
        return vetor[0];
    }

    int resto = maiorvet(vetor, n - 1);

    if (resto > vetor[n - 1])
    {
        return resto;
    }
    else
    {
        return vetor[n - 1];
    }
}