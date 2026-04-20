#include <stdio.h>
#include <stdlib.h>
#include "matEsparsa.h"

Esparsa cria_mat(){
    Esparsa m;
    printf("\nTamanho da Matriz Esparsa (linhas x colunas): ");
    scanf("%d %d", &m.linhas, &m.colunas);
    m.prim = NULL;
    return m;
}

Lista* novo_noh(Lista* listaMat, int l, int c, int v){
    Lista* novoNoh = (Lista*) malloc(sizeof(Lista));
    novoNoh->linha = l;
    novoNoh->coluna = c;
    novoNoh->info = v;
    novoNoh->prox = listaMat;
    return novoNoh;
}

void preenche_mat(Esparsa* m){
    printf("\nPreenchimento da matriz esparsa: digite a linha, coluna e o valor nao nulo\n");
    printf("(Para parar de preencher a matriz, digite 0 0 0)\n");
    int r = 1;
    while(r==1){
        int l, c, v;
        scanf("%d %d %d", &l, &c, &v);
        if((l==0 && c==0) && v==0)
            r = 0;
        else if((l>=0 && l<m->linhas) && (c>=0 && c<m->colunas))
            m->prim = novo_noh(m->prim, l, c, v);
        else
            printf("Posicao para a matriz invalida!Tente de novo ou pare (0 0 0): \n");
    }
}

//funcao adicional para visualizar a matriz, nao foi solicitada no exercicio
void imprime_mat(Esparsa m){
    Lista* aux;
    int l, c;
    printf("\nMatriz Esparsa:\n");
    for(l=0; l<m.linhas; l++){
        for(c=0; c<m.colunas; c++){
            int nulo = 1;
            for (aux = m.prim; aux != NULL; aux = aux->prox){
                if((aux->linha == l) && (aux->coluna == c)){
                    printf("%4d ", aux->info);
                    nulo = 0;
                    break;
                }
            }
            if(nulo == 1)
                printf("%4d ", 0);
            if(c == m.colunas-1)
                printf("\n");
        }
    }    
    printf("\n");
}

//funcao auxiliar: repete while ate a input ser valido (1 ou 0), retorna opcao para funcao principal
int resposta(){
    int r;
    do{
        printf("\n[1] Repetir operacao   [0] Parar\t");
        scanf("%d", &r);
        if(r != 1 && r != 0)
            printf("invalido!");
    }while(r!=1 && r!=0);
    return r;
}

void consulta_elem(Esparsa m){
    int lin, col;
    Lista* aux;
    int r = 1;    
    while(r==1){
        printf("\nLinha e Coluna do elemento a consultar: ");
        scanf("%d %d", &lin, &col);
        
        if((lin>=0 && lin<m.linhas) && (col>=0 && col<m.colunas)){
            int nulo = 1;
            for(aux = m.prim; aux != NULL; aux = aux->prox){
                if((lin == aux->linha) && (col == aux->coluna)){
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

int main(int argc, char const *argv[])
{
    Esparsa matriz = cria_mat();
    preenche_mat(&matriz);
    imprime_mat(matriz);
    consulta_elem(matriz);
    imprime_somatorio_linha(matriz);
    percent_nao_nulos(matriz);
    return 0;
}