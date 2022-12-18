#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct elemento
{
    char letra;
    struct elemento *anterior;
} elemento;

typedef struct pilha
{
    elemento *topo;
} pilha;

pilha *criaPilha();
int empilha(pilha *p, char letra);
int pilhaVazia(pilha *p);
char desempilha(pilha *p);

int main()
{
    int palindromo = 1;
    char palavra[MAX];
    int i;
    int deuCerto;
    int pilhaV;
    pilha *p = criaPilha();
    char desempilhou;

    printf("Digite na palavra:\n");
    gets(palavra);

    for(i = 0; palavra[i]!='\0'; i++){
        deuCerto = empilha(p, palavra[i]);
    }
    for(i = 0; palavra[i]!='\0'; i++){
        desempilhou = desempilha(p);
        if(desempilhou!=palavra[i]){
            palindromo = 0;
            printf("Nao e palindromo.\n");
            break;
        }
    }

    if(palindromo==1)
        printf("E palindromo.\n");

    return 0;
}

pilha *criaPilha()
{
    pilha *p = (pilha *)malloc(sizeof(pilha));
    p->topo = NULL;

    return (p);
}

int empilha(pilha *p, char letra)
{
    elemento *novo = (elemento *)malloc(sizeof(elemento));
    if (novo == NULL)
        return 0;
    else
    {
        novo->anterior = p->topo;
        p->topo = novo;
        novo->letra = letra;
    }
    return 1;
}

char desempilha(pilha *p)
{
    elemento *aux;
    aux = p->topo;
     char letra = p->topo->letra;
    p->topo = aux->anterior;
    free(aux);
    return letra;
}

int pilhaVazia(pilha *p)
{
    if (p->topo == NULL)
        return 1;
    else
        return 0;
}



