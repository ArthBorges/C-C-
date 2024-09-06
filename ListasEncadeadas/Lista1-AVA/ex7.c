//Escreva uma função para retornar a quantidade de ocorrências de uma chave x em uma lista encadeada p.

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

int conta_ocorrencia(celula **lista, int num)
{
    celula *aux = NULL;
    aux = *lista;
    int cont=0;

    while (aux)
    {
        if (aux->valor == num)
        {
            cont++;
        }      
        aux = aux->prox;
    }
    return cont;
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
    int num, cont;

    scanf("%d", &num);
    while (num != -1)
    {
        insere_num(&p, num);
        scanf("%d", &num);
    }
    // imprime_lista(p);

    printf("\nDigite o numero a ser verificado: ");
    scanf("%d", &num);

    cont = conta_ocorrencia(&p, num);
    printf("O valor %d tem %d ocorrencias na lista!", num, cont);

    free(p);

    return 0;
}