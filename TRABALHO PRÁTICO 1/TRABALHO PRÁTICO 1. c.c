#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define QUANTJOGADORES 8
#define QUANTCARTAS 5

typedef struct carta{
    int naipe;
    int valor;
    int forcaCarta;
}Carta;
/*Struct das cartas pertencentes ao baralho.*/

typedef struct Baralho{
    Carta vetor[40];
}Baralho;
/*Struct das cartas do baralho, de forma que ela e uma estrutura do tipo "pilha".*/

typedef struct baralhoPilha{
    int topo;
    Carta vetorCartas[40];

}BaralhoPilha;
/*Struct que controla o topo do baralho.*/

typedef struct Jogador{
    Carta CartasMao[QUANTCARTAS];
    struct Jogador *proximo;
    int vidas;
    int numero;
    int rodadaFaz;
    int rodadaFez;
}Jogador;
/*Struct dos jogadores.*/

typedef struct listaJogadores{
    Jogador *primeiroJogador;
}ListaJogadores;
/*Struct que controla os jogadores, de forma que eles sao da estrutura "lista".*/

typedef struct fila{
    int inicio;
    int fim;
    int tamanho;
    Jogador** vetor;
}Fila;
/*Struct que controla os jogadores, de forma que eles sao da estrutura "fila". O tamanho maximo no vetor e oito, visto que a quantidade maxima de jogadores que um jogo pode ter.*/

Baralho *criarBaralho(); /*Funcao utilizada para criar baralho.*/
void embaralhar(Baralho *baralho, BaralhoPilha *cartasPilhas); /*Funcao responsavel por embaralhar o baralho.*/
BaralhoPilha *CriaPilhaCartas(); /*Funcao responsavel por criar a pilha de cartas do baralho.*/
void empilharBaralho(BaralhoPilha *cartasPilha, Carta valor); /*Funcao responsavel por empilhar a pilha o baralho embaralhado com o auxilio da funcao "embaralhar".*/
Carta desempilharBaralho(BaralhoPilha *cartasPilha); /*Funcao responsavel por desempilhar o baralho, de forma a passar a carta armazenada na auxiliar (antigo topo)para o jogador.*/
ListaJogadores *listaDeJogadores(); /*Funcao responsavel por criar a fila de jogadores que prticiparao das partidas.*/
int inserirLista(ListaJogadores *listaJogadores, int i, BaralhoPilha *cartasPilha); /*Funcao responsavel por criar jogadores e distribuir as cartas desempilhadas do baralho para os jogadores.*/
void imprimirCartas(Carta cartaImprimida, int numeroCarta);/*Funcao responsavel por nomear as cartas do baralho de acordo com seus devidos valores e naipes.*/
void imprimirDadosJogadores(Jogador *jogadorImprimido, int quantCartas); /*Funcao responsavel por imprimir os dados do jogador, como vidas.*/
void imprimirListaJogadores(ListaJogadores *listaJogadores, int quantCartas); /*Funcao responsavel por imprimir lista de jogadores.*/
void compararCartas(Carta *cartasMesa, int quantJogadores, Fila *filaJogadores, FILE *log); /*Funcao responsavel por  comparar as cartas e retornar a posicao da carta mais forte.*/
void imprimirQuantRodadas(Fila *filaJogadores, int quantJogadores, int quantCartas, FILE *log); /*Funcao responsavel por controlar a quantas de vezes que cada jogador faz.*/
void escolherCarta(Carta *cartasMesa, Fila *filaJogadores, int quantCartas, FILE *log); /*Funcao responsavel por mostrar qual carta os jogadores escolheram.*/
void realocarCartas(Jogador *jogador, int numeroCarta, int  quantCartas); /*Funcao responsavel por realocar cartas na mao dos jogadores conforme as rodadas acontecem.*/
int retirarVidas(ListaJogadores *listaJogadores, FILE *log); /*Funcao responsavel por retirar vidas com base na comparacao de rodadas feitas com o numero de rodadas que o jogador disse fazer anteriormente.*/
void controlaRodada(int quantCartas, Carta *cartasMesa, Fila *filaJogadores, int quantJogadores, FILE *log); /*Funcao responsavel por controlar o numero de cartas das partidas, de forma que em partidas impares as cartas diminuem e em partidas pares as cartas aumentam.*/
void distribuirCartas(BaralhoPilha *cartasPilha, ListaJogadores *listaJogadores, int cartasDistribuidas); /*Funcao responsavel por  distribuir  cartas.*/
void controlePartida(ListaJogadores *listaJogadores, BaralhoPilha *cartasPilha, Baralho *baralho, Carta *cartasMesa, int quantJogadores, Fila *filaJogadores, FILE *log); /*Funcao responsavel por  controlar todos os aspectos da partida, como  distribuicao de cartas, controle de retirada de cartas, e impressao dos jogadores.*/
Fila *criaFila(); /*Funcao responsavel por  criar fila de jogadores.*/
void enfileirar(Fila *filaJogadores, ListaJogadores *listaJogadores, int primeiroJogadorPartida); /*Funcao responsavel por  enfileirar jogadores a cada partida, visto que a cada partida os jogadores que zerarem as vidas serao eliminados.*/
void removerElementoPorPosicaoLista(ListaJogadores *listaJogadores, int numeroJogador, FILE *log); /*Funcao responsavel por eliminar um jogador da partida quando as vidas destes acabam.*/
void imprimirValorCarta(FILE *log, Carta cartaImprimida); /*Funcao responsavel por mostrar a carta escolhida por determinado jogador no log.*/


