#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matDiagonal.h"

//FUNCOES AUXILIARES

/*---valida se a posicao digitada pelo usuario esta dentro do tamanho da matriz---*/
bool posicao_valida(int lin, int col, int ordem){
    return (lin>=0 && lin<ordem) && (col>=0 && col<ordem);
}


/*---imprime o resultado da consulta feita na funcao 'consulta_elem'---*/
void imprime_consulta(Diagonal* m, int lin, int col){
    //confere se a posicao eh valida e printa conforme a condição
    if(posicao_valida(lin, col, m->ordem)){
        if(lin == col)
            printf("\nElemento na posicao (%d,%d): %d", lin, col, m->v[lin]); //diagonal principal
        else
            printf("\nElemento na posicao (%d,%d): 0", lin, col);         //valores nulos
    }else   //se posicao invalida
        printf("\nPosicao (%d, %d) invalida! Indice min: 0, indice max: %d", lin, col, m->ordem-1);
}


/*---loop para tratar possivel entrada que nao seja um valor inteiro, para a posicao a se consultar em 'consulta_elem'---*/
void posicoes_inteiras(int* linha, int* coluna){
    int invalido = true;
    int auxLin, auxCol;
    do{
        auxLin = scanf("%d", linha);  //passa entrada do usuario para variavel auxiliar
        auxCol = scanf("%d", coluna);
        if(auxLin != 1 || auxCol != 1){
            printf("Entrada invalida!Digite os indices de novo: ");
            while(getchar() != '\n');       //limpa buffer
        }else{
            break;
        }
    }while(invalido);
}


/*---loop para tratar possivel entrada que nao seja um valor inteiro(como char ou strings)---*/
int input_eh_inteiro(){
    int input, aux;
    do{
        aux = scanf("%d", &input);  //passa entrada do usuario para variavel auxiliar
    
        if(aux != 1){   //se o scanf nao leu um int
            printf("Entrada invalida!Tente de novo: ");
            while(getchar() != '\n');       //limpa buffer
        }
    }while(aux != 1);
    return input;   //retorna input ok
}


/*---loop ateh o input do usuario ser valido para o seu caso especifico---*/
void valida_valores(int* input, int caso){
    bool invalido;  //loop ate o input ser valido(false)
    do{
        if(caso == 1 && *input <= 0){               //caso da funcao 'cria_mat()' para a var 'm.ordem'
            printf("Ordem deve ser maior que 0: ");
            invalido = true;
        }else if(caso == 2 && (*input != 0 && *input != 1)){    //caso da funcao 'consulta_elem()', saber se continua consultando
            printf("Digite 0 ou 1!: ");
            invalido = true;
        }else{
            invalido = false;   //se o input for valido, quebra loop e o valor do * de input estarah ok 
            break;
        }
        *input = input_eh_inteiro();    //rele valor do input e confirma que eh int
    }while(invalido);
}


/*---função chamada pelas principais para realizar leitura e validação da entrada---*/
int leitura_input(int caso){
    int input;  
    switch (caso){
    case 1:         //se 'caso' for '1', funcao 'leitura_input' foi chamda pela principal 'cria_mat()'
        printf("Digite a ordem da Matriz Diagonal: ");  
        input = input_eh_inteiro(); //loop ate ler um input que seja tipo int, devolve quando ok
        valida_valores(&input, 1);  //loop se o input for =< 0, rele ate ser um int e >0, "atualiza" 'input' quando ok 
        return input;   //retorna para cria_mat(), pra var 'm.ordem'
    case 2:
        printf("\n[1] Repetir operacao   [0] Parar\t");
        input = input_eh_inteiro(); //loop ate ler um input que seja tipo int, devolve quando ok
        valida_valores(&input, 2);  //loop se o input for != de 1 e 0, rele ate ser um int e == a 1 ou 0, "atualiza" 'input' quando ok 
        return input;   //retorna para 'consulta_elem()', para o 'while()'
    default:
        printf("\nHa algo de errado no codigo!");   //aparece apenas se alguem alterou o valor fixo de 'caso' em alguma das f principais
        exit(1);
    }
}

//FUNCOES PRINCIPAIS

/*---criação da matriz---*/
Diagonal cria_mat(){
    Diagonal m;
//alocacao dinamica do vetor da matriz
    m.ordem = leitura_input(1);         //chama funcao que le e valida a entrada do usuario, retorna valor para m.ordem
    m.v = malloc(m.ordem * sizeof(int));
//mensagem de erro
    if(m.v == NULL){
        printf("\nErro: Alocacao da matriz malsucedida\n");
        exit(1);
    }
    return m;   //retorna Diagnonal m para a Diagonal matriz no main 
}


/*---preenchimento da matriz---*/
void preenche_mat(Diagonal* m){
    int i;
    printf("\nInforme o valor para a posicao:\n");
//laço para guardar apenas os valores da diagonal no vetor da matriz
    for(i=0; i<m->ordem; i++){
        printf("(%d,%d):", i, i);   //mostra a posicao que o valor serah guardado
        m->v[i] = input_eh_inteiro();   //guarda valor retornado no vetor
    }
}


/*---impressão da matriz---*/
void imprime_mat(Diagonal m){
    int lin, col;

    printf("\nMatriz Diagonal:\n");
    for(lin=0; lin<m.ordem; lin++){
        for(col=0; col<m.ordem; col++){
            printf("%4d ", (lin==col) ? m.v[lin] : 0); //se linha e coluna iguais: info da diagonal, senao: 0 (nao eh diagonal)
        }
        printf("\n");   //nova linha quando for ultima coluna
    }
}


/*---consulta de um determinado elemento da matriz---*/
void consulta_elem(Diagonal* m){
    int lin, col;
    do{
    //usuario informa a linha e coluna onde o elemento se encontra
        printf("\nInforme a posicao (linha, coluna) do elemento: ");
        posicoes_inteiras(&lin, &col);
        imprime_consulta(m, lin, col);      //chama funcao para imprimir resultado da consulta
    }while(leitura_input(2) == 1);
}


/*---libera vetor da matriz---*/
void libera_mat(Diagonal *m){
    if(m!=NULL && m->v!=NULL){
        free(m->v);
        m->v = NULL;
    }
    m->ordem = 0;
}


//FUNCAO PRINCIPAL MAIN
int main(int argc, char const *argv[])
{
    Diagonal matriz = cria_mat();
    preenche_mat(&matriz);
    imprime_mat(matriz);
    consulta_elem(&matriz);
    libera_mat(&matriz);
    return 0;
}