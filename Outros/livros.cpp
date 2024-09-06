/*Faca um programa que leia um vetor com os dados de N (N <= 10)livros:
titulo (maximo de 30 letras), autor (maximo de 30 letras) e ano. Leia um valor P e
mostre as informacoes de todos os livros com ano abaixo de P. Repita este processo ate que seja lido
um valor P = 0 seja informado.

Crie uma funcao para fazer a leitura dos N livros, armazenando-os em um vetor de
registros. A funcao deve receber como parametro o valor de N e o vetor para armazenar
os dados.

Crie uma funcao para fazer a listagem dos livros com ano menor que P.*/

#include <stdio.h>

// constantes
#define TAM 10
#define MAX 30

// definicao de tipos
struct tLivro
{
	char titulo[MAX], autor[MAX];
	int ano;
};

void leitura(tLivro vetor[TAM], int n); // complete o prototipo desta funcao

void listagem(tLivro vetor[TAM], int n, int P);

// funcao principal
int main()
{
	tLivro colecao[TAM];
	int n, P;
	do
	{
		scanf("%d", &n);
	} while (n < 1 || n > 10);
	
	leitura(colecao, n);

	do
	{
		scanf("%d", &P);
		listagem(colecao, n, P);
	} while (P != 0);

	return 0;
}

void leitura(tLivro vetor[TAM], int n)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s %d\n", vetor[i].titulo, vetor[i].autor, &vetor[i].ano);
	}
}

void listagem(tLivro vetor[TAM], int n, int P){
	for (int i = 0; i < n; i++)
	{
		if (vetor[i].ano < P)
		{
			printf("Título: %s - Autor: %s - Ano: %d\n", vetor[i].titulo, vetor[i].autor, vetor[i].ano);
		}
		
	}
	
}