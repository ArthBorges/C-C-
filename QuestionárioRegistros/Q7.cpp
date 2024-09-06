#include <stdio.h>

#define MAX_NOME 30

struct tProduto
{
    int codigo;
    char nome[MAX_NOME];
    float preco;
};

void Cadastro(tProduto prod[10], int i);
void Imprime(tProduto prod[10], int i);
int Busca(tProduto prod[10], int n, int codigo);

int main()
{
    int n, i, busca_cod, val;
    tProduto produtos[10];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        Cadastro(produtos, i);
    }

    Imprime(produtos, i);
    scanf("%d", &busca_cod);
    val = Busca(produtos, n, busca_cod);

    if (val == 1)
    {
        printf("Inexistente");
    }

    return 0;
}

void Cadastro(tProduto prod[10], int i)
{
    scanf("%d %s %f", &prod[i].codigo, prod[i].nome, &prod[i].preco);
}

void Imprime(tProduto prod[10], int i)
{
    printf("LISTAGEM\n");
    for (int j = 0; j < i; j++)
    {
        printf("%d %s\n", prod[j].codigo, prod[j].nome);
    }
}

int Busca(tProduto prod[10], int n, int codigo)
{
    for (int i = 0; i < n; i++)
    {
        if (prod[i].codigo == codigo)
        {
            printf("Preço: R$ %.2f\n", prod[i].preco);
            return 0;
        }
    }

    return 1;
}