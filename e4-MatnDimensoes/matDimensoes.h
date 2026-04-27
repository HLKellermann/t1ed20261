#ifndef MATDIMENSOES_H
#define MATDIMENSOES_H

#include <stdio.h>
#include <stdlib.h>

/* PROTÓTIPOS DAS FUNÇÕES*/

// Aloca dinamicamente uma matriz 3D de inteiros (m x n x z)
int*** aloca_matriz(int m, int n, int z);

// Preenche a matriz com a lógica de soma de índices
void preenche_matriz(int m, int n, int z, int ***mat);

// Imprime a matriz no console separada por planos (camadas)
void imprime_matriz(int m, int n, int z, int ***mat);

// Libera toda a memória alocada para a matriz 3D
void libera_matriz(int m, int n, int ***mat);

#endif