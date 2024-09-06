#include <stdio.h>

int fatorial(int n);

int main()
{
    int n, res;
    scanf("%d", &n);
    res = fatorial(n);
    printf("%d", res);
    return 0;
}

int fatorial(int n)
{

    if (n <= 1)
    {
        return n;
    }
    else
    {
        return n * fatorial(n - 1);
    }
}