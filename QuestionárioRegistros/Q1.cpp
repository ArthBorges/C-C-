#include <stdio.h>

#define MAX_LETRAS 60
#define MAX_COMP 5

struct tipoData
{
    int dia;
    int mes;
    int ano;
};

struct Tarefas
{
    char compromisso[MAX_LETRAS];
    tipoData data;
};

int main()
{
    Tarefas afazeres[MAX_COMP];
    tipoData pesq_data;

    for (int i = 0; i < MAX_COMP; i++)
    {
        scanf("%s", afazeres[i].compromisso);
        scanf("%d/%d/%d", &afazeres[i].data.dia, &afazeres[i].data.mes, &afazeres[i].data.ano);
    }

    scanf("%d/%d", &pesq_data.mes, &pesq_data.ano);
    while (pesq_data.mes != 0 && pesq_data.ano != 0)
    {
        for (int i = 0; i < MAX_COMP; i++)
        {
            if (afazeres[i].data.mes == pesq_data.mes && afazeres[i].data.ano == pesq_data.ano)
            {
                printf("%s\n", afazeres[i].compromisso);
            }
        }
        scanf("%d/%d", &pesq_data.mes, &pesq_data.ano);
    }

    return 0;
}
