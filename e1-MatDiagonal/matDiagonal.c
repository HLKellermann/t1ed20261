#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matDiagonal.h"

/*---valida se a posicao digitada pelo usuario esta dentro do tamanho da matriz---*/
bool posicao_valida(int lin, int col, int ordem){
    return ((lin>=0 && lin<ordem) && (col>=0 && col<ordem)) ? true : false;
}

/*---criação da matriz---*/
Diagonal cria_mat(){
    Diagonal m;
    int o;
//userInput: ordem da matriz
    printf("Digite a ordem da Matriz Diagonal: ");
    scanf("%d", &o);
//alocacao dinamica da matriz na struct Diagonal
    m.ordem = o;
    m.v = (int*) malloc(m.ordem * sizeof(int));
    if(m.v == NULL){    // mensagem de erro
        printf("\nErro: Alocacao da matriz malsucedida\n");
        exit(1);
    }
    return m;   //retorna Diagnonal m para a Diagonal matriz no main 
}

/*---preenchimento da matriz---*/
void preenche_mat(Diagonal* m){
    int i;
    printf("\nInforme o valor para a posicao:\n");
//userInput: guarda apenas os valores da diagonal no vetor de Diagonal matriz 
    for(i=0; i<m->ordem; i++){
        printf("(%d,%d):", i, i);
        scanf("%d", &m->v[i]);
    }
}

/*---impressão da matriz---*/
void imprime_mat(Diagonal m){
    int lin, col;

    printf("\nMatriz Diagonal:\n");
    for(lin=0; lin<m.ordem; lin++){
        for(col=0; col<m.ordem; col++){
            if (lin == col)                 //lin == col: diagonal
                printf("%d ", m.v[lin]);
            else
                printf("0 ");               //eh nulo

            if (col == m.ordem-1)    //ultima coluna, passa pra nova linha
                printf("\n");
        }   
    }
    printf("\n");
}

/*---consulta de um determinado elemento da matriz---*/
void consulta_elem(Diagonal m){
    int lin, col;
//UserInput: informa a linha e coluna onde o elemento se encontra
    printf("\nInforme a posicao (linha, coluna) do elemento: ");
    scanf("%d%d", &lin, &col);
//confere se a posicao eh valida
    if(posicao_valida(lin, col, m.ordem)){
        if(lin == col)
            printf("\nElemento na posicao (%d,%d): %d", lin, col, m.v[lin]); //diagonal principal
        else
            printf("\nElemento na posicao (%d,%d): 0", lin, col);         //valores nulos
    }else   //posicao invalida
        printf("\nPosicao invalida! Matriz Diagonal de Ordem %d, logo:\ninicio: (0,0) - fim: (%d, %d)", m.ordem, m.ordem-1, m.ordem-1);
}

/*---//libera vetor da matriz---*/
void libera_mat(Diagonal *m){
    if(m!=NULL && m->v!=NULL){
        free(m->v);
        m->v = NULL;
    }
}

int main(int argc, char const *argv[])
{
    Diagonal matriz = cria_mat();
    preenche_mat(&matriz);
    imprime_mat(matriz);
    consulta_elem(matriz);
    libera_mat(&matriz);
    return 0;
}