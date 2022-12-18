#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct lista
{
    int vetor[MAX];
    int fim;
} lista;

lista *criaLista();
int listaCheia(lista *l);
void imprimirVetor(lista *l);
int inserirElementoFinalLista(lista *l, int v);
void liberarLista(lista *l);
int imprimirQuantidadeElementos(lista *l);
int inserirElementoPosicao(lista *l, int inserirPosicao, int v);
int recuperarElementoChave(lista *l, int *valorBuscado);
int recuperarElementoPosicao(lista *l, int *posicaoBuscada);
void removerElementoFim(lista *l);

int main()
{
    lista *l = criaLista();
    int repeteMenu = 1;
    int menu;
    int elementoBuscado;
    int posicaoBuscada;
    int recuperarPorPosicao;
    int recuperarPorChave;
    int inserirElemento;
    int inserirPosicao;
    int i;
    int v;

    while (repeteMenu == 1)
    {
        printf("0 - Sair:\n1 - Inserir item no final da lista:\n2 - Inserir item  por posicao:\n3 - Remover item no final da lista:\n4 - Recuperar item por chave:\n5 - Recuperar item por posicao:\n6 - Contar quantidade de itens da lista:\n7 - Imprimir os itens da lista:\n8 - Liberar lista:\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            return 0;
        case 1:
            printf("Digite o valor que se deseja inserir na  ultima posicao da lista:\n");
            scanf("%d", &v);
            inserirElemento = inserirElementoFinalLista(l, v);
            if (inserirElemento == 1)
                printf("%d\n", l->vetor[l->fim - 1]);
            break;
        case 2:
            printf("Digite a posicao em que se deseja inserir um elemento:\n");
            scanf("%d", &inserirPosicao);
            printf("Digite o valor que se deseja inserir:\n");
            scanf("%d", &v);
            inserirElemento = inserirElementoPosicao(l, inserirPosicao, v);
            if (inserirElemento == 1)
                printf("Elemento inserido:\n%d\n", l->vetor[inserirPosicao - 1]);
            break;
        case 3:
            removerElementoFim(l);
            break;
        case 4:
            printf("Digite o elemento que deseja buscar:\n");
            scanf("%d", &elementoBuscado);
            recuperarPorChave = recuperarElementoChave(l, &elementoBuscado);
            if (recuperarPorChave == 1)
                printf("Elemento da lista:\n%d\n", elementoBuscado);
            break;
        case 5:
            printf("Digite a posicao que se deseja encontrar:\n");
            scanf("%d", &posicaoBuscada);
            recuperarPorPosicao = recuperarElementoPosicao(l, &posicaoBuscada);
            if (recuperarPorPosicao == 1)
                printf("Elemento da posicao buscada:\n%d\n", l->vetor[posicaoBuscada - 1]);
            break;
        case 6:
            i = imprimirQuantidadeElementos(l);
            printf("Quantidade de elementos da lista:\n%d\n", i);
            break;
        case 7:
            imprimirVetor(l);
            break;
        case 8:
            liberarLista(l);
            break;
        default:
            printf("Comando invalido.\n");
        }
    }
    return 0;
}

lista *criaLista()
{
    lista *l = (lista *)malloc(MAX * sizeof(lista));
    l->fim = 0;
    return l;
}
void liberarLista(lista *l)
{
    free(l);
}
int listaCheia(lista *l)
{
    if (l->fim == MAX)
        return 1;
    else
        return 0;
}
void imprimirVetor(lista *l)
{
    int i;
    printf("Elementos da lista:\n");
    for (i = 0; i < l->fim; i++)
    {
        printf("%d\n", l->vetor[i]);
    }
}
int imprimirQuantidadeElementos(lista *l)
{
    int i = 0;
    while (i < l->fim)
        i++;

    return i;
}
int inserirElementoFinalLista(lista *l, int v)
{
    if (listaCheia(l) == 0)
    {
        l->vetor[l->fim] = v;
        l->fim++;
        return 1;
    }
    else
    {
        printf("Lista cheia.\n");
        return 0;
    }
}

int listaVazia(lista *l)
{
    if (l->fim == 0)
        return 1;
    else
        return 0;
}

int inserirElementoPosicao(lista *l, int inserirPosicao, int v)
{
    int aux;
    int i;
    int elementoInserido;
    if (listaCheia(l) == 0)
    {
        if (inserirPosicao < 1 || inserirPosicao > MAX)
        {
            printf("Posicao invalida.\n");
            return 0;
        }
        else
        {
            if (inserirPosicao >= l->fim)
                elementoInserido = inserirElementoFinalLista(l, v);
            else
            {
                for (i = l->fim - 1; i >= inserirPosicao - 1; i--)
                    l->vetor[i + 1] = l->vetor[i];
                l->fim++;
                l->vetor[inserirPosicao - 1] = v;
                return 1;
            }
        }
    }
    else
    {
        printf("Lista cheia.\n");
        return 0;
    }
}

int recuperarElementoChave(lista *l, int *valorBuscado)
{
    int i;
    if (listaVazia(l) == 1)
        printf("Lista vazia.\n");
    else
    {
        for (i = 0; i < l->fim; i++)
        {
            if (l->vetor[i] == *valorBuscado)
                return 1;
            else
            {
                printf("Valor nao presente na lista.\n");
                return 0;
            }
        }
    }
}
int recuperarElementoPosicao(lista *l, int *posicaoBuscada)
{
    int i;
    if (listaVazia(l) == 1)
        printf("Lista vazia.\n");
    else
    {
        if (*posicaoBuscada < 1 || *posicaoBuscada > l->fim)
        {
            printf("Posicao nao encontrada.\n");
            return 0;
        }
        else
        {
            for (i = 0; i < l->fim; i++)
            {
                if (*posicaoBuscada - 1 == i)
                    return 1;
            }
            return 0;
        }
    }
}

void removerElementoFim(lista *l)
{
    int aux;
    if (listaVazia(l) == 0)
    {
        aux = l->vetor[l->fim - 1];
        printf("Elemento removido:\n%d\n", aux);
        l->fim--;
    }
    else
        printf("Lista vazia.\n");
}
