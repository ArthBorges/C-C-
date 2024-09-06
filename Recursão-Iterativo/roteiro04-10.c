// recebe dois vetores de tamanhos m e n, ordena e depois intercala
// estes dois vetores em um terceiro vetor resultante

#include <stdio.h>
#include <stdlib.h> // atoi(s): converte a string s e retorna um inteiro

// ******************************
// método bolha para ordenação
// ******************************
// m --> tamanho do vetor
// v --> ponteiro para o vetor
// FAZER O ACESSO AOS ELEMENTOS DO VETOR UTILIZANDO A NOTAÇÃO DE PONTEIROS
void Ordena(int m, int *v)
{
    int i, j, aux;
    for (i = m - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (*(v + j) > *(v + j + 1))
            {
                aux = *(v + j);
                *(v + j) = *(v + j + 1);
                *(v + j + 1) = aux;
            }
        }
    }
}

// ******************************
// imprime um vetor de inteiros
// ******************************
// FAZER O ACESSO AOS ELEMENTOS DO VETOR UTILIZANDO A NOTAÇÃO DE PONTEIROS
void Imprime(int m, int *v)
{
    int *pt;
    for (pt = v; pt < (v + m); pt++)
    {
        printf("%d ", *pt);
    }
    printf("\n");
}

// ********************************
// intercala dois vetores v1 e v2
// já ordenados e produz um terceiro
// vetor ordenado também
// ********************************
void Intercala(int tam_v1, int *v1, int tam_v2, int *v2, int *vetor_intercalado)
{
    int i = 0, j = 0, k = 0;

    while (i < tam_v1 && j < tam_v2)
    {
        while (v1[i] <= v2[j])
        {
            vetor_intercalado[k] = v1[i];
            i++;
            k++;
        }
        while (v2[j] <= v1[i])
        {
            vetor_intercalado[k] = v2[j];
            j++;
            k++;
        }
    }

    while (i < tam_v1)
    {
        vetor_intercalado[k] = v1[i];
        i++;
        k++;
    }

    while (j < tam_v2)
    {
        vetor_intercalado[k] = v2[j];
        j++;
        k++;
    }
}

// *******************************************
// recebe como argumento de entrada o tamanho
// do vetor 1 e tamanho do vetor 2
// Exemplo:  ./a.out 5 8
// *******************************************
int main(int argc, char const *argv[])
{
    int i, tam_v1, tam_v2;
    int *v1, *v2, *v;

    // atribui o tamanho dos vetores às respectivas variáveis
    tam_v1 = atoi(argv[1]);
    tam_v2 = atoi(argv[2]);

    // aloque memória para os vetores
    v1 = (int *)malloc(tam_v1 * sizeof(int));
    v2 = (int *)malloc(tam_v2 * sizeof(int));
    v = (int *)malloc((tam_v1 + tam_v2) * sizeof(int));

    // Leia os valores do vetor v1
    printf("Digite os valores do primeiro vetor: \n");
    for (i = 0; i < tam_v1; i++)
        scanf("%d", (v1 + i));

    // Leia os valores do vetor v2
    printf("Digite os valores do segundo vetor: \n");
    for (i = 0; i < tam_v2; i++)
        scanf("%d", (v2 + i));

    // Ordena v1
    Ordena(tam_v1, v1);
    // Ordena v1
    Ordena(tam_v2, v2);

    // Imprime v1 (que já está ordenado)
    printf("Este é o primeiro vetor, após ordenação\n");
    Imprime(tam_v1, v1);

    // Imprime v2 (que já está ordenado)
    printf("Este é o segundo vetor, após ordenação\n");
    Imprime(tam_v2, v2);

    // Realiza a intercalação de v1 e v2 a fim de obter o vetor v3, também ordenado
    Intercala(tam_v1, v1, tam_v2, v2, v);
    // Imprime v3

    printf("Vetor resultante da intercalação dos vetores de entrada (após ordenação): \n");
    Imprime(tam_v1 + tam_v2, v);

    return 0;
}