/*Faça um código em C que apresente o seguinte menu de opções para o usuário:
i) Empilha( ) → função que recebe um inteiro e o topo de uma pilha e
empilha o elemento dado.
ii) Desempilha( ) → função que recebe o topo de uma pilha, desempilha o
elemento do topo da pila e retorna o elemento desempilhado. Este
elemento deve ser impresso na main ou a informação "pilha" vazia deve
ser impressa.
iii) Conta( ) → função que recebe o topo da pilha e retorna a quantidade de
elementos empilhados
iv) ImprimeA( ) → função que recebe o topo da pilha e imprime seus
elementos (o primeiro elemento a ser impresso é o primeiro elemento da
pilha)
v) ImprimeB( ) → função que recebe o topo da pilha e imprime seus
elementos (o primeiro elemento a ser impresso é o último elemento da
pilha)
vi) Reverse( ) → função que recebe uma pilha e altera a mesma, de modo
que a pilha resultante seja a inversa da pilha recebida*/

#include <stdio.h>
#include <stdlib.h>

typedef struct pil
{
    int num;
    struct pil *prox;
} Pilha;

Pilha *Empilha(int num, Pilha *topo)
{
    Pilha *novo = malloc(sizeof(Pilha));
    if (novo)
    {
        novo->num = num;
        novo->prox = topo;
        return novo;
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
    return NULL;
}

Pilha *Desempilha(Pilha **topo)
{
    Pilha *remover = NULL;

    if (*topo)
    {
        remover = *topo;
        *topo = remover->prox;
    }
    else
        printf("Pilha vazia!\n");

    return remover;
}

int Conta(Pilha *topo)
{
    int cont = 0;
    while (topo)
    {
        cont++;
        topo = topo->prox;
    }
    return cont;
}

void ImprimeA(Pilha *pilha)
{
    printf("\n------Pilha-----\n");
    while (pilha)
    {
        printf("\t%d\n", pilha->num);
        pilha = pilha->prox;
    }
    printf("\n--Fim da Pilha--\n");
}

void ImprimeB(Pilha *pilha)
{
    if (pilha)
    {
        ImprimeB(pilha->prox);
        printf("\t%d\n", pilha->num);
    }
}

void Reverse(Pilha **topo){
    Pilha *ant = NULL, *prox = NULL, *atual = *topo;

    while(atual){
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    *topo = ant;
    printf("A pilha foi invertida!\n");
}

int main()
{
    int num, op;
    Pilha *removido, *pilha = NULL;

    do
    {
        printf("\n1 - Empilha\n2 - Desempilha\n3 - Conta\n4 - Imprime A\n5 - Imprime B\n6 - Reverse\n7 - Exit\nOpcao: \n");
        scanf("%d", &op);

        if (op == 1)
        {
            printf("Digite um numero para empilhar:\n");
            scanf("%d", &num);
            pilha = Empilha(num, pilha);
        }
        else if (op == 2)
        {
            removido = Desempilha(&pilha);
            if (removido)
                printf("O elemento %d foi removido da pilha!\n", removido->num);
            free(removido);
        }
        else if (op == 3)
        {
            num = Conta(pilha);
            printf("A pilha contem %d elementos empilhados!\n", num);
        }
        else if (op == 4)
        {
            ImprimeA(pilha);
        }
        else if (op == 5)
        {
            ImprimeB(pilha);
        }
        else if (op == 6)
        {
            Reverse(&pilha);
        }
    } while (op != 7);
    return 0;
}