int main(){
    FILE *log = fopen("log.txt","w");
    srand(time(NULL));/*Foi utilizado para embaralhar de diferentes formas a funcao "embaralhar, de forma que se duas partidas seguidas forem jogadas, a distribuicao das cartas no baralho sera diferente."*/
    Carta *cartasMesa = (Carta*)malloc(8 * sizeof (Carta));
    int partidas = 0;
    int quantCartas = 5;
    int i;
    int quantJogadores;
    int listaInserir;
    Baralho *baralho = criarBaralho();
    BaralhoPilha *cartasPilha = CriaPilhaCartas();
    Fila *filaJogadores = criaFila();
    ListaJogadores *listaJogadores = listaDeJogadores();
    fputs("Iniciou-se o jogo 'Fedaput'\n", log);
    printf("**************************** BEM-VINDO AO JOGO 'FEDAPUT*' ****************************\n\n\n\n");
    printf("Quantos jogadores participarao da partida:\n1 - Dois jogadores:\n2 - Tres jogadores:\n3 - Quatro jogadores:\n4 - Cinco jogadores:\n5 - Seis jogadores:\n6 - Sete jogadores:\n7 - Oito jogadores:\n");
    scanf("%d", &quantJogadores);
    while(quantJogadores<1||quantJogadores>7){
        printf("Quantidade de jogadores invalida.\nDigite novamente:\n");
        scanf("%d", &quantJogadores);
    }
    for(i = 1; i<= quantJogadores + 1; i++){
         listaInserir = inserirLista(listaJogadores, i, cartasPilha);
    }
    controlePartida(listaJogadores, cartasPilha, baralho, cartasMesa, quantJogadores, filaJogadores, log);
    fclose(log);
return 0;
}

Baralho *criarBaralho(){
    Baralho *baralho = (Baralho*)malloc(sizeof(Baralho));
    int tamanhoBaralho = 4;
    int i;
    int j;

    baralho->vetor[0].naipe = 1;
    baralho->vetor[0].valor = 4;
    baralho->vetor[0].forcaCarta = 40;
    baralho->vetor[1].naipe = 2;
    baralho->vetor[1].valor = 7;
    baralho->vetor[1].forcaCarta = 39;
    baralho->vetor[2].naipe = 3;
    baralho->vetor[2].valor = 1;
    baralho->vetor[2].forcaCarta = 38;
    baralho->vetor[3].naipe = 4;
    baralho->vetor[3].valor = 7;
    baralho->vetor[3].forcaCarta = 37;

         for(j = 3; j>0; j--){
                 for(i = 1; i<5; i++){
                    if(!(i == 3&&j == 1)){
                        baralho->vetor[tamanhoBaralho].naipe = i;
                        baralho->vetor[tamanhoBaralho].valor = j;
                        baralho->vetor[tamanhoBaralho].forcaCarta = 40 - tamanhoBaralho;
                    tamanhoBaralho++;
            }
        }
    }
         for(j = 10; j>7; j--){
                 for(i = 1; i<5; i++){
                        baralho->vetor[tamanhoBaralho].naipe = i;
                        baralho->vetor[tamanhoBaralho].valor = j;
                        baralho->vetor[tamanhoBaralho].forcaCarta = 40 - tamanhoBaralho;
                    tamanhoBaralho++;
        }
    }
        for(j = 7; j>3; j--){
                 for(i = 1; i<5; i++){
                    if(!((i == 1&&j == 4)|| (i == 2 &&j == 7)||(i == 4&&j == 7))){
                        baralho->vetor[tamanhoBaralho].naipe = i;
                        baralho->vetor[tamanhoBaralho].valor = j;
                        baralho->vetor[tamanhoBaralho].forcaCarta = 40 - tamanhoBaralho;
                    tamanhoBaralho++;
            }

        }
    }
    return baralho;
}
/*Funcao utilizada para criar baralho.*/
/*ForcaValor e uma variavel utilizada para considerar a forca das cartas, levando em cosideracao a manilha e o restante das cartas.*/

