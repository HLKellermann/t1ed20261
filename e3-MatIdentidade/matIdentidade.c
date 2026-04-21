#include <stdio.h>
#include <stdlib.h>
#include "matIdentidade.h"

Identidade cria_mat(){
    Identidade m;
    printf("Ordem da matriz identidade: ");
    scanf("%d", &m.ordem);
    m.iniLista = NULL;
    return m;
}

Lista* novo_noh(Lista* listaMat, int l, int c, int v){
    Lista* novoNoh = (Lista*) malloc(sizeof(Lista));
    novoNoh->lin = l;
    novoNoh->col = c;
    novoNoh->info = v;
    novoNoh->prox = listaMat;
    return novoNoh;
}

void preenche_mat(Identidade* m){
    printf("\nPreenchimento da matriz: digite a linha, coluna e o valor\n");
    printf("(Para parar de preencher a matriz, digite 0 0 0)\n");
    int r=1;
    while(r==1){
        int l, c, v;
        scanf("%d%d%d", &l, &c, &v);
        if((l==0 && c==0) && v==0)
            r=0;
        else if((l>=0 && l<m->ordem) && (c>=0 && c<m->ordem))
            m->iniLista = novo_noh(m->iniLista, l, c, v);
        else
            printf("Posicao para a matriz invalida!Tente de novo ou pare (0 0 0): \n");
    }    
}

void verifica_identidade(Identidade* m){
    Lista* a;
    int foraErr = 0, diagOk = 0;
    for(a = m->iniLista; a != NULL; a = a->prox){
        if((a->lin == a->col) && a->info == 1)
            ++diagOk;
        foraErr += ((a->lin != a->col) && a->info != 0) ? 1 : 0;
    }
    printf("\n%d e %d", diagOk, foraErr);
    m->ehIdentidade = ((foraErr == 0) && (diagOk == m->ordem));
}

void imprime_mat(Identidade m){
    Lista* a;
    int l, c;
    printf("\nImpressao da matriz:\n");
    for(l=0; l<m.ordem; l++){
        for(c=0; c<m.ordem; c++){
            int nulo = 1;
            for (a = m.iniLista; a != NULL; a = a->prox){
                if((a->lin == l) && (a->col == c)){
                    printf("%4d ", a->info);
                    nulo = 0;
                    break;
                }
            }
            if(nulo == 1)
                printf("%4d ", 0);
            if(c == m.ordem-1)
                printf("\n");
        }
    }    
    printf("\n");
}


int atende_regras(Lista* a){
    return ((a->lin==a->col && a->info==1) || ((a->lin!=a->col && a->info==0))) ? 1 : 0;
}


void fora_da_principal(Identidade m){
    Lista* a = m.iniLista;
    int i, j;
    if(m.ehIdentidade == 0){
        printf("\nNao eh matriz identidade!\nPara ser Identidade, deve atender a regra:");
        printf("\nM(i,j): {1, se i = j\n\t{0, se i != j\n");
        printf("\nPosicoes que violaram essa propriedade:");
        for(i=0; i<m.ordem; i++){
            for(j=0; j<m.ordem; j++){
                for(a = m.iniLista; a != NULL; a = a->prox){
                    if((i == a->lin) && (j == a->col))
                        if(atende_regras(a) == 0)
                            printf("\n(%d, %d): %d", a->lin, a->col, a->info);
                }
            }
        }
    }else{
        printf("\nA matriz inserida eh uma matriz identidade!");
    }
}

int main(int argc, char const *argv[])
{
    Identidade matriz= cria_mat();
    preenche_mat(&matriz);
    verifica_identidade(&matriz);
    imprime_mat(matriz);
    fora_da_principal(matriz);
    return 0;
}