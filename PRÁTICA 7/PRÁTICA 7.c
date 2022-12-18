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
} pilha;

pilha *criaPilha();
int empilha(pilha *p, int v);
int desempilha(pilha *p, int *v);
int pilhaVazia(pilha *p);
void liberaPilha(pilha *p);

int main()
{
    int menu;
    int repete = 1;
    int v;
    int deuCerto;
    int desempilhou;
    int pilhaV;
    pilha *p = criaPilha();

    while (repete == 1)
    {
        printf("0- Sair:\n1- Empilhar:\n2- Desempilhar:\n3- Verificar se esta vazia:\n4- Liberar pilha:\n");
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
                desempilhou = desempilha(p, &v);
                pilhaV = pilhaVazia(p);
                if (desempilhou == 1)
                {
                    if (pilhaV == 0)
                        printf("%d\n", v);
                }
                else
                    printf("Erro!\n");
            }
            break;
        case 3:
            pilhaV = pilhaVazia(p);
            if (pilhaV == 1)
                printf("Pilha vazia!\n");
            else
                printf("Pilha nao esta vazia!\n");
        break;
        case 4:
            liberaPilha(p);
            break;
        default:
            printf("Comando invalido.");
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
    return 1;
}
int pilhaVazia(pilha *p)
{
    if (p->topo == NULL)
        return 1;
    else
        return 0;
}

int desempilha(pilha *p, int *v)
{
    elemento *aux;
    aux = p->topo;
    p->topo = aux->anterior;
    free(aux);
    if (pilhaVazia(p) == 1)
        printf("Pilha vazia!\n");
    else
        *v = p->topo->valor;
    return 1;
}

void liberaPilha(pilha *p)
{
    elemento *aux;
    while (p->topo != NULL)
    {
        aux = p->topo;
        p->topo = aux->anterior;
        free(aux);
    }
    free(p);
}
