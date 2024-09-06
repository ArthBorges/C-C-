#include <stdio.h>
#define MAX 100

int maximo(int n, int v[MAX]);

int main()
{
    int n, v[MAX], maior;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    maior = maximo(n, v);
    printf("Maior: %d\n", maior);
    return 0;
}

int maximo(int n, int v[MAX])
{
    int aux;
    if (n == 1)
    {
        return v[0];
    }
    else
    {
        aux = maximo(n - 1, v);
        if (aux > v[n - 1])
        {
            return aux;
        }
        else
        {
            return v[n - 1];
        }
    }
}