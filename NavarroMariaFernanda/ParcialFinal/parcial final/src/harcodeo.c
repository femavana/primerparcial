#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "pedidos.h"
#define CANT_CLIENTES 100
#define CANT_PEDIDOS 1000
#define TRUE 0
#define FALSE 1
#define ESTADO_PENDIENTE 1
#define ESTADO_COMPLETADO  0


void harcodeoCliente(Clients* client,int cant)
 {
	  strcpy(client[1].nombreEmpresa,"Telefonica");
	  strcpy(client[1].direccion,"Lima 1234");
	  strcpy(client[1].localidad,"CABA");
	  strcpy(client[1].cuit,"30-11223344-5");
	  client[1].isEmpty=FALSE;
	  client[1].idCliente=1;

    strcpy(client[2].nombreEmpresa,"DATASOFT");
    strcpy(client[2].direccion,"Corrientes 2547");
    strcpy(client[2].localidad,"CABA");
    strcpy(client[2].cuit,"30-44556677-6");
    client[2].isEmpty=FALSE;
    client[2].idCliente=2;

    strcpy(client[3].nombreEmpresa,"NESTLE");
    strcpy(client[3].direccion,"cucha cucha 555");
    strcpy(client[3].localidad,"LANUS");
    strcpy(client[3].cuit,"30-88995521-9");
    client[3].isEmpty=FALSE;
    client[3].idCliente=3;

    strcpy(client[4].nombreEmpresa,"TERRABUSI");
    strcpy(client[4].direccion,"rocha 784");
    strcpy(client[4].localidad,"QUILMES");
    strcpy(client[4].cuit,"30-56781423-5");
    client[4].isEmpty=FALSE;
    client[4].idCliente=4;

    strcpy(client[5].nombreEmpresa,"DIA");
    strcpy(client[5].direccion,"Mitre 750");
    strcpy(client[5].localidad,"AVELLANEDA");
    strcpy(client[5].cuit,"31-54581253-3");
    client[5].isEmpty=FALSE;
    client[5].idCliente=5;

    strcpy(client[6].nombreEmpresa,"QUILMES");
    strcpy(client[6].direccion,"rocha 741");
    strcpy(client[6].localidad,"QUILMES");
    strcpy(client[6].cuit,"30-51485759-6");
    client[6].isEmpty=FALSE;
    client[6].idCliente=6;
 }

void harcodeoPedido(Pedidos* pedido,int size,Clients* client,int cant)
 {
    pedido[1].isEmpty=FALSE;
    pedido[1].idPedido=1;
    pedido[1].idCliente=client[1].idCliente;
    pedido[1].cantRecoleccion=1000;
    pedido[1].HDPE=200;
    pedido[1].LDPE=145;
    pedido[1].PP=230;
    pedido[1].estado=ESTADO_COMPLETADO;

    pedido[2].isEmpty=FALSE;
    pedido[2].idPedido=2;
    pedido[2].idCliente=client[1].idCliente;
    pedido[2].cantRecoleccion=800;
    pedido[2].HDPE=210;
    pedido[2].LDPE=45;
    pedido[2].PP=30;
    pedido[2].estado=ESTADO_COMPLETADO;

    pedido[3].isEmpty=FALSE;
    pedido[3].idPedido=3;
    pedido[3].idCliente=client[2].idCliente;
    pedido[3].cantRecoleccion=100;
    pedido[3].estado=ESTADO_PENDIENTE;

    pedido[4].isEmpty=FALSE;
    pedido[4].idPedido=4;
    pedido[4].idCliente=client[2].idCliente;
    pedido[4].cantRecoleccion=300;
    pedido[4].estado=ESTADO_PENDIENTE;

    pedido[5].isEmpty=FALSE;
    pedido[5].idPedido=5;
    pedido[5].idCliente=client[3].idCliente;
    pedido[5].cantRecoleccion=1500;
    pedido[5].HDPE=500;
    pedido[5].LDPE=150;
    pedido[5].PP=270;
    pedido[5].estado=ESTADO_COMPLETADO;

    pedido[6].isEmpty=FALSE;
    pedido[6].idPedido=6;
    pedido[6].idCliente=client[4].idCliente;
    pedido[6].cantRecoleccion=750;
    pedido[6].HDPE=100;
    pedido[6].LDPE=50;
    pedido[6].PP=70;
    pedido[6].estado=ESTADO_COMPLETADO;

    pedido[7].isEmpty=FALSE;
    pedido[7].idPedido=7;
    pedido[7].idCliente=client[1].idCliente;
    pedido[7].cantRecoleccion=200;
    pedido[7].estado=ESTADO_PENDIENTE;

    pedido[8].isEmpty=FALSE;
    pedido[8].idPedido=8;
    pedido[8].idCliente=client[5].idCliente;
    pedido[8].cantRecoleccion=30;
    pedido[8].HDPE=10;
    pedido[8].LDPE=5;
    pedido[8].PP=3;
    pedido[8].estado=ESTADO_COMPLETADO;

    pedido[9].isEmpty=FALSE;
    pedido[9].idPedido=9;
    pedido[9].idCliente=client[6].idCliente;
    pedido[9].cantRecoleccion=456;
    pedido[9].estado=ESTADO_PENDIENTE;

 }
