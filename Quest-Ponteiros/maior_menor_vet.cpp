// PONTEIROS E FUNÇÕES
// Leia um vetor de tamanho n (n < MAX) e
// Determie o maior e o menor elemento deste vetor.
// Seu código deve implementar as seguintes funções

// void le_vet(int n, int vetor[]);
// void min_max(int n, int vetor[], int &max, int &min);

#include <stdio.h>
#define MAX 100

void le_vet(int n, int vetor[]);
void min_max(int n, int vetor[], int &max, int &min);

int main()
{
	int n;
	int maior, menor;

	// lê tamanho do vetor
	do
	{
		scanf("%d", &n);
	} while (n < 1 || n > MAX);

	// declara um vetor de tamanho n
	int v[n];

	// leitura do vetor
	le_vet(n, v);

	// encontra o maior e menor elemento do vetor
	min_max(n, v, maior, menor);

	// imprime o resultado
	printf("Maior: %d - Menor: %d\n", maior, menor);

	return 0;
}

void le_vet(int n, int vetor[])
{
	for (int i = 0; i < n; i++)
	{
		scanf("%d", (vetor + i));
	}
}

void min_max(int n, int vetor[], int &max, int &min)
{
	int *p;
	max = *vetor;
	min = *vetor;

	for (p = vetor; p < vetor + n; p++)
	{
		if (*p > max)
		{
			max = *p;
		}
		if (*p < min)
		{
			min = *p;
		}
	}
}