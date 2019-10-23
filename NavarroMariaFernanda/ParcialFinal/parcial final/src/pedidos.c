
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "pedidos.h"
#include "getInput.h"
#define CANT_CLIENTES 100
#define CANT_PEDIDOS 1000
#define TRUE 0
#define FALSE 1
#define ESTADO_PENDIENTE 1
#define ESTADO_COMPLETADO  0

void subMenuPedido()
{
	printf("\n");
	printf("____________________________________");
	printf("\n1-Alta_pedido");
	printf("\n2-Modificar_pedido");
	printf("\n3-Baja_pedido");
	printf("\n4-Volver a menu principal");
	printf("\n_________________________________");
}

void subMenuChangePedido()
{
	printf("\n");
	printf("__CHANGE_______________________________");
	printf("\n1-Cambiar estado del pedido");
	printf("\n2-Cambiar cantidad de recoleccion");
	printf("\n3-Volver a menu principal");
	printf("\n______________________________________");
}

int initPedido(Pedidos* pedido,int size)
{
	int ret=-1;
	int i;
	if(pedido!= NULL && size > 0 )
	{
	 for(i=0;i<size;i++)
	 {
	 pedido[i].isEmpty=TRUE;
	 }
	 ret=0;
	}
return ret;
}

int printPositionPedido(Pedidos* pedido,int size,int position)
{
	int ret=-1;
	if(pedido!= NULL && size > 0 && pedido[position].isEmpty == FALSE)
	{
                printf("\n___PEDIDOS__________________________________________________________");
				printf("\nESTADO: 1.PENDIENTE| 2.COMPLETADO \n");
				printf("______________________________________________________________________");
				printf("\nidCliente:%d \nidPedido:%d \nCantidad_Recoleccion:%.2f kg \nEstado:%d\n",
				pedido[position].idCliente,pedido[position].idPedido,
				pedido[position].cantRecoleccion,
				pedido[position].estado);
				printf("____________________________________________________________________\n");

		ret=0;
	}
return ret;
}

int addPedido(Pedidos* pedido,Clients* client,int cant,int size,int *pedidoCount)
{
	int ret=-1;
    int freePosition;
    int position;
    float cantRecoleccion;

	if(pedido!= NULL && size > 0 && searchFreeSpacePedido(pedido,size,&freePosition)==0)
	   {
	    if(findByIdClient(client,cant,&position)==0)
	   {
	    (*pedidoCount)++;
	    getFloat(&cantRecoleccion,"Ingrese cantidad de recoleccion en kilos: ","\nError!!.",1,10000,2);
	    pedido[freePosition].idCliente=client[position].idCliente;
	    pedido[freePosition].idPedido=*pedidoCount;
        pedido[freePosition].estado=ESTADO_PENDIENTE;
        pedido[freePosition].cantRecoleccion=cantRecoleccion;
	    pedido[freePosition].isEmpty=FALSE;
		ret=0;
		printPositionPedido(pedido,size,freePosition);
	   }
	    else
	    {
	        printf("No existe el ID ingresado");
	    }
	   }
	   else
	   {
			printf("\nNo hay mas lugar!!!");
	   }
return ret;
}

int searchFreeSpacePedido(Pedidos* pedido,int size,int *freePosition)
{
 int i;
 int ret=-1;

 if(pedido!= NULL && size > 0 )
 {
     for(i=0;i<size;i++)
 		{
 			if(pedido[i].isEmpty==TRUE)
 			{
 				ret=0;
 			    *freePosition=i;
 			}
 		}
 }
return ret;
}

int cargaPedido(Pedidos* pedido,Clients* client,int cant, int size,int *pedidoCount)
{
    int ret=-1;
    int option;


	   if(client!=NULL && size>0)
       {
    	    do{
        	 subMenuPedido();
        	 getInt(&option,"\n\nIngrese una opcion:","\n\tERROR!!.Opcion invalida\n",1,4,2);
        	   switch(option)
        	  {
        	  case 1:
        	  printf("\n_________Alta_________\n");
        	  addPedido(pedido,client,cant,size,pedidoCount);
        	  break;
        	  case 2:
        	  printf("\n_________Modificacion_________\n");
        	  changeByIdPedido(pedido,size,pedidoCount);
        	  break;
        	  case 3:
        	    printf("\n_______Baja_________\n");
        	    removeByIdPedido(pedido,size,pedidoCount);
        	     break;
        	  }
		    }while(option!=4);
    	    ret=0;
       }
 return ret;
}

int changeByIdPedido(Pedidos* pedido, int size,int *pedidoCount)
{
    int ret=-1;
    int position;
    int option;
    int estado;
    float cantRecoleccion;

       if(pedido!=NULL && size>0 && loadedOrder(pedido,size,*pedidoCount)==0)
       {
    	    if(findByIdPedido(pedido,size,&position)==0)
    	   {
    	    do{
        	 subMenuChangePedido();
        	 getInt(&option,"\n\nIngrese una opcion:","\n\tERROR!!.Opcion invalida\n",1,3,2);
        	   switch(option)
        	  {
        	  case 1:
        	  printf("\n__Cambiar_Estado");
              getInt(&estado,"\nIngrese el nuevo estado (1.PENDIENTE,2.COMPLETADO): ","\nError!!.",1,2,2);
              pedido[position].estado=estado;
        	  break;
        	  case 2:
        	  printf("\n__Cambiar_cantidad_de_recoleecion__");
        	  getFloat(&cantRecoleccion,"\nIngrese nueva cantidad de recoleccion en kilos: ","\nError!!.",1,10000,2);
        	  pedido[position].cantRecoleccion=cantRecoleccion;
        	  break;
        	  }
        	   if(option!=3)
        	   {printf("El cambio fue exitoso!!\n");
        	   printPositionPedido(pedido,size,position);
        	    ret=0;
        	    break;
        	   }
		    }while(option!=3);
  		    }
    	    else
            {
        	printf("No existe el id ingresado!!");
            }
       }
 return ret;
}

