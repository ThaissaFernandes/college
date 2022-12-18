#include <stdio.h>
#include <stdlib.h>

#define MAX 100

float preencherConjuntosRacionais(float *numerosRacionais, int quantInserida);
float somarElementos(float *numerosRacionais, int quantAdicionada);
float multiplicarElementos(float *numerosRacionais, int quantAdicionada);
int elementosIguais(float *numerosRacionais, int quantAdicionada);

int main()
{
    float *numerosRacionais = (float *)malloc(MAX * sizeof(float));
    float somaElementos;
    float multElementos;
    int quantAdicionada = 0;
    int i, menu;
    int valoresIguais;
    int repete = 1;
    while (repete == 1)
    {
        printf("0- Sair:\n1-Inserir numeros racionais:\n2- Somar numeros racionais:\n3- Multiplicar numeros nacionais:\n4- Verificar se os numeros sao iguais:\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            return 0;
            break;
        case 1:
            quantAdicionada = preencherConjuntosRacionais(numerosRacionais, quantAdicionada);
            for (i = 0; i < quantAdicionada; i++)
            {
                printf("%.2f\n", numerosRacionais[i]);
            }
            break;
        case 2:
            somaElementos = somarElementos(numerosRacionais, quantAdicionada);
            printf("%.2f\n", somaElementos);
            break;
        case 3:
            multElementos = multiplicarElementos(numerosRacionais, quantAdicionada);
            printf("%.2f\n", multElementos);
            break;
        case 4:
            valoresIguais = elementosIguais(numerosRacionais, quantAdicionada);
            if (valoresIguais == 1)
                printf("Os numeros sao iguais.\n");
            else
                printf("Os numeros nao sao iguais.\n");
            break;
        default:
            printf("Valor invalido.\n");
        }
    }

    return 0;
}

float preencherConjuntosRacionais(float *numerosRacionais, int quantInserida)
{
    printf("Digite um numero pertencente ao conjunto dos numeros racionais:\n");
    scanf("%f", &numerosRacionais[quantInserida]);

    return quantInserida + 1;
}
float somarElementos(float *numerosRacionais, int quantAdicionada)
{
    int i;
    float soma = 0;
    for (i = 0; i < quantAdicionada; i++)
        soma += numerosRacionais[i];
    return soma;
}
float multiplicarElementos(float *numerosRacionais, int quantAdicionada)
{
    int i;
    float mult = 1;
    for (i = 0; i < quantAdicionada; i++)
        mult = mult * numerosRacionais[i];
    return mult;
}
int elementosIguais(float *numerosRacionais, int quantAdicionada)
{
    int i, j, igual;

    for (i = 0; i <= quantAdicionada; i++)
    {
        for (j = i + 1; j < quantAdicionada; j++)
        {
            if (numerosRacionais[j] == numerosRacionais[i])
                igual = 1;
            else
                igual = 0;
        }
    }
    if (igual == 1)
        return 1;
    else
        return 0;
}
