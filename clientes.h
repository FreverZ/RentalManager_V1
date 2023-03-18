/**
 * @file clientes.c
 * @author Carlos Brandão 26025
 * @date 2023-03-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdbool.h>
#define MORADALENGTH 100
#define NOMELENGTH 50

typedef struct cliente
{
    int nif;
    char nome[NOMELENGTH];
    char morada[MORADALENGTH];
    float saldo;
    struct cliente *seguinte;
} Cliente;

Cliente *inserirCliente(Cliente *inicio, int nif, char nome[], char morada[], float saldo); // Inserção de um novo registo
void listarClientes(Cliente* inicio); // Listar na consola o conteúdo da lista ligada
bool existeCliente(Cliente *inicio, int nif); // Determinar existência do 'nif' na lista ligada 'inicio'
Cliente* removerCliente(Cliente* inicio, int nif); // Remover um Cliente a partir do seu nif
// int guardarClientes(Cliente* inicio);
Cliente* lerClientes(); // Lê a informação dos clientes que está no 'clientes.txt'
bool editarSaldo(Cliente *inicio, int nif, float novosaldo); //Edita o saldo de um cliente com base no seu 'nif'
