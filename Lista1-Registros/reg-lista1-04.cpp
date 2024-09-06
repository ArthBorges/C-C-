#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_PROD 3
#define PRODUTOS 8
#define CLIENTES 4

struct tipoProduto
{
    char nome[MAX];
    int quantidade;
    float valor;
};

struct tipoCliente
{
    char nome[MAX];
    char lista[MAX_PROD];
};

int main()
{
    tipoProduto estoque[PRODUTOS];
    tipoCliente clientes[CLIENTES];
    for (int i = 0; i < PRODUTOS; i++)
    {
        scanf("%s %d %f\n", estoque[i].nome, &estoque[i].quantidade, &estoque[i].valor);
    }
    for (int i = 0; i < CLIENTES; i++)
    {
        scanf("%s\n", clientes[i].nome);
        for (int j = 0; j < MAX_PROD; j++)
        {
            scanf("%s", clientes[j].lista);
        }
        
    }
    
    
    return 0;
}
