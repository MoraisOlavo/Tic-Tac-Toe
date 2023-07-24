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

int VerificarVitoria(Posicao p,char simbolo_primeiro_jogador, char simbolo_segundo_jogador){
	for(int i=0;i<=6;i=i+=3){
		if (p.tabuleiro[i]==simbolo_segundo_jogador && p.tabuleiro[i+1]==simbolo_segundo_jogador && p.tabuleiro[i+2]==simbolo_segundo_jogador){
			return -1;
		}
		if (p.tabuleiro[i]==simbolo_primeiro_jogador && p.tabuleiro[i+1]==simbolo_primeiro_jogador && p.tabuleiro[i+2]==simbolo_primeiro_jogador){
			return 1;
		}
	}

	for(int i=0;i<=2;i++){
		if (p.tabuleiro[i]==simbolo_segundo_jogador && p.tabuleiro[i+3]==simbolo_segundo_jogador && p.tabuleiro[i+6]==simbolo_segundo_jogador){
			return -1;
		}
		if (p.tabuleiro[i]==simbolo_primeiro_jogador && p.tabuleiro[i+3]==simbolo_primeiro_jogador && p.tabuleiro[i+6]==simbolo_primeiro_jogador){
			return 1;
		}
	}

	if(p.tabuleiro[0]==simbolo_segundo_jogador && p.tabuleiro[4]==simbolo_segundo_jogador && p.tabuleiro[8]==simbolo_segundo_jogador){
		return -1;
	}

	if(p.tabuleiro[0]==simbolo_primeiro_jogador && p.tabuleiro[4]==simbolo_primeiro_jogador && p.tabuleiro[8]==simbolo_primeiro_jogador){
		return 1;
	}

	if(p.tabuleiro[2]==simbolo_segundo_jogador && p.tabuleiro[4]==simbolo_segundo_jogador && p.tabuleiro[6]==simbolo_segundo_jogador){
		return -1;
	}

	if(p.tabuleiro[2]==simbolo_primeiro_jogador && p.tabuleiro[4]==simbolo_primeiro_jogador && p.tabuleiro[6]==simbolo_primeiro_jogador){
		return 1;
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
