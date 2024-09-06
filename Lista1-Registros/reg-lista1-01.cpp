// ex: media.cpp
#include <stdio.h>

struct TipoAluno
{
    float p1;
    float p2;
    float p3;
};

void LeNotas(TipoAluno &notas)
{
    printf("Informe as notas:\n");
    scanf("%f%f%f", &notas.p1, &notas.p2, &notas.p3);
}

int main()
{
    float media;
    TipoAluno notas;
    LeNotas(notas);

    media = ((notas.p1 * 2 + notas.p2 * 3 + notas.p3 * 4) / 9);
    printf("A média do aluno é: %.2f\n", media);

    return 0;
}
