// Escreva uma função para imprimir as chaves de uma lista p

void imprime_chaves(celula *lista)
{
    printf("\nLista: ");
    while (lista)
    {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n\n");
}
