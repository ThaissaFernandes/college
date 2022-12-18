#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct fila
{
    int inicio;
    int fim;
    int vetor[MAX];
} fila;

fila *criaFila();
int filaCheia(fila *f);
int filaVazia(fila *f);
int enfileirar(fila *f, int valor);
void imprimirFila(fila *f);

int main()
{
    fila *fila2 = criaFila();
    fila *fila1 = criaFila();

    int menu;
    int repete = 1;
    int valor;
    int enfileirarFila;
    int concatenar;

    while (repete == 1)
    {
        printf("0-Sair:\n1-Enfileirar fila 1:\n2- Enfileirar fila 2:\n3- Fila 1 concatenada com fila 2:\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("Digite o valor que deseja enfileirar:\n");
            scanf("%d", &valor);
            enfileirarFila = enfileirar(fila1, valor);
            if (enfileirarFila == 1)
                imprimirFila(fila1);
            break;
        case 2:
            printf("Digite o valor que deseja enfileirar:\n");
            scanf("%d", &valor);
            enfileirarFila = enfileirar(fila2, valor);
            if (enfileirarFila == 1)
                imprimirFila(fila2);
            break;
        case 3:
            concatenar = concatenarFilas(fila1, fila2);
            imprimirFila(fila1);
            free(fila2);
            break;
        default:
            printf("Comando invalido.\n");
        }
    }
    return 0;
}

fila *criaFila()
{
    fila *f = (fila *)malloc(sizeof(fila));
    f->inicio = 0;
    f->fim = 0;

    return f;
}
int enfileirar(fila *f, int valor)
{
    if (filaCheia(f) == 1)
    {
        printf("Fila cheia.\n");
        return 0;
    }
    else
    {
        f->vetor[f->fim] = valor;
        f->fim++;
    }

    return 1;
}

int filaCheia(fila *f)
{
    if (f->fim - f->inicio == MAX)
        return 1;
    else
        return 0;
}

int filaVazia(fila *f)
{
    if (f->inicio == f->fim)
        return 1;
    else
        return 0;
}
void imprimirFila(fila *f)
{
    int i;
    printf("Fila:\n");
    for (i = 0; i < f->fim; i++)
        printf("%d\n", f->vetor[i]);
}

int concatenarFilas(fila *fila1, fila *fila2)
{
    int i;
    int enfileirarFila;
    if (filaVazia(fila1) == 1)
        printf("Fila 1 vazia.\n");
    if (filaVazia(fila2) == 1)
        printf("Fila 2 vazia.\n");
    else
        for (i = 0; i < fila2->fim; i++)
            enfileirarFila = enfileirar(fila1, fila2->vetor[i]);

    return 1;
}
