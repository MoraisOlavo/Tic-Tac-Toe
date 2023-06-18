#include <stdio.h>
#include "no.h"
void PrintPosicao(Posicao pos){
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",pos.tabuleiro[0],pos.tabuleiro[1],pos.tabuleiro[2]);
    
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",pos.tabuleiro[3],pos.tabuleiro[4],pos.tabuleiro[5]);
    printf("---|---|---\n");

    printf(" %c | %c | %c \n",pos.tabuleiro[6],pos.tabuleiro[7],pos.tabuleiro[8]);
    printf("   |   |   \n");
}

int VerificarVitoria(Posicao p){
    for(int i=0;i<=6;i=i+=3){
        if (p.tabuleiro[i]=='X' && p.tabuleiro[i+1]=='X' && p.tabuleiro[i+2]=='X'){
            return -1;
        }
        if (p.tabuleiro[i]=='O' && p.tabuleiro[i+1]=='O' && p.tabuleiro[i+2]=='O'){
            return 1;
        }
    }

    for(int i=0;i<=2;i++){
        if (p.tabuleiro[i]=='X' && p.tabuleiro[i+3]=='X' && p.tabuleiro[i+6]=='X'){
            return -1;
        }
        if (p.tabuleiro[i]=='O' && p.tabuleiro[i+3]=='O' && p.tabuleiro[i+6]=='O'){
            return 1;
        }
    }

    if(p.tabuleiro[0]=='X' && p.tabuleiro[4]=='X' && p.tabuleiro[8]=='X'){
        return -1;
    }

    if(p.tabuleiro[0]=='O' && p.tabuleiro[4]=='O' && p.tabuleiro[8]=='O'){
        return 1;
    }

    if(p.tabuleiro[2]=='X' && p.tabuleiro[4]=='X' && p.tabuleiro[6]=='X'){
        return -1;
    }

    if(p.tabuleiro[2]=='O' && p.tabuleiro[4]=='O' && p.tabuleiro[6]=='O'){
        return -1;
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
        do{
            scanf("%d",&aux);
        }while(aux<0 || aux>8);

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
