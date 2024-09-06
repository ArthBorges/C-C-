#include <stdio.h>
#include <stdlib.h>

void fibonacci(int vetor[], int n);

int main()
{
    int n, *vet;
    scanf("%d", &n);
    vet = (int *)malloc(n * sizeof(int));

    fibonacci(vet, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }

    return 0;
}

void fibonacci(int vetor[], int n)
{
    int fibo = 0, ant = 1, i = 0, cont = 0, aux;

    while (i < n + 1)
    {
        if (i == n - 1)
        {
            vetor[cont] = fibo;
            cont++;
        }
        else
        {
            vetor[cont] = fibo;
            cont++;
        }
        aux = fibo;
        fibo = ant;
        ant = aux + ant;
        i++;
    }
}