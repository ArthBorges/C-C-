#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int valor;
    struct pilha *prox;
} Pilha;

Pilha *empilhar(Pilha *p, int num)
{
    Pilha *novo = malloc(sizeof(Pilha));
    if (novo)
    {
        novo->valor = num;
        novo->prox = p;
        return novo;
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
    return NULL;
}

Pilha *desempilhar(Pilha **p)
{
    Pilha *remover = NULL;
    if (*p)
    {
        remover = *p;
        *p = remover->prox;
        return remover;
    }
    else
    {
        printf("Pilha vazia!\n");
    }
    return remover;
}

void imprimir(Pilha *p)
{
    printf("PILHA -------------\n");
    while (p)
    {
        printf("\t%d\n", p->valor);
        p = p->prox;
    }
    printf("Fim da PILHA ------\n");
}

int main()
{
    int num, op;
    Pilha *removido, *pilha = NULL;

    do
    {
        printf("\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n4 - Sair\nOpcao: ");
        scanf("%d", &op);
        if (op == 1)
        {
            printf("\nDigite o nro para Empilhar: ");
            scanf("%d", &num);
            pilha = empilhar(pilha, num);
        }
        else if (op == 2)
        {
            removido = desempilhar(&pilha);
            if (removido)
            {
                printf("O nro %d foi removido!\n", removido->valor);
            }
            free(removido);
        }
        else if (op == 3)
        {
            imprimir(pilha);
        }

    } while (op != 4);

    free(pilha);
    return 0;
}