void embaralhar(Baralho *baralho, BaralhoPilha *cartasPilha){
    Carta auxCarta;
    int i;
    int baralhoEmbaralhado;
    for(i = 0; i<40; i++){
        baralhoEmbaralhado =  rand() % 40;
        auxCarta = baralho->vetor[i];
        baralho->vetor[i] = baralho->vetor[baralhoEmbaralhado];
        baralho->vetor[baralhoEmbaralhado] = auxCarta;
    }
    cartasPilha->topo = 0;
    for(i = 0; i<40; i++)
       empilharBaralho(cartasPilha,baralho->vetor[i]);

}
/*Funcao responsavel por embaralhar o baralho.*/

BaralhoPilha *CriaPilhaCartas(){
    BaralhoPilha *cartasPilha = (BaralhoPilha*)malloc(sizeof(BaralhoPilha));
    cartasPilha->topo = 0;
return cartasPilha;
}
/*Funcao responsavel por criar a pilha de cartas do baralho.*/

void empilharBaralho(BaralhoPilha *cartasPilha, Carta valor){
        cartasPilha->vetorCartas[cartasPilha->topo] = valor;
        cartasPilha->topo++;

}
/*Funcao responsavel por empilhar a pilha o baralho embaralhado com o auxilio da funcao "embaralhar".*/

Carta desempilharBaralho(BaralhoPilha *cartasPilha){
    Carta aux;
    aux = cartasPilha->vetorCartas[cartasPilha->topo - 1];
    cartasPilha->topo--;
    return aux;
}
/*Funcao responsavel por desempilhar o baralho, de forma a passar a carta armazenada na auxiliar (antigo topo)para o jogador.*/

ListaJogadores *listaDeJogadores(){
    ListaJogadores *listaJogadores = (ListaJogadores*)malloc(sizeof(ListaJogadores));
    listaJogadores->primeiroJogador = NULL;
    return listaJogadores;
}
/*Funcao responsavel por criar a lista de jogadores que prticiparao das partidas.*/

int inserirLista(ListaJogadores *listaJogadores, int i, BaralhoPilha *cartasPilha){
    int j;
    Jogador *auxJogador = listaJogadores->primeiroJogador;
    Jogador *novoJogador = ( Jogador*)malloc(sizeof( Jogador));
    if(novoJogador == NULL)
        return 0;
    else {
         novoJogador->vidas = 5;
         novoJogador->numero = i;
         novoJogador->proximo = NULL;
         novoJogador->rodadaFaz = 0;
         novoJogador->rodadaFez = 0;

        if(listaJogadores->primeiroJogador == NULL){
             listaJogadores->primeiroJogador = novoJogador;
        }
        else{
            while(auxJogador->proximo != NULL)
                auxJogador = auxJogador->proximo;
            auxJogador->proximo = novoJogador;
        }
    }
    return 1;
}
/*Funcao responsavel por criar jogadores e distribuir as cartas desempilhadas do baralho para os jogadores.*/

