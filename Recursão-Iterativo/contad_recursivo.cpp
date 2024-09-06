#include <stdio.h>

int contad(int n);

int main()
{
    int n, res;
    scanf("%d", &n);
    res = contad(n / 10);
    printf("%d", res);
    return 0;
}

int contad(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return 1 + contad(n / 10);
    }
}