#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct elemento
{
    char palavra[20];
    struct elemento *anterior;
} elemento;

typedef struct pilha
{
    elemento *topo;
} pilha;

pilha *criaPilha();
int empilha(pilha *p, char palavra[]);
int pilhaVazia(pilha *p);
int desempilha(pilha *p, char *v);
int inverterPalavra(char *palavra);

int main()
{
     int repete = 1;
     int menu;
     char v;
    char frase[100];
    int i;
    int deuCerto;
    int desempilhou;
    int pilhaV;
    char *palavra;
    int j = 0;
    pilha *p = criaPilha();

     while (repete == 1)
    {
        printf("0- Sair:\n1- Escrever frase desejada:\n2- Escrever frase com palavras com as letras opostas:\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("Escreva frase desejada:\n");
            setbuf(stdin, NULL);
            gets(frase);
            for(i = 0; frase[i]!= '\0'; i++){

                if(j ==  0)
                    palavra = (char *)malloc(sizeof(char));
                if(frase[i]!= ' '){
                    palavra[j] =  frase[i];
                    j++;
                }
               else{
                palavra[j] =  '\0';
                 /*inverterPalavra(palavra);*/
                 j = 0;
                 deuCerto = empilha(p, palavra);
                 printf(" ");
                 free(palavra);
               }
            }
            palavra[j] =  '\0';
            /*inverterPalavra(palavra);*/
            deuCerto = empilha(p, palavra);
             printf(".\n");

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
int empilha(pilha *p, char palavra[])
{
    int i;
    elemento *novo = (elemento *)malloc(sizeof(elemento));
    if (novo == NULL)
        return 0;
    else{
        novo->anterior = p->topo;
        p->topo = novo;
        for(i = 0; palavra[i]!= '\0'; i++){
            novo->palavra[i] = palavra[i];
           printf("%c", palavra[i]);
        }
        }
    return 1;
}

int desempilha(pilha *p, char *v)
{
    elemento *aux;
    aux = p->topo;
    p->topo = aux->anterior;
    free(aux);
    if (pilhaVazia(p) == 1)
        printf("Pilha vazia!\n");
    else
        *v = p->topo->palavra;
    return 1;
}

int pilhaVazia(pilha *p)
{
    if (p->topo == NULL)
        return 1;
    else
        return 0;
}


int inverterPalavra(char *palavra){
    int i = 0;
    int j = 0;
    char aux[20];
    while(palavra[i]!= '\0')
        i++;
    for(j = 0; j!='\0'; j++)
        aux[j] = palavra[j];
    for(j = 0; i >= 0; i--){
        palavra[j] = aux[i];
         j++;
    }

    return 1;
}
