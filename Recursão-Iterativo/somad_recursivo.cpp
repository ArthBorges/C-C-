#include <stdio.h>

int somaD(int n);

int main()
{
    int n, res;
    scanf("%d", &n);
    res = somaD(n);
    printf("%d", res);
    return 0;
}

int somaD(int n)
{
    int soma = 0, dig;
    if (n / 10 == 0)
    {
        dig = n % 10;
        soma += dig;
        return soma;
    }
    else
    {
        dig = n % 10;
        soma += dig;
        n /= 10;
        return soma + somaD(n);
    }
}