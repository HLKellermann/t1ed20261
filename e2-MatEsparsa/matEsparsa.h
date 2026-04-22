#ifndef MATESPARSA_H
#define MATESPARSA_H

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

bool posicao_valida(Esparsa* m, int lin, int col);

bool pos_iguais(Lista* a, int lin, int col);

int resposta();

Esparsa cria_mat();

Lista* novo_noh(int l, int c, int v);

void preenche_mat(Esparsa* m);

void imprime_mat(Esparsa m);

void consulta_elem(Esparsa* m);

void imprime_somatorio_linha(Esparsa m);

void percent_nao_nulos(Esparsa m);

void libera_mat(Esparsa* m);

#endif