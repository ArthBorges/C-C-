//Soma dois números
// os dois valores de entrada são lidos em uma mesma linha

#include <stdio.h>

int main()
{
    int x, y, soma;
    printf("Digite os valores dos dois inteiros:");
    scanf("%d %d", &x, &y);
    
    soma = x + y;
    printf("%d", soma);
    
    return 0;
}
