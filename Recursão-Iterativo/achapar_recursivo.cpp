#include <stdio.h>
#include <stdlib.h>

bool contem_par(int n, int V[]);

int main()
{
    int n, *vet;
    scanf("%d", &n);
    vet = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", (vet + i));
    }

    if (contem_par(n, vet))
    {
        printf("O vetor possui nros pares\n");
    }
    else
    {
        printf("O vetor NAO possui nros pares\n");
    }

    return 0;
}

bool contem_par(int n, int V[])
{
    if (n == 1)
    {
        if (V[0] % 2 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (V[n-1] % 2 == 0)
        {
            return true;
        }
        else
        {
            return contem_par(n - 1, V);
        }
    }
}