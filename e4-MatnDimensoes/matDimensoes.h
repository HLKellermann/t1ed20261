#ifndef MATDIMENSOES_H
#define MATDIMENSOES_H

// Protótipos das funções exigidos no exercício
int*** aloca_matriz(int m, int n, int z);
void preenche_matriz(int m, int n, int z, int ***mat);
void imprime_matriz(int m, int n, int z, int ***mat);
void libera_matriz(int m, int n, int ***mat);

#endif