void imprimirCartas(Carta cartaImprimida, int numeroCarta){
   printf("%d - [", numeroCarta);
    switch(cartaImprimida.valor){
        case 1:
            printf("As");
        break;
        case 2:
            printf("2");
        break;
        case 3:
            printf("3");
        break;
        case 4:
            printf("4");
        break;
        case 5:
            printf("5");
        break;
        case 6:
            printf("6");
        break;
        case 7:
            printf("7");
        break;
        case 8:
            printf("Q");
        break;
        case 9:
            printf("J");
        break;
        case 10:
            printf("K");
        break;
    }
    printf(" de ");
    switch(cartaImprimida.naipe){
        case 1:
            printf("Paus");
        break;
        case 2:
            printf("Copas");
        break;
        case 3:
            printf("Espadas");
        break;
        case 4:
            printf("Ouros");
        break;
    }
    printf("]\n");
}
/*Funcao responsavel por nomear as cartas do baralho de acordo com seus devidos valores e naipes.*/

void imprimirDadosJogadores(Jogador *jogadorImprimido, int quantCartas){
    int i;
    printf("\nJogador %d\n", jogadorImprimido->numero);
    printf("Quantidade de vidas: %d\n", jogadorImprimido->vidas);
    printf("Cartas distribuidas:\n");
    for(i = 0; i<quantCartas; i++){
        imprimirCartas(jogadorImprimido->CartasMao[i], i + 1);
    }
}
/*Funcao responsavel por imprimir os dados do jogador, como vidas.*/

void imprimirListaJogadores(ListaJogadores *listaJogadores, int quantCartas){
    Jogador *auxJogador = listaJogadores->primeiroJogador;

    while (auxJogador != NULL){
        imprimirDadosJogadores(auxJogador, quantCartas);
        auxJogador = auxJogador->proximo;
    }
}
/*Funcao responsavel por imprimir lista de jogadores.*/

void compararCartas(Carta *cartasMesa, int quantJogadores, Fila *filaJogadores, FILE *log){
    int i;
    int j;
    int cartaMaisForte = 0;
    for(i = 1; i<=quantJogadores; i++){
        if(cartasMesa[i].forcaCarta>cartasMesa[cartaMaisForte].forcaCarta)
            cartaMaisForte = i;
    }
    for(j = 0; filaJogadores->tamanho != j; j++){
        if(j == cartaMaisForte){
            filaJogadores->vetor[j]->rodadaFez++;
            printf("Jogador %d ganhou a rodada!", filaJogadores->vetor[j]->numero);
            fprintf(log,"Jogador %d ganhou a rodada!\n", filaJogadores->vetor[j]->numero);
        }
    }


}
/*Funcao responsavel por  comparar as cartas e retornar a posicao da carta mais forte.*/

void imprimirQuantRodadas(Fila *filaJogadores, int quantJogadores, int quantCartas, FILE *log){
    int i;
    int j = 0;
    int soma = 0;
    while (filaJogadores->tamanho != j){
        imprimirDadosJogadores(filaJogadores->vetor[j], quantCartas);
        printf("\nQuantas rodadas voce faz?\n");
        scanf("%d", &i);
        while(i<0||i>5||soma + i == quantJogadores*5){
            printf("Valor invalido.\nDigite novamente:\n");
            scanf("%d", &i);
        }
        soma += i;
        filaJogadores->vetor[j]->rodadaFaz = i;
       fprintf(log, "Jogador %d disse que faz %d rodada(s).\n", filaJogadores->vetor[j]->numero, i);
       j++;

    }
}
/*Funcao responsavel por controlar a quantas de vezes que cada jogador faz.*/

void escolherCarta(Carta *cartasMesa, Fila *filaJogadores, int quantCartas, FILE *log){
    int i;
    int numeroCarta;
       for(i = 0; i != filaJogadores->tamanho; i++){
        imprimirDadosJogadores(filaJogadores->vetor[i], quantCartas);
        printf("\nQual carta voce escolhera?\n");
        scanf("%d", &numeroCarta);
        printf("1 - %d\n", filaJogadores->tamanho);
        while(numeroCarta<1||numeroCarta>quantCartas){
            printf("Valor invalido.\nDigite novamente:\n");
            scanf("%d", &numeroCarta);
        }
        fprintf(log, "Carta escolhida pelo jogador %d: ", filaJogadores->vetor[i]->numero);
        printf("2 - %d\n", filaJogadores->tamanho);
        imprimirValorCarta(log, filaJogadores->vetor[i]->CartasMao[numeroCarta - 1]);
        printf("3 - %d\n", filaJogadores->tamanho);
        cartasMesa[i] = filaJogadores->vetor[i]->CartasMao[numeroCarta - 1];
        printf("4 - %d\n", filaJogadores->tamanho);
        realocarCartas(filaJogadores->vetor[i], numeroCarta, quantCartas);
        printf("5 - %d\n", filaJogadores->tamanho);
       }
        quantCartas--;
}
/*Funcao responsavel por mostrar qual carta os jogadores escolheram.*/

