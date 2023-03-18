/**
 * @file aluguer.c
 * @author Carlos Brandão 26025
 * @date 2023-03-10
 * @brief ficheiro que contem as funções utilizadas para gerir os Alugueres
 * @copyright Copyright (c) 2023
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "aluguer.h"

Aluguer *lerAlugueres()
{
	FILE *fp;
	int nif;
	int idveiculo;
	char data[DATALENGTH];
	char hora[HORALENGTH];
	char loc[LOCALIZACAO];
	Aluguer *aux = NULL;
	fp = fopen("Alugueres.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%[^;];%[^;];%f\n", &nif, &idveiculo, data, hora, loc);
			aux = inserirAluguer(aux, nif, idveiculo, data, hora, loc);
		}
		fclose(fp);
	}
	return (aux);
}

// Inserção de um novo registo
Aluguer *inserirAluguer(Aluguer *inicio, int nif, int idveiculo, char data[], char hora[], char loc[])
{
	if (!existeAluguer(inicio, nif))
	{
		Aluguer *novo = malloc(sizeof(struct aluguer));
		if (novo != NULL)
		{
			novo->nif = nif;
			novo->idveiculo = idveiculo;
			strcpy(novo->data, data);
			strcpy(novo->hora, hora);
			strcpy(novo->loc, loc);
			novo->seguinte = inicio;
			return (novo);
		}
	}
	else
		return (inicio);
}

// listar na consola o conteúdo da lista ligada
void listarAlugueres(Aluguer *inicio)
{
	while (inicio != NULL)
	{
		printf("%d %d %s %s %s\n", inicio->nif, inicio->idveiculo, inicio->data, inicio->hora, inicio->loc);
		inicio = inicio->seguinte;
	}
}

// Determinar existência do 'nif' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contrário
bool existeAluguer(Aluguer *inicio, int nif)
{
	while (inicio != NULL)
	{
		if (inicio->nif == nif)
			return (true);
		inicio = inicio->seguinte;
	}
	return (false);
}

// Remover um Aluguer a partir do seu código
Aluguer *removerAluguer(Aluguer *inicio, int nif)
{
	Aluguer *anterior = inicio, *atual = inicio, *aux;

	if (atual == NULL)
		return (NULL);
	else if (atual->nif == nif) // remoção do 1º registo
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
