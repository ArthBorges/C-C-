#include <stdio.h>

int somaNum(int n);

int main()
{
    int n, res;
    scanf("%d", &n);
    res = somaNum(n-1);
    printf("%d", res);
    return 0;
}

int somaNum(int n)
{
    if (n == 2)
    {
        return n;
    }
    else{
        return n + somaNum(n-1);
    }

}