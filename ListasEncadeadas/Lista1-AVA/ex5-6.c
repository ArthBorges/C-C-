// 5 - Escreva uma função para retornar SIM, caso uma chave x exista em uma lista encadeada p ou NAO caso contrári
// 6 - Escreva uma função para retornar o ponteiro que aponta para a primeira ocorrência de uma chave
// x, caso esta exista em uma lista encadeada p ou NULL caso contrário.

#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int valor;
    struct cel *prox;
} celula;

void insere_num(celula **lista, int num)
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

void conta_celulas(celula *lista)
{
    int cont = 0;
    while (lista)
    {
        cont++;
        lista = lista->prox;
    }
    printf("A lista possui %d celulas!", cont);
}

int busca_numero(celula **lista, int num)
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

    if (busca)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

celula *busca_primeira_ocorrencia(celula **lista, int num)
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
    celula *ocorrencia, *p = NULL;
    int num;

    scanf("%d", &num);
    while (num != -1)
    {
        insere_num(&p, num);
        scanf("%d", &num);
    }
    // imprime_lista(p);

    printf("\nDigite o numero a ser buscado: ");
    scanf("%d", &num);

    if (busca_numero(&p, num))
    {
        printf("SIM\n");
    }
    else
    {
        printf("NAO\n");
    }

    ocorrencia = busca_primeira_ocorrencia(&p, num);
    printf("%d\n", ocorrencia->valor);

    free(p);

    return 0;
}