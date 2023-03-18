/**
 * @file clientes.c
 * @author Carlos Brandão 26025
 * @date 2023-03-16
 * @brief Ficheiro main.c que chama as funções
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include "veiculos.h"
#include "clientes.h"

int menu()
{
	int op;
	printf("Veiculos\n");
	printf("	1 Inserir Veiculo\n");
	printf("	2 Listar Veiculos\n");
	printf("	3 Remover Veiculo\n");
	printf("	4 Guardar Veiculos <NAO FUNCIONAL>\n");
	printf("	5 Ler Veiculos\n");
	printf("Clientes\n");
	printf("	6 Inserir Cliente\n");
	printf("	7 Listar Clientes\n");
	printf("	8 Remover Cliente\n");
	printf("	9 Editar Saldo\n");
	printf("	10 Guardar Clientes <NAO FUNCIONAL>\n");
	printf("	11 Ler Clientes\n");
	printf("	0 Sair\n");
	printf("Opcao:\n");
	scanf("%d",&op);
	return(op);
}

int main()
	{
	int op;

	Veiculo *veiculos = NULL;
	int cod;
	float bat, aut;
	char tipo[TIPOLENGTH];
	char loc[LOCATION];

	Cliente *clientes = NULL;
	int nif;
	char nome[NOMELENGTH];
	char morada[MORADALENGTH];
	float saldo;

	do
	{
		op = menu();
		switch(op)
		{
			case 1: printf("Codigo?\n");
			scanf("%d",&cod);
			scanf("%*c"); 
			printf("Tipo\n");
			scanf("%[^\n]s",tipo);
			printf("Nivel da bateria?\n");
			scanf("%f",&bat);
			printf("Autonomia\n");
			scanf("%f",&aut);
			fflush(stdin);
			printf("Localizacao (Ex: D15)\n");
			scanf("%[^\n]s", loc);
			veiculos = inserirVeiculo(veiculos, cod, tipo, bat, aut, loc);
			break;
		case 2:
			listarVeiculos(veiculos);
			break;
		case 3: printf("Codigo do meio de mobilidade a remover?\n");
			scanf("%d",&cod);
			veiculos = removerVeiculo(veiculos, cod);
			break;
		case 4:
			//guardarVeiculos(veiculos);
			break;
		case 5:
			veiculos = lerVeiculos();
			break;
		case 6:
			printf("Nif?\n");
			scanf("%d", &nif);
			scanf("%*c");
			printf("Nome\n");
			scanf("%[^\n]s", nome);
			fflush(stdin);
			printf("Morada\n");
			scanf("%[^\n]s", morada);
			printf("Saldo\n");
			scanf("%f", &saldo);
			clientes = inserirCliente(clientes, nif, nome, morada, saldo);
			break;
		case 7:
			listarClientes(clientes);
			break;
		case 8:
			printf("Nif da pessoa a remover?\n");
			scanf("%d", &nif);
			clientes = removerCliente(clientes, nif);
			break;
		case 9:
			printf("Nif?\n");
			scanf("%d", &nif);
			printf("Novo saldo\n");
			scanf("%f", &saldo);
			editarSaldo(clientes, nif, saldo);
			break;
		case 10:
			//guardarClientes(clientes);
			break;
		case 11:
			clientes = lerClientes();
			break;
		}
	} while (op!=0);
	return(0);
}
