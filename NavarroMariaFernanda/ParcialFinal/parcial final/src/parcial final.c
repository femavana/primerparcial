/*
 ============================================================================
 Name        : PrimerParcial.c
 Author      : NavarroMariaFernanda
 Version     :
 Copyright   : Your copyright notice
 Description :  First Exam in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "pedidos.h"
#include "informes.h"
#include "harcodeo.h"
#include "getInput.h"
#define CANT_CLIENTES 100
#define CANT_PEDIDOS 1000
#define TRUE 0
#define FALSE 1
#define ESTADO_PENDIENTE 1
#define ESTADO_COMPLETADO  0

int main(void)
{
	int option;
	int clientCount=0;
	int pedidoCount=0;
	 Clients client[CANT_CLIENTES];
	 initClient(client,CANT_CLIENTES);
	 Pedidos pedido[CANT_PEDIDOS];
	 initPedido(pedido,CANT_PEDIDOS);


     do{
		//clearScreen();
    	harcodeoCliente(client,CANT_CLIENTES);
    	harcodeoPedido(pedido,CANT_PEDIDOS,client,CANT_CLIENTES);
		menu();
	    getInt(&option,"\nIngrese una opcion: ","\nERROR!!.Opcion no valida!.",1,10,2);
	switch(option)
		{
		case 1:
			printf("\n\t______Alta_Cliente_________________________________");
			//addClient(client,CANT_CLIENTES,&clientCount);
			break;
		case 2:
			printf("\n\t______Modificar_Datos_Cliente______________________");
			changeByIdClient(client,CANT_CLIENTES,clientCount);
			break;
		case 3:
			printf("\n\t______ Baja_Cliente_________________________________");
			removeByIdClient(client,CANT_CLIENTES,&clientCount);
			break;
		case 4:
			printf("\n_________Crear_Pedido_de_Recoleccion__________________ ");
			//cargaPedido(pedido,client,CANT_CLIENTES,CANT_PEDIDOS,&pedidoCount);
			break;
		case 5:
			printf("\n\t________Procesar_Residuos____________________________");
			//procesarResiduos(pedido,CANT_PEDIDOS,pedidoCount);
			break;
		case 6:
			printf("\n\t________Imprimir_Clientes____________________________");
			listClients(pedido,client,CANT_CLIENTES,CANT_PEDIDOS);
			break;
		case 7:
			printf("\n\t________Imprimir_Pedidos_Recoleccion_Pendientes__________________");
			orderListPending(pedido,client,CANT_CLIENTES,CANT_PEDIDOS);
            break;
		case 8:
			 printf("\n\t_______Imprimir_Pedidos__Recoleccion_Procesados__________________");
			 orderListProcessed(pedido,client,CANT_CLIENTES,CANT_PEDIDOS);
		     break;
		case 9:
			cargaInformes(pedido,client,CANT_CLIENTES,CANT_PEDIDOS);
		    break;

		}
	}while(option!=10);
return 0;
}