void realocarCartas(Jogador *jogador, int numeroCarta, int  quantCartas){
    int i;

    for (i  = numeroCarta  - 1; i < quantCartas - 1; i++){
         jogador->CartasMao[i] = jogador->CartasMao[i + 1];
    }
}
/*Funcao responsavel por realocar cartas na mao dos jogadores conforme as rodadas acontecem.*/

int retirarVidas(ListaJogadores *listaJogadores, FILE *log){
     int j;
     int i = 0;
     Jogador *auxJogador = listaJogadores->primeiroJogador;
     for(j = 0; auxJogador!= NULL; j++){
        if(auxJogador->rodadaFez > auxJogador->rodadaFaz)
                auxJogador->vidas = auxJogador->vidas - (auxJogador->rodadaFez - auxJogador->rodadaFaz);

        if(auxJogador->rodadaFez < auxJogador->rodadaFaz)
                auxJogador->vidas = auxJogador->vidas - (auxJogador->rodadaFaz - auxJogador->rodadaFez);
        fprintf(log, "Jogador %d permanece com %d vida(s)\n", auxJogador->numero, auxJogador->vidas);

        auxJogador->rodadaFez = 0;
        if(auxJogador->vidas<=0)
            removerElementoPorPosicaoLista(listaJogadores, auxJogador->numero, log);
        else
            i++;
        auxJogador = auxJogador->proximo;

    }
    return i - 1 ;
}
/*Funcao responsavel por retirar vidas com base na comparacao de rodadas feitas com o numero de rodadas que o jogador disse fazer anteriormente.*/

void controlaRodada(int quantCartas, Carta *cartasMesa, Fila *filaJogadores, int quantJogadores, FILE *log){
   int i;
   int j = quantCartas;
    for(i = 1; i <= quantCartas; i++){
        printf("\n\n******************************* RODADA %d *******************************\n", i);
        fprintf(log, "Comecou a rodada: %d\n", i);
        escolherCarta(cartasMesa, filaJogadores, j, log);
        compararCartas(cartasMesa, quantJogadores, filaJogadores, log);
        j--;
    }

}
/*Funcao responsavel por controlar o numero de cartas das partidas, de forma que em partidas impares as cartas diminuem e em partidas pares as cartas aumentam.*/

void distribuirCartas(BaralhoPilha *cartasPilha, ListaJogadores *listaJogadores, int cartasDistribuidas){
    int j;
    Jogador *auxJogador = listaJogadores->primeiroJogador;

        while(auxJogador != NULL){
            for (j = 0; j<cartasDistribuidas; j++){
                auxJogador->CartasMao[j] = desempilharBaralho(cartasPilha);
            }
            auxJogador = auxJogador->proximo;
        }
    }
/*Funcao responsavel por  distribuir  cartas.*/

void controlePartida(ListaJogadores *listaJogadores, BaralhoPilha *cartasPilha, Baralho *baralho, Carta *cartasMesa, int quantJogadores, Fila *filaJogadores, FILE *log){
    int quantCartas = 5;
    int contabilizaPartida = 1;
    int incrementando = 0;
    int primeiroJogadorPartida = 1;
    while(quantJogadores>0){
        fprintf(log,"Iniciou-se a partida: %d\n", contabilizaPartida);
        printf("\n\n******************************* PARTIDA %d *******************************\n", contabilizaPartida);
        embaralhar(baralho, cartasPilha);
        distribuirCartas(cartasPilha, listaJogadores, quantCartas);
        enfileirar(filaJogadores,listaJogadores, primeiroJogadorPartida);
        imprimirQuantRodadas(filaJogadores, quantJogadores + 1, quantCartas, log);
        controlaRodada(quantCartas, cartasMesa, filaJogadores, quantJogadores, log);
        quantJogadores = retirarVidas(listaJogadores, log);
        contabilizaPartida++;
        if(primeiroJogadorPartida!= quantJogadores + 1)
            primeiroJogadorPartida++;
        else
            primeiroJogadorPartida = 1;
        if(incrementando == 0)
            quantCartas--;
        else
            quantCartas++;
        if(quantCartas == 1)
            incrementando = 1;
        else if (quantCartas == 5)
            incrementando = 0;
    }
    fprintf(log, "Jogador %d ganhou o jogo.\n", listaJogadores->primeiroJogador->numero);
    printf("\n\n******************************* O JOGADOR %d GANHOU O JOGO! *******************************\n", listaJogadores->primeiroJogador->numero);
}
/*Funcao responsavel por  controlar todos os aspectos da partida, como  distribuicao de cartas, controle de retirada de cartas, e impressao dos jogadores.*/

