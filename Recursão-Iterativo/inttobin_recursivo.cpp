#include <stdio.h>
#include <stdlib.h>

int calcula_bin(int n, int bin, int pos);

int main()
{
    int n, bin = 0, pos = 1, res;
    scanf("%d", &n);

    res = calcula_bin(n, bin, pos);
    printf("%d\n", res);

    return 0;
}

int calcula_bin(int n, int bin, int pos)
{
    if (n <= 0)
    {
        return bin;
    }
    else
    {
        int resto = n % 2;
        bin += resto * pos;
        pos *= 10;
        n /= 2;
        return calcula_bin(n, bin, pos);
    }
}