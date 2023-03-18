/**
 * @file clientes.c
 * @author Carlos Brandão 26025
 * @date 2023-03-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdbool.h>
#include <stdio.h>
#define TIPOLENGTH 50
#define LOCATION 5

typedef struct veiculo
{
    int codigo;
    char tipo[TIPOLENGTH];
    float bateria;
    float autonomia;
    char localizacao[LOCATION];
    struct veiculo *seguinte;
} Veiculo;

Veiculo *lerVeiculos(); // Leitura dos veículos a partir de um ficheiro .txt
Veiculo* inserirVeiculo(Veiculo* inicio, int cod, char tipo[], float bat, float aut, char loc[]); // Inserção de um novo registo
void listarVeiculos(Veiculo* inicio); // Listar na consola o conteúdo da lista ligada
bool existeVeiculo(Veiculo* inicio, int codigo); // Determinar existência do 'codigo' na lista ligada 'inicio'
Veiculo* removerVeiculo(Veiculo* inicio, int cod); // Remover um Veiculo a partir do seu código
// guardarVeiculos(Veiculo* atual);
void listarVGeo(Veiculo *inicio, char loc[]) 
