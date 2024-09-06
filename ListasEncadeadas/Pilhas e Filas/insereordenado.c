#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int valor;
    struct cel *prox;
} celula;

void insere_ordenado(celula **lista, int num)
{
    celula *aux, *novo = malloc(sizeof(celula));

    if (novo)
    {
        novo->valor = num;
        // lista está vazia?
        if (*lista == NULL)
        {
            novo->prox = NULL;
            *lista = novo;
        }
        // novo é o menor?
        else if (novo->valor < (*lista)->valor) // verifica se o novo elemento q estou inserindo é menor q o primeiro elemento da lista
        {
            novo->prox = *lista;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->prox && novo->valor > aux->prox->valor) // compara o valor de novo enquanto aux->prox for diferente de null e aux->prox->valor for menor que o valor de novo
            // o loop para quando aux->prox é null ou quando o valor de aux->prox é maior que o valor de novo
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
    int num, op;
    celula *lista = NULL;

    do
    {
        printf("\n0 - Sair\n1 - Inserir ordenadamente\n2 - Imprimir lista\n\nOpcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Digite o valor:\n");
            scanf("%d", &num);
            insere_ordenado(&lista, num);
            break;
        case 2:
            imprime_lista(lista);
            break;
        default:
            if (op != 0)
            {
                printf("Opcao invalida!\n");
            }
        }
    } while (op != 0);

    free(lista);

    return 0;
}
