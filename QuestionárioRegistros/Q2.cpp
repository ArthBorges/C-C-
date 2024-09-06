#include <stdio.h>
#include <string.h>

#define MAX 30

struct tAluno
{
    int mat;
    char nome[MAX];
    char curso[MAX];
};

int main()
{
    tAluno alunos[5];
    char nome_curso[MAX];

    for (int i = 0; i < 5; i++)
    {
        scanf("%d\n %[^\n]\n %[^\n]", &alunos[i].mat, alunos[i].nome, alunos[i].curso);
    }
    
    scanf(" %[^\n]", nome_curso);

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(alunos[i].curso, nome_curso) == 0)
        {
            printf("%d %s\n", alunos[i].mat, alunos[i].nome);
        }        
    }
    return 0;
}
