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

	int aux;
	while(VerificarVitoria(pos_atual)==0){       
		if(pos_atual.vez==1){
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
			pos_atual.tabuleiro[aux]='O';
		}else{
			pos_atual.tabuleiro[aux]='X';
		}

		pos_atual.vez*=-1;
		PrintPosicao(pos_atual);
	}

	if(VerificarVitoria(pos_atual)==1){
		printf("O venceu\n");
	}else{
		printf("X venceu\n");
	}
}
