#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *v1, *v2, *vres;
    scanf("%d", &n);

    v1 = (int *)malloc(n * sizeof(int));
    v2 = (int *)malloc(n * sizeof(int));
    vres = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", (v1 + i));
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (v2 + i));
    }
    for (int i = 0; i < n; i++)
    {
        *(vres + i) = *(v1 + i) * *(v2 + i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(vres + i));
    }
    
    return 0;
}
