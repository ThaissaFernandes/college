#include <stdio.h>


void preencheVetor(int vetor[]);
void bubbleSort(int vetor[], int tamanho);
void selectionSort(int vetor[], int tamanho);
void InsertionSort(int vetor[], int tamanho);
void imprimirVetor(int vetor[], int tamanho);

int main()
{
    int vetor[10];
    int tamanho = 10;
    int repete = 1;
    int menu;
    preencheVetor(vetor);

    while (repete == 1){
        printf("0 - Sair:\n1 - BubbleSort:\n2 - SelectiionSort:\n3 - InsertionSort:\n");
        scanf("%d", &menu);
        switch(menu){
            case 0:
                return 0;
            break;
            case 1:
                bubbleSort(vetor, tamanho);
                imprimirVetor(vetor, tamanho);
            break;
            case 2:
                selectionSort(vetor, tamanho);
                imprimirVetor(vetor,tamanho);
            break;
            case 3:
                InsertionSort(vetor, tamanho);
                imprimirVetor(vetor, tamanho);
            break;
            default:
                printf("Comando invalido.\n");
        }
    }
    return 0;
}

 void preencheVetor(int vetor[]){
    vetor[0] = 7;
    vetor[1] = 3;
    vetor[2] = 5;
    vetor[3] = 19;
    vetor[4] = 43;
    vetor[5] = 11;
    vetor[6] = 29;
    vetor[7] = 13;
    vetor[8] = 13;
    vetor[9] = 37;
}

void bubbleSort(int vetor[], int tamanho){
    int i;
    int j;
    int aux;
    for(i = 0; i< tamanho - 1; i++){
        for(j = 1; j < tamanho - 1; j++){
            if(vetor[j] < vetor[j - 1]){
                aux = vetor[j];
                vetor[j] = vetor[j - 1];
                vetor[j - 1] = aux;
            }
        }
    }
}

void selectionSort(int vetor[], int tamanho){
    int i;
    int j;
    int menorElemento;
    int x;
    for(i = 0; i<tamanho - 1; i++){
        menorElemento = i;
        for(j = i + 1; j < tamanho; j++){
            if(vetor[j] <vetor[menorElemento]){
                menorElemento = j;
            }
        }
    x = vetor[menorElemento];
    vetor[menorElemento] = vetor[i];
    vetor[i] = x;
    }
}

void InsertionSort(int vetor[], int tamanho){
    int i;
    int j;
    int x;
    for (i = 1; i < tamanho; i++){
        x = vetor[i];
        j = i - 1;
        while (x < vetor[j] && j>=0){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = x;
    }
}

void imprimirVetor(int vetor[], int tamanho){
    int i = 0;
    printf("Vetor ordenado:\n");
    while (i < tamanho){
        printf("%d\n", vetor[i]);
        i++;
    }
}
