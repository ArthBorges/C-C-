/*Leia dois números inteiros e calcule o primeiro número elevado à potência do segundo.
Depois, calcule a raiz quadrada do resultado.*/

#include <stdio.h>
#include <math.h>

int main()
{
    int n1, n2, n3;
    float raiz;

    printf("Digite dois inteiros:\n");
    scanf("%d %d", &n1, &n2);
    
    n3 = pow(n1, n2);
    raiz = sqrt(n3);

    printf("POT %d ^ %d = %d.\nSQRT: %.2f\n", n1, n2, n3, raiz);
    return 0;
}