Fila *criaFila (){
 Fila *f = (Fila*)malloc( sizeof(Fila));
 f->inicio = 0;
 f->fim = 0;
 f->tamanho = 0;
 return f;
}
/*Funcao responsavel por  criar fila de jogadores.*/

void enfileirar(Fila *filaJogadores, ListaJogadores *listaJogadores, int primeiroJogadorPartida)
{
    filaJogadores->tamanho = 0;
    filaJogadores->fim = 0;
    Jogador* vetor = (Jogador*)malloc(40 * sizeof (Jogador));
    filaJogadores->vetor = vetor;
    Jogador *auxJogador = listaJogadores->primeiroJogador;
    while(auxJogador != NULL){
        if(auxJogador->numero >= primeiroJogadorPartida){
            filaJogadores->tamanho++;
            filaJogadores->vetor[filaJogadores->fim] = auxJogador;
            filaJogadores->fim++;
        }
        auxJogador = auxJogador->proximo;

    }
    auxJogador = listaJogadores->primeiroJogador;
    while (auxJogador->numero != primeiroJogadorPartida && auxJogador != NULL){
                printf("111111111\n");
        filaJogadores->tamanho++;
                printf("222222222\n");
        filaJogadores->vetor[filaJogadores->fim] = auxJogador;
                printf("333333333\n");
        filaJogadores->fim++;
                printf("444444444\n");
        auxJogador = auxJogador->proximo;
    }
}
/*Funcao responsavel por  enfileirar jogadores a cada partida, visto que a cada partida os jogadores que zerarem as vidas serao eliminados.*/

void removerElementoPorPosicaoLista(ListaJogadores *listaJogadores, int numeroJogador, FILE *log)
{
    int jogadorRemovido;
    Jogador *aux = listaJogadores->primeiroJogador;
    Jogador *auxProximo = listaJogadores->primeiroJogador->proximo;
    if(listaJogadores->primeiroJogador->proximo != NULL){
    if (numeroJogador == aux->numero)
    {
        jogadorRemovido = aux->numero;
        free(aux);
        listaJogadores->primeiroJogador = auxProximo;
    }
    else
    {
        while (auxProximo->numero != numeroJogador)
        {
            aux = aux->proximo;
            auxProximo = auxProximo->proximo;
        }
        jogadorRemovido = auxProximo->numero;
        aux->proximo = auxProximo->proximo;
        free(auxProximo);
        }
        fprintf(log, "Jogador %d saiu da partida.\n", jogadorRemovido);
        printf("\n**************************** O JOGADOR %d SAIU DA PARTIDA! ****************************\n",jogadorRemovido);
    }

    }
/*Funcao responsavel por eliminar um jogador da partida quando as vidas destes acabam.*/

void imprimirValorCarta(FILE *log, Carta cartaImprimida){
    switch(cartaImprimida.valor){
        case 1:
            fprintf(log, "As");
        break;
        case 2:
            fprintf(log, "2");
        break;
        case 3:
            fprintf(log, "3");
        break;
        case 4:
            fprintf(log, "4");
        break;
        case 5:
            fprintf(log, "5");
        break;
        case 6:
            fprintf(log, "6");
        break;
        case 7:
            fprintf(log, "7");
        break;
        case 8:
            fprintf(log, "Q");
        break;
        case 9:
            fprintf(log, "J");
        break;
        case 10:
            fprintf(log, "K");
        break;
    }
    fprintf(log, " de ");
    switch(cartaImprimida.naipe){
        case 1:
            fprintf(log, "Paus\n");
        break;
        case 2:
            fprintf(log, "Copas\n");
        break;
        case 3:
            fprintf(log, "Espadas\n");
        break;
        case 4:
            fprintf(log, "Ouros\n");
        break;
    }
}
/*Funcao responsavel por mostrar a carta escolhida por determinado jogador no log.*/
