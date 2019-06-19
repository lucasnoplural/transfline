#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main(){	
	//input
	int qtdPontos;
	float n = 0; //amplia a figura em N vezes ou recebe o valor de k para cisalhamento
	int alfa; //ângulo para rotação da figura

	
	printf("Digite a qtd de pontos que sua figura possui no plano: ");
	scanf("%d", &qtdPontos);
	
	double vertices[qtdPontos][2];
	
	int ponto;
	int coordenada;
	
	for(ponto = 0; ponto < qtdPontos; ponto++){
		printf("\nPonto %d:", ponto+1);
		for(coordenada = 0; coordenada < 2; coordenada++){
			if((coordenada+1) % 2 != 0){	
				printf("\nDigite o valor de x: ");
			}else{
				printf("Digite o valor de y: ");
			}
			scanf("%lf", &vertices[ponto][coordenada]);
		}
	}
			
	//testando
	//imprimindo
	printf("\n\nCoordenadas no plano\n");
	
	for(ponto = 0; ponto < qtdPontos; ponto++){
		printf("\nPonto %d:", ponto+1);
		for(coordenada = 0; coordenada < 2; coordenada++){
			if((coordenada+1) % 2 != 0){	
				printf("\nx: %.2lf", vertices[ponto][coordenada]);
			}else{
				printf("\ny: %.2lf\n", vertices[ponto][coordenada]);
			}
		}
	}
	
	//menu
	int opcao;
	
	do{
		printf("\nMenu\n");
		printf("1. Ampliacao no eixo x de n unidades\n");
		printf("2. Rotacao para o angulo de alfa graus\n");
		printf("3. T(x ; y) = (-x ; y)\n");
		printf("4. Cisalhamento de k = n em relacao ao eixo x\n");
		printf("5. Sair\nOpcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("\nDigite o valor de n: "); //para o exercício 6 n=3
				scanf("%f", &n);
				
				for(ponto = 0; ponto < qtdPontos; ponto++){
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){//se a coordenada for x	
							vertices[ponto][coordenada] *= n;
						}
					}
				}
				
				//imprimindo
				printf("\n\nNovas coordenadas\n");
				
				for(ponto = 0; ponto < qtdPontos; ponto++){
					printf("\nPonto %d:", ponto+1);
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){	
							printf("\nx: %.2lf", vertices[ponto][coordenada]);
						}else{
							printf("\ny: %.2lf\n", vertices[ponto][coordenada]);
						}
					}
				}
				break;
				
			case 2: //sen de 180 = 0; cos de 180 = -1
			//atualização para: sen de -90 = -1; cos de -90 = 0
			//para o exercício 6 alfa = -90
				printf("\nDigite o valor do angulo: "); //para o exercício 6 n=3
				scanf("%d", &alfa);				
			
				for(ponto = 0; ponto < qtdPontos; ponto++){
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){//se a coordenada for x
							vertices[ponto][coordenada] = (vertices[ponto][coordenada] * cos(alfa * PI/180)) - (vertices[ponto][coordenada+1] * sin(alfa * PI/180));
						}else{
							vertices[ponto][coordenada] = (vertices[ponto][coordenada-1] * sin(alfa * PI/180)) + (vertices[ponto][coordenada] * cos(alfa * PI/180));
						}
					}
				}
				
				//imprimindo
				printf("\n\nNovas coordenadas\n");
				//printf("%lf", sin(alfa * PI/180)); //checando se o valor da conversão rad - graus está correto
				
				for(ponto = 0; ponto < qtdPontos; ponto++){
					printf("\nPonto %d:", ponto+1);
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){	
							printf("\nx: %.2lf", vertices[ponto][coordenada]);
						}else{
							printf("\ny: %.2lf\n", vertices[ponto][coordenada]);
						}
					}
				}
				break;
				
			case 3: //T(x ; y) = (-x ; y)
				for(ponto = 0; ponto < qtdPontos; ponto++){
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){//se a coordenada for x
							vertices[ponto][coordenada] *= -1;
						}
					}
				}
				
				//imprimindo
				printf("\n\nNovas coordenadas\n");
				
				for(ponto = 0; ponto < qtdPontos; ponto++){
					printf("\nPonto %d:", ponto+1);
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){	
							printf("\nx: %.2lf", vertices[ponto][coordenada]);
						}else{
							printf("\ny: %.2lf\n", vertices[ponto][coordenada]);
						}
					}
				}
				break;
				
			case 4: //k = 2 para o exercício 6
				
				printf("\nDigite o valor de k: "); //para o exercício 6 n=3
				scanf("%f", &n);
			
				for(ponto = 0; ponto < qtdPontos; ponto++){
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){//se a coordenada for x
							vertices[ponto][coordenada] += (vertices[ponto][coordenada+1] * n);
						}
					}
				}
				
				//imprimindo
				printf("\n\nNovas coordenadas\n");
				
				for(ponto = 0; ponto < qtdPontos; ponto++){
					printf("\nPonto %d:", ponto+1);
					for(coordenada = 0; coordenada < 2; coordenada++){
						if((coordenada+1) % 2 != 0){	
							printf("\nx: %.2lf", vertices[ponto][coordenada]);
						}else{
							printf("\ny: %.2lf\n", vertices[ponto][coordenada]);
						}
					}
				}
				break;
				
			case 5:
				break;
			default:
				printf("\nOpcao nao valida\n");
				break;
		}
	}while(opcao != 5);
		
	system("pause");
	return 0;
}
