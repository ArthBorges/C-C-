#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int valor;
    struct cel *prox;
} celula;

typedef struct pil
{
    celula *topo;
    int tam;
} Pilha;

void criar_pilha(Pilha *p)
{
    p->topo = NULL;
    p->tam = 0;
}

void empilha(Pilha *p, int num)
{
    celula *novo = malloc(sizeof(celula));

    if (novo)
    {
        novo->valor = num;
        novo->prox = p->topo;
        p->topo = novo;
        p->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
}

celula *desempilhar(Pilha *p)
{
    celula *remover = NULL;

    if (p->topo)
    {
        remover = p->topo;
        p->topo = remover->prox;
        p->tam--;
        return remover;
    }
    else
    {
        printf("Pilha vazia!\n");
    }
    return NULL;
}

void imprime_pilha(Pilha *p)
{
    celula *aux = p->topo;
    printf("\n----- Pilha Tam %d-----\n", p->tam);
    while (aux)
    {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
    printf("\n---- Fim da Pilha -----\n");
}

int main()
{
    int num, op;
    celula *remover;
    Pilha *p;
    criar_pilha(&p);

    do
    {
        printf("\n\n1 - Empilhar");
        printf("\n2 - Desempilhar");
        printf("\n3 - Imprimir pilha");
        printf("\n4 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &op);

        if (op == 1)
        {
            printf("Digite o valor a ser empilhado:\n");
            scanf("%d", &num);
            empilha(&p, num);
        }
        else if (op == 2)
        {
            remover = desempilhar(&p);
            if (remover)
            {
                printf("Elemento %d removido\n", remover->valor);
                free(remover);
            }
            else
            {
                printf("Nenhum elemento encontrado!\n");
            }
        }
        else if (op == 3)
        {
            imprime_pilha(&p);
        }

    } while (op != 4);

    free(p);

    return 0;
}