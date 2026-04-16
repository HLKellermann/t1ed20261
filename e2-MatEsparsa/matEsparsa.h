#ifndef MATESPARSA_H
#define MATESPARSA_H

//lista de valores não nulos da matriz esparsa. Os elementos não nulos da matriz são armazenados nesta lista.
//Os valores restantes, q são nulos, não são armazenados em nenhum lugar.
struct lista
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


Esparsa cria_mat();

Lista* aloca_noh(Lista* prim, int l, int c, int v);

void preenche_mat(Esparsa* m);

void imprime_mat(Esparsa m);


#endif