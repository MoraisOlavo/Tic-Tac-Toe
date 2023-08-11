#include "posicao.h"
#include <stdio.h>

void IgualarPosicoes(Posicao pos_original, Posicao* pos_aux){
	pos_aux->vez=pos_original.vez;
	pos_aux->valor=pos_original.valor;
	pos_aux->simbolo_primeiro_jogador=pos_original.simbolo_primeiro_jogador;
	pos_aux->simbolo_segundo_jogador=pos_original.simbolo_segundo_jogador;

	for(int i=0;i<9;i++){
		pos_aux->tabuleiro[i]=pos_original.tabuleiro[i];	
	}
}

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
		if (p.tabuleiro[i]==p.simbolo_segundo_jogador && p.tabuleiro[i+1]==p.simbolo_segundo_jogador && p.tabuleiro[i+2]==p.simbolo_segundo_jogador){
			return -1;
		}
		if (p.tabuleiro[i]==p.simbolo_primeiro_jogador && p.tabuleiro[i+1]==p.simbolo_primeiro_jogador && p.tabuleiro[i+2]==p.simbolo_primeiro_jogador){
			return 1;
		}
	}

	for(int i=0;i<=2;i++){
		if (p.tabuleiro[i]==p.simbolo_segundo_jogador && p.tabuleiro[i+3]==p.simbolo_segundo_jogador && p.tabuleiro[i+6]==p.simbolo_segundo_jogador){
			return -1;
		}
		if (p.tabuleiro[i]==p.simbolo_primeiro_jogador && p.tabuleiro[i+3]==p.simbolo_primeiro_jogador && p.tabuleiro[i+6]==p.simbolo_primeiro_jogador){
			return 1;
		}
	}

	if(p.tabuleiro[0]==p.simbolo_segundo_jogador && p.tabuleiro[4]==p.simbolo_segundo_jogador && p.tabuleiro[8]==p.simbolo_segundo_jogador){
		return -1;
	}

	if(p.tabuleiro[0]==p.simbolo_primeiro_jogador && p.tabuleiro[4]==p.simbolo_primeiro_jogador && p.tabuleiro[8]==p.simbolo_primeiro_jogador){
		return 1;
	}

	if(p.tabuleiro[2]==p.simbolo_segundo_jogador && p.tabuleiro[4]==p.simbolo_segundo_jogador && p.tabuleiro[6]==p.simbolo_segundo_jogador){
		return -1;
	}

	if(p.tabuleiro[2]==p.simbolo_primeiro_jogador && p.tabuleiro[4]==p.simbolo_primeiro_jogador && p.tabuleiro[6]==p.simbolo_primeiro_jogador){
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
