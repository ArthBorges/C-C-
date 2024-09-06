#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int valor;
    struct cel *prox;
} celula;

void insere_inicio(celula **lista, int num)
{
    celula *novo = malloc(sizeof(celula));

    if (novo)
    {
        novo->valor = num;
        novo->prox = *lista;
        *lista = novo;
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
}

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

void insere_meio(celula **lista, int num, int ant)
{
    celula *aux, *novo = malloc(sizeof(celula));

    if (novo)
    {
        novo->valor = num;
        // a lista é vazia?
        if (*lista == NULL)
        {
            novo->prox = NULL;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->valor != ant && aux->prox)
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

void remove_numero(celula **lista, int num) //remove o primeiro elemento encontrado apenas
{
    celula *aux, *remover = NULL;

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

celula *busca_numero(celula **lista, int num)
{
    celula *aux, *busca = NULL;
    aux = *lista;

    while (aux && aux->valor != num)
    {
        aux = aux->prox;
    }
    if (aux)
    {
        busca = aux;
    }
    return busca;
}

void imprime_lista(celula *cel)
{
    printf("\n\tLista: ");
    while (cel)
    {
        printf("%d ", cel->valor);
        cel = cel->prox;
    }
    printf("\n\n");
}

int main()
{
    int num, op, ant;
    celula *busca, *lista = NULL;

    do
    {
        printf("\n\n1 - Inserir numero no final da lista");
        printf("\n2 - Inserir numero no inicio da lista");
        printf("\n3 - Inserir numero no meio da lista");
        printf("\n4 - Remover da lista");
        printf("\n5 - Imprimir lista");
        printf("\n6 - Buscar na lista");
        printf("\n7 - Sair");
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
            printf("Digite o valor a ser inserido:\n");
            scanf("%d", &num);
            insere_inicio(&lista, num);
        }
        else if (op == 3)
        {
            printf("Digite o valor a ser inserido e o valor de referencia:\n");
            scanf("%d %d", &num, &ant);
            insere_meio(&lista, num, ant);
        }

        else if (op == 4)
        {
            printf("Digite o valor a ser removido:\n");
            scanf("%d", &num);
            remove_numero(&lista, num);
        }
        else if (op == 5)
        {
            imprime_lista(lista);
        }
        else if (op == 6)
        {
            printf("Digite o valor a ser buscado:\n");
            scanf("%d", &num);
            busca = busca_numero(&lista, num);
            if (busca)
            {
                printf("Elemento encontrado!\n");
            }
            else
            {
                printf("Elemento nao encontrado!\n");
            }
        }
    } while (op != 7);

    free(lista);

    return 0; 
}
