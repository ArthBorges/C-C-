#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int valor;
    struct cel *prox;
} celula;

typedef struct lista
{
    celula *inicio;
    int tam;
} Lista;

void cria_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}

void insere_inicio(Lista *lista, int num)
{
    celula *novo = malloc(sizeof(celula));

    if (novo)
    {
        novo->valor = num;
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
}

void insere_fim(Lista *lista, int num)
{
    celula *aux, *novo = malloc(sizeof(celula));

    if (novo)
    {
        novo->valor = num;
        novo->prox = NULL;

        if (lista->inicio == NULL)
        {
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            while (aux->prox)
            {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
}

void insere_meio(Lista *lista, int num, int ant)
{
    celula *aux, *novo = malloc(sizeof(celula));

    if (novo)
    {
        novo->valor = num;
        // a lista é vazia?
        if (lista->inicio == NULL)
        {
            novo->prox = NULL;
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            while (aux->valor != ant && aux->prox)
            {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
}

celula *remove_numero(Lista *lista, int num)
{
    celula *aux, *remove = NULL;

    if (lista->inicio)
    {
        if (lista->inicio->valor = num)
        {
            remove = lista->inicio;
            lista->inicio = remove->prox;
            lista->tam--;
        }
        else
        {
            aux = lista->inicio;
            while (aux->prox && aux->prox->valor != num)
            {
                aux = aux->prox;
            }
            if (aux->prox)
            {
                remove = aux->prox;
                aux->prox = remove->prox;
                lista->tam--;
            }
        }
    }
    return remove;
}

celula* busca_numero(Lista *lista, int num){
    celula *aux, *busca = NULL;

    aux = lista->inicio;

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

void imprime_lista(Lista lista)
{
    celula *cel = lista.inicio;
    printf("\n\tLista tam %d: ", lista.tam);
    while (cel)
    {
        printf("%d ", cel->valor);
        cel = cel->prox;
    }
    printf("\n\n");
}

void apaga_lista(Lista *lista)
{
    free(lista->inicio);
}

int main()
{
    int num, op, ant;
    celula *retorno;
    // celula *lista = NULL;
    Lista lista;
    cria_lista(&lista);

    do
    {
        printf("\n\n1 - Inserir numero no inicio da lista");
        printf("\n2 - Inserir numero no final da lista");
        printf("\n3 - Inserir numero no meio da lista");
        printf("\n4 - Remover da lista");
        printf("\n5 - Imprimir lista");
        printf("\n6 - Imprimir lista");
        printf("\n7 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &op);

        if (op == 1)
        {
            printf("Digite o valor a ser inserido:\n");
            scanf("%d", &num);
            insere_inicio(&lista, num);
        }
        else if (op == 2)
        {
            printf("Digite o valor a ser inserido:\n");
            scanf("%d", &num);
            insere_fim(&lista, num);
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
            retorno = remove_numero(&lista, num);

            if (retorno)
            {
                printf("Elemento %d removido!\n", retorno->valor);
            }
            else
            {
                printf("Elemento inexistente!\n");
            }
            free(retorno);
        }
        else if (op == 5)
        {
            imprime_lista(lista);
        }
        else if (op == 6)
        {
            printf("Digite o valor a ser buscado:\n");
            scanf("%d", &num);
            retorno = busca_numero(&lista, num);
            if (retorno)
            {
                printf("Elemento %d encontrado!\n", retorno->valor);
            }
            else
            {
                printf("Elemento nao encontrado!\n");
            }
        }
    } while (op != 7);

    apaga_lista(&lista);

    return 0;
}
