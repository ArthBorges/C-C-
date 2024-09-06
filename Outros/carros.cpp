#include <stdio.h>
#include <string.h>

#define MAXCAR 30
#define MAX 15

struct tCarro
{
    char marca[MAX];
    int ano;
    float preco;
};

void menu();

void CadastrarCar(tCarro vetor[MAXCAR], int &c_cadastrados);

void ListaCar(tCarro vetor[MAXCAR], int c_cadastrados);

float Media(tCarro vetor[MAXCAR], int c_cadastrados, int ano);

int main()
{
    int opcao, qtd_carros, qtd_lidos = 0, ano;
    tCarro vetor[MAXCAR];
    float media;

    do
    {
        menu();
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            if (qtd_lidos < 30)
                CadastrarCar(vetor, qtd_carros);
            else
                printf("Lista Cheia!\n");
        }
        else if (opcao == 2)
        {
            ListaCar(vetor, qtd_carros);
        }
        else if (opcao == 3)
        {
            scanf("%d", &ano);
            media = Media(vetor, qtd_carros, ano);
            if (media != -1)
                printf("A media e: %.2f", media);
            else
                printf("Nao existem carros cadastrados com o ano infomado!");
        }
    } while (opcao != 4);

    return 0;
}

void menu()
{
    printf("\n[1] Cadastrar um carro\n");
    printf("[2] Listar carros\n");
    printf("[3] Media de precos de um ano\n");
    printf("Opcao: ");
}

void CadastrarCar(tCarro vetor[MAXCAR], int &c_cadastrados)
{
    scanf("%s %d %f", vetor[c_cadastrados].marca, &vetor[c_cadastrados].ano, &vetor[c_cadastrados].preco);
    c_cadastrados++;
}

void ListaCar(tCarro vetor[MAXCAR], int c_cadastrados)
{
    for (int i = 0; i < c_cadastrados; i++)
    {
        printf("%s %d %.2f\n", vetor[i].marca, vetor[i].ano, vetor[i].preco);
    }
}

float Media(tCarro vetor[MAXCAR], int c_cadastrados, int ano)
{
    float soma = 0.0;
    int cont = 0;

    for (int i = 0; i < c_cadastrados; i++)
    {
        if (vetor[i].ano == ano)
        {
            soma += vetor[i].preco;
            cont++;
        }
    }
    if (cont == 0)
        return -1;
    else
        return soma / cont;
}