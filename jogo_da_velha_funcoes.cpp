#include <stdio.h>
#include <stdlib.h>

void inicializarMapa(char matriz[3][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			matriz[i][j] = ' ';	
		}
	}
}

void apresentarMapa(char matriz[3][3]){
	system("cls");
	printf("-----------------\n");
	printf("| Jogo da Velha |\n");
	printf("-----------------\n");
	printf("| # | 0 | 1 | 2 |\n");
	printf("-----------------\n");
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			if (j==0){
				printf("| %d | %c ", i,matriz[i][j]);	
			}
			else if(j==1){
				printf("| %c |",matriz[i][j]);
			}
			else{
				printf(" %c |",matriz[i][j]);
			}
		}
		printf("\n-----------------\n");
	}
}

void jogador_x(char matriz[3][3]){
	int flag=1;
	do{
		int linha, coluna;
		printf("\nJogador X\n");
		printf("Linha: ");
		scanf("%d", &linha);
		printf("Coluna: ");
		scanf("%d", &coluna);
		
		if (matriz[linha][coluna] == ' '){
			matriz[linha][coluna] = 'x';
			flag = 0;
		}
		else{
			printf("\nEspaco ocupado. ");
			flag = 1;
		}
		
	}while(flag);
}

void jogador_o(char matriz[3][3]){
	int flag=1;
	do{
		int linha, coluna;
		printf("\nJogador O\n");
		printf("Linha: ");
		scanf("%d", &linha);
		printf("Coluna: ");
		scanf("%d", &coluna);
		
		if (matriz[linha][coluna] == ' '){
			matriz[linha][coluna] = 'o';
			flag = 0;
		}
		else{
			printf("\nEspaco ocupado. ");
			flag = 1;
		}
		
	}while(flag);
}

int SeraQueXganhou(char matriz[3][3]){
	if ((matriz[0][0] == 'x' && matriz[0][1] == 'x' && matriz[0][2] == 'x' ) || (matriz[1][0] == 'x' && matriz[1][1] == 'x' && matriz[1][2] == 'x') ||  (matriz[2][0] == 'x' && matriz[2][1] == 'x' && matriz[2][2] == 'x') ||
		(matriz[0][0] == 'x' && matriz[1][0] == 'x' && matriz[2][0] == 'x' ) || (matriz[0][1] == 'x' && matriz[1][1] == 'x' && matriz[2][1] == 'x' ) || (matriz[0][2] == 'x' && matriz[1][2] == 'x' && matriz[2][2] == 'x' ) || 
		(matriz[0][0] == 'x' && matriz[1][1] == 'x' && matriz[2][2] == 'x' ) || (matriz[0][2] == 'x' && matriz[1][1] == 'x' && matriz[2][0] == 'x' )){
			
			return 1;		
	}
	else{
		return 0;
	}
}

int SeraQueOganhou(char matriz[3][3]){
	if ((matriz[0][0] == 'o' && matriz[0][1] == 'o' && matriz[0][2] == 'o' ) || (matriz[1][0] == 'o' && matriz[1][1] == 'o' && matriz[1][2] == 'o') ||  (matriz[2][0] == 'o' && matriz[2][1] == 'o' && matriz[2][2] == 'o') ||
		(matriz[0][0] == 'o' && matriz[1][0] == 'o' && matriz[2][0] == 'o' ) || (matriz[0][1] == 'o' && matriz[1][1] == 'o' && matriz[2][1] == 'o' ) || (matriz[0][2] == 'o' && matriz[1][2] == 'o' && matriz[2][2] == 'o' ) || 
		(matriz[0][0] == 'o' && matriz[1][1] == 'o' && matriz[2][2] == 'o' ) || (matriz[0][2] == 'o' && matriz[1][1] == 'o' && matriz[2][0] == 'o' )){
			
			return 1;
			
	}
	else{
		return 0;
	}
}

int SeraQueEmpatou(char matriz[3][3]){	
	if(matriz[0][0] != ' ' && matriz[0][1] != ' ' && matriz[0][2] != ' '  && matriz[1][0] != ' ' && matriz[1][1] != ' ' && matriz[1][2] != ' ' && matriz[2][0] != ' ' && matriz[2][1] != ' ' && matriz[2][2] != ' '){
		return 1;
	}
	else{
		return 0;
	}
}

int main(void){
	char matriz[3][3];
	int ganhador_x = 0;
	int ganhador_o = 0;
	int empate = 0;
	
	
	inicializarMapa(matriz);
	
	do{
		apresentarMapa(matriz);

		// JOGADOR X
		jogador_x(matriz);
		apresentarMapa(matriz);
		ganhador_x = SeraQueXganhou(matriz);
		if (ganhador_x){
			printf("\nJogador X ganhou!\n");
			break;
		}
		
		// VERIFICAR EMPATE (SO OCORRE QUANDO HOUVE 9 TENTATIVAS)
		empate = SeraQueEmpatou(matriz);
		if (empate){
			printf("\nEmpate\n");
			break;
		}
		
		// JOGADOR O
		jogador_o(matriz);
		apresentarMapa(matriz);
		ganhador_o = SeraQueOganhou(matriz);
		if (ganhador_o){
			printf("\nJogador O ganhou!\n");
			break;
		}
		
		
		
	}while(!ganhador_x && !ganhador_o && !empate);
	
	printf("Volte sempre!!!");
	
}
