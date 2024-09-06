#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int valor;
    struct cel *prox;
} Celula;

void insere_ord(Celula **lista, int num)
{
    Celula *aux, *novo = malloc(sizeof(Celula));

    if (novo)
    {
        novo->valor = num;

        if (*lista == NULL)
        {
            novo->prox = NULL;
            *lista = novo;
        }
        else if (novo->valor < (*lista)->valor)
        {
            novo->prox = *lista;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->prox && novo->valor > aux->prox->valor)
            {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
}

void insere_depois(Celula **lista, int num, int ant)
{
    Celula *aux, *novo = malloc(sizeof(Celula));

    if (novo)
    {
        novo->valor = num;
        if (*lista == NULL)
        {
            novo->prox = NULL;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->prox && aux->valor != ant)
            {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
}

void insere_antes(Celula **lista, int num, int ant)
{
    Celula *aux, *novo = malloc(sizeof(Celula));

    if (novo)
    {
        novo->valor = num;
        if (*lista == NULL)
        {
            novo->prox = NULL;
            *lista = novo;
        }
        else if (novo->valor < (*lista)->valor)
        {
            novo->prox = *lista;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->prox && aux->prox->valor != ant)
            {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
}

Celula *remove_num(Celula **lista, int num)
{
    Celula *aux, *remover = NULL;

    if (*lista)
    {
        if ((*lista)->valor == num)
        {
            remover = *lista;
            *lista = remover->prox;
        }
        else
        {
            aux = *lista;
            while (aux->prox && aux->prox->valor != num)
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
    
    return remover;
}

void imprime(Celula *lista)
{
    printf("\nLista:\n");
    while (lista)
    {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n");
}

int main()
{
    int num, op, ref;
    Celula *removido, *lista = NULL;

    do
    {
        printf("\n0 - Exit\n1 - Inserir Ordenado\n2 - Inserir Antes\n3 - Inserir Depois\n4 - Remover Primeiro\n5 - Remover Todos\n6 - Imprimir\nOpcao: ");
        scanf("%d", &op);

        if (op == 1)
        {
            printf("Digite o valor a ser inserido: \n");
            scanf("%d", &num);
            insere_ord(&lista, num);
        }
        else if (op == 2)
        {
            printf("Digite o valor a ser inserido e o valor de referencia: \n");
            scanf("%d %d", &num, &ref);
            insere_antes(&lista, num, ref);
        }
        else if (op == 3)
        {
            printf("Digite o valor a ser inserido e o valor de referencia: \n");
            scanf("%d %d", &num, &ref);
            insere_depois(&lista, num, ref);
        }
        else if (op == 4)
        {
            printf("Digite o valor a ser removido: \n");
            scanf("%d", &num);
            removido = remove_num(&lista, num);
            if (removido)
            {
                printf("Elemento %d removido!\n", removido->valor);
                free(removido);
            }
        }
        else if (op == 5)
        {
            printf("Digite o valor a ser removido: \n");
            scanf("%d", &num);

            while (removido)
                removido = remove_num(&lista, num);
            printf("Elementos removidos!\n");
        }
        else if (op == 6)
        {
            imprime(lista);
        }
    } while (op != 0);

    free(lista);

    return 0;
}