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
	pos_atual.valor=0;

	char simbolo_primeiro_jogador;
	char simbolo_segundo_jogador;
	int aux;

	printf("Digite qual será o símbolo do primeiro jogador\n");
	scanf(" %c",&simbolo_primeiro_jogador);
	fflush(stdin);

	printf("Digite qual será o símbolo do segundo jogador\n");
	scanf(" %c",&simbolo_segundo_jogador);
	fflush(stdin);

	printf("Digite 1 para começar jogando, qulquer outra coisa caso contrário\n");
	scanf("%d",&aux);
	if(aux==1){
		pos_atual.vez=1;
	}else{
		pos_atual.vez=-1;
	}
	fflush(stdin);

	while(VerificarVitoria(pos_atual,simbolo_primeiro_jogador,simbolo_segundo_jogador)==0){       
		if(pos_atual.vez==1){
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

	if(VerificarVitoria(pos_atual,simbolo_primeiro_jogador,simbolo_segundo_jogador)==1){
		printf("%c venceu\n",simbolo_primeiro_jogador);
	}else{
		printf("%c venceu\n",simbolo_segundo_jogador);
	}
}
