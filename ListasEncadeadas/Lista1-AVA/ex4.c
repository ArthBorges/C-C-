//Escreva uma função para determinar a quantidade de c´elulas de uma lista p.

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

void conta_celulas(celula *lista){
    int cont=0;
    while (lista)
    {
        cont++;
        lista = lista->prox;
    }
    printf("A lista possui %d celulas!", cont);
}

void imprime_lista(celula *lista){
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
    int num;

    scanf("%d", &num);
    while (num != -1)
    {
        insere_num(&p, num);
        scanf("%d", &num);
    }

    imprime_lista(p);
    conta_celulas(p);
    free(p);
    
    return 0;
}
