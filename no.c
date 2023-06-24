#include <stdlib.h>
#include "no.h"
#include "posicao.h"

No* CriarArvore(Posicao pos){
	No* no_raiz=(No*)malloc(sizeof(No));
	no_raiz->pos=pos;
	
	
	no_raiz->n_filhos=ContarEspacosVazios(pos);

}
