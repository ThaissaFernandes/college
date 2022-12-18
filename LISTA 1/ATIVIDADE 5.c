#include <stdio.h>
#include <stdlib.h>

typedef struct cubo
{
    float aresta;
    float areaLado;
    float areaTotal;
    float volume;
} cubo;

cubo *iniciarCubo();
void valorLateral(cubo *c);
float areaLado(cubo *c);
float areatotal(cubo *c);
float volume(cubo *c);

int main()
{
    int menu;
    int repete = 1;
    cubo *c = iniciarCubo();

    while (repete = 1)
    {
        printf("0- Sair:\n1- Determinar valor da aresta:\n2- Determinar a area lateral:\n3- Determinar a area total\n4- Determinar o volume:\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            return 0;
            break;
        case 1:
            valorLateral(c);
            printf("%.2f\n", c->aresta);
            break;
        case 2:
            c->areaLado = areaLado(c);
            printf("%.2f\n", c->areaLado);
            break;
        case 3:
            c->areaTotal = areatotal(c);
            printf("%.2f\n", c->areaTotal);
            break;
        case 4:
            c->volume = volume(c);
            printf("%.2f\n", c->volume);
            break;
        default:
            printf("Valor invalido.\n");
        }
    }

    return 0;
}

cubo *iniciarCubo()
{
    cubo *c = (cubo *)malloc(sizeof(cubo));
    c->aresta = 0;
    return c;
}

void valorLateral(cubo *c)
{
    printf("Determine o valor da aresta:\n");
    scanf("%f", &c->aresta);
    while (c->aresta <= 0)
    {
        printf("Valor invalido:\nDigite novamente:\n");
        scanf("%f", &c->aresta);
    }
}

float areaLado(cubo *c)
{
    c->areaLado = c->aresta * c->aresta;

    return c->areaLado;
}

float areatotal(cubo *c)
{
    c->areaTotal = 6 * c->areaLado;

    return c->areaTotal;
}
float volume(cubo *c)
{
    c->volume = c->aresta * c->aresta * c->aresta;

    return c->volume;
}
