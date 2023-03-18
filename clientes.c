/**
 * @file clientes.c
 * @author Carlos Brandão 26025
 * @date 2023-03-10
 * @brief ficheiro que contem as funções utilizadas para gerir os clientes
 * @copyright Copyright (c) 2023
 *
 */

#include <stdlib.h>
#include <string.h>
#include "clientes.h"

Cliente *lerClientes()
{
	FILE *fp;
	int nifcliente;
	float saldocliente;
	char nomecliente[NOMELENGTH];
	char moradacliente[MORADALENGTH];
	Cliente *aux = NULL;
	fp = fopen("clientes.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%[^;];%[^;];%f\n", &nifcliente, nomecliente, moradacliente, &saldocliente);
			aux = inserirCliente(aux, nifcliente, nomecliente, moradacliente, saldocliente);
		}
		fclose(fp);
	}
	return (aux);
}

// Insere um cliente no registo
Cliente *inserirCliente(Cliente *inicio, int nifcliente, char nomecliente[], char moradacliente[], float saldocliente)
{
	if (!existeCliente(inicio, nifcliente))
	{
		Cliente *novo = malloc(sizeof(struct cliente));
		if (novo != NULL)
		{
			novo->nif = nifcliente;
			strcpy(novo->nome, nomecliente);
			strcpy(novo->morada, moradacliente);
			novo->saldo = saldocliente;
			novo->seguinte = inicio;
			return (novo);
		}
	}
	else
		return (inicio);
}

// Listar na consola o conteúdo da lista ligada
void listarClientes(Cliente *inicio)
{
	while (inicio != NULL)
	{
		printf("%d %s %s %.2f\n", inicio->nif, inicio->nome, inicio->morada, inicio->saldo);
		inicio = inicio->seguinte;
	}
}

// Determinar existência do 'nif' na lista ligada 'inicio'
bool existeCliente(Cliente *inicio, int nif)
{
	while (inicio != NULL)
	{
		if (inicio->nif == nif)
			return (true);
		inicio = inicio->seguinte;
	}
	return (false);
}

// Remover um Cliente a partir do seu código
Cliente *removerCliente(Cliente *inicio, int nif)
{
	Cliente *anterior = inicio, *atual = inicio, *aux;

	if (atual == NULL)
		return (NULL);
	else if (atual->nif == nif)
	{
		aux = atual->seguinte;
		free(atual);
		return (aux);
	}
	else
	{
		while ((atual != NULL) && (atual->nif != nif))
		{
			anterior = atual;
			atual = atual->seguinte;
		}
		if (atual == NULL)
			return (inicio);
		else
		{
			anterior->seguinte = atual->seguinte;
			free(atual);
			return (inicio);
		}
	}
}

// Edita o saldo de um cliente com base no seu 'nif'
bool editarSaldo(Cliente *inicio, int nif, float novosaldo)
{
	while (inicio != NULL)
	{
		if(inicio->nif == nif)
		{
			inicio->saldo = novosaldo;
			return(true);
		}
		inicio = inicio->seguinte;
	}
	return(false);
}