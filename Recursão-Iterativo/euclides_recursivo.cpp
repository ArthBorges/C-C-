#include <stdio.h>

int mdc(int a, int b);

int main()
{
    int a, b, res;
    scanf("%d %d", &a, &b);
    res = mdc(a, b);
    printf("%d", res);
    return 0;
}

int mdc(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return mdc(b, a % b);
    }
}
