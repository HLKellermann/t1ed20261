#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matIdentidade.h"

//FUNCOES AUXILIARES

bool pos_valida(int lin, int col, int ordem){
    return ((lin>=0 && lin<ordem) && (col>=0 && col<ordem)) ? true : false;
}

bool pos_iguais(Lista* a, int lin, int col){
    return (a->lin == lin && a->col == col) ? true : false;
}

bool atende_regras_identidade(Lista* a){
    return ((a->lin==a->col && a->info==1) || ((a->lin!=a->col && a->info==0))) ? true : false;
}

bool verifica_identidade(Identidade* m){
    Lista* a;
    int foraErr = 0, diagOk = 0;
    for(a = m->iniLista; a != NULL; a = a->prox){
        if((a->lin == a->col) && a->info == 1)
            ++diagOk;
        foraErr += ((a->lin != a->col) && a->info != 0) ? 1 : 0;
    }
    return ((foraErr == 0) && (diagOk == m->ordem));
}


//FUNCOES PRINCIPAIS(SOLICITADAS)

Identidade cria_mat(){
    Identidade m;
    printf("\nOrdem da matriz identidade: ");
    scanf("%d", &m.ordem);
    m.iniLista = NULL;
    return m;
}


Lista* novo_noh(int lin, int col, int v){
    Lista* novoNoh = (Lista*) malloc(sizeof(Lista));
    if(novoNoh == NULL){
        printf("\nErro de alocacao! Encerrando");
        exit(1);
    }

    novoNoh->lin = lin;
    novoNoh->col = col;
    novoNoh->info = v;
    novoNoh->prox = NULL;
    return novoNoh;
}

void preenche_mat(Identidade* m){
    printf("\nPreenchimento da matriz: digite a linha, coluna e o valor\n");
    printf("(Para parar de preencher a matriz, digite 0 0 0)\n");
    int r=1;
    while(r==1){
        int lin, col, valor;
        scanf("%d%d%d", &lin, &col, &valor);
        if((lin==0 && col==0) && valor==0)
            r=0;
        else if(pos_valida(lin, col, m->ordem)){
            Lista* aux;
            int jaExiste = 0;
            for(aux = m->iniLista; aux != NULL; aux = aux->prox){
                if(pos_iguais(aux, lin, col)){
                    aux->info = valor;
                    jaExiste = 1;
                    break;
                }
            }
            if(jaExiste == 0){
                Lista* novoNoh = novo_noh(lin, col, valor);
                novoNoh->prox = m->iniLista;
                m->iniLista = novoNoh;
            }
        }
        else
            printf("Posicao para a matriz invalida!Tente de novo ou pare (0 0 0): \n");
    }    
}


void imprime_mat(Identidade m){
    Lista* a;
    int i, j;
    printf("\nImpressao da matriz:\n");
    for(i=0; i<m.ordem; i++){
        for(j=0; j<m.ordem; j++){
            int nulo = 1;
            for (a = m.iniLista; a != NULL; a = a->prox){
                if((a->lin == i) && (a->col == j)){
                    printf("%4d ", a->info);
                    nulo = 0;
                    break;
                }
            }
            if(nulo == 1)
                printf("%4d ", 0);
            if(j == m.ordem-1)
                printf("\n");
        }
    }    
}


void fora_da_principal(Identidade* m){
    Lista* a = m->iniLista;
    int i, j;

    if(!verifica_identidade(m)){
        printf("\nNao eh matriz identidade!\nPara ser Identidade, deve atender a regra:");
        printf("\nM(i,j): {1, se i = j\n\t{0, se i != j\n");
        printf("\nPosicoes que violaram essa propriedade:");
        for(i=0; i<m->ordem; i++){
            for(j=0; j<m->ordem; j++){
                bool existe = false;
                for(a = m->iniLista; a != NULL; a = a->prox){
                    if(pos_iguais(a, i, j)){
                        existe = true;
                        if(atende_regras_identidade(a) == 0)
                            printf("\n(%d, %d): %d", a->lin, a->col, a->info);
                    }
                }
                if((i==j) && existe == false)
                    printf("\n(%d, %d): 0", i, j);
            }
        }
    }else{
        printf("\nA matriz inserida eh uma matriz identidade!");
    }
}

void libera_mat(Identidade* m){
    if (m==NULL) return;

    Lista* atual = m->iniLista;
    Lista* prox;

    while (atual != NULL){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    m->iniLista = NULL;
}

int main(int argc, char const *argv[])
{
    Identidade matriz= cria_mat();
    preenche_mat(&matriz);
    imprime_mat(matriz);
    fora_da_principal(&matriz);
    libera_mat(&matriz);
    return 0;
}