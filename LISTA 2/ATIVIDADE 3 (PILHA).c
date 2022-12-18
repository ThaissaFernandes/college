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
    int maiorValor;
    int menorValor;
    int soma;
    float mediaArit;
    int i;
} pilha;

pilha *criaPilha();
int empilha(pilha *p, int v);
int pilhaVazia(pilha *p);

int main()
{
    int v;
    int repeteMenu = 1;
    int menu;
    int deuCerto;
    int pilhaV;

    pilha *p = criaPilha();

    while (repeteMenu == 1)
    {
        printf("0 - Sair:\n1 - Empilhar:\n2 - Maior valor:\n3 - Menor valor:\n4 - Media aritmetica:\n");
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
            if (pilhaV == 1)
                printf("Pilha vazia!\n");
            else
            {
                printf("Maior valor:\n");
                printf("%d\n", p->maiorValor);
            }
            break;
        case 3:
            pilhaV = pilhaVazia(p);
            if (pilhaV == 1)
                printf("Pilha vazia!\n");
            else
            {
                printf("Menor valor:\n");
                printf("%d\n", p->menorValor);
            }
            break;
        case 4:
            pilhaV = pilhaVazia(p);
            if (pilhaV == 1)
                printf("Pilha vazia!\n");
            else
            {
                printf("%d\n", p->soma);
                p->mediaArit = p->soma / p->i;
                printf("Media aritmetica:\n");
                printf("%.2f\n", p->mediaArit);
            }
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
    p->i = 0;
    p->soma = 0;

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
    if (p->i == 0 || v > p->maiorValor)
        p->maiorValor = v;
    if (p->i == 0 || v < p->menorValor)
        p->menorValor = v;
    p->soma += v;
    p->i++;

    return 1;
}
int pilhaVazia(pilha *p)
{
    if (p->topo == NULL)
        return 1;
    else
        return 0;
}
