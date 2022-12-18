#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct fila
{
    int inicio;
    int fim;
    int vetor[MAX];
    int tamanho;
} fila;

typedef struct Pilha
{
    int topo;
    int vetor[MAX];
} pilha;

fila *criaFila();
pilha *criaPilha();
int enfileirar(fila *f, int valor);
int filaCheia(fila *f);
int filaVazia(fila *f);
void imprimirFila(fila *f);
void imprimirPilha(pilha *p);
int desenfileirar(fila *f, int *valor);
int pilhaVazia(pilha *p);
int pilhaCheia(pilha *p);
int pilhaInvertida(fila *f, pilha *p);

int main()
{
    int menu;
    int repete = 1;
    fila *f = criaFila();
    pilha *p = criaPilha();
    int enfileirarFila;
    int empilharPilhaInvertida;
    int valor;

    while (repete == 1)
    {
        printf("0-Sair:\n1-Enfileirar fila e verificar se a pilha esta vazia:\n2- Inverter a ordem da fila e verificar se a pilha esta vazia:\n");
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
            else
                printf("Fila cheia.\n");
            break;
        case 2:
            empilharPilhaInvertida = pilhaInvertida(f, p);
            if (empilharPilhaInvertida == 1)
                imprimirPilha(p);
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
    f->tamanho = 0;
    return f;
}

pilha *criaPilha()
{
    pilha *p = (pilha *)malloc(sizeof(pilha));
    p->topo = 0;

    return p;
}

int enfileirar(fila *f, int valor)
{
    if (filaCheia(f) == 1)
    {
        return 0;
    }
    else
    {
        f->tamanho++;
        f->vetor[f->fim] = valor;
        if (f->fim == MAX)
            f->fim = 0;
        else
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

void imprimirPilha(pilha *p)
{
    int i;
    printf("Pilha:\n");
    for (i = 0; i < p->topo; i++)
        printf("%d\n", p->vetor[i]);
}

int desenfileirar(fila *f, int *valor)
{
    if (filaVazia(f) == 1)
    {
        printf("Fila vazia!\n");
        return 0;
    }
    else
    {
        f->tamanho--;
        if (f->inicio == MAX - 1)
            f->inicio = 0;
        else
            f->inicio++;
    }
    return 1;
}

int empilhar(pilha *p, int valor)
{
    if (pilhaCheia(p) == 1)
    {
        printf("Pilha cheia!\n");
        return 0;
    }
    else
    {
        p->vetor[p->topo] = valor;
        p->topo++;
    }
    return 0;
}

int pilhaVazia(pilha *p)
{
    if (p->topo == 0)
        return 1;
    else
        return 0;
}
int pilhaCheia(pilha *p)
{
    if (p->topo == MAX)
        return 1;
    else
        return 0;
}

int pilhaInvertida(fila *f, pilha *p)
{
    int i;
    int empilharP;
    for (i = f->fim - 1; i >= f->inicio; i--)
        empilharP = empilhar(p, f->vetor[i]);
    return 1;
}
