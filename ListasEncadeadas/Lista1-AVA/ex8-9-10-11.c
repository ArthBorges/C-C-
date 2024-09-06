/*
8 - Escreva uma função para inserir no início da lista encadeada p uma célula de chave x.
9 - Escreva uma função para inserir no final da lista encadeada p uma célula de chave x.
10 - Escreva uma função para inserir uma célula de chave x, antes da chave y, caso esta exista na lista.
Se y não existir, faça a inserção no final da lista.
11 - Escreva uma função para inserir uma célula de chave x, depois da chave y, caso esta exista na lista.
Se y não existir, faça a inserção no final da lista.
*/

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
}

void insere_final(celula **lista, int num)
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

void insere_antes(celula **lista, int num, int ref) //NÃO TA COLOCANDO NO FINAL CASO NÃO ACHE O VALOR DE REFERENCIA
{
    celula *ant, *aux, *novo = malloc(sizeof(celula));

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
            ant = NULL;
            while (aux->valor != ref && aux)
            {
                ant = aux;
                aux = aux->prox;
            }

            if (aux)
            {
                novo->prox = aux;
                if (ant)
                {
                    ant->prox = novo;
                }
                else
                {
                    *lista = novo;
                }
            }
            else
            {
                ant->prox = novo;
            }
        }
    }
}

void insere_depois(celula **lista, int num, int ref)
{
    celula *aux, *novo = malloc(sizeof(celula));

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
            while (aux->valor != ref && aux->prox)
            {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
}

void imprime_lista(celula *lista)
{
    printf("\nLista: ");
    while (lista)
    {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n\n");
}

int main()
{
    celula *p = NULL;
    int num, op, ref;

    do
    {
        printf("\n1 - InsereInicio\n2 - InsereFinal\n3 - InsereAntes\n4 - InsereDepois\n5 - ImprimirLista\n6 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            scanf("%d", &num);
            insere_inicio(&p, num);
            break;
        case 2:
            scanf("%d", &num);
            insere_final(&p, num);
            break;
        case 3:
            printf("\nInforme o numero a ser inserido e o valor de referencia: \n");
            scanf("%d %d", &num, &ref);
            insere_antes(&p, num, ref);
            break;
        case 4:
            printf("\nInforme o numero a ser inserido e o valor de referencia: \n");
            scanf("%d %d", &num, &ref);
            insere_depois(&p, num, ref);
            break;
        case 5:
            imprime_lista(p);
            break;
        default:
            break;
        }
    } while (op != 6);

    free(p);

    return 0;
}