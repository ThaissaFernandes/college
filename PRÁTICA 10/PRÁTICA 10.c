#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct elemento
{
    int valor;
    struct elemento *proximo;
} Elemento;

typedef struct lista
{
    Elemento *inicio;
    int tamLista;
} lista;

lista *criaLista();
void imprimirVetor(lista *l);
int inserirElementoFinalLista(lista *l, int v);
void liberarLista(lista *l);
int imprimirQuantidadeElementos(lista *l);
int inserirElementoPosicao(lista *l, int inserirPosicao, int v);
int recuperarElementoChave(lista *l, int valorBuscado);
int recuperarElementoPosicao(lista *l, int posicaoBuscada);
void removerElementoFim(lista *l);
void removerElementoPorPosicao(lista *l, int posicaoRemovida);

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
    int removerPosicao;
    int i;
    int v;

    while (repeteMenu == 1)
    {
        printf("0 - Sair:\n1 - Inserir item no final da lista:\n2 - Inserir item  por posicao:\n3 - Remover item no final da lista:\n4 - Removar elemento por posicao:\n5 - Recuperar item por chave:\n6 - Recuperar item por posicao:\n7 - Contar quantidade de itens da lista:\n8 - Imprimir os itens da lista:\n9 - Liberar lista:\n");
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
                imprimirVetor(l);
            break;
        case 2:
            printf("Digite a posicao em que se deseja inserir um elemento:\n");
            scanf("%d", &inserirPosicao);
            printf("Digite o valor que se deseja inserir:\n");
            scanf("%d", &v);
            inserirElemento = inserirElementoPosicao(l, inserirPosicao, v);
            if (inserirElemento == 1)
                imprimirVetor(l);
            break;
        case 3:
            removerElementoFim(l);
            break;
        case 4:
            if (listaVazia(l) == 1)
            {
                printf("Lista vazia!\n");
                break;
            }
            printf("Digite a posicao em que se deseja remover um elemento:\n");
            scanf("%d", &removerPosicao);
            while (removerPosicao < 0 || removerPosicao > l->tamLista)
            {
                printf("Valor invalido.\nDigite novamente:\n");
                scanf("%d", &removerPosicao);
            }
            removerElementoPorPosicao(l, removerPosicao);
            break;
        case 5:
            printf("Digite o elemento que deseja buscar:\n");
            scanf("%d", &elementoBuscado);
            recuperarPorChave = recuperarElementoChave(l, elementoBuscado);
            if (recuperarPorChave == 1)
                printf("Elemento da lista:\n%d\n", elementoBuscado);
            break;
        case 6:
            printf("Digite a posicao que se deseja encontrar:\n");
            scanf("%d", &posicaoBuscada);
            while (posicaoBuscada < 1 || posicaoBuscada > l->tamLista)
            {
                printf("Valor invalido.\nDigite novamente:\n");
                scanf("%d", &posicaoBuscada);
            }
            recuperarPorPosicao = recuperarElementoPosicao(l, posicaoBuscada);
            if (recuperarPorPosicao != 0)
                printf("Elemento da posicao buscada:\n%d\n", recuperarPorPosicao);
            break;
        case 7:
            i = imprimirQuantidadeElementos(l);
            printf("Quantidade de elementos da lista:\n%d\n", i);
            break;
        case 8:
            imprimirVetor(l);
            break;
        case 9:
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
    lista *l = (lista *)malloc(sizeof(lista));
    l->inicio = NULL;
    l->tamLista = 0;
    return l;
}

void liberarLista(lista *l)
{
    Elemento *aux;
    if (l->inicio != NULL)
    {
        while (l->inicio != NULL)
        {
            aux = l->inicio;
            l->inicio = l->inicio->proximo;
            free(aux);
        }
        free(l);
    }
}

void imprimirVetor(lista *l)
{
    Elemento *aux = l->inicio;
    int i = 0;
    printf("Elementos da lista:\n");
    while (i != l->tamLista)
    {
        printf("%d\n", aux->valor);
        aux = aux->proximo;
        i++;
    }
}

