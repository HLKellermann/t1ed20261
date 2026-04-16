#ifndef MATDIAGONAL_H
#define MATDIAGONAL_H

struct diagonal
{
int ordem;      //ordem da matriz
int* v;         //o tamanho do vetor é igual a ordem da matriz. Os elementos da diagonal principal são armazenados neste vetor
};
typedef struct diagonal Diagonal;

//criação da matriz;
Diagonal cria_mat();

//preenchimento da matriz;
void preenche_mat(Diagonal* m);

//impressão da matriz;
void imprime_mat(Diagonal m);

//consulta de um determinado elemento da matriz (para consultar um elemento, o usuário informa a l e a c onde o elemento se encontra);
void consulta_elem(Diagonal m);

#endif