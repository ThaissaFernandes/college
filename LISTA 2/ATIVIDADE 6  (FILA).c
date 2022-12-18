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
int inverterFila(fila *f, fila *filaInvertida);

int main()
{
    fila *f = criaFila();
    fila *filaInvertida = criaFila();
    int menu;
    int repete = 1;
    int filaC, filaV;
    int valor;
    int enfileirarFila;
    int enfileirarFilaInvertida;

    while (repete == 1)
    {
        printf("0-Sair:\n1-Enfileirar:\n2- Inverter a ordem da fila:\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("Digite o valor que deseja enfileirar:\n");
            scanf("%d", &valor);
            enfileirarFila = enfileirar(f, valor);
            if (enfileirarFila == 1)
                imprimirFila(f);
            break;
        case 2:
            enfileirarFilaInvertida = inverterFila(f, filaInvertida);
            if (enfileirarFilaInvertida == 1)
                imprimirFila(filaInvertida);
            break;
        default:
            printf("Comando invalido.\n");
        }
    }
    return 0;
}

fila *criaFila()
{
    fila *f = (fila *)malloc(MAX * sizeof(fila));
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

int inverterFila(fila *f, fila *filaInvertida)
{
    int enfileirarFila;
    int auxFila[MAX];
    int j = 0;
    int i;
    if (filaVazia(f) == 1)
    {
        printf("Fila vazia.\n");
        return 0;
    }
    else
    {
        for (i = f->fim - 1; i >= f->inicio; i--)
            auxFila[j++] = f->vetor[i];

        for (i = 0; i < f->fim; i++)
            enfileirarFila = enfileirar(filaInvertida, auxFila[i]);
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
