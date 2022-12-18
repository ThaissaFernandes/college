#include <stdio.h>
#include <stdlib.h>

typedef struct alunos
{
    char nome[30];
    int matricula;
    float notas[3];
    float media;
} alunos;

float fazerMedia(float notas[]);
void preencherVetor(alunos *alunos, int n);
int buscaSequencial(alunos *aluno, int n, int matriculaBuscada);
void ordena(alunos *aluno, int n);
int buscaBinaria(int matriculaBuscada, alunos *aluno, int n);
void imprimirArranjo(alunos *aluno, int matriculaEncontrada);

int main()
{
    int n;
    int matriculaBuscada;
    int matriculaEncontrada;
    int i;
    int j;
    printf("Digite o valor da variavel n:\n");
    scanf("%d", &n);

    alunos *aluno = (alunos *)malloc(n * sizeof(alunos));

    preencherVetor(aluno, n);

    printf("Digite a matricula buscada:\n");
    scanf("%d", &matriculaBuscada);
    matriculaEncontrada = buscaSequencial(aluno, n, matriculaBuscada);
    if (matriculaEncontrada != -1)
        imprimirArranjo(aluno, matriculaEncontrada);
    else
        printf("Matricula nao encontrada.\n");

    ordena(aluno, n);
    matriculaEncontrada = buscaBinaria(matriculaBuscada, aluno, n);
    if (matriculaEncontrada != -1)
        imprimirArranjo(aluno, matriculaEncontrada);
    else
        printf("Matricula nao encontrada.\n");

    return 0;
}

float fazerMedia(float notas[])
{
    float soma = 0;
    float media;
    int j;
    for (j = 0; j < 3; j++)
        soma += notas[j];
    media = soma / 3;
    return media;
}

void preencherVetor(alunos *aluno, int n)
{
    int i;
    int j;
    printf("Preencha o vetor:\n");
    for (i = 0; i < n; i++)
    {
        printf("Nome:\n");
        scanf("%s", &aluno[i].nome);
        setbuf(stdin, NULL);
        printf("Matricula:\n");
        scanf("%d", &aluno[i].matricula);
        for (j = 0; j < 3; j++)
        {
            printf("Nota %d:\n", j + 1);
            scanf("%f", &aluno[i].notas[j]);
        }
        aluno[i].media = fazerMedia(aluno[i].notas);
    }
}

int buscaSequencial(alunos *aluno, int n, int matriculaBuscada)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (aluno[i].matricula == matriculaBuscada)
            return i;
    }
    return -1;
}

void ordena(alunos *aluno, int n)
{
    int i, j;
    alunos aux;
    for (j = n - 1; j > 0; j--)
    {
        for (i = 0; i < j; i++)
        {
            if (aluno[1 + i].matricula < aluno[i].matricula)
            {
                aux = aluno[i];
                aluno[i] = aluno[i + 1];
                aluno[i + 1] = aux;
            }
        }
    }
}
int buscaBinaria(int matriculaBuscada, alunos *aluno, int n)
{
    int i;
    int esq = 0;
    int dir = n - 1;

    do
    {
        i = (dir + esq) / 2;
        if (matriculaBuscada > aluno[i].matricula)
            esq = i + 1;
        else
            dir = i - 1;

    } while (matriculaBuscada != aluno[i].matricula && esq <= dir);
    if (matriculaBuscada == aluno[i].matricula)
        return i;
    else
        return -1;
}
void imprimirArranjo(alunos *aluno, int matriculaEncontrada)
{
    int i;
    int j;
    printf("Nome:%s\nMatricula:%d\n", aluno[matriculaEncontrada].nome, aluno[matriculaEncontrada].matricula);
    for (j = 0; j < 3; j++)
        printf("Nota %d:%.2f\n", j + 1, aluno[matriculaEncontrada].notas[j]);
    printf("Media:%.2f\n", aluno[matriculaEncontrada].media);
}
