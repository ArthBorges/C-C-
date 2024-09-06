// Escreva uma função para ler 5 valores e armazenar em uma lista p

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

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &num);
        insere_num(&p, num);
    }
    imprime_lista(p);
    free(p);
    
    return 0;
}
