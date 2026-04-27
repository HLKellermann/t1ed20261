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
int main(int argc, char const *argv[])
{
    int m, n, z;

    printf("\n--- Teste de Matriz 3D (Exercicio 4) ---\n");
    printf("Digite as dimensoes da matriz (Planos Linhas Colunas): ");
    
    // Lendo as 3 dimensões para criar o volume da matriz
    if (scanf("%d %d %d", &m, &n, &z) != 3) {
        printf("Erro: Entrada invalida para as dimensoes.\n");
        return 1;
    }

    if (m <= 0 || n <= 0 || z <= 0) {
        printf("Erro: As dimensoes devem ser maiores que zero.\n");
        return 1;
    }

    // 1. Alocacao Dinamica
    printf("\nAlocando matriz de tamanho %d x %d x %d...\n", m, n, z);
    int ***matriz = aloca_matriz(m, n, z);

    if (matriz == NULL) {
        printf("Erro critico: Falha na alocacao de memoria.\n");
        return 1;
    }

    // 2. Preenchimento
    // Chama a funcao para preencher com a soma i+j+k
    printf("Preenchendo valores automaticamente...\n");
    preenche_matriz(m, n, z, matriz);

    // 3. Impressao
    // Mostra a matriz separada por planos no terminal
    printf("\n--- Conteudo da Matriz 3D ---\n");
    imprime_matriz(m, n, z, matriz);

    // 4. Liberacao de Memoria (conforme .h)
    printf("\nLiberando memoria da matriz...\n");
    libera_matriz(m, n, matriz); 
    
    // Anulamos o ponteiro por seguranca
    matriz = NULL;

    printf("Teste concluido com sucesso!\n");

    return 0;
}