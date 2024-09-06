// Matrícula, turma e nota
#include <stdio.h>

int main()
{
    int mat;
    char turma[3];
    float nota;
    scanf("%d %s %f", &mat, turma, &nota);
    printf("O estudante de matrícula %d da turma %s tem nota %.1f\n", mat, turma, nota);
    return 0;
}
