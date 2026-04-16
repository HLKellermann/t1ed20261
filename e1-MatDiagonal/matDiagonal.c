#include <stdio.h>
#include <stdlib.h>
#include "matDiagonal.h"

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
        printf("Erro: Alocacao da matriz malsucedida\n");
        exit(1);
    }
    return m;   //retorna Diagnonal m para a Diagonal matriz no main 
}

void preenche_mat(Diagonal* m){
    int i;
    printf("\nInforme o valor para a posicao:\n");
//userInput: guarda-se apenas os valores da diagonal no vetor de Diagonal matriz 
    for(i=0; i<m->ordem; i++){
        printf("(%d,%d):", i, i);
        scanf("%d", &m->v[i]);
    }
}

void imprime_mat(Diagonal m){
    int l, c;

    printf("\nMatriz Diagonal:\n");
    for(l=0; l<m.ordem; l++){
        for(c=0; c<m.ordem; c++){
            if (l == c)                 //lin == col: diagonal
                printf("%d ", m.v[l]);
            else if (c == m.ordem-1)    //col == ordem-1: ultima coluna -> nulo e nova linha
                printf("0\n");
            else
            printf("0 ");               //nao e ultima coluna e eh nulo
        }   
    }
    printf("\n");
}

void consulta_elem(Diagonal m){
    int l, c;
    printf("\nInforme a posicao (linha, coluna) do elemento: ");
    scanf("%d%d", &l, &c);
//confere se a posicao eh valida
    if((l>=0 && l<m.ordem) && (c>=0 || c<m.ordem)){
        if(l == c)
            printf("Elemento na posicao (%d,%d): %d", l, c, m.v[l]); //diagonal principal
        else
            printf("Elemento na posicao (%d,%d): 0", l, c);         //valores nulos
    }else   //invalido
        printf("Posicao invalida! Matriz Diagonal de Ordem %d, logo:\ninicio: (0,0) - fim: (%d, %d)", m.ordem, m.ordem-1, m.ordem-1);
}


int main(int argc, char const *argv[])
{
    Diagonal matriz = cria_mat();
    preenche_mat(&matriz);
    imprime_mat(matriz);
    consulta_elem(matriz);

    free(matriz.v);
    return 0;
}