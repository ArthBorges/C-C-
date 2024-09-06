#include <stdio.h>

int main()
{
    float h, pideal;
    char s;

    printf("Informe a altura e sexo(M/F) da pessoa:\n");
    scanf("%f %c", &h, &s);

    if (s == 'M' || s == 'm')
    {
        pideal = (72.7 * h) - 58;
    }
    else if (s == 'F' || s == 'f')
    {
        pideal = (62.1 * h) - 44.7;
    }
    else
    {
        printf("Sexo inválido, digite M ou F.\n");
        return 1;
    }
    
    printf("O peso ideal é: %.2f\n", pideal);
    return 0;
}
