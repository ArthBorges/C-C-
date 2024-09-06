#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, M[10][10], i, j;
    char nome_arq_in[30];
    FILE *pt_arqin;

    printf("Digite o nome do arquivo de entrada: \n");
    scanf("%s", nome_arq_in);

    pt_arqin = fopen(nome_arq_in, "r");

    if(pt_arqin == NULL){
        printf("Erro ao abrir arquivo!\n");
        return 0;
    }

    fscanf(pt_arqin, "%d %d", &m, &n);

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            fscanf(pt_arqin, "%d", &M[i][j]);

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }

    fclose(pt_arqin);
    
    return 0;
}
