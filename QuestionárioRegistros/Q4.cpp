#include <stdio.h>

struct tipoHora
{
    int hora;
    int min;
    int seg;
};

int main()
{
    tipoHora hora_inicial, hora_final, resultado;
    int total_i = 0, total_f = 0;

    scanf("%d:%d:%d %d:%d:%d", &hora_inicial.hora, &hora_inicial.min, &hora_inicial.seg, &hora_final.hora, &hora_final.min, &hora_final.seg);

    if (hora_final.hora == 0)
    {
        hora_final.hora = 24;
    }

    total_i += hora_inicial.hora * 3600;
    total_i += hora_inicial.min * 60;
    total_i += hora_inicial.seg;

    total_f += hora_final.hora * 3600;
    total_f += hora_final.min * 60;
    total_f += hora_final.seg;

    total_f = total_f - total_i;
    if (total_f < 0)
    {
        total_f *= -1;
    }

    resultado.hora = total_f / 3600;
    resultado.min = (total_f % 3600) / 60;
    resultado.seg = total_f % 60;

    if (resultado.hora == 24)
    {
        resultado.hora = 0;
    }

    printf("%.2d:%.2d:%.2d", resultado.hora, resultado.min, resultado.seg);

    return 0;
}