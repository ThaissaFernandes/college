#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int valor;
    struct elemento *proximo;
} elemento;

typedef struct fila
{
    elemento *inicio;
    elemento *fim;
} fila;

fila *criaFila();
int enfileirar(fila *f, int v);
int desenfileirar(fila *f, int *v);
int filaVazia(fila *f);
int determinarNumerosPares(fila *f, int v, int quantPares, int inserindo);

int main()
{
    int menu;
    int repete = 1;
    int v;
    int filaV;
    int deuCerto;
    int desenfileirou;
    int quantPares = 0;

    fila *f = criaFila();

    while ((repete = 1))
    {
        printf("0- Sair:\n1- Enfileirar:\n2- Desenfileirar:\n3- Retornar quantos elementos da fila sao pares:\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("Determine o valor a ser enfileirado:\n");
            scanf("%d", &v);
            quantPares = determinarNumerosPares(f, v, quantPares, 1);
            deuCerto = enfileirar(f, v);
            if (deuCerto == 1)
                printf("%d\n", f->fim->valor);
            break;
        case 2:
            filaV = filaVazia(f);
            if (filaV == 1)
                printf("Fila vazia!\n");
            else
            {
                desenfileirou = desenfileirar(f, &v);
                filaV = filaVazia(f);
                if (desenfileirou == 1)
                {
                    quantPares = determinarNumerosPares(f, v, quantPares, 0);
                    printf("%d\n", v);
                }

                else
                    printf("Erro!\n");
            }
            break;
        case 3:
            printf("Quantidade de elementos pares: %d\n", quantPares);
            break;
        default:
            printf("Comando invalido.");
        }
    }

    return 0;
}

fila *criaFila()
{
    fila *f = (fila *)malloc(sizeof(fila));
    f->inicio = NULL;
    f->fim = NULL;

    return (f);
}

int enfileirar(fila *f, int v)
{
    elemento *novo = (elemento *)malloc(sizeof(elemento));
    if (novo == NULL)
        return 0;
    else
    {
        novo->valor = v;
        novo->proximo = NULL;
        if (f->inicio == NULL && f->fim == NULL)
        {
            f->fim = novo;
            f->inicio = novo;
        }
        else
        {
            f->fim->proximo = novo;
            f->fim = novo;
        }
    }
    return 1;
}

int filaVazia(fila *f)
{
    if (f->inicio == NULL || f->fim == NULL)
        return 1;
    else
        return 0;
}

int desenfileirar(fila *f, int *v)
{
    elemento *aux;

    aux = f->inicio;
    f->inicio = aux->proximo;
    *v = aux->valor;
    free(aux);

    return 1;
}
int determinarNumerosPares(fila *f, int v, int quantPares, int inserindo)
{
    if (v % 2 == 0 && inserindo == 1)
        quantPares++;
    if (v % 2 == 0 && inserindo == 0)
        quantPares--;

    return quantPares;
}
