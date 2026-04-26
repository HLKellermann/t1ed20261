#include <stdio.h>
#include <stdlib.h>
#include "matDimensoes.h"

int*** aloca_matriz(int m, int n, int z) {
    int ***mat;
    mat = (int ***) malloc(m * sizeof(int **));
    if (mat == NULL) {
        printf("Erro de memoria!\n");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        mat[i] = (int **) malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++) {
            mat[i][j] = (int *) malloc(z * sizeof(int));
        }
    }
    return mat;
}

void preenche_matriz(int m, int n, int z, int ***mat) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < z; k++) {
                // Preenche com um valor qualquer (ex: soma dos índices)
                mat[i][j][k] = i + j + k;
            }
        }
    }
}

void imprime_matriz(int m, int n, int z, int ***mat) {
    for (int i = 0; i < m; i++) {
        printf("Plano %d:\n", i);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < z; k++) {
                printf("%d ", mat[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
void libera_matriz(int m, int n, int ***mat) {
    if (mat == NULL) return;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Primeiro libera o vetor de inteiros (profundidade)
            free(mat[i][j]);
        }
        // Depois libera o vetor de ponteiros (colunas)
        free(mat[i]);
    }
    // Por fim, libera o vetor principal (linhas)
    free(mat);
    printf("Memoria da matriz liberada com sucesso!\n");
}