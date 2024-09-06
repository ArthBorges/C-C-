// PONTEIROS E FUNÇÕES
// Leia um vetor de tamanho n (n < MAX) e
// Determie o maior  elemento deste vetor.
// Seu código deve implementar a seguinte função

// int* maximo(int n, int vetor[])

#include <stdio.h>
#define MAX 100

int *maximo(int n, int vetor[]);

int main()
{
    int n;
    int *p;

    // lê tamanho do vetor
    do
    {
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    // declara o vetor de tamanho n
    int v[n];

    // leitura do vetor
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (v + i));
    }

    // encontra endereço de memória onde o maior elemento
    // do vetor está armazenado
    p = maximo(n, v);

    // imprime o conteúdo do endereço de memória apontado por p
    printf("Maior valor: %d\n", *p);
    
    return 0;
}

int *maximo(int n, int vetor[])
{
    int *p, maior, *pt_maior;
    maior = *vetor;
    pt_maior = &maior;

	for (p = vetor; p < vetor + n; p++)
	{
		if (*p > maior)
		{
			maior = *p;
		}
	}
    return pt_maior;
}