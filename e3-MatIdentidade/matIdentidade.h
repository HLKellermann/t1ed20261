#ifndef MATIDENTIDADE_H
#define MATIDENTIDADE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    struct lista* iniLista;
};
typedef struct identidade Identidade;


//PROTOTIPOS DAS FUNCOES

bool pos_valida(int l, int c, int ordem);

bool pos_iguais(Lista* a, int l, int c);

bool atende_regras_identidade(Lista* a);

bool verifica_identidade(Identidade* m);

Identidade cria_mat();

Lista* novo_noh(int l, int c, int v);

void preenche_mat(Identidade* m);

void imprime_mat(Identidade m);

void fora_da_principal(Identidade* m);

void libera_mat(Identidade* m);

#endif