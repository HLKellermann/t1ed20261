#ifndef MATESPARSA_H
#define MATESPARSA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//DEFINICAO DE STRUCTS

struct lista //lista de valores não nulos da matriz esparsa. Os elementos não nulos da matriz são armazenados nesta lista.
{
    int linha; // linha onde se encontra o elemento não nulo
    int coluna; // coluna onde se encontra o elemento não nulo
    int info; // valor do elemento não nulo
    struct lista* prox; // apontador para o proximo elemento não nulo da matriz
};
typedef struct lista Lista;

struct esparsa
{
    int linhas; //numero de linhas da matriz
    int colunas; //numero de colunas da matriz
    struct lista* prim; //apontador para o primeiro noh não nulo da matriz
};
typedef struct esparsa Esparsa;


//PROTOTIPOS DAS FUNCOES

//valida se a posicao digitada pelo usuario esta dentro do tamanho da matriz
bool posicao_valida(Esparsa* m, int lin, int col);

//valida se linha = linha da lista, e se coluna = coluna da lista
bool pos_iguais(Lista* a, int lin, int col);

//repete while ate o input ser valido (1 ou 0), retorna opcao para funcao principal
int resposta();

//criação da matriz
Esparsa cria_mat();

//criação de novo noh da lista
Lista* novo_noh(int l, int c, int v);

//preenchimento da matriz
void preenche_mat(Esparsa* m);

//impressão da matriz
void imprime_mat(Esparsa m);

//consulta de um determinado elemento da matriz (para consultar, o usuário informa a linha e a coluna onde o elemento se encontra)
void consulta_elem(Esparsa* m);

//impressao da soma de todos os elementos da linha informada
void imprime_somatorio_linha(Esparsa m);

//porcentagem de elementos nao nulos da matriz
void percent_nao_nulos(Esparsa m);

//libera matriz
void libera_mat(Esparsa* m);

#endif