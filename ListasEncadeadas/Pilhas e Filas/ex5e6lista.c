/*
5. Escreva a função Desempilha() que recebe um ponteiro p para a pilha e remove o elemento do topo
desta pilha. O elemento desempilhado deve ser retornado pela função.
6. Escreva a função Empilha() que recebe um ponteiro p para a pilha e um inteiro k a ser empilhado.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int valor;
    struct cel *prox;
} Celula;

Celula* Empilha(Celula *p, int k)
{
    Celula *novo = malloc(sizeof(Celula));
    if (novo)
    {
        novo->valor = k;
        novo->prox = p;
        return novo;
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
    return NULL;
}

Celula *Desempilha(Celula **p)
{
    Celula *remover = NULL;
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
    return NULL;
}

void Imprime(Celula *p)
{
    printf("\n-----Pilha------\n");
    while (p)
    {
        printf("      %d\n", p->valor);
        p = p->prox;
    }
    printf("--Fim da Pilha--\n");
}

int main()
{
    int num, op;
    Celula *removido, *pilha = NULL;

    do
    {
        printf("\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n4 - Sair\nOpcao: ");
        scanf("%d", &op);
        if (op == 1)
        {
            printf("Valor a ser empilhado:\n");
            scanf("%d", &num);
            pilha = Empilha(pilha, num);
        }
        else if (op == 2)
        {
            removido = Desempilha(&pilha);
            if (removido)
            {
                printf("Valor %d removido da pilha!\n", removido->valor);
                free(removido);
            }
        }
        else if (op == 3)
        {
            Imprime(pilha);
        }
    } while (op != 4);

    free(pilha);

    return 0;
}