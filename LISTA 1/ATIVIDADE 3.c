#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int *preencherConjunto();
int *unirConjuntos(int *conjunto1, int *conjunto2, int quantRecebida1, int quantRecebida2);
int *CriarConjuntoVazio();
int inserirElemento(int *conjunto, int quantInserida);
int removerElemento(int quantInserida);
int interseccaoConjuntos(int *conjunto1, int *conjunto2, int quantRecebida1, int quantRecebida2, int *conjuntoInterseccao);
int diferancaConjunto(int *conjunto1, int *conjunto2, int quantRecebida1, int quantRecebida2, int *diferencaConjunto);
int verificarElemento(int elemento, int *conjunto, int quantrecebida);
int menorValor(int *conjunto, int quantRecebida);
int maiorValor(int *conjunto, int quantRecebida);
int conjuntosIguais(int *conjunto1, int *conjunto2, int quantRecebida1, int quantRecebida2);
int verificarTamanho(int quantRecebida);
int verificarConjuntoVazio(int quantRecebida);

int main()
{
    int *conjunto1 = (int)malloc(MAX * sizeof(int));
    int *conjunto2 = (int)malloc(MAX * sizeof(int));
    int *conjuntoUniao = (int)malloc((MAX) * sizeof(int));
    int *conjuntoVazio = (int)malloc((MAX) * sizeof(int));
    int *conjuntoInterseccao = (int)malloc((MAX) * sizeof(int));
    int *diferencaConjunto = (int)malloc((MAX) * sizeof(int));
    int quantRecebida1 = 0;
    int quantRecebida2 = 0;
    int tamUniao;
    int menorValor1 = 0, menorValor2 = 0;
    int maiorValor1 = 0, maiorValor2 = 0;
    int i, menu;
    int constante = -1;
    int elemento, var1, var2;
    int quantRecebidaInterseccao = 0;
    int quantRecebidaDiferenca = 0;
    int menuConjunto;
    int iguais;
    int vertam1, vertam2;
    int vazio1, vazio2;
    while (constante == -1)
    {
        printf("Digite a opcao desejada:\n0 - Sair:\n1 - Uniao dos conjuntos:\n2 - Criar conjunto vazio:\n3 - Preencher conjunto:\n4 - Remover elemento dos conjuntos:\n5 - Interseccao de conjuntos:\n6 - Diferenca entre dois vetores:\n7 - Conferir se um numero pertence a um conjunto:\n8 - Menor valor:\n9 - Maior valor:\n10 - Verificar se conjuntos sao iguais:\n11 - Verificar tamanho do conjunto:\n12 - Testar se um conjunto e vazio\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 0:
            return 0;
            break;
        case 1:
            conjuntoUniao = unirConjuntos(conjunto1, conjunto2, quantRecebida1, quantRecebida2);
            tamUniao = quantRecebida1 + quantRecebida2;
            printf("Conjunto uniao:\n");
            if (tamUniao == 0)
                printf("Vazio!\n");
            for (i = 0; i < tamUniao; i++)
            {
                printf("%d\n", conjuntoUniao[i]);
            }
            break;
        case 2:
            conjuntoVazio = CriarConjuntoVazio();
            break;
        case 3:
            printf("Escolha em qual conjunto deseja-se inserir um elemento:\n1- Conjunto 1:\n2- Conjunto 2:\n");
            scanf("%d", &menuConjunto);
            while (menuConjunto > 2 || menuConjunto < 1)
            {
                printf("Numero invalido.\nDigite novamente:\n");
                scanf("%d", &menuConjunto);
            }
            if (menuConjunto == 1)
                quantRecebida1 = inserirElemento(conjunto1, quantRecebida1);
            else
                quantRecebida2 = inserirElemento(conjunto2, quantRecebida2);
            break;
        case 4:
            printf("Escolha em qual conjunto deseja-se remover um elemento:\n1- Conjunto 1:\n2- Conjunto 2:\n");
            scanf("%d", &menuConjunto);
            while (menuConjunto > 2 || menuConjunto < 1)
            {
                printf("Numero invalido.\nDigite novamente:\n");
                scanf("%d", &menuConjunto);
            }
            if (menuConjunto == 1)
            {
                if (quantRecebida1 == 0)
                    printf("Conjunto vazio.\n");
                quantRecebida1 = removerElemento(quantRecebida1);
            }
            else
            {
                if (quantRecebida1 == 0)
                    printf("Conjunto vazio.\n");
                quantRecebida2 = removerElemento(quantRecebida2);
            }
            break;
        case 5:
            quantRecebidaInterseccao = interseccaoConjuntos(conjunto1, conjunto2, quantRecebida1, quantRecebida2, conjuntoInterseccao);
            printf("%d\n", quantRecebidaInterseccao);
            printf("Conjunto interseccao:\n");
            for (i = 0; i < quantRecebidaInterseccao; i++)
            {
                if (conjuntoInterseccao[i] != NULL)
                    printf("%d\n", conjuntoInterseccao[i]);
            }
            if (quantRecebidaInterseccao == 0)
                printf("Vazio!\n");
            break;
        case 6:
            quantRecebidaDiferenca = diferancaConjuntos(conjunto1, conjunto2, quantRecebida1, quantRecebida2, diferencaConjunto);
            if (quantRecebidaDiferenca != 0)
            {
                for (i = 0; i < quantRecebidaDiferenca; i++)
                {
                    printf("%d\n", diferencaConjunto[i]);
                }
            }
            else
                printf("Vazio.\n");
            break;
        case 7:
            printf("Digite um numero inteiro:\n");
            scanf("%d", &elemento);
            var1 = verificarElemento(elemento, conjunto1, quantRecebida1);
            if (var1 == 1)
                printf("Elemento pertence ao conjunto 1.\n");
            else
                printf("Elemento nao pertence ao conjunto 1.\n");
            var2 = verificarElemento(elemento, conjunto2, quantRecebida2);
            if (var2 == 1)
                printf("Elemento pertence ao conjunto 2.\n");
            else
                printf("Elemento nao pertence ao conjunto 2.\n");
            break;
        case 8:
            printf("Escolha o conjunto desejado para buscar o menor elemento:\n1- Conjunto 1:\n2- Conjunto 2:\n");
            scanf("%d", &menuConjunto);
            while (menuConjunto > 2 || menuConjunto < 1)
            {
                printf("Numero invalido.\nDigite novamente:\n");
                scanf("%d", &menuConjunto);
            }
            if (menuConjunto == 1)
            {
                if(quantRecebida1 == 0)
                    printf("Vazio!");
                else{
                menorValor1 = menorValor(conjunto1, quantRecebida1);
                printf("Menor elemento:\n");
                printf("%d\n", menorValor1);
                }
            }
            else
            {
                if(quantRecebida2 == 0)
                    printf("Vazio!");
                else{
                menorValor2 = menorValor(conjunto2, quantRecebida2);
                printf("Menor elemento:\n");
                printf("%d\n", menorValor2);
                }
            }
            break;
        case 9:
            printf("Escolha o conjunto desejado para buscar o maior elemento:\n1- Conjunto 1:\n2- Conjunto 2:\n");
            scanf("%d", &menuConjunto);
            while (menuConjunto > 2 || menuConjunto < 1)
            {
                printf("Numero invalido.\nDigite novamente:\n");
                scanf("%d", &menuConjunto);
            }
            printf("Maior elemento:\n");
            if (menuConjunto == 1)
            {
                if(quantRecebida1 == 0)
                    printf("Vazio!");
                else{
                maiorValor1 = maiorValor(conjunto1, quantRecebida1);
                printf("%d\n", maiorValor1);
                }
            }
            else
            {
                if(quantRecebida1 == 0)
                    printf("Vazio!");
                else{
                maiorValor2 = maiorValor(conjunto2, quantRecebida2);
                printf("%d\n", maiorValor2);
                }
            }
            break;
        case 10:
            iguais = conjuntosIguais(conjunto1, conjunto2, quantRecebida1, quantRecebida2);
            if (iguais == 1)
                printf("Os conjuntos sao iguais.\n");
            else
                printf("Os conjuntos sao diferentes.\n");
            break;
        case 11:
            printf("Escolha o conjunto em que se deseja buscar o tamanho:\n1- Conjunto 1:\n2- Conjunto 2:\n");
            scanf("%d", &menuConjunto);
            while (menuConjunto > 2 || menuConjunto < 1)
            {
                printf("Numero invalido.\nDigite novamente:\n");
                scanf("%d", &menuConjunto);
            }
            printf("Quantidade de elementos:\n");
            if (menuConjunto == 1)
            {
                vertam1 = verificarTamanho(quantRecebida1);
                printf("%d\n", vertam1);
            }
            else
            {
                vertam2 = verificarTamanho(quantRecebida2);
                printf("%d\n", vertam2);
            }
            break;
        case 12:
            printf("Escolha o conjunto em que se deseja verificar se e vazio:\n1- Conjunto 1:\n2- Conjunto 2:\n");
            scanf("%d", &menuConjunto);
            while (menuConjunto > 2 || menuConjunto < 1)
            {
                printf("Numero invalido.\nDigite novamente:\n");
                scanf("%d", &menuConjunto);
            }
            if (menuConjunto == 1)
            {
                vazio1 = verificarConjuntoVazio(quantRecebida1);
                if (vazio1 == 1)
                    printf("Conjunto vazio.\n");
                else
                    printf("Conjunto nao vazio.\n");
            }
            else
            {
                vazio2 = verificarConjuntoVazio(quantRecebida2);
                if (vazio1 == 1)
                    printf("Conjunto vazio.\n");
                else
                    printf("Conjunto nao vazio.\n");
            }
            break;
        default:
            printf("Comando invalido.\n");
        }
    }
    return 0;
}

