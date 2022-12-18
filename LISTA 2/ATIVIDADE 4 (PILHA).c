
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct elemento
{
    int elemento;
    struct elemento *anterior;
} elemento;

typedef struct pilha
{
    elemento *topo;
} pilha;

pilha *criaPilha();
int empilha(pilha *p, int el);
int pilhaVazia(pilha *p);
pilha *inverter(pilha *p);

int main()
{
    int deuCerto;
    int pilhaV;
    pilha *p = criaPilha();
    int desempilhou;
    pilha *invertido;
    int repeteMenu = 1;
    int menu;
    int v;
    while (repeteMenu == 1)
    {
        printf("0- Sair:\n1- Empilhar:\n2- Inverter elementos da pilha:\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("Determine o elemento a ser empilhado:\n");
            scanf("%d", &v);
            deuCerto = empilha(p, v);
            if (deuCerto == 1)
                printf("%d\n", p->topo->elemento);
            else
                printf("Erro!\n");
            break;
        case 2:
            pilhaV = pilhaVazia(p);
            if (pilhaV == 1)
                printf("Pilha vazia.\n");
            else
                invertido = inverter(p);
            break;
        default:
            printf("Comando invalido.\n");
        }
    }

    return 0;
}

pilha *criaPilha()
{
    pilha *p = (pilha *)malloc(sizeof(pilha));
    p->topo = NULL;

    return (p);
}

int empilha(pilha *p, int el)
{
    elemento *novo = (elemento *)malloc(sizeof(elemento));
    if (novo == NULL)
        return 0;
    else
    {
        novo->anterior = p->topo;
        p->topo = novo;
        novo->elemento = el;
    }
    return 1;
}

int pilhaVazia(pilha *p)
{
    if (p->topo == NULL)
        return 1;
    else
        return 0;
}

pilha *inverter(pilha *p)
{
    pilha *invertido = criaPilha();
    int i;
    int deuCerto;
    elemento *aux = p->topo;
    printf("Pilha invertida:\n");
    while (aux != NULL)
    {
        deuCerto = empilha(invertido, aux->elemento);
        if (deuCerto == 1)
            printf("%d\n", invertido->topo->elemento);
        else
            printf("Erro!\n");
        aux = aux->anterior;
    }
    printf("\n");
    return (invertido);
}
