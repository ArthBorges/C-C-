/*Leia valores correspondentes a um depósito e dois saques e, em seguida, calcule o
saldo final, sabendo que cada operação custa 0.38 por cento do valor sacado.*/

#include <stdio.h>

int main()
{
    float dep, saq1, saq2, saldo_f;
    printf("Informe o valor do depósito e dos dois saques:\n");
    scanf("%f %f %f", &dep, &saq1, &saq2);

    saldo_f = dep - (saq1 * 0.0038) - (saq2 * 0.0038) - saq1 - saq2;

    printf("Saldo Final: %.2f\n", saldo_f);
    return 0;
}
