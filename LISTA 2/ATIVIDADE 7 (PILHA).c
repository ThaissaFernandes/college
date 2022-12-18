#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int valor;
    struct elemento *anterior;
} elemento;

typedef struct pilha
{
    elemento *topo;
    int tamanho;
} pilha;

pilha *criaPilha();
int empilha(pilha *p, int v);
int pilhaVazia(pilha *p);

int main()
{
    int v;
    int pilhaV;
    int repeteMenu = 1;
    int menu;
    int deuCerto;

    pilha *p = criaPilha();

    while (repeteMenu == 1)
    {
        printf("0 - Sair:\n1 - Empilhar pilha:\n2 - Quantidade de valores impares:\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("Determine o valor a ser empilhado:\n");
            scanf("%d", &v);
            deuCerto = empilha(p, v);
            if (deuCerto == 1)
                printf("%d\n", p->topo->valor);
            else
                printf("Erro!\n");
            break;
        case 2:
            pilhaV = pilhaVazia(p);
            if (pilhaV == 0)
            {
                printf("Quantidade de numeros impares da pilha:\n");
                printf("%d\n", p->tamanho);
            }
            else
                printf("Pilha vazia.\n");
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
    p->tamanho = 0;

    return (p);
}

int empilha(pilha *p, int v)
{
    elemento *novo = (elemento *)malloc(sizeof(elemento));
    if (novo == NULL)
        return 0;
    else
    {
        novo->anterior = p->topo;
        p->topo = novo;
        novo->valor = v;
    }
    if (v % 2 != 0)
        p->tamanho++;

    return 1;
}
int pilhaVazia(pilha *p)
{
    if (p->topo == NULL)
        return 1;
    else
        return 0;
}