int *preencherConjunto()
{
    int i;
    int *conjunto = (int)malloc(MAX * sizeof(int));
    printf("Digite os numeros pertencentes ao conjuntos:\n");
    for (i = 0; i < MAX; i++)
    {
        printf("Numero %d:", i + 1);
        scanf("%d", &conjunto[i]);
    }
    return conjunto;
}
int *unirConjuntos(int *conjunto1, int *conjunto2, int quantRecebida1, int quantRecebida2)
{
    int i, tamUniao = quantRecebida1 + quantRecebida2;
    int *conjuntoUniao = (int *)malloc((MAX) * sizeof(int));

    for (i = 0; i < quantRecebida1; i++)
    {
        conjuntoUniao[i] = conjunto1[i];
    }
    for (i = 0; i < quantRecebida2; i++)
    {
        conjuntoUniao[i + quantRecebida1] = conjunto2[i];
    }

    return conjuntoUniao;
}
int *CriarConjuntoVazio()
{
    int *conjuntoVazio = (int)malloc(MAX * sizeof(int));
    return conjuntoVazio;
}
int inserirElemento(int *conjunto, int quantInserida)
{
    printf("Insira um elemento ao conjunto:\n");
    scanf("%d", &conjunto[quantInserida]);

    return (quantInserida + 1);
}
int removerElemento(int quantInserida)
{

    return (quantInserida - 1);
}
int interseccaoConjuntos(int *conjunto1, int *conjunto2, int quantRecebida1, int quantRecebida2, int *conjuntoInterseccao)
{
    int i, j;
    int quantInserida = 0;
    for (i = 0; i < quantRecebida1; i++)
    {
        for (j = 0; j < quantRecebida2; j++)
        {
            if (conjunto1[i] == conjunto2[j])
            {
                conjuntoInterseccao[quantInserida] = conjunto1[i];
                quantInserida++;
            }
        }
    }
    return quantInserida;
}
int diferancaConjuntos(int *conjunto1, int *conjunto2, int quantRecebida1, int quantRecebida2, int *diferencaConjunto)
{
    int i, j;
    int quantInserida = 0;
    for (i = 0; i < quantRecebida1; i++)
    {
        for (j = 0; j < quantRecebida2; j++)
        {
            if (conjunto1[i] != conjunto2[j])
            {
                diferencaConjunto[quantInserida] = conjunto1[i];
                quantInserida++;
                diferencaConjunto[quantInserida] = conjunto2[j];
                quantInserida++;
            }
        }
    }
    return quantInserida;
}
int verificarElemento(int elemento, int *conjunto, int quantRecebida)
{
    int i;
    for (i = 0; i < quantRecebida; i++)
    {
        if (elemento == conjunto[i])
            return 1;
        else
            return 0;
    }
}
int menorValor(int *conjunto, int quantRecebida)
{
    int i, menorElemento = conjunto[0];

    for (i = 0; i < quantRecebida - 1; i++)
    {
        if (conjunto[i] <= conjunto[i + 1])
            menorElemento = conjunto[i];
        else
            menorElemento = conjunto[i + 1];
    }
    return menorElemento;
}
int maiorValor(int *conjunto, int quantRecebida)
{
    int i, maiorElemento = conjunto[0];
    for (i = 0; i < quantRecebida - 1; i++)
    {
        if (conjunto[i] <= conjunto[i + 1])
            maiorElemento = conjunto[i + 1];
        else
            maiorElemento = conjunto[i];
    }
    return maiorElemento;
}
int conjuntosIguais(int *conjunto1, int *conjunto2, int quantRecebida1, int quantRecebida2)
{
    int i, j;
    if (quantRecebida1 == quantRecebida2)
    {
        for (i = 0; i < quantRecebida1; i++)
        {
            for (j = 0; j < quantRecebida2; j++)
            {
                if (conjunto1[i] == conjunto2[j])
                    break;
                if (j == quantRecebida2 - 1)
                    return 0;
            }
        }
    }
    else
        return 0;
    return 1;
}
int verificarTamanho(int quantRecebida)
{
    return quantRecebida;
}
int verificarConjuntoVazio(int quantRecebida)
{
    if (quantRecebida == 0)
        return 1;
    else
        return 0;
}
