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


void menu()
{
	printf("\n");
	printf("______________________");
	printf("\n1-Alta_Cliente");
	printf("\n2-Modificar_Datos_Client");
	printf("\n3-Baja_Cliente");
	printf("\n4-Crear_Pedido_de_Recoleccion");
	printf("\n5-Procesar_Residuos");
	printf("\n6-Imprimir_Clientes");
	printf("\n7-Imprimir_Pedidos_Pendientes");
	printf("\n8-Imprimir_Pedidos_Procesados");
	printf("\n9-Informes");
	printf("\n10-Salir");
	printf("\n____________________________________ ");
}

void subMenuChangeClient()
{
	printf("\n");
	printf("__CHANGE___________________________");
	printf("\n1-Cambiar direccion");
	printf("\n2-Cambiar localidad");
	printf("\n3-Volver a menu principal");
	printf("\n_________________________________");
}

int initClient(Clients* client,int size)
{
	int ret=-1;
	int i;
	if(client!= NULL && size > 0 )
	{
	 for(i=0;i<size;i++)
	 {
	 client[i].isEmpty=TRUE;
	 }
	 ret=0;
	}
return ret;
}

int printClient(Clients* client,int size)
{
	int ret=-1;
	int i;

	if(client!= NULL && size > 0)
	{
		printf("\n______CLIENTES______________________________________________________");
	for(i=0;i<size;i++)
    {
	   if(client[i].isEmpty == FALSE)
		{
		printf("\nidClient:%d \nCUIT:%s \nNombre_Empresa:%s \nDireccion:%s \nLocalidad:%s\n",
				client[i].idCliente,client[i].cuit,client[i].nombreEmpresa,
			    client[i].direccion,client[i].localidad);
		printf("____________________________________________________________________\n");
		}
	}
	ret=0;
	}
return ret;
}

int printPositionClient(Clients* client,int size,int position)
{
	int ret=-1;
	if(client!= NULL && size > 0 && client[position].isEmpty == FALSE)
	{           printf("\n____CLIENTES_______________________________________________________");
				printf("\nidClient:%d \nCUIT:%s \nNombre_Empresa:%s \nDireccion:%s \nLocalidad:%s\n",
				client[position].idCliente,client[position].cuit,client[position].nombreEmpresa,
				client[position].direccion,client[position].localidad);
				printf("____________________________________________________________________\n");
		ret=0;
	}
return ret;
}


int addClient(Clients* client,int size,int *clientCount)
{
	int ret=-1;
    int freePosition;
    char nombreEmpresa[51];
    char direccion[51];
    char localidad[51];
    char cuit[14];

    if(client!=NULL && size>0 )
	{
	   if(searchFreeSpaceClient(client,size,&freePosition)==0)
	   {
	    (*clientCount)++;
	    getName(nombreEmpresa,"\nIngrese el nombre de la empresa: ","Error!!.\n",2,51,2);
	    getAlfanumerico(direccion,"Ingrese direccion de la empresa: ","Error!!.\n",3,51,2);
	    getName(localidad,"Ingrese localidad de la empresa: ","Error!!.\n",2,51,2);
	    getCUIT(cuit,"Ingrese el CUIT de la empresa: ","Error!!.Ingrese ej:00-00000000-0 \n",10,14,2);
        client[freePosition].idCliente=*clientCount;
        strcpy(client[freePosition].cuit,cuit);
		strcpy(client[freePosition].localidad,localidad);
		strcpy(client[freePosition].direccion,direccion);
		strcpy(client[freePosition].nombreEmpresa,nombreEmpresa);
	    client[freePosition].isEmpty=FALSE;
		ret=0;
		printPositionClient(client,size,freePosition);
	   }
		else
		{
			printf("\nNo hay mas lugar!!!");
		}
    }
return ret;
}

int searchFreeSpaceClient(Clients* client,int size,int *freePosition)
{
 int i;
 int ret=-1;

 if(client!= NULL && size > 0 )
 {
     for(i=0;i<size;i++)
 		{
 			if(client[i].isEmpty==TRUE)
 			{
 				ret=0;
 			    *freePosition=i;
 			}
 		}
 }
return ret;
}

int changeByIdClient(Clients* client, int size, int clientCount)
{
    int ret=-1;
    int position;
    int option;
    char direccion[51];
    char localidad[51];

           if(client!=NULL && size>0 && loadedClient(client,size,clientCount)==0)
    	   {
			if(findByIdClient(client,size,&position)==0)
    	    {
		    do{
        	 subMenuChangeClient();
        	 getInt(&option,"\n\nIngrese una opcion:","\n\tERROR!!.Opcion invalida\n",1,3,2);
        	   switch(option)
        	  {
        	  case 1:
        	  printf("\n__Cambiar_direccion__");
        	  getAlfanumerico(direccion,"\nIngrese la nueva direccion: ","\nError!!.",3,51,2);
              strcpy(client[position].direccion,direccion);
        	  break;
        	  case 2:
        	  printf("\n__Cambiar_localidad__");
              getName(localidad,"\nIngrese la nueva localidad: ","\nError!!.Ingrese solo letras",3,51,2);
        	  strcpy(client[position].localidad,localidad);
        	  break;
        	  }
        	   if(option!=3)
        	   {printf("El cambio fue exitoso!!\n");
        	    printPositionClient(client,size,position);
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

int removeByIdClient(Clients* client, int size,int *clientCount)
{
    int ret=-1;
    int position;
    char seguir;

    	 if(client!=NULL && size>0 && loadedClient(client,size,*clientCount)==0)
        {
    	 if(!findByIdClient(client,size,&position))
    	 {
          getSeguir(&seguir,"Desea eliminar el cliente (s/n):","Error!!.Opcion invalida\n",'s','n',2);
    	  if(seguir!='n')
    	 {
        	(*clientCount)--;
            client[position].idCliente=0;
            client[position].isEmpty=TRUE;
            strcpy(client[position].cuit,"");
            strcpy(client[position].direccion,"");
            strcpy(client[position].localidad,"");
            strcpy(client[position].nombreEmpresa,"");
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

int findByIdClient(Clients* client,int size,int *position)
{
    int ret=-1;
    int i;
    int idCliente;
    if(client!= NULL && size>=0)
    {
    	printClient(client,size);
    	getInt(&idCliente,"\n\nIngrese el ID del cliente: ","\nERROR.",1,100,2);
        for(i=0;i<size;i++)
        {
            if(client[i].isEmpty == FALSE && client[i].idCliente==idCliente)
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

int loadedClient(Clients* client,int size,int clientCount)
{
	int ret=-1;
    int i;

    if(client!= NULL && size > 0)
	{
	for(i=0;i<size;i++)
	{
	  if(client[i].isEmpty == TRUE && clientCount==0)
	  {

		  printf("\nError!!.No hay clientes cargados\n");
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
