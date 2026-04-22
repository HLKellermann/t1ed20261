#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matDiagonal.h"

/*---valida se a posicao digitada pelo usuario esta dentro do tamanho da matriz---*/
bool posicao_valida(int lin, int col, int ordem){
    return (lin>=0 && lin<ordem) && (col>=0 && col<ordem);
}

/*---imprime o resultado da consulta feita na funcao 'consulta_elem'---*/
void imprime_consulta(Diagonal* m, int lin, int col){
    //confere se a posicao eh valida e printa conforme a condição
    if(posicao_valida(lin, col, m->ordem)){
        if(lin == col)
            printf("\nElemento na posicao (%d,%d): %d", lin, col, m->v[lin]); //diagonal principal
        else
            printf("\nElemento na posicao (%d,%d): 0", lin, col);         //valores nulos
    }else   //se posicao invalida
        printf("\nPosicao (%d, %d) invalida! Indice min: 0, indice max: %d", lin, col, m->ordem-1);
}

int continuar(){
    printf("\n[1] Repetir operacao   [0] Parar\t");
    int resposta = valida_input();
    return resposta;
}

int valida_input(){
    int valor, valorOk;
//enquanto valor do input nao for valido, repete
    do{
        valorOk = scanf("%d", &valor);  //passa valor lido para variavel auxiliar

        //se o valor lido nao foi um inteiro, avisa usuario e limpa buffer
        if(valorOk != 1){
            printf("Entrada invalida!Tente de novo: ");
            while(getchar() != '\n');       //limpa buffer
        }
    }while(valorOk != 1);
    return valor;
}

int valida_ordem(){
    bool invalido;
    int ordem;
    printf("Digite a ordem da Matriz Diagonal: ");
    do{
        ordem = valida_input();
        invalido = (ordem <= 0);
        if(invalido)
            printf("Valor deve ser maior do que 0! De novo: ");
    }while(invalido);
    return ordem;
}

/*---criação da matriz---*/
Diagonal cria_mat(){
    Diagonal m;
//alocacao dinamica do vetor da matriz
    m.ordem = valida_ordem();
    m.v = malloc(m.ordem * sizeof(int));
//mensagem de erro
    if(m.v == NULL){
        printf("\nErro: Alocacao da matriz malsucedida\n");
        exit(1);
    }
    return m;   //retorna Diagnonal m para a Diagonal matriz no main 
}

/*---preenchimento da matriz---*/
void preenche_mat(Diagonal* m){
    int i;
    printf("\nInforme o valor para a posicao:\n");
//laço para guardar apenas os valores da diagonal no vetor da matriz
    for(i=0; i<m->ordem; i++){
        printf("(%d,%d):", i, i);   //mostra a posicao que o valor serah guardado
        m->v[i] = valida_input();   //guarda valor informado no vetor
    }
}

/*---impressão da matriz---*/
void imprime_mat(Diagonal m){
    int lin, col;

    printf("\nMatriz Diagonal:\n");
    for(lin=0; lin<m.ordem; lin++){
        for(col=0; col<m.ordem; col++){
            printf("%4d ", (lin==col) ? m.v[lin] : 0); //se linha e coluna iguais: info da diagonal, senao: 0 (nao eh diagonal)
        }
        printf("\n");   //nova linha quando for ultima coluna
    }
}


/*---consulta de um determinado elemento da matriz---*/
void consulta_elem(Diagonal* m){
    int lin, col;
    do{
    //usuario informa a linha e coluna onde o elemento se encontra
        printf("\nInforme a posicao (linha, coluna) do elemento: ");
        lin = valida_input();
        col = valida_input();

        imprime_consulta(m, lin, col);      //chama funcao para imprimir resultado da consulta
    }while(continuar() == 1);
}

/*---libera vetor da matriz---*/
void libera_mat(Diagonal *m){
    if(m!=NULL && m->v!=NULL){
        free(m->v);
        m->v = NULL;
    }
    m->ordem = 0;
}

//FUNCAO PRINCIPAL MAIN
int main(int argc, char const *argv[])
{
    Diagonal matriz = cria_mat();
    preenche_mat(&matriz);
    imprime_mat(matriz);
    consulta_elem(&matriz);
    libera_mat(&matriz);
    return 0;
}