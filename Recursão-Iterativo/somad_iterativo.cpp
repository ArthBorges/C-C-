#include <stdio.h>

void somaD(int n);

int main()
{
    int n;
    scanf("%d", &n);
    somaD(n);
    return 0;
}

void somaD(int n)
{
    int soma = 0, dig;
    while (n > 0)
    {
        dig = n % 10;
        soma += dig;
        n /= 10;
    }
    printf("%d", soma);
}