int imprimirQuantidadeElementos(lista *l)
{
    Elemento *aux = l->inicio;
    int i = 0;
    if (listaVazia(l) == 1)
        return -1;
    else
        return l->tamLista;
}

int inserirElementoFinalLista(lista *l, int v)
{
    Elemento *auxInserir = l->inicio;
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    if (novo == NULL)
        return 0;
    else
    {
        novo->proximo = NULL;
        novo->valor = v;
        l->tamLista++;
        if (listaVazia(l) == 1)
        {

            l->inicio = novo;
            return 1;
        }
        else
        {
            while (auxInserir->proximo != NULL)
                auxInserir = auxInserir->proximo;
            auxInserir->proximo = novo;

            return 1;
        }
    }
}
int listaVazia(lista *l)
{
    if (l->inicio == NULL)
        return 1;
    else
        return 0;
}

int inserirElementoPosicao(lista *l, int inserirPosicao, int v)
{
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    Elemento *aux = l->inicio;
    int i = 1;
    int elementoInserido;
    if (novo == NULL)
        return 0;
    else
    {
        novo->valor = v;
        l->tamLista++;
        if (listaVazia(l) == 1)
        {
            novo->proximo = NULL;
            l->inicio = novo;
            return 1;
        }
        if (inserirPosicao == 1)
        {
            novo->proximo = l->inicio;
            l->inicio = novo;
            return 1;
        }
        while (i != inserirPosicao - 1)
        {
            aux = aux->proximo;
            i++;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;

        return 1;
    }
}

int recuperarElementoChave(lista *l, int valorBuscado)
{
    Elemento *auxChave = l->inicio;

    int i;
    if (listaVazia(l) == 1)
        printf("Lista vazia.\n");
    else
    {
        for (i = 0; i < l->tamLista; i++)
        {
            if (auxChave->valor == valorBuscado)
                return 1;
            auxChave = auxChave->proximo;
        }
        printf("Valor nao presente na lista.\n");
        return 0;
    }
}

int recuperarElementoPosicao(lista *l, int posicaoBuscada)
{
    Elemento *aux = l->inicio;

    int i;
    if (listaVazia(l) == 1)
        printf("Lista vazia.\n");
    else
    {
        for (i = 0; i < l->tamLista; i++)
        {
            if (i == posicaoBuscada - 1)
                return aux->valor;
            aux = aux->proximo;
        }
        printf("Valor nao presente na lista.\n");
        return 0;
    }
}

void removerElementoFim(lista *l)
{
    int elementoRemovido;
    Elemento *aux = l->inicio;
    if (listaVazia(l) == 0)
    {
        if (l->tamLista == 1)
        {
            elementoRemovido = aux->valor;
            free(aux);
            l->inicio = NULL;
        }
        else
        {
            while (aux->proximo->proximo != NULL)
                aux = aux->proximo;
            elementoRemovido = aux->proximo->valor;
            free(aux->proximo);
            aux->proximo = NULL;
        }
        printf("Elemento removido: %d\n", elementoRemovido);
        l->tamLista--;
    }
    else
        printf("Lista vazia.\n");
}

void removerElementoPorPosicao(lista *l, int posicaoRemovida)
{
    int i = 0;
    int elementoRemovido;
    Elemento *aux = l->inicio;
    Elemento *auxProximo = l->inicio->proximo;
    if (listaVazia(l) == 0)
    {
        if (posicaoRemovida == 1)
        {
            elementoRemovido = aux->valor;
            free(aux);
            l->inicio = auxProximo;
        }
        else
        {
            while (i != posicaoRemovida - 2)
            {
                aux = aux->proximo;
                auxProximo = auxProximo->proximo;
                i++;
            }
            elementoRemovido = auxProximo->valor;
            aux->proximo = auxProximo->proximo;
            free(auxProximo);
        }
        printf("Elemento removido: %d\n", elementoRemovido);
        l->tamLista--;
    }
    else
        printf("Lista vazia.\n");
}
