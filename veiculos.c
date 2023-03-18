/**
 * @file veiculos.c
 * @author Carlos Brandão 26025
 * @date 2023-03-16
 * @brief ficheiro que contem as funções utilizadas para gerir os veiculos
 * @copyright Copyright (c) 2023
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "veiculos.h"

// Leitura do ficheiro "veiculos.txt" para futuro armazenamento da informação
Veiculo* lerVeiculos()
{
	FILE* fp;
	int cod;
	float bat, aut;
	char tipo[50];
	char loc[5];
	Veiculo* aux=NULL;
	fp = fopen("veiculos.txt","r");
	if (fp!=NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%f;%f;%[^;];%[^\n]s\n", &cod, &bat, &aut, tipo, loc);
			aux = inserirVeiculo(aux, cod, tipo, bat, aut, loc);
		}
	fclose(fp);
	}
	return(aux);
}

// Inserção de um novo registo
Veiculo* inserirVeiculo(Veiculo* inicio, int cod, char tipo[], float bat, float aut, char loc[])
{
	if (!existeVeiculo(inicio, cod))
	{
		Veiculo* novo = malloc(sizeof(struct veiculo));
		if (novo != NULL)
		{
			novo->codigo = cod;
			strcpy(novo->tipo,tipo);
			novo->bateria = bat;
			novo->autonomia = aut;
			strcpy(novo->localizacao,loc);
			novo->seguinte = inicio;
			return(novo);
		}
	} else
	return(inicio);
}
  
// Listar na consola o conteúdo da lista ligada
void listarVeiculos(Veiculo* inicio)
{while (inicio != NULL)
	{
		printf("%d %s %.2f %.2f %s\n", inicio->codigo, inicio->tipo, inicio->bateria, inicio->autonomia, inicio->localizacao);
		inicio = inicio->seguinte;
	}
}

// Verificar a existência de um veiculo
bool existeVeiculo(Veiculo* inicio, int cod)
{while(inicio!=NULL)
	{
		if (inicio->codigo == cod) return(true);
		inicio = inicio->seguinte;
	}
	return(false);
}

// Remover um Veiculo a partir do seu código{
Veiculo* removerVeiculo(Veiculo* inicio, int cod) 
{
	Veiculo *anterior=inicio, *atual=inicio, *aux;

	if (atual==NULL) 
		return(NULL);
	else if (atual->codigo == cod)
	{
		aux = atual->seguinte;
		free(atual);
		return(aux);
	}
	else
	{
		while ((atual!=NULL)&&(atual->codigo!=cod)) 
		{
			anterior = atual;
			atual = atual->seguinte;
		}
	if (atual==NULL)
		return(inicio);
	else
	{
		anterior->seguinte = atual->seguinte;
		free(atual);
		return(inicio);
	}
	}
}

// Listar veículos que estão na localização dada pelo utilizador
void listarVGeo(Veiculo *inicio, char loc[])
{
	while (inicio != NULL)
	{
		printf("Veiculos na localizacao %s:\n", loc);
		if (strcmp(inicio->loc, loc) == 0)
		{
			printf("%d %s %.2f %.2f\n", inicio->codigo, inicio->tipo, inicio->bateria, inicio->autonomia);
		}
	inicio = inicio->seguinte;
	}
}
