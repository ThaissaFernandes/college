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

int main()
{
    int v;
    int repeteMenu = 1;
    int menu;
    int deuCerto;

    pilha *p1 = criaPilha();
    pilha *p2 = criaPilha();

    while (repeteMenu == 1)
    {
        printf("0 - Sair:\n1 - Empilhar pilha 1:\n2 - Empilhar pilha 2:\n3 - Comparar tamanho das pilhas:\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("Determine o valor a ser empilhado:\n");
            scanf("%d", &v);
            deuCerto = empilha(p1, v);
            if (deuCerto == 1)
                printf("%d\n", p1->topo->valor);
            else
                printf("Erro!\n");
            break;
        case 2:
            printf("Determine o valor a ser empilhado:\n");
            scanf("%d", &v);
            deuCerto = empilha(p2, v);
            if (deuCerto == 1)
                printf("%d\n", p2->topo->valor);
            else
                printf("Erro!\n");
            break;
        case 3:
            if (p1->tamanho == p2->tamanho)
                printf("As pilhas possuem o mesmo tamanho:%d\n", p1->tamanho);
            else if (p1->tamanho > p2->tamanho)
                printf("A pilha 1 possui mais elementos que a pilha 2.\nPilha 1:%d\nPilha 2:%d\n", p1->tamanho, p2->tamanho);
            else
                printf("A pilha 2 possui mais elementos que a pilha 1.\nPilha 1:%d\nPilha 2:%d\n", p1->tamanho, p2->tamanho);
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
    p->tamanho++;

    return 1;
}