int removeByIdPedido(Pedidos* pedido, int size,int *pedidoCount)
{
    int ret=-1;
    int position;
    char seguir;

    if(pedido!=NULL && size>0 && loadedOrder(pedido,size,*pedidoCount)==0)
    {
        if(findByIdPedido(pedido,size,&position)==0)
        {
        	getSeguir(&seguir,"Desea eliminar el pedido (s/n):","Error!!.Opcion invalida\n",'s','n',2);
        	if(seguir!='n')
        	{
        		(*pedidoCount)--;
        		pedido[position].idCliente=0;
        		pedido[position].idPedido=0;
        		pedido[position].estado=0;
        		pedido[position].cantRecoleccion=0;
        		pedido[position].HDPE=0;
        		pedido[position].LDPE=0;
        		pedido[position].PP=0;
        		pedido[position].isEmpty=TRUE;
        		ret=0;
        		printf("La baja fue exitosa!!");
        	 }
        	 else
        	 {
        	 printf("Se cancela eliminacion...");
        	}
        }
        else
        {
        	printf("No existe el ID ingresado");
        }
    }
 return ret;
}

int findByIdPedido(Pedidos* pedido,int size,int *position)
{
    int ret=-1;
    int i;
    int idPedido;

    if(pedido!= NULL && size>=0)
    {
    	printPedido(pedido,size);
    	getInt(&idPedido,"\n\nIngrese el ID del pedido: ","\nERROR.",1,1000,2);
        for(i=0;i<size;i++)
        {
            if(pedido[i].isEmpty == FALSE && pedido[i].idPedido==idPedido)
            {
            	*position=i;
                ret=0;
                break;
            }
            else
            {
                 continue;
            }
        }
    }
return ret;
}

int printPedido(Pedidos* pedido,int size)
{
	int ret=-1;
	int i;

	if(pedido!= NULL && size > 0)
	{
		printf("\n____PEDIDOS_________________________________________________________");
	    printf("\nESTADO: 1.PENDIENTE| 2.COMPLETADO \n");
		printf("______________________________________________________________________");
		for(i=0;i<size;i++)
    {
	   if(pedido[i].isEmpty == FALSE)
		{
		printf("\nidClient:%d \nidPedido:%d \ncant_Recoleccion:%.2f kg \nEstado:%d\n",
		pedido[i].idCliente,pedido[i].idPedido,pedido[i].cantRecoleccion,
		pedido[i].estado);
		printf("____________________________________________________________________\n");
		}
	}
	ret=0;
	}

return ret;
}

int procesarResiduos(Pedidos* pedido,int size,int pedidoCount)
{
	int ret=-1;
	int position;
	float cantRecoleccion;
	float residuos;
    float HDPE;
    float LDPE;
    float PP;

	    if(pedido!=NULL && size>0 && loadedOrder(pedido,size,pedidoCount)==0)
	    {
	        if(findByIdPedido(pedido,size,&position)==0)
	        {
	        	printf("Tipos de plastico que la empresa puede reciclar: 'HDPE'|'LDPE'|'PP'");
	        	getFloat(&HDPE,"\nIngrese cantidad de kilos de plastico HDPE: ","\nError!!.",0,10000,2);
	        	getFloat(&LDPE,"Ingrese cantidad de kilos de plastico LDPE: ","\nError!!.",0,10000,2);
	        	getFloat(&PP,"Ingrese cantidad de kilos de plastico PP: ","\nError!!.",0,10000,2);
	            pedido[position].estado=ESTADO_COMPLETADO;
	            pedido[position].HDPE=HDPE;
	            pedido[position].LDPE=LDPE;
	            pedido[position].PP=PP;
	            cantRecoleccion=pedido[position].cantRecoleccion;
	            residuos=cantRecoleccion-(HDPE+LDPE+PP);
	            ret=0;
	            printf("\tEl procesamiento fue exitoso!!");
	            printf("\nRecoleccion total  del cliente: %.2f kg"
	            		"\nCantidad por tipo de plastico:"
	            		"\nHDPE:%.2f kg"
	            		"\nLDPE:%.2f kg"
	            		"\nPP:%.2f kg"
	            		"\nResiduos:%.2f kg\n"
						,pedido[position].cantRecoleccion,HDPE,LDPE,PP,residuos);
	        }
		else
	        {
	        	printf("No existe el id ingresado!!");
	        }
	       }
return ret;
}

int loadedOrder(Pedidos* pedido,int size,int pedidoCount)
{
	int ret=-1;
    int i;

    if(pedido!= NULL && size > 0)
	{
	for(i=0;i<size;i++)
	{
	  if(pedido[i].isEmpty == TRUE && pedidoCount==0)
	  {

		  printf("\nError!!.No hay pedidos cargados\n");
		  break;
	  }
	  else
	  {
		  ret=0;
		  continue;
	  }
	 }
	 }
return ret;
}
