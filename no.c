#include <stdlib.h>
#include "no.h"
#include "posicao.h"

No* CriarArvore(Posicao pos, int mov_feito){
	No* no_raiz=(No*)malloc(sizeof(No));	
	no_raiz->ultimo_mov=mov_feito;
	
	int aux=VerificarVitoria(pos);

	if(aux==1){
		no_raiz->valor=aux;
		no_raiz->n_filhos=0;
	}else if(aux==-1){
		no_raiz->valor=aux;
		no_raiz->n_filhos=0;
	}else{
		no_raiz->n_filhos=ContarEspacosVazios(pos);
		no_raiz->vetor_filhos=(No**)malloc(no_raiz->n_filhos*sizeof(No*));

		for(int i=0;i<no_raiz->n_filhos;i++){
			no_raiz->vetor_filhos[i]=(No*)malloc(sizeof(No));
		}

		Posicao pos_aux;
		aux=0;
		for(int i=0;i<9;i++){
			if(pos.tabuleiro[i]==' '){
				IgualarPosicoes(pos,&pos_aux);
				if(pos.vez==1){
					pos_aux.tabuleiro[i]=pos.simbolo_segundo_jogador;
				}else{
					pos_aux.tabuleiro[i]=pos.simbolo_primeiro_jogador;
				}
				pos_aux.vez*=-1;
				no_raiz->vetor_filhos[aux]=CriarArvore(pos_aux,i);
				aux++;
			}
		}

		no_raiz->valor=0;
		for(int i=0;i<no_raiz->n_filhos;i++){
			if(no_raiz->vetor_filhos[i]->valor==1 && (pos.vez==1 || no_raiz->valor!=-1)){
				no_raiz->valor=1;
				break;
			}
			if(no_raiz->vetor_filhos[i]->valor==-1 && (pos.vez==-1 || no_raiz->valor!=1)){
				no_raiz->valor=-1;
				break;
			}
		}

	}

	return no_raiz;	
} 

void DeletarArvore(No* no_raiz){
	if(no_raiz->n_filhos==0){
		free(no_raiz);
	}else{
		for(int i=0;i<no_raiz->n_filhos;i++){
			DeletarArvore(no_raiz->vetor_filhos[i]);
		}
	}
}
