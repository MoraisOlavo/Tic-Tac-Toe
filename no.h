#include "posicao.h"
#ifndef NO_H
#define NO_H
typedef struct{
    Posicao pos;
    int n_filhos;
    void** vetor_filhos;
} No;

No* CriarArvore(Posicao pos);
#endif