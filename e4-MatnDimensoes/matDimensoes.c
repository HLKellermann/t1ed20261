#include <stdio.h>
#include <stdlib.h>
#include "matDimensoes.h"

/*--- Alocação da matriz 3D com verificação de segurança em cada nível ---*/
int*** aloca_matriz(int m, int n, int z) {
    // Validação inicial 
    if (m <= 0 || n <= 0 || z <= 0) {
        printf("\nErro: Dimensoes invalidas (%dx%dx%d). Devem ser maiores que zero.\n", m, n, z);
        exit(1);
    }

    int ***mat;

    // 1. Aloca as linhas
    mat = (int ***) malloc(m * sizeof(int **));
    if (mat == NULL) {
        printf("Erro de memoria no nivel 1!\n");
        exit(1);
    }

    for (int i = 0; i < m; i++) {
        // 2. Aloca as colunas
        mat[i] = (int **) malloc(n * sizeof(int *));
        if (mat[i] == NULL) {
            printf("Erro de memoria no nivel 2!\n");
            exit(1);
        }
        
        for (int j = 0; j < n; j++) {
            // 3. Aloca a profundidade
            mat[i][j] = (int *) malloc(z * sizeof(int));
            if (mat[i][j] == NULL) {
                printf("Erro de memoria no nivel 3!\n");
                exit(1);
            }
        }
    }
    return mat;
}

/*--- Preenchimento da matriz ---*/
void preenche_matriz(int m, int n, int z, int ***mat) {
    if (mat == NULL) return;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < z; k++) {
                // Mantendo a lógica de soma de índices para teste
                mat[i][j][k] = i + j + k;
            }
        }
    }
}

/*--- Impressão organizada por Planos ---*/
void imprime_matriz(int m, int n, int z, int ***mat) {
    if (mat == NULL) {
        printf("\nMatriz vazia ou nao alocada.\n");
        return;
    }

    printf("\n--- Exibindo Matriz 3D (%dx%dx%d) ---\n", m, n, z);
    for (int i = 0; i < m; i++) {
        printf("Plano %d:\n", i);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < z; k++) {
                printf("%4d ", mat[i][j][k]); // %4d ajuda a alinhar os números
            }
            printf("\n");
        }
        printf("\n");
    }
}

/*--- Liberação de memória (Desalocação) ---*/
void libera_matriz(int m, int n, int ***mat) {
    if (mat == NULL) return;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Libera o nível mais interno primeiro
            free(mat[i][j]);
        }
        // Libera o nível intermediário
        free(mat[i]);
    }
    // Libera o nível base
    free(mat);
    
    printf("Memoria da matriz 3D liberada com sucesso!\n");
}