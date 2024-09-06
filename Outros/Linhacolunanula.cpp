#include <stdio.h>

#define MAX 100

void LeMatriz(int n, int m, int M[MAX][MAX])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }
}

int ContaLinhasNulas(int n, int m, int M[MAX][MAX])
{
    int cont = 0, i, j;
    bool verifica = true;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (M[i][j] == 0)
            {
                verifica = true;
            }
            else
            {
                verifica = false;
                break;
            }
        }
        if (verifica == true)
        {
            cont += 1;
        }
    }
    return cont;
}

void ContaColunasNulas(int n, int m, int M[MAX][MAX], int &conta_c)
{
    int i, j;
    bool verifica = true;

    for (j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (M[i][j] == 0)
            {
                verifica = true;
            }
            else
            {
                verifica = false;
                break;
            }
        }
        if (verifica == true)
        {
            conta_c += 1;
        }
    }
}

int main()
{
    int m, n, conta_c = 0, linhas_null;
    int M[MAX][MAX];

    scanf("%d%d", &n, &m);
    LeMatriz(n, m, M);
    linhas_null = ContaLinhasNulas(n, m, M);
    ContaColunasNulas(n, m, M, conta_c);

    printf("Linhas nulas = %d\nColunas nulas = %d\n", linhas_null, conta_c);

    return 0;
}
