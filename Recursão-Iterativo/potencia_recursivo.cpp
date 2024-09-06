#include <stdio.h>

int potencia(int x, int n);

int main()
{
    int n, x, res;
    scanf("%d %d", &x, &n);
    res = potencia(x, n);
    printf("%d", res);
    return 0;
}

int potencia(int x, int n)
{
    int res = x;
    if (n == 0)
    {
        return 1;
    }

    else
    {
        return res * potencia(x, n - 1);
    }
}