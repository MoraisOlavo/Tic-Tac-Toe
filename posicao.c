#include "posicao.h"
#include <stdio.h>

void PrintPosicao(Posicao pos){
	printf("   |   |   \n");
	printf(" %c | %c | %c \n",pos.tabuleiro[0],pos.tabuleiro[1],pos.tabuleiro[2]);

	printf("---|---|---\n");
	printf(" %c | %c | %c \n",pos.tabuleiro[3],pos.tabuleiro[4],pos.tabuleiro[5]);
	printf("---|---|---\n");

	printf(" %c | %c | %c \n",pos.tabuleiro[6],pos.tabuleiro[7],pos.tabuleiro[8]);
	printf("   |   |   \n");

	printf("\n");
}

int VerificarVitoria(Posicao p){
	for(int i=0;i<=6;i=i+=3){
		if (p.tabuleiro[i]=='X' && p.tabuleiro[i+1]=='X' && p.tabuleiro[i+2]=='X'){
			return -1;
		}
		if (p.tabuleiro[i]=='O' && p.tabuleiro[i+1]=='O' && p.tabuleiro[i+2]=='O'){
			return 1;
		}
	}

	for(int i=0;i<=2;i++){
		if (p.tabuleiro[i]=='X' && p.tabuleiro[i+3]=='X' && p.tabuleiro[i+6]=='X'){
			return -1;
		}
		if (p.tabuleiro[i]=='O' && p.tabuleiro[i+3]=='O' && p.tabuleiro[i+6]=='O'){
			return 1;
		}
	}

	if(p.tabuleiro[0]=='X' && p.tabuleiro[4]=='X' && p.tabuleiro[8]=='X'){
		return -1;
	}

	if(p.tabuleiro[0]=='O' && p.tabuleiro[4]=='O' && p.tabuleiro[8]=='O'){
		return 1;
	}

	if(p.tabuleiro[2]=='X' && p.tabuleiro[4]=='X' && p.tabuleiro[6]=='X'){
		return -1;
	}

	if(p.tabuleiro[2]=='O' && p.tabuleiro[4]=='O' && p.tabuleiro[6]=='O'){
		return -1;
	}

	return 0;
}


int ContarEspacosVazios(Posicao pos){
    int cont=0;
    for(int i=0;i<9;i++){
        if(pos.tabuleiro[i]==' '){
            cont++;
        }
    }
    return cont;
}