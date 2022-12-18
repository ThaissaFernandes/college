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
int maiorElemento(fila *f);
int menorElemento(fila *f);
float mediaAritmetica(fila *f);

int main()
{
    fila *f = criaFila();
    int menu;
    int repete = 1;
    int valor;
    int enfileirarFila;
    int maiorValor;
    int menorValor;
    float mediaArit;

    while (repete == 1)
    {
        printf("0-Sair:\n1-Enfileirar:\n2- Maior elemento:\n3- Menor elemento:\n4- Media aritmetica:\n");
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
            maiorValor = maiorElemento(f);
            if (maiorElemento(f) == 0)
                printf("Fila vazia.\n");
            else
                printf("Maior elemento:\n%d\n", maiorValor);
            break;
        case 3:
            menorValor = menorElemento(f);
            if (menorElemento(f) == 0)
                printf("Fila vazia.\n");
            else
                printf("Menor elemento:\n%d\n", menorValor);
            break;
        case 4:
            mediaArit = mediaAritmetica(f);
            if (menorElemento(f) == 0)
                printf("Fila vazia.\n");
            else
            {
                printf("Media aritmetica:\n%.2f\n", mediaArit);
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

int maiorElemento(fila *f)
{
    int i;
    int maiorElemento;
    if (filaVazia(f) == 1)
    {
        return 0;
    }
    else
    {
        for (i = 0; i < f->fim - 1; i++)
        {
            if (f->vetor[i] >= f->vetor[i + 1])
                maiorElemento = f->vetor[i];
            else
                maiorElemento = f->vetor[i + 1];
        }
        return maiorElemento;
    }
}

int menorElemento(fila *f)
{
    int i;
    int menorElemento;
    if (filaVazia(f) == 1)
    {
        return 0;
    }
    else
    {
        for (i = 0; i < f->fim - 1; i++)
        {
            if (f->vetor[i] <= f->vetor[i + 1])
                menorElemento = f->vetor[i];
            else
                menorElemento = f->vetor[i + 1];
        }
        return menorElemento;
    }
}
float mediaAritmetica(fila *f)
{
    int i;
    int soma = 0;
    if (filaVazia(f) == 1)
    {
        return 0;
    }
    else
    {
        for (i = 0; i < f->fim; i++)
            soma += f->vetor[i];
    }
    return soma / i;
}
