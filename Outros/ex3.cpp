#include <stdio.h>

int main()
{
    int num, ult, penult, resto, soma;
    scanf("%d", &num);
    ult = num % 10;
    resto = num / 10;
    penult = resto % 10;
    soma = ult + penult;
    printf("A soma entre os dois últimos dígitos é %d.", soma);

    return 0;
}
