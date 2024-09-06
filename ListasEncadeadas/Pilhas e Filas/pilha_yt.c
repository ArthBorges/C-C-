#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int valor;
    struct cel *prox;
} celula;

celula *empilha(celula *topo, int num)
{
    celula *novo = malloc(sizeof(celula));

    if (novo)
    {
        novo->valor = num;
        novo->prox = topo;
        return novo;
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
    return NULL;
}

celula *desempilhar(celula **topo)
{
    celula *remover = NULL;

    if (*topo)
    {
        remover = *topo;
        *topo = remover->prox;
        return remover;
    }
    else
    {
        printf("Pilha vazia!\n");
    }
    return NULL;
}

void imprime_pilha(celula *topo)
{
    printf("\n------- Pilha ------\n");
    while (topo)
    {
        printf("%d\n", topo->valor);
        topo = topo->prox;
    }
    printf("\n--- Fim da Pilha ---\n");
}

int main()
{
    int num, op;
    celula *remover, *topo = NULL;

    do
    {
        printf("\n\n1 - Empilhar");
        printf("\n2 - Desempilhar");
        printf("\n3 - Imprimir pilha");
        printf("\n4 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &op);

        if (op == 1)
        {
            printf("Digite o valor a ser empilhado:\n");
            scanf("%d", &num);
            topo = empilha(topo, num);
        }
        else if (op == 2)
        {
            remover = desempilhar(&topo);
            if (remover)
            {
                printf("Elemento %d removido\n", remover->valor);
                free(remover);
            }
            else
            {
                printf("Nenhum elemento encontrado!\n");
            }
        }
        else if (op == 3)
        {
            imprime_pilha(topo);
        }

    } while (op != 4);

    free(topo);

    return 0;
}