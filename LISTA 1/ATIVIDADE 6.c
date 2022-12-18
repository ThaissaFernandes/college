#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct cilindro
{
    float raio;
    float altura;
    float areaBase;
    float areaLateral;
    float areaTotal;
    float volume;
} cilindro;

cilindro *iniciarCilindro();
void raioCilindro(cilindro *c);
void alturaCilindro(cilindro *c);
float areaTotal(cilindro *c);
void volumeCilindro(cilindro *c);

int main()
{
    int menu;
    int repete = 1;
    cilindro *c = iniciarCilindro();

    while (repete = 1)
    {
        printf("0- Sair:\n1- Determinar raio:\n2- Determinar altura:\n3- Area total do cilindro:\n4- Volume do cilindro:\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            return 0;
            break;
        case 1:
            raioCilindro(c);
            printf("%.2f\n", c->raio);
            break;
        case 2:
            alturaCilindro(c);
            printf("%.2f\n", c->altura);
            break;
        case 3:
            c->areaTotal = areaTotal(c);
            printf("%.2f\n", c->areaTotal);
            break;
        case 4:
            volumeCilindro(c);
            printf("%.2f\n", c->volume);
            break;
        default:
            printf("comando invalido.\n");
        }
    }

    return 0;
}

cilindro *iniciarCilindro()
{
    cilindro *c = (cilindro *)malloc(sizeof(cilindro));
    c->raio = 0;
    c->altura = 0;
    return c;
}

void raioCilindro(cilindro *c)
{
    printf("Digite o valor do raio do cilindro:\n");
    scanf("%f", &c->raio);
    while (c->raio <= 0)
    {
        printf("Valor invalido.\nDigite novamente:\n");
        scanf("%f", &c->raio);
    }
}

void alturaCilindro(cilindro *c)
{
    printf("Digite o valor da altura do cilindro:\n");
    scanf("%f", &c->altura);
    while (c->altura <= 0)
    {
        printf("Valor invalido.\nDigite novamente:\n");
        scanf("%f", &c->altura);
    }

    return c->altura;
}

float areaTotal(cilindro *c)
{

    c->areaBase = 3.14 * (pow(c->raio, 2));
    c->areaLateral = 2 * 3.14 * c->raio;
    c->areaTotal = c->areaBase + c->areaLateral;

    return c->areaTotal;
}

void volumeCilindro(cilindro *c)
{
    c->areaBase = 3.14 * (pow(c->raio, 2));
    c->volume = c->areaBase * c->altura;
}
