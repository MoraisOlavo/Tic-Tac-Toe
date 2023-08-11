#include <stdio.h>
#include "no.h"

// int CalcularJogada(Posicao pos_atual){
// 	for(int i=0;i<9;i++){
// 		if(pos_atual.tabuleiro[i]==' '){
// 			return i;
// 		}
// 	}
// 	return 0;
// }

int CalcularJogada(Posicao pos_atual){
	No* arvore=CriarArvore(pos_atual,-1);
	int menor=0;
	for(int i=1;i<arvore->n_filhos;i++){
		if(arvore->vetor_filhos[i]->valor<arvore->vetor_filhos[menor]->valor){
			menor=i;
		}
	}

	int retorno=arvore->vetor_filhos[menor]->ultimo_mov;
	DeletarArvore(arvore);
	return retorno;
}

void main(){
	Posicao pos_atual;
	for(int i=0;i<9;i++){
		pos_atual.tabuleiro[i]=' ';
	}
	pos_atual.valor=0;

	int aux;

	printf("Digite qual será o símbolo do primeiro jogador\n");
	scanf(" %c",&pos_atual.simbolo_primeiro_jogador);
	fflush(stdin);

	printf("Digite qual será o símbolo do segundo jogador\n");
	scanf(" %c",&pos_atual.simbolo_segundo_jogador);
	fflush(stdin);

	printf("Digite 1 para começar jogando, qulquer outra coisa caso contrário\n");
	scanf("%d",&aux);
	if(aux==1){
		pos_atual.vez=1;
	}else{
		pos_atual.vez=-1;
	}
	fflush(stdin);

	while(VerificarVitoria(pos_atual)==0){       
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
			pos_atual.tabuleiro[aux]=pos_atual.simbolo_primeiro_jogador;
		}else{
			pos_atual.tabuleiro[aux]=pos_atual.simbolo_segundo_jogador;
		}

		pos_atual.vez*=-1;
	}

	if(VerificarVitoria(pos_atual)==1){
		printf("%c venceu\n",pos_atual.simbolo_primeiro_jogador);
	}else{
		printf("%c venceu\n",pos_atual.simbolo_segundo_jogador);
	}
}
