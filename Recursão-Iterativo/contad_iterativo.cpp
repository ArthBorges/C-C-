#include <stdio.h>

void contad(int n);

int main()
{
    int n;
    scanf("%d", &n);
    contad(n);
    return 0;
}

void contad(int n)
{
    int cont = 0;
    if (n == 0)
    {
        cont = 1;
    }

    while (n > 0)
    {
        n /= 10;
        cont++;
    }
    printf("%d", cont);
}