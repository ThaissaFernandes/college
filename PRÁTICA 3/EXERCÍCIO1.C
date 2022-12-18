#include<stdio.h>
#include <stdlib.h>
void preencherVetor(int *numero, int n);
int buscaSequencial(int *numero, int n, int chave);
void ordena(int *numero, int n);
int buscaBinaria(int chave, int *numero, int n);

int main()
{
    int i;
    int n;
    int chave;
    int numeroEncontrado;

    printf("Digite o valor da variavel n:\n");
    scanf("%d", &n);

    int *numero = (int *)malloc(n * sizeof(int));

    preencherVetor(numero, n);

    printf("Digite o valor da chave:\n");
    scanf("%d", &chave);
    numeroEncontrado = buscaSequencial(numero, n, chave);
    if (numero[numeroEncontrado] == chave)
        printf("Numero encontrado.\n");
    else
        printf("Numero nao encontrado.\n");

    ordena(numero, n);
    numeroEncontrado = buscaBinaria(chave, numero, n);
    if (numero[numeroEncontrado] == chave)
        printf("Numero encontrado.\n");
    else
        printf("Numero nao encontrado.\n");

    return 0;
}

void preencherVetor(int *numero, int n)
{
    int i;
    printf("Preencha o vetor:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &numero[i]);
}
int buscaSequencial(int *numero, int n, int chave)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (numero[i] == chave)
            return i;
    }
    return -1;
}
void ordena(int *numero, int n)
{
    int i, j, aux;
    for (j = n - 1; j > 0; j--)
    {
        for (i = 0; i < j; i++)
        {
            if (numero[1 + i] < numero[i])
            {
                aux = numero[i];
                numero[i] = numero[i + 1];
                numero[i + 1] = aux;
            }
        }
    }
}
int buscaBinaria(int chave, int *numero, int n)
{
    int i;
    int esq = 0;
    int dir = n - 1;

    do
    {
        i = (dir + esq) / 2;
        if (chave > numero[i])
            esq = i + 1;
        else
            dir = i - 1;

    } while (chave != numero[i] && esq <= dir);
    if (chave == numero[i])
        return i;
    else
        return -1;
}
