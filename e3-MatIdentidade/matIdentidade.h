#ifndef MATIDENTIDADE_H
#define MATIDENTIDADE_H

//DEFINICAO DE STRUCTS

struct lista
{
    int lin;
    int col;
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

struct identidade
{
    int ordem;
    int ehIdentidade;
    struct lista* iniLista;
};
typedef struct identidade Identidade;


//PROTOTIPOS DAS FUNCOES

Identidade cria_mat();

Lista* novo_noh(Lista* listaMat, int l, int c, int v);

void preenche_mat(Identidade* m);

void verifica_identidade(Identidade* m);

int atende_regras(Lista* a);

void imprime_mat(Identidade m);

void fora_da_principal(Identidade m);

#endif