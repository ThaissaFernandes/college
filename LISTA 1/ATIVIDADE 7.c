
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct esfera
{
    float raio;
    float areaTotal;
    float volume;
} esfera;

esfera *iniciarEsfera();
void raioEsfera(esfera *e);
float areaTotal(esfera *e);
float volumeEsfera(esfera *e);

int main()
{
    int menu;
    int repete = 1;
    esfera *e = iniciarEsfera();

    while (repete = 1)
    {
        printf("0- Sair:\n1- Determinar raio:\n2- Area total da esfera:\n3- Volume da esfera:\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            return 0;
            break;
        case 1:
            raioEsfera(e);
            printf("%.2f\n", e->raio);
            break;
        case 2:
            e->areaTotal = areaTotal(e);
            printf("%.2f\n", e->areaTotal);
            break;
        case 3:
            e->volume = volumeEsfera(e);
            printf("%.2f\n", e->volume);
            break;
        default:
            printf("Comando invalido.\n");
        }
    }

    return 0;
}

esfera *iniciarEsfera()
{
    esfera *e = (esfera *)malloc(sizeof(esfera));
    e->raio = 0;
    return e;
}

void raioEsfera(esfera *e)
{
    printf("Digite o valor do raio da esfera:\n");
    scanf("%f", &e->raio);
    while (e->raio <= 0)
    {
        printf("Valor invalido.\nDigite novamente:\n");
        scanf("%f", &e->raio);
    }
}

float areaTotal(esfera *e)
{

    e->areaTotal = 4 * (3.14) * pow(e->raio, 2);

    return e->areaTotal;
}

float volumeEsfera(esfera *e)
{
    e->volume = (4 * (3.14) * pow(e->raio, 3)) / 3;

    return e->volume;
}
