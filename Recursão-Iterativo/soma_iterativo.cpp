#include <stdio.h>

void somaNum(int n);

int main()
{
    int n;
    scanf("%d", &n);
    somaNum(n);

    return 0;
}

void somaNum(int n)
{
    int sum = 0;
    for (int i = 2; i < n; i++)
    {
        sum += i;
    }
    printf("%d", sum);
}