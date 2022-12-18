#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Pilha
{
    int topo;
    int vetor[MAX];
} Pilha;

void criaPilha(Pilha *pilha);
void push(Pilha *pilha, int valor);
void pop(Pilha *pilha);
int pilhaVazia(Pilha *pilha);
int pilhaCheia(Pilha *pilha);
void liberaPilha(Pilha *pilha);

int main()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    int menu;
    criaPilha(pilha);

    int constante = -1;
    while (constante == -1)
    {
        printf("0- Sair\n1- Empilhar:\n2- Desempilhar:\n3- Verificar se a pilha esta vazia:\n4- Verificar se a pilha esta cheia:\n5- Liberar memoria da pilha:\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            return 0;
            break;
        case 1:
            if (pilhaCheia(pilha) == 1)
                printf("Pilha cheia!\n");
            else{
                push(pilha, 10);
                push(pilha, 20);
                push(pilha, 30);
            }
            break;
        case 2:
        {
            if (pilhaVazia(pilha) == 1)
                printf("Pilha vazia!\n");
            else
                pop(pilha);
        }
        break;
        case 3:
        {
            int pilhaV = pilhaVazia(pilha);
            if (pilhaV == 1)
                printf("Pilha vazia!\n");
            else
                printf("Pilha nao esta vazia!\n");
        }
        break;
        case 4:
        {
            int pilhaC = pilhaCheia(pilha);
            if (pilhaC == 1)
                printf("Pilha cheia!\n");
            else
                printf("Pilha nao esta cheia!\n");
        }
        break;
        case 5:
            liberaPilha(pilha);
            break;
        default:
            printf("Comando invalido.\n");
        }
    }
    return 0;
}

void criaPilha(Pilha *pilha)
{
    pilha->topo = 0;
}

void push(Pilha *pilha, int valor){
        pilha->vetor[pilha->topo] = valor;
        pilha->topo++;
}
void pop(Pilha *pilha)
{
    int aux;
    aux = pilha->vetor[pilha->topo];
    pilha->topo--;
}

int pilhaVazia(Pilha *pilha)
{
    if (pilha->topo == 0)
        return 1;
    else
        return 0;
}
int pilhaCheia(Pilha *pilha)
{
    if (pilha->topo == MAX)
        return 1;
    else
        return 0;
}

void liberaPilha(Pilha *pilha)
{
    free(pilha);
}
