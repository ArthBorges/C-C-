#include <stdio.h>
#define MAX 5

int main()
{
    int matriz[MAX][MAX], n, *p;
    scanf("%d", &n);
    for (p = &matriz[0][0]; p <= &matriz[MAX-1][MAX-1]; p++)
    {
        *p = n;
        n--;
    }
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%.2d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}