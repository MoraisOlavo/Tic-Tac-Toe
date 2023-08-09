#include "posicao.h"
#ifndef NO_H
#define NO_H
typedef struct{
    Posicao pos;
    int n_filhos;
    int ultimo_mov;
    void** vetor_filhos;
} No;

No* CriarArvore(Posicao pos);
#endif
