/*
 ============================================================================
 Name        : Primer_Parcial.c
 Author      : NavarroMariaFernanda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "pedidos.h"
#include "getInput.h"
#define CANT_CLIENTES 100
#define CANT_PEDIDOS 1000
#define CANT_PROCESOS 1000
#define TRUE 0
#define FALSE 1
#define ESTADO_PENDIENTE 1
#define ESTADO_COMPLETADO 0

int main(void)
{
	Clients client[CANT_CLIENTES];
	Pedidos pedido[CANT_PEDIDOS];
	//Procesos proceso[CANT_PROCESOS];


	int opcion;
	int clientCount=0;
	int pedidoCount=0;

	 initClient(client,CANT_CLIENTES);
	 initPedido(pedido,CANT_PEDIDOS);
	do{
		menu();
	    getInt(&opcion,"\nIngrese una opcion: ","\nERROR!!.Opcion no valida!.",1,9,2);
	switch(opcion)
		{
		case 1:
			printf("\n\t__Alta_Cliente_______");
			addClient(client,CANT_CLIENTES,&clientCount);
			break;
		case 2:
			printf("\n\t__Modificar_Datos_Cliente____");
			changeByIdClient(client,CANT_CLIENTES,clientCount);
			break;
		case 3:
			printf("\n\t__Baja_Cliente________");
			removeByIdClient(client,CANT_CLIENTES,&clientCount);
			break;
		case 4:
					 printf("\n\t__Crear_Pedido_de_Recoleccion___");
					 cargaPedido(pedido,client,CANT_CLIENTES,CANT_PEDIDOS,&pedidoCount);
		             break;
		case 5:
					 printf("\n\t__Procesar_Reciduos____");

				     break;
		case 6:
					 printf("\n\t__Imprimir_Clientes____");

				     break;
		case 7:
					 printf("\n\t__Imprimir_Pedidos_Pendientes____");

				     break;
		case 8:
			 printf("\n\t__Imprimir_Pedidos_Procesados____");

		     break;


		}
	}while(opcion!=9);
return EXIT_SUCCESS;
}
