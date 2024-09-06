/*
3. Escreva a função Enfileira() que recebe um ponteiro p para a fila e um inteiro k a ser enfileirado.
4. Escreva a função Desenfileira() que recebe um ponteiro p para a fila e remove o primeiro elemento
da fila. O elemento desenfileirado deve ser retornado pela função.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int valor;
    struct cel *prox;
} Fila;

void Enfileira(Fila **p, int num)
{
    Fila *aux, *novo = malloc(sizeof(Fila));
    if (novo)
    {
        novo->valor = num;
        novo->prox = NULL;

        if (*p == NULL)
            *p = novo;
        else
        {
            aux = *p;
            while (aux->prox)
                aux = aux->prox;
            aux->prox = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
}

Fila *Desenfileira(Fila **p)
{
    Fila *remover = NULL;
    if (*p)
    {
        remover = *p;
        *p = remover->prox;
    }
    else
    {
        printf("Fila vazia!\n");
    }
    return remover;
}

void Imprime(Fila *p)
{
    printf("Fila\n");
    while (p)
    {
        printf("%d  ", p->valor);
        p = p->prox;
    }
    printf("\nFim da Fila\n");
}

int main()
{
    int num, op;
    Fila *removido, *fila = NULL;

    do
    {
        printf("\n1 - Enfileirar\n2 - Desenfileirar\n3 - Imprimir\n4 - EXIT\nOpcao: ");
        scanf("%d", &op);
        if (op == 1)
        {
            printf("\nDigite o num para Enfileirar: ");
            scanf("%d", &num);
            Enfileira(&fila, num);
        }
        else if (op == 2)
        {
            removido = Desenfileira(&fila);
            if (removido)
                printf("Elemento %d removido da fila!\n", removido->valor);
            free(removido);
        }
        else if (op == 3)
        {
            Imprime(fila);
        }
    } while (op != 4);

    free(fila);

    return 0;
}
