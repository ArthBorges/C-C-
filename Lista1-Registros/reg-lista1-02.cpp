// ex: contatos.cpp
#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_NOME 30
#define MAX_NUM 20

struct TipoContato
{
    char nome[MAX_NOME];
    char telefone[MAX_NUM];
};

void menu();
void AdicionarContato(int &n, TipoContato contatos[MAX]);
void RemoveContato(TipoContato contatos[], int &n);
void ListaContatos(TipoContato contatos[MAX], int n);

int main()
{
    int n, opcao;
    TipoContato contatos[MAX];

    printf("Digite a quantidade de contatos\n");
    scanf("%d", &n);

    do
    {
        menu();
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            AdicionarContato(n, contatos);
        }
        else if (opcao == 2)
        {
            RemoveContato(contatos, n);
        }
        else if (opcao == 3)
        {
            ListaContatos(contatos, n);
        }
    } while (opcao != 4);
    return 0;
}

void menu()
{
    printf("\n[1] Adicionar contato\n");
    printf("[2] Remover contato\n");
    printf("[3] Lista contatos\n");
    printf("[4] Sair\n");
}

void AdicionarContato(int &n, TipoContato contatos[MAX])
{
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (cont == n)
        {
            printf("A lista de contatos está cheia.\n");
            break;
        }
        else
        {
            printf("Nome e Num do contato:\n");
            scanf("%s %s", contatos[i].nome, contatos[i].telefone);
        }
        cont++;
    }
}

void RemoveContato(TipoContato contatos[], int &n)
{
    char nome_remover[MAX_NOME];
    int indice_nome = -1;

    printf("Digite o nome do contato a ser removido: ");
    scanf("%s", nome_remover);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(contatos[i].nome, nome_remover) == 0)
        {
            indice_nome = i;
            break;
        }
    }

    if (indice_nome != -1)
    {
        for (int i = indice_nome; i < n - 1; i++)
        {
            contatos[i] = contatos[i + 1];
        }
        n--;
        printf("Contato removido!\n");
    }
    else
    {
        printf("ERRO: Contato não encontrado.\n");
    }
}

void ListaContatos(TipoContato contatos[MAX], int n)
{
    printf("Lista de Contatos:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Nome: %s\nTelefone: %s\n", contatos[i].nome, contatos[i].telefone);
    }
}