#include <stdio.h>

void fatorial(int n);

int main()
{
    int n;
    scanf("%d", &n);
    fatorial(n);

    return 0;
}

void fatorial(int n){
    int fat = 1;
    for (int i = 1; i < n+1; i++)
    {
        fat = fat * i;
    }
    printf("%d", fat);
}