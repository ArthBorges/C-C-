#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int valor;
    struct cel *prox;
} Celula;

void inserir_fila(Celula **fila, int num)
{
    Celula *aux, *novo = malloc(sizeof(Celula));
    if (novo)
    {
        novo->valor = num;
        novo->prox = NULL;
        if (*fila == NULL)
            *fila = novo;
        else
        {
            aux = *fila;
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

Celula *remover_fila(Celula **fila)
{
    Celula *remover = NULL;

    if (*fila)
    {
        remover = *fila;
        *fila = remover->prox;
    }
    else
        printf("Fila vazia!\n");

    return remover;
}

void imprime_fila(Celula *fila){
    printf("\nFILA:\n");
    while(fila){
        printf("%d ", fila->valor);
        fila = fila->prox;
    }
    printf("\nFim da FILA\n");
}

int main()
{
    int num, op;
    Celula *removido, *fila = NULL;

    do
    {
        printf("\n1 - Inserir na fila\n2 - Remover da fila\n3 - Imprimir fila\n4- Sair\nOpcao: ");
        scanf("%d", &op);

        if (op == 1)
        {
            printf("\nDigite um nro para inserir na fila: \n");
            scanf("%d", &num);
            inserir_fila(&fila, num);
        }
        else if (op == 2)
        {
            removido = remover_fila(&fila);
            if (removido)
                printf("Elemento %d removido da fila!\n", removido->valor);
            free(removido);
        }
        else if (op == 3)
        {
            imprime_fila(fila);
        }
    } while (op != 4);

    free(fila);
    return 0;
}