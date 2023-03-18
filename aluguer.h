/**
 * @file aluguer.h
 * @author Carlos Brandão 26025
 * @date 2023-03-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdbool.h>
#define DATALENGTH 10
#define HORALENGTH 5
#define LOCALIZACAO 5

typedef struct aluguer
{
    int nif;
    int idveiculo;
    char data[DATALENGTH];
    char hora[HORALENGTH];
    char loc[LOCALIZACAO];
    struct aluguer *seguinte;
} Aluguer;

Aluguer *inserirAluguer(Aluguer *atual, int nif, int idveiculo, char data[], char hora[], char loc[]); // Inserção de um novo registo
void listarAlugueres(Aluguer *atual); // listar na consola o conteúdo da lista ligada
Aluguer *removerAluguer(Aluguer *atual, int nif); // Remover um Aluguer a partir do seu nif
Aluguer *lerAlugueres(); // lê a informação dos alugueres que está no 'aluguer.txt'
bool existeAluguer(Aluguer *atual, int nif); // Verifica a existência do aluguer
