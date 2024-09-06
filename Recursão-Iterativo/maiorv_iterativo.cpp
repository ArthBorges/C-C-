#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *vet, *p, maior;
    scanf("%d", &n);

    vet = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (vet + i));
    }
    
    maior = *vet;
    for (p = vet; p < (vet + n); p++)
    {
        if (*p > maior)
        {
            maior = *p;
        }
    }

    printf("Maior: %d\n", maior);
    
    return 0;
}
