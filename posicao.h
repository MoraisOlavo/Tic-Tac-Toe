#ifndef POSICAO_H
#define POSICAO_H
typedef struct {
    char tabuleiro[9];
    int vez;
    int valor;
} Posicao;

int ContarEspacosVazios(Posicao pos);
void PrintPosicao(Posicao pos);
int VerificarVitoria(Posicao p);
#endif