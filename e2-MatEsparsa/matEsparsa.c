#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matEsparsa.h"

/*---valida se a posicao digitada pelo usuario esta dentro do tamanho da matriz---*/
bool posicao_valida(Esparsa* m, int lin, int col){
    return ((lin>=0 && lin<m->linhas) && (col>=0 && col<m->colunas));
}

/*---valida se linha = linha da lista, e se coluna = coluna da lista ---*/
bool pos_iguais(Lista* a, int lin, int col){
    return (a->linha == lin && a->coluna == col);
}

//funcao auxiliar: repete while ate o input ser valido (1 ou 0), retorna opcao para funcao principal
int resposta(){
    int r;
    do{
        printf("\n[1] Repetir operacao   [0] Parar\t");
        if(scanf("%d", &r) != 1){
            printf("Invalido!");
            while (getchar() != '\n'); // limpa buffer
            continue;
        }
        if(r != 1 && r != 0)
            printf("Opcao invalida! Digite 1 ou 0.\n");

    }while(r!=1 && r!=0);

    return r;
}

Esparsa cria_mat(){
    Esparsa m;
    printf("\nTamanho da Matriz Esparsa (linhas x colunas): ");
    scanf("%d %d", &m.linhas, &m.colunas);
    if(m.linhas>0 && m.colunas>0){
        m.prim = NULL;
        return m;
    }else{
        printf("\nTamanho de matriz invalido!");
        exit(1);
    }
}

Lista* novo_noh(int lin, int col, int valor){
    Lista* novoNoh = (Lista*) malloc(sizeof(Lista));
    if(novoNoh == NULL){
        printf("\nErro de alocacao! Encerrando");
        exit(1);
    }
    
    novoNoh->linha = lin;
    novoNoh->coluna = col;
    novoNoh->info = valor;
    novoNoh->prox = NULL;
    return novoNoh;
}

void preenche_mat(Esparsa* m){
    printf("\nPreenchimento da matriz esparsa: digite a linha, coluna e o valor nao nulo\n");
    printf("(Para parar de preencher a matriz, digite 0 0 0)\n");
    int resposta = 1;
    while(resposta==1){
        int lin, col, valor;
        scanf("%d %d %d", &lin, &col, &valor);
        if((lin==0 && col==0) && valor==0){
            resposta = 0;
        }else if(posicao_valida(m, lin, col)){
            Lista* aux;
            for(aux = m->prim; aux != NULL; aux = aux->prox){
                if(pos_iguais(aux, lin, col)){
                    if(valor != 0)
                        aux->info = valor;
                    break;
                }
            }
            if(aux==NULL && valor!=0){
                Lista* novoNoh = novo_noh(lin, col, valor);
                novoNoh->prox = m->prim;
                m->prim = novoNoh;
            }
        }else{
            printf("Posicao para a matriz invalida!Tente de novo ou digite '0 0 0' para sair: \n");
        }
    }
}

//funcao adicional para visualizar a matriz, nao foi solicitada no exercicio
void imprime_mat(Esparsa m){
    Lista* aux;
    int i, j;
    printf("\nMatriz Esparsa:\n");
    for(i=0; i<m.linhas; i++){
        for(j=0; j<m.colunas; j++){
            int nulo = 1;
            for (aux = m.prim; aux != NULL; aux = aux->prox){
                if(pos_iguais(aux, i, j)){
                    printf("%4d ", aux->info);
                    nulo = 0;
                    break;
                }
            }
            if(nulo == 1)
                printf("%4d ", 0);
            if(j == m.colunas-1)
                printf("\n");
        }
    }    
}


void consulta_elem(Esparsa* m){
    int lin, col;
    Lista* aux;
    int r = 1;    
    while(r==1){
        printf("\nLinha e coluna do elemento a consultar: ");
        scanf("%d %d", &lin, &col);
        
        if(posicao_valida(m, lin, col)){
            int nulo = 1;
            for(aux = m->prim; aux != NULL; aux = aux->prox){
                if(pos_iguais(aux, lin, col)){
                    printf("Elemento da posicao (%d, %d): %d", lin, col, aux->info);
                    nulo = 0;
                    break;
                }
            }
            if(nulo == 1)
                printf("Elemento da posicao (%d, %d): 0", lin, col);
        }else{
            printf("Posicao a consultar invalida!");
        }
        r = resposta(); 
    }
}

void imprime_somatorio_linha(Esparsa m){
    int lin, r = 1;
    Lista* aux;
    while(r==1){
        int somatorio = 0;
        printf("\nLinha a se realizar o somatorio: ");
        scanf("%d", &lin);
        if(lin>= 0 && lin<m.linhas){
            for(aux = m.prim; aux != NULL; aux = aux->prox){
                if(aux->linha == lin)
                    somatorio += aux->info;
            }
            printf("Somatorio dos elementos da linha %d: %d\n", lin, somatorio);
        }else{
            printf("Linha invalida!");
        }
        r = resposta();
    }
}

void percent_nao_nulos(Esparsa m){
    Lista* aux;
    float naoNulos = 0;
    for(aux = m.prim; aux != NULL; aux = aux->prox){
        naoNulos += 1;
    }
    printf("\nPercentual de elementos nao nulos da matriz: %.2f %%", (naoNulos/(m.linhas*m.colunas)) * 100.0);
}

void libera_mat(Esparsa* m){
    if(m == NULL) return;
    Lista* atual = m->prim;
    Lista* prox;

    while(atual != NULL){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    m->prim = NULL;
}

int main(int argc, char const *argv[])
{
    Esparsa matriz = cria_mat();
    preenche_mat(&matriz);
    imprime_mat(matriz);
    consulta_elem(&matriz);
    imprime_somatorio_linha(matriz);
    percent_nao_nulos(matriz);
    libera_mat(&matriz);
    return 0;
}