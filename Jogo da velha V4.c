#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int opc = 0;
	int i = 0, j = 0;
	char jogo[3][3];
	int linha, coluna;
	int jogador = 1, win = 0;
	int jogadas = 0, opcao1;
	
	while (opc != 9) {
		printf ("\t ... ::: JOGO DA VELHA ::: ...\n");
		printf ("1 . INICIAR JOGO                \n");
		printf ("2 . EXIBIR REGRAS               \n");
		printf ("3 . INSTRUCOES PARA JOGAR       \n");
		printf ("9 . SAIR \n");
		printf ("Digite opcao desejada: \n");
		scanf ("%i", &opc);
		
		if (opc == 1) {
			do {
				jogador = 1;
				win = 0;
				jogadas = 0; 
					
				for (i = 0; i < 3; i++) {
					for (j = 0; j < 3; j++){
						jogo[i][j] = ' ';
					}
				}
				
				do {
						
					printf ("\n\n\t  0    1    2  \n\n");
					for (i = 0; i < 3; i++) {
						for (j = 0; j < 3; j++) {
							if (j == 0) {
								printf ("\t");
							}
							printf (" %c ", jogo[i][j]);
							if (j < 2) {
								printf (" | ");
							}
							if (j == 2) {
								printf (" %i", i);
							}
						}
						if (i < 2) {
								printf ("\n\t -------------");
								printf ("\n");
							}
					}
					printf ("\n\n");
					
					
					do {
						printf ("JOGADOR %i : Digite a linha e a coluna que queira jogar: \n", jogador);
						scanf ("%i%i", &linha, &coluna);
					} while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');
					
					
					if (jogador == 1) {
						jogo[linha][coluna] = 'o';
						jogador ++;
					} else {
						jogo[linha][coluna] = 'x';
						jogador = 1;
					}
					jogadas++;
			
					
					//ganhador por linha
					if (jogo[0][0] == 'o' && jogo[0][1] == 'o' && jogo[0][2] == 'o' ||
						jogo[1][0] == 'o' && jogo[1][1] == 'o' && jogo[1][2] == 'o' ||
						jogo[2][0] == 'o' && jogo[2][1] == 'o' && jogo[2][2] == 'o') {
						printf ("\n\n Parabens! O jogador 1 venceu por linha ! \n");
						win = 1;
					}
					if (jogo[0][0] == 'x' && jogo[0][1] == 'x' && jogo[0][2] == 'x' ||
						jogo[1][0] == 'x' && jogo[1][1] == 'x' && jogo[1][2] == 'x' ||
						jogo[2][0] == 'x' && jogo[2][1] == 'x' && jogo[2][2] == 'x') {
						printf ("\n\n Parabens! O jogador 2 venceu por linha ! \n");
						win = 1;
					}
					
					//ganhador por coluna
					if (jogo[0][0] == 'o' && jogo[1][0] == 'o' && jogo[2][0] == 'o' ||
						jogo[0][1] == 'o' && jogo[1][1] == 'o' && jogo[2][1] == 'o' ||
						jogo[0][2] == 'o' && jogo[1][2] == 'o' && jogo[2][2] == 'o') {
						printf ("\n\n Parabens! O jogador 1 venceu por coluna ! \n");
						win = 1;
					}
					if (jogo[0][0] == 'x' && jogo[1][0] == 'x' && jogo[2][0] == 'x' ||
						jogo[0][1] == 'x' && jogo[1][1] == 'x' && jogo[2][1] == 'x' ||
						jogo[0][2] == 'x' && jogo[1][2] == 'x' && jogo[2][2] == 'x') {
						printf ("\n\n Parabens! O jogador 2 venceu por coluna ! \n");
						win = 1;
					}
					
					//ganhador por diagonal principal
					if (jogo[0][0] == 'o' && jogo[1][1] == 'o' && jogo[2][2] == 'o') {
						printf ("\n\n Parabens! O jogador 1 venceu por diagonal principal ! \n");
						win = 1;
					}
					if (jogo[0][0] == 'x' && jogo[1][1] == 'x' && jogo[2][2] == 'x') {
						printf ("\n\n Parabens! O jogador 2 venceu por diagonal principal ! \n");
						win = 1;
					}
					
					//ganhador por diagonal secundaria
					if (jogo[0][2] == 'o' && jogo[1][1] == 'o' && jogo[2][0] == 'o') {
						printf ("\n\n Parabens! O jogador 1 venceu por diagonal secundaria ! \n");
						win = 1;
					}
					if (jogo[0][2] == 'x' && jogo[1][1] == 'x' && jogo[2][0] == 'x') {
						printf ("\n\n Parabens! O jogador 2 venceu por diagonal secundaria ! \n");
						win = 1;
					}
					
				} while (win == 0 && jogadas < 9);
				
				if (win == 0) {
					printf ("\n FIM de jogo sem GANHADOR !\n");
				}
				printf ("\n Digite 1 para jogar novamente:\n");
				scanf ("%i", &opcao1);
			} while (opcao1 == 1);
			
		} else if (opc == 2) {
			printf ("\n\tRegras do jogo \n");
			printf ("Cada jogador podera realizar uma jogada em um dos espacos vazios \n"
					"Vence o jogo, o jogador que conseguir adicionar tres simbolos iguais \n");
			
		} else if (opc == 3) {
			printf ("\n\t Instrucoes para jogar \n");
			printf ("1. Escolha uma linha, que vai de 0 ate 2. \n"
					"2. Escolha uma coluna, que vai de 0 ate 2. \n"
					"3. Para come�ar aperte ENTER e aguarde a jogada do proximo jogador. \n");
			
		}
	}

	system ("pause");
	return 0;
}

