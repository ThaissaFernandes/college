#include<stdio.h>
#include<math.h>

typedef struct ponto{
	int x;
	int y;
}ponto;

ponto inicializacao (int x, int y);
ponto lerPonto ();
int analisarQuadrante(ponto p1);
void analisarPontoQuadrante (int quadrante, ponto p1);
ponto alterarPonto (ponto p1);
void distanciaDoisPontos (ponto p1);

int main (){
	ponto p1 = inicializacao(0,0);
	ponto p2 = inicializacao(0,0);
	int quadrante, menu, menuQuadrante, repeteMenu = 1;
	float distancia;


    while (repeteMenu== 1){
	printf("1-Dar valor ao ponto.\n2-Verificar quadrante.\n3- Comparar quadrante.\n4- Alterar valor do ponto.\n5- Distancia de dois pontos.\n6- Maior valor da coordenada de um ponto.\n");
	scanf("%d", &menu);
	while(menu<0||menu>6){
        printf("Numero invalido.\nDigite novamente:\n");
        scanf("%d", &menu);
	}

	switch(menu){
        case 1:
            p1 = lerPonto();
        break;
        case 2:
            quadrante = analisarQuadrante(p1);
        break;
        case 3:
            printf("Digite um dos numeros abaixo para verificar quadrante:\n");
            printf("0- Centro\n1- Quadrante 1\n2- Quadrante 2\n3- Quadrante 3\n4-Quadrante 4\n5- Eixo y\n6- Eixo x\n");
            scanf("%d", &menuQuadrante);
            while(menuQuadrante<0||menuQuadrante>6){
                printf("Numero invalido.\nDigite novamente:\n");
                scanf("%d", &menuQuadrante);
            }
            analisarPontoQuadrante (menuQuadrante, p1);

        break;
        case 4:
            p1 = alterarPonto (p1);
        break;
        case 5:
            distanciaDoisPontos (p1);
        break;
        case 6:
            retornarValor(p1);
        break;
	}
    }

	return 0;
}

ponto inicializacao (int x, int y){
	ponto p1;
	p1.x = x;
	p1.y = y;

	return (p1);
}

ponto lerPonto (){
	ponto p1;
	printf("Digite o valor de x e de y:\n");
	scanf("%d %d", &p1.x, &p1.y);

	return (p1);
}

int analisarQuadrante(ponto p1){
	int quadrante, eixoX, eixoY;
	if (p1.x==0&&p1.y==0){
		printf("O ponto esta no centro do plano cartesiano.\n");
		quadrante = 0;
	}
	else if(p1.x>0&&p1.y>0){
		printf("O ponto esta no primeiro quadrante.\n");
		quadrante = 1;
	}
	else if (p1.x<0&&p1.y>0){
		printf("O ponto esta no segundo quadrante.\n");
		quadrante = 2;
	}
	else if (p1.x<0&&p1.y<0){
		printf("O ponto esta no terceiro quadrante.\n");
		quadrante = 3;
	}
	else if (p1.x>0&&p1.y<0){
		printf("O ponto esta no quarto quadrante.\n");
		quadrante = 4;
	}
    else if (p1.x == 0&&p1.y!=0){
		printf("O ponto esta sobre o eixo y.\n");
		quadrante = 5;
	}
	else if (p1.x!=0&&p1.y==0){
		printf("O ponto esta sobre o eixo x.\n");
		quadrante = 6;
	}
	return quadrante;
	}

    void analisarPontoQuadrante (int quadrante, ponto p1){
        int quadranteCorreto = analisarQuadrante(p1);
        if(quadrante == quadranteCorreto)
            printf("Quadrante correto.\n");
        else
            printf("Quadrante incorreto.\n");

    }

    ponto alterarPonto (ponto p1){
        printf ("Digite os novos valores de x e de y:\n");
        scanf("%d%d", &p1.x, &p1.y);

    return (p1);
    }
    void distanciaDoisPontos (ponto p1){
        ponto p2;
        float dist;
        printf("Digite x e y de p2:\n");
        scanf ("%d%d", &p2.x, &p2.y);
        dist = sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
        printf("A distancia entre os dois pontos e: %.2f\n", dist);
    }
    void retornarValor(ponto p1){
        if(p1.x>p1.y)
            printf("X e maior.\nValor de x: %d\n", p1.x);
        else if(p1.y>p1.x)
            printf("Y e maior.\nValor de y: %d\n", p1.y);
        else if(p1.y==p1.x)
            printf("X e Y sao iguais.\nValor de x de y: %d\n", p1.y);
    }


