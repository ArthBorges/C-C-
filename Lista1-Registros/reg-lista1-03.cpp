// ex: sistema_academico.cpp

#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_ALUNO 7
#define MAX_CURSO 5

struct tipoCurso
{
    char nome[MAX];
    int codigo;
};

struct tipoAluno
{
    int RGA;
    char nome[MAX];
    int codcurso;
};

void BuscaCurso(tipoCurso cursos[MAX_CURSO], tipoAluno alunos[MAX_ALUNO], int RGA, int qtd_cursos, int qtd_alunos);

int main()
{
    tipoCurso cursos[MAX_CURSO];
    cursos[0].codigo = 1;
    strcpy(cursos[0].nome, "Engenharia de Computação");
    cursos[1].codigo = 2;
    strcpy(cursos[1].nome, "Ciência da Computação");
    cursos[2].codigo = 3;
    strcpy(cursos[2].nome, "Engenharia de Software");
    cursos[3].codigo = 4;
    strcpy(cursos[3].nome, "Engenharia Mecânica");
    cursos[4].codigo = 5;
    strcpy(cursos[4].nome, "Administração");

    tipoAluno alunos[MAX_ALUNO];
    alunos[0].RGA = 1001;
    strcpy(alunos[0].nome, "Arthur");
    alunos[0].codcurso = 1;
    alunos[1].RGA = 1002;
    strcpy(alunos[1].nome, "Gabi");
    alunos[1].codcurso = 2;
    alunos[2].RGA = 1003;
    strcpy(alunos[2].nome, "Lucas");
    alunos[2].codcurso = 1;
    alunos[3].RGA = 1004;
    strcpy(alunos[3].nome, "Analice");
    alunos[3].codcurso = 3;
    alunos[4].RGA = 1005;
    strcpy(alunos[4].nome, "Gustavo");
    alunos[4].codcurso = 2;
    alunos[5].RGA = 1006;
    strcpy(alunos[5].nome, "Karen");
    alunos[5].codcurso = 4;
    alunos[6].RGA = 1007;
    strcpy(alunos[6].nome, "Nathalia");
    alunos[6].codcurso = 5;

    int RGA;
    printf("Informe o RGA do aluno:\n");
    scanf("%d", &RGA);

    BuscaCurso(cursos, alunos, RGA, MAX_CURSO, MAX_ALUNO);
    return 0;
}

void BuscaCurso(tipoCurso cursos[MAX_CURSO], tipoAluno alunos[MAX_ALUNO], int RGA, int qtd_cursos, int qtd_alunos)
{
    for (int i = 0; i < qtd_alunos; i++)
    {
        if (RGA == alunos[i].RGA)
        {
            for (int j = 0; j < qtd_cursos; j++)
            {
                if (cursos[j].codigo == alunos[i].codcurso)
                {
                    printf("O aluno de RGA %d está matriculado no curso de %s", RGA, cursos[i].nome);
                    return;
                }
            }
        }
    }
    printf("Aluno não encontrado!\n");
}