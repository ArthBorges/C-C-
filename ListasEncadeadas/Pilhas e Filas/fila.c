#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int valor;
    struct cel *prox;
} celula;

void insere_fim(celula **lista, int num)
{
    celula *aux, *novo = malloc(sizeof(celula));

    if (novo)
    {
        novo->valor = num;
        novo->prox = NULL;

        if (*lista == NULL)
        {
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->prox)
            {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
}

void remove_numero(celula **lista)
{
    celula *aux, *remover = NULL;

    if (*lista)
    {
        if ((*lista)->valor)
        {
            remover = *lista;
            *lista = remover->prox;
        }
        else
        {
            aux = *lista;
            while (aux->prox && aux->prox->valor)
            {
                aux = aux->prox;
            }
            if (aux->prox)
            {
                remover = aux->prox;
                aux->prox = remover->prox;
            }
        }
    }
    if (remover == NULL)
    {
        printf("O elemento nao existe!\n");
    }
    else
    {
        printf("Elemento removido!\n");
        free(remover);
    }
}

void imprime_lista(celula *cel)
{
    printf("\n\tFila: ");
    while (cel)
    {
        printf("%d ", cel->valor);
        cel = cel->prox;
    }
    printf("\n\n");
}

int main()
{
    int num, op;
    celula *lista = NULL;

    do
    {
        printf("\n\n1 - Inserir na fila");
        printf("\n2 - Remover da fila");
        printf("\n3 - Imprimir fila");
        printf("\n4 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &op);

        if (op == 1)
        {
            printf("Digite o valor a ser inserido:\n");
            scanf("%d", &num);
            insere_fim(&lista, num);
        }
        else if (op == 2)
        {
            remove_numero(&lista);
        }
        else if (op == 3)
        {
            imprime_lista(lista);
        }

    } while (op != 4);

    free(lista);

    return 0;
}