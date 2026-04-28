#ifndef MATDIAGONAL_H
#define MATDIAGONAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*---STRUCTS---*/

struct diagonal
{
int ordem;      //ordem da matriz
int* v;         //o tamanho do vetor é igual a ordem da matriz. Os elementos da diagonal principal são armazenados neste vetor
};
typedef struct diagonal Diagonal;

/*---FUNCOES AUXILIARES---*/

//valida se a posicao digitada pelo usuario esta dentro do tamanho da matriz
bool posicao_valida(int lin, int col, int ordem);

//imprime o resultado da consulta feita na funcao 'consulta_elem'
void imprime_consulta(Diagonal* m, int lin, int col);

//loop para tratar possivel entrada que nao seja um valor inteiro, para a posicao a se consultar em 'consulta_elem'
void posicoes_inteiras(int* llinha, int* coluna);

//loop para tratar possivel entrada que nao seja um valor inteiro(como char ou strings)
int input_eh_inteiro();

//loop ateh o input do usuario ser valido para o seu caso especifico
void valida_valores(int* input, int caso);

//função chamada pelas principais para realizar leitura e validação da entrada
int leitura_input(int caso);

/*---FUNCOES PRINCIPAIS---*/

//criação da matriz
Diagonal cria_mat();

//preenchimento da matriz
void preenche_mat(Diagonal* m);

//impressão da matriz
void imprime_mat(Diagonal m);

//consulta de um determinado elemento da matriz (para consultar, o usuário informa a linha e a coluna onde o elemento se encontra)
void consulta_elem(Diagonal* m);

//libera vetor da matriz
void libera_mat(Diagonal *m);

#endif
