#include <stdio.h>

void potencia(int x, int n);

int main()
{
    int n, x;
    scanf("%d %d", &x, &n);
    potencia(x, n);

    return 0;
}

void potencia(int x, int n){
    int res = x;
    for (int i = 1; i < n; i++)
    {
        res *= x;
    }
    printf("%d", res);
}