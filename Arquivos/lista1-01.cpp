#include <stdio.h>
#include <stdlib.h>

int main()
{
    int /*min = 0, max = 0, cont = 0,*/ valor;
    char nome_arq[30];
    // float avg = 0.0;
    FILE *ptarq;


    printf("%s", nome_arq);

    ptarq = fopen(nome_arq, "r");

    if (ptarq == NULL)
    {
        printf("Nao abriu o arq\n");
    }

    while (feof(ptarq) == 0) // RETORNA 0 ENQUANTO O PONTEIRO NÃO CHEGAR NO FINAL DO ARQUIVO
    {
        fscanf(ptarq, "%d", &valor);
        printf("%d", valor);
        /*avg += *pt;
        cont++;

        if (*pt > max)
        {
            max = *pt;
        }
        else if (*pt < min)
        {
            min = *pt;
        }*/
    }

    // printf("Media: %.2f\nMaior: %d\nMenor: %d", avg, max, min);

    return 0;
}
