/*
- consulta de um determinado elemento da matriz (para consultar um elemento, informe a linha e a coluna onde ele se encontra);
- impressão de somatório de uma linha i (informada pelo usuário);
- percentual de elementos não nulos na matriz lida.*/

#include <stdio.h>
#include <stdlib.h>

struct lista //lista de valores não nulos da matriz esparsa. Os elementos não nulos da matriz são armazenados nesta lista.
{
    int linha; // linha onde se encontra o elemento não nulo
    int coluna; // coluna onde se encontra o elemento não nulo
    int info; // valor do elemento não nulo
    struct lista* prox; // apontador para o proximo elemento não nulo da matriz
};
typedef struct lista Lista;

struct esparsa
{
    int linhas; //numero de linhas da matriz
    int colunas; //numero de colunas da matriz
    struct lista* prim; //apontador para o primeiro noh não nulo da matriz
};
typedef struct esparsa Esparsa;

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
        else
            m->prim = novo_noh(m->prim, l, c, v);
    }
}

//nao e obrigatorio essa aqui
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


void consulta_elem(Esparsa m){//informar linha e coluna
    int lin, col;
    Lista* aux;
    int r = 1;    
    while(r==1){
        printf("\nLinha e Coluna do elemento a consultar: ");
        scanf("%d %d", &lin, &col);
    
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
        printf("\nOutra pesquisa? 1-SIM   0-NAO\t");
        scanf("%d", &r);
    }
}

void imprime_somatorio_linha(Esparsa m){
    int lin, somatorio = 0;
    Lista* aux;
    printf("\nLinha a se realizar o somatorio: ");
    scanf("%d", &lin);
    for(aux = m.prim; aux != NULL; aux = aux->prox){
        if(aux->linha == lin)
            somatorio += aux->info;
    }
    printf("Somatorio dos elementos da linha %d: %d\n", lin, somatorio);
}
void percentulal_nao_nulos(Esparsa m){
    Lista* aux;
    float naoNulos = 0;
    for(aux = m.prim; aux != NULL; aux = aux->prox){
        naoNulos += 1;
    }
printf("\nPercentual de elementos nao nulos da matriz: %.2f %%", naoNulos * ((m.linhas * m.colunas) / 100));
}


int main(int argc, char const *argv[])
{
    Esparsa matriz = cria_mat();
    preenche_mat(&matriz);
    imprime_mat(matriz);//nao e obrigatorio essa aqui
    consulta_elem(matriz);
    imprime_somatorio_linha(matriz);
    percentulal_nao_nulos(matriz);
    return 0;
}
