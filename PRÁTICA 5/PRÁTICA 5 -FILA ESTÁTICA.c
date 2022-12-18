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
void enfileirar(fila *f, int valor);
void desenfileirar(fila *f);
void liberaFila(fila *f);

int main()
{
    fila *f = criaFila();
    int menu;
    int repete = 1;
    int filaC, filaV;

    while (repete == 1)
    {
        printf("0-Sair:\n1-Enfileirar:\n2- Desenfileirar:\n3- Verifica se esta cheia:\n4- Verifica se esta vazia:\n5- Liberar fila:\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 0:
            return 0;
            break;
        case 1:
            if (filaCheia(f) == 1)
                printf("Fila cheia!\n");
            else
            {
                enfileirar(f, 10);
                enfileirar(f, 20);
                enfileirar(f, 30);
            }
            break;
        case 2:
            if (filaVazia(f) == 1)
                printf("Fila vazia!\n");
            else
                desenfileirar(f);
            break;
        case 3:
            filaC = filaCheia(f);
            if (filaC == 1)
                printf("A fila esta cheia.\n");
            else
                printf("A fila nao esta cheia.\n");
            break;
        case 4:
            filaV = filaVazia(f);
            if (filaV == 1)
                printf("A fila esta vazia.\n");
            else
                printf("A fila nao esta vazia.\n");
            break;
        case 5:
            liberaFila(f);
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
void enfileirar(fila *f, int valor)
{
    f->vetor[f->fim] = valor;
    f->fim++;
}
void desenfileirar(fila *f)
{
    f->inicio++;
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

void liberaFila(fila *f)
{
    free(f);
}

