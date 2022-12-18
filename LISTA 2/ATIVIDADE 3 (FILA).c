#include <stdio.h>
#include <stdlib.h>

#define MAX 3

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
int tamanhoFila(fila *f);

int main()
{
    fila *fila1 = criaFila();
    fila *fila2 = criaFila();
    int menu;
    int repete = 1;
    int valor;
    int enfileirarFila;
    int tamFila1;
    int tamfila2;
    int menorValor;
    int tamanhoFila(fila * f);

    while (repete == 1)
    {
        printf("0-Sair:\n1-Enfileirar fila 1:\n2- Enfileirar fila 2:\n3- Comparar o tamanho das filas:\n");
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
            tamFila1 = tamanhoFila(fila1);
            tamfila2 = tamanhoFila(fila2);
            if (tamFila1 == tamfila2)
            {
                printf("As duas filas possuem o mesmo tamanho.\n");
                printf("Quantidade de elementos nas duas filas: %d\n", tamFila1);
            }
            else if (tamFila1 > tamfila2)
            {
                printf("A fila 1 e maior que a fila 2.\n");
                printf("Quantidade de elementos na fila 1: %d\nQuantidade de elementos na fila 1: %d\n", tamFila1, tamfila2);
            }
            else
            {
                printf("A fila 2 e maior que a fila 1.\n");
                printf("Quantidade de elementos na fila 1: %d\nQuantidade de elementos na fila 1: %d\n", tamFila1, tamfila2);
            }
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

int tamanhoFila(fila *f)
{
    int i = 0;

    while (i < f->fim)
        i++;
    return i;
}
