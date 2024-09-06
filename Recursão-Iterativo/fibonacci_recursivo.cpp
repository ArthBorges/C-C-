#include <stdio.h>
#include <stdlib.h>

int fibonacci(int vetor[], int n);

int main()
{
    int n, *vet;
    scanf("%d", &n);
    vet = (int *)malloc(n * sizeof(int));

    if (n == 0)
    {
        printf("%d", n);
    }
    else
    {
        n++;
        fibonacci(vet, n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", vet[i]);
        }
    }

    return 0;
}

int fibonacci(int vetor[], int n)
{
    if (n <= 0)
    {
        vetor[0] = 0;
        return 0;
    }
    if (n == 1)
    {
        vetor[1] = 1;
        return 1;
    }
    else
    {
        return vetor[n] = fibonacci(vetor, n - 1) + fibonacci(vetor, n - 2);
    }
}