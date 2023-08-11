#ifndef POSICAO_H
#define POSICAO_H
typedef struct {
    char tabuleiro[9];
    int vez;
    int valor;
    char simbolo_primeiro_jogador;
    char simbolo_segundo_jogador;
} Posicao;

int ContarEspacosVazios(Posicao pos);
void PrintPosicao(Posicao pos);
int VerificarVitoria(Posicao p);
void IgualarPosicoes(Posicao p_original, Posicao* pos_aux);
#endif
