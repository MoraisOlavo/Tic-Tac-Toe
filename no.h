#include "posicao.h"
#ifndef NO_H
#define NO_H
typedef struct No{
    int valor;
    int n_filhos;
    int ultimo_mov;
    struct No** vetor_filhos;
} No;

No* CriarArvore(Posicao pos, int mov_feito);
void DeletarArvore(No* no_raiz);
#endif
