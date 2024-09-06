#include <stdio.h>
#include <stdlib.h>

float somatoria(int n);

int main()
{
    int n;
    scanf("%d", &n);
    float res = somatoria(n);
    printf("Somatoria: %.2f\n", res);
    
    return 0;
}

float somatoria(int n)
{
    if (n == 1)
    {
        return 1.0;
    }
    else
    {
        return 1.0 / n + somatoria(n - 1);
    }
}