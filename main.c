#include <stdio.h>
#include "no.h"

int CalcularJogada(Posicao pos_atual){
	for(int i=0;i<9;i++){
		if(pos_atual.tabuleiro[i]==' '){
			return i;
		}
	}
	return 0;
}

void main(){
	Posicao pos_atual;
	for(int i=0;i<9;i++){
		pos_atual.tabuleiro[i]=' ';
	}
	pos_atual.vez=1;
	pos_atual.valor=0;

	char simbolo_primeiro_jogador;
	char simbolo_segundo_jogador;
	int aux;

	printf("Digite qual será o símbolo do primeiro jogador\n");
	scanf(" %c",&simbolo_primeiro_jogador);
	printf("Char lido: %c\n",simbolo_primeiro_jogador);
	fflush(stdin);

	printf("Digite qual será o símbolo do segundo jogador\n");
	scanf(" %c",&simbolo_segundo_jogador);
	fflush(stdin);


	while(VerificarVitoria(pos_atual)==0){       
		if(pos_atual.vez==1){
			printf("bolsonaro a\n");
			PrintPosicao(pos_atual);
			do{
				scanf("%d",&aux);
			}while(aux<0 || aux>8);
		}else{
			aux=CalcularJogada(pos_atual);
		}

		if(pos_atual.tabuleiro[aux]!=' '){
			printf("Posição já utilizada\n");
			continue;
		}

		if(pos_atual.vez==1){
			pos_atual.tabuleiro[aux]=simbolo_primeiro_jogador;
		}else{
			pos_atual.tabuleiro[aux]=simbolo_segundo_jogador;
		}

		pos_atual.vez*=-1;
	}

	if(VerificarVitoria(pos_atual)==1){
		printf("O venceu\n");
	}else{
		printf("X venceu\n");
	}
}
