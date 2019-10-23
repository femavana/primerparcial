#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "pedidos.h"
#include "informes.h"
#include "getInput.h"
#define CANT_CLIENTES 100
#define CANT_PEDIDOS 1000
#define TRUE 0
#define FALSE 1
#define ESTADO_PENDIENTE 1
#define ESTADO_COMPLETADO  0


int listClients(Pedidos* pedido,Clients* client,int cant,int size)
{
    int ret=-1;
    int i;//client
    int j;//pedido
    int pedido_pendiente=0;
    int acumPedidos[7];


   if(client!= NULL && cant > 0 && pedido!= NULL && size > 0)
   {
    for(i=0;i<cant;i++)
     {
     if(client[i].isEmpty==FALSE)
     {
          for(j=0;j<size;j++)
           {
        	if(pedido[j].isEmpty==FALSE && client[i].idCliente == pedido[j].idCliente)
        	{
               if(pedido[j].estado == ESTADO_PENDIENTE)
        	  {
            	  pedido_pendiente++;
  	        }
           }
           }
          acumPedidos[i]=pedido_pendiente;
          pedido_pendiente=0;
       }
       ret=0;
       }
   }

    if(client!= NULL && cant > 0)
       {
    	 printf("\n______CLIENTES______________________________________________________");
    for(i=0;i<cant;i++)
     {
    if(client[i].isEmpty==FALSE)
    {
     printf("\nidClient:%d \nCUIT:%s \nNombre_Empresa:%s \nDireccion:%s \nLocalidad:%s"
     "\nPedidos_recoleccion_pendientes:%d\n",
      client[i].idCliente,client[i].cuit,client[i].nombreEmpresa,
       client[i].direccion,client[i].localidad,acumPedidos[i]);
       printf("____________________________________________________________________\n");
         }
        ret=0;
        }
       }

 return ret;
}

int orderListPending(Pedidos* pedido,Clients* client,int cant,int size)
{
	int ret=-1;
	int i;//client
	int j;//pedido


	   if(client!= NULL && size > 0 && pedido!= NULL && size > 0)
	   {
	    for(i=0;i<cant;i++)
	     {
	     if(client[i].isEmpty==FALSE)
	     {
	          for(j=0;j<size;j++)
	           {
	        	  if(pedido[j].isEmpty==FALSE && pedido[j].idCliente == client[i].idCliente)
	        	  {
	              if(pedido[j].estado==ESTADO_PENDIENTE)
	              {
		       printf("\nIdPedido:%d \nNombre_Empresa:%s \nCUIT:%s \nDireccion:%s \nCantidad_a_recolectar:%.2f kg\n",
		    	pedido[j].idPedido,client[i].nombreEmpresa,client[i].cuit,client[i].direccion,pedido[j].cantRecoleccion);
		       printf("____________________________________________________________________\n");
	              }
	              }
	            }
	     }
	    }
	  ret=0;
	  }
return ret;
}

int orderListProcessed(Pedidos* pedido,Clients* client,int cant,int size)
{
	int ret=-1;
		int i;//client
		int j;//pedido


		   if(client!= NULL && size > 0 && pedido!= NULL && size > 0)
		   {
		    for(i=0;i<cant;i++)
		     {
		     if(client[i].isEmpty==FALSE)
		     {
		          for(j=0;j<size;j++)
		           {
		        	  if(pedido[j].isEmpty==FALSE && pedido[j].idCliente == client[i].idCliente)
		        	  {
		              if(pedido[j].estado==ESTADO_COMPLETADO)
		              {
			          printf("\nIdPedido:%d \nNombre_Empresa:%s \nCUIT:%s \nDireccion:%s"
			    		"\nCantidad_de_reciclado_por_tipo_de_plastico:"
	            		"\nHDPE:%.2f kg"
	            		"\nLDPE:%.2f kg"
	            		"\nPP:%.2f kg\n",
						pedido[j].idPedido,client[i].nombreEmpresa,client[i].cuit,client[i].direccion,pedido[j].HDPE,pedido[j].LDPE,pedido[j].PP);
			       printf("____________________________________________________________________\n");
		              }
		              }
		            }
		     }
		    }
		  ret=0;
		  }
return ret;
}

void subMenuInformes()
{
	printf("\n");
	printf("__________INFORMES____________");
	printf("\na-Cliente_con_mas_pedidos_pendientes");
	printf("\nb-Cliente_con_mas_pedidos_completados");
	printf("\nc-Cliente_con_mas_pedidos");
	printf("\nd-Cliente_que_reciclo_mas_kilos");
	printf("\ne-Cliente_que_reciclo_menos_kilos");
	printf("\nf-Cantidad_clientes_que_reciclaron_mas_de_1000kilos");
	printf("\ng-Cantidad_clientes_que_reciclaron_menos_de_100kilos");
	printf("\nh-Pedidos_completados_");
	printf("\ni-Cantidad_pedidos_pendientes_por_localidad");
	printf("\nj-Cantidad_kilos_de_polipropileno_reciclado_promedio_por_cliente");
	printf("\nk-Cantidad_kilos_totales_reciclados_de_cliente_por_tipo_de_plastico");
	printf("\nl-Volver a menu principal");
	printf("\n____________________________________ ");
}

int cargaInformes(Pedidos* pedido,Clients* client,int cant,int size)
{
    int ret=-1;
    char option;

           if(client!=NULL && size>0 && pedido!=NULL)
    	   {
		    do{
		     subMenuInformes();
        	 getLetter(&option,"\n\nIngrese una opcion:","\n\tERROR!!.Opcion invalida\n",2);
        	   switch(option)
        	  {
        	  case 'a':
        	  printf("\n__Cliente_con_mas_pedidos_pendientes__");
        	  clientsMostOrdersPending(pedido,client,CANT_CLIENTES,CANT_PEDIDOS);
        	  break;
        	  case 'b':
        	  printf("\n__Cliente_con_mas_pedidos_completados__");
        	  clientsMostOrdersProcesed(pedido,client,CANT_CLIENTES,CANT_PEDIDOS);
        	  break;
        	  case 'c':
        	   printf("\n__Cliente_con_mas_pedidos__");
        	   clientsMostOrders(pedido,client,CANT_CLIENTES,CANT_PEDIDOS);
        	    break;
        	  case 'd':
        	     printf("\n__Cliente_que_reciclo_mas_kilos__");
        	     clientsMostRecicled(pedido,client,CANT_CLIENTES,CANT_PEDIDOS);
        	     break;
        	  case 'e':
        	     printf("\n__Cliente_que_reciclo_menos_kilos__");
        	     clientsLessRecicled(pedido,client,CANT_CLIENTES,CANT_PEDIDOS);
        	     break;
        	  case 'f':
        	      printf("\n__Cantidad_clientes_que_reciclaron_mas_de_1000kilos__");
        	     kilosRecicladosMayorA(pedido,client,CANT_CLIENTES,CANT_PEDIDOS);
        	      break;
        	  case 'g':
        	       printf("\n__Cantidad_clientes_que_reciclaron_menos_de_100kilos__");
        	       kilosRecicladosMenorA(pedido,client,CANT_CLIENTES,CANT_PEDIDOS);
        	       break;
        	  case 'h':
        	        printf("\n__Pedidos_completados__");
        	        // orderProcessedListByCriteria(pedido,client,CANT_CLIENTES,CANT_PEDIDOS);
        	          break;
        	  case 'i':
        	         printf("\n__Cantidad_pedidos_pendientes_por_localidad__");
        	         listPendingByLocation(pedido,client,CANT_CLIENTES,CANT_PEDIDOS);
        	         break;
        	  case 'j':
        	         printf("\n__Cantidad_kilos_de_polipropileno_reciclado_promedio_por_cliente__");
        	         break;
        	  case 'k':
        	         printf("\n__Cantidad_kilos_totales_reciclados_de_cliente_por_tipo_de_plastico");

        	         break;
        	  }
		    }while(option !='l');
       }
 return ret;
}

int kilosRecicladosMayorA(Pedidos* pedido,Clients* client,int cant, int size)
{
    int ret=-1;
    int i;//client
    int j;//pedido
    int cantClientes=0;

   if(client!= NULL && cant > 0 && pedido!= NULL && size > 0)
   {
    for(i=0;i<cant;i++)
     {
     if(client[i].isEmpty==FALSE)
     {
          for(j=0;j<size;j++)
           {
        	  if(pedido[j].isEmpty==FALSE && pedido[j].idCliente == client[i].idCliente)
        	  {
              if(pedido[j].estado==ESTADO_COMPLETADO)
              {
            	 if((pedido[j].HDPE + pedido[j].LDPE + pedido[j].PP) > 1000)
            	 {
            		 cantClientes++;
            	 }
               }
              }
            }
  	  }
  	 }
  	ret=0;
     }

   printf("\nClientes con mas de 1000 kilos reciclados: \n"
		   "%d clientes\n",cantClientes);

  return ret;
}

int kilosRecicladosMenorA(Pedidos* pedido,Clients* client,int cant, int size)
{
    int ret=-1;
    int i;//client
    int j;//pedido
    int cantClientes=0;
    char nombre[51];

   if(client!= NULL && cant > 0 && pedido!= NULL && size > 0)
   {
    for(i=0;i<cant;i++)
     {
     if(client[i].isEmpty==FALSE)
     {
          for(j=0;j<size;j++)
           {
        	  if(pedido[j].isEmpty==FALSE && pedido[j].idCliente == client[i].idCliente)
        	  {
              if(pedido[j].estado==ESTADO_COMPLETADO)
              {
            	 if((pedido[j].HDPE + pedido[j].LDPE + pedido[j].PP) < 100)
            	 {
            		 cantClientes++;
            		 strcpy(nombre,client[i].nombreEmpresa);
            	 }
               }
              }
            }
  	  }
  	 }
  	ret=0;
     }

   printf("\nClientes con menos de 100 kilos reciclados:\n"
		   " %d cliente,%s\n",cantClientes,nombre);

  return ret;
}

int listPendingByLocation(Pedidos* pedido,Clients* client,int cant,int size)
{
	int ret=-1;
	int i;//client
	int j;//pedido
	int pedidoPendiente=0;
    char localidad[51];

	   if(client!= NULL && cant > 0 && pedido!= NULL && size > 0)
	   {
		   getName(localidad,"\nIngrese localidad de la empresa: ","Error.!!.\n",2,51,2);
	    for(i=0;i<cant;i++)
	     {
	     if(client[i].isEmpty==FALSE && strcmp(localidad,client[i].localidad)==0)
	     {
	        for(j=0;j<size;j++)
	         {
	         if(pedido[j].isEmpty==FALSE && pedido[j].idCliente == client[i].idCliente)
	        	  {
	              if(pedido[j].estado==ESTADO_PENDIENTE)
	              {
	            	  pedidoPendiente++;

	            	 }
	               }
	              }
	        ret=0;
	     }
	      }
	   }

	    if(ret==0)
	    {
      	 printf("La localidad %s tiene %d pedidos pendientes\n",localidad,pedidoPendiente);
		 }
	    else
	    {
	     printf("La localidad no existe. Ingrese solo mayusculas\n");
	    }


return ret;
}

int clientsMostOrders(Pedidos* pedido,Clients* client,int cant, int size)
{
    int ret=-1;
    int i;//client
    int j;//pedido
    int  pedidos=0;
    int maximo=1;
    int maximoCliente[7];

   if(client!= NULL && cant > 0 && pedido!= NULL && size > 0)
   {
    for(i=0;i<cant;i++)
     {
     if(client[i].isEmpty==FALSE)
     {
          for(j=0;j<size;j++)
           {
        	  if(pedido[j].isEmpty==FALSE && pedido[j].idCliente == client[i].idCliente)
        	  {
            	  pedidos++;
              }
           }
          maximoCliente[i]=pedidos;
          pedidos=0;
     }
     }

   }


   if(client!= NULL && cant)
   {
    for(i=0;i<7;i++)
     {
     if(client[i].isEmpty==FALSE && maximoCliente[i] > maximo)
     {
      maximo=maximoCliente[i];
      printf("\nEl cliente con mas pedidos es: %s con %d pedidos\n",
       client[i].nombreEmpresa,maximo);
      }
     }
    ret=0;
   }

  return ret;
}

int clientsMostOrdersPending(Pedidos* pedido,Clients* client,int cant, int size)
{
	  int ret=-1;
	    int i;//client
	    int j;//pedido
	    int  pedidosPendientes=0;
	    int maximo=1;
	    int maximoCliente[7];


	   if(client!= NULL && cant > 0 && pedido!= NULL && size > 0)
	   {
	    for(i=0;i<cant;i++)
	     {

	     if(client[i].isEmpty==FALSE)
	     {
	          for(j=0;j<size;j++)
	           {
	        	  if(pedido[j].isEmpty==FALSE && pedido[j].idCliente == client[i].idCliente)
	        	  {
	        	    if(pedido[j].estado==ESTADO_PENDIENTE)
	        		{
	        	    	pedidosPendientes++;
	              }
	        	  }
	           }
	          maximoCliente[i]=pedidosPendientes;
	          pedidosPendientes=0;
	     }

	     }
	   }

	   if(client!= NULL && cant)
	      {
	       for(i=0;i<7;i++)
	        {
	        if(client[i].isEmpty==FALSE && maximoCliente[i] > maximo)
	        {
	         maximo=maximoCliente[i];
	         printf("\nEl cliente con mas pedidos pendientes es:\n %s con %d pedidos pendientes\n",
	          client[i].nombreEmpresa,maximo);
	         }
	        }
	       ret=0;
	      }
return ret;
}

int clientsMostOrdersProcesed(Pedidos* pedido,Clients* client,int cant, int size)
{
    int ret=-1;
    int i;//client
    int j;//pedido
    int  pedidosCompletados=0;
    int maximo=1;
    int maximoCliente[7];


   if(client!= NULL && cant > 0 && pedido!= NULL && size > 0)
   {
    for(i=0;i<cant;i++)
     {
     if(client[i].isEmpty==FALSE)
     {
          for(j=0;j<size;j++)
           {
        	  if(pedido[j].isEmpty==FALSE && pedido[j].idCliente == client[i].idCliente)
        	  {
        	    if(pedido[j].estado==ESTADO_COMPLETADO)
        		{
        	    	pedidosCompletados++;
              }
        	  }
           }
         maximoCliente[i]=pedidosCompletados;
        pedidosCompletados=0;
     }
     }
   }

   if(client!= NULL && cant)
   	      {
   	       for(i=0;i<7;i++)
   	        {
   	        if(client[i].isEmpty==FALSE && maximoCliente[i] > maximo)
   	        {
   	         maximo=maximoCliente[i];
   	         printf("\nEl cliente con mas pedidos completados es:\n %s con %d pedidos completados\n",
   	          client[i].nombreEmpresa,maximo);
   	         }
   	        }
   	       ret=0;
   	      }

 return ret;
}

int clientsMostRecicled(Pedidos* pedido,Clients* client,int cant, int size)
{
    int ret=-1;
    int i;//client
    int j;//pedido
    int maximo=1;
    int cantReciclado;
    char nombre[51];

    if(client!= NULL && cant > 0 && pedido!= NULL && size > 0)
       {
        for(i=0;i<cant;i++)
         {
         if(client[i].isEmpty==FALSE)
         {
              for(j=0;j<size;j++)
               {
            	  if(pedido[j].isEmpty==FALSE && pedido[j].idCliente == client[i].idCliente)
            	  {
                  if(pedido[j].estado==ESTADO_COMPLETADO)
                  {
                	  cantReciclado=(pedido[j].HDPE + pedido[j].LDPE + pedido[j].PP);
                	    if(cantReciclado > maximo)
                	    {
                	     maximo=cantReciclado;
                	     strcpy(nombre,client[i].nombreEmpresa);
                	    }
                  }
                  }
                }
      	  }
      	 }
        ret=0;
         }

       printf("\nEl cliente con mas kilos reciclados es:\n %s con %d kilos reciclados\n",
       nombre,maximo);

  return ret;
}

int clientsLessRecicled(Pedidos* pedido,Clients* client,int cant, int size)
{
	 int ret=-1;
	    int i;//client
	    int j;//pedido
	    int minimo=50;
	    int cantReciclado;
	    char nombre[51];

	    if(client!= NULL && cant > 0 && pedido!= NULL && size > 0)
	       {
	        for(i=0;i<cant;i++)
	         {
	         if(client[i].isEmpty==FALSE)
	         {
	              for(j=0;j<size;j++)
	               {
	            	  if(pedido[j].isEmpty==FALSE && pedido[j].idCliente == client[i].idCliente)
	            	  {
	                  if(pedido[j].estado==ESTADO_COMPLETADO)
	                  {
	                	cantReciclado=(pedido[j].HDPE + pedido[j].LDPE + pedido[j].PP);
	                	if(cantReciclado < minimo)
	                	 {
	                	   minimo=cantReciclado;
	                	   strcpy(nombre,client[i].nombreEmpresa);
	                	  }
	                  }
	                  }
	                }
	      	  }
	      	 }
	        ret=0;
	         }

	       printf("\nEl cliente con menos kilos reciclados es:"
	       "\n %s con %d kilos reciclados\n",
	       nombre,minimo);

	  return ret;
	}

/**
int kilosRecicladoByTipoPlastico(Pedidos* pedido,Clients* client,int cant,int size)
{
	int ret=-1;
	int i;//client
	int j;//pedido
    char localidad[51];
    char cuit[51];
    char tipo[51];

	   if(client!= NULL && cant > 0 && pedido!= NULL && size > 0)
	   {
	    getCUIT(cuit,"Ingrese el CUIT de la empresa: ","Error!!.Ingrese ej:00-00000000-0 \n",10,14,2);
	    for(i=0;i<cant;i++)
	     {
	     if(client[i].isEmpty==FALSE && strcmp(cuit,client[i].cuit)==0)
	     {
	        for(j=0;j<size;j++)
	         {
	         getName(tipo,"\nIngrese un tipo de plastico (HDPE ||LDPE||PP): ","Error!!.\n",2,4,2);
	         if(pedido[j].isEmpty==FALSE && pedido[j].idCliente == client[i].idCliente)
	        	  {
	              if(strcmp(tipo,pedido[i].HDPE)==0)
	              {
	            	  pedidoPendiente++;

	            	 }
	               }
	              }
	        ret=0;
	     }
	      }
	   }

	    if(ret==0)
	    {
      	 printf("La localidad %s tiene %d pedidos pendientes\n",localidad,pedidoPendiente);
		 }
	    else
	    {
	     printf("La localidad no existe. Ingrese solo mayusculas\n");
	    }
int kilosRecicladoByTipoPlastico(Pedidos* pedido,Clients* client,int cant,int size)
{
	int ret=-1;
	int i;//client
	int j;//pedido
    char localidad[51];
    char cuit[51];
    char tipo[51];

	   if(client!= NULL && cant > 0 && pedido!= NULL && size > 0)
	   {
	    getCUIT(cuit,"Ingrese el CUIT de la empresa: ","Error!!.Ingrese ej:00-00000000-0 \n",10,14,2);
	    for(i=0;i<cant;i++)
	     {
	     if(client[i].isEmpty==FALSE && strcmp(cuit,client[i].cuit)==0)
	     {
	        for(j=0;j<size;j++)
	         {
	         getName(tipo,"\nIngrese un tipo de plastico (HDPE ||LDPE||PP): ","Error!!.\n",2,4,2);
	         if(pedido[j].isEmpty==FALSE && pedido[j].idCliente == client[i].idCliente)
	        	  {
	              if(strcmp(tipo,pedido[i].HDPE)==0)
	              {
	            	  pedidoPendiente++;

	            	 }
	               }
	              }
	        ret=0;
	     }
	      }
	   }

	    if(ret==0)
	    {
      	 printf("La localidad %s tiene %d pedidos pendientes\n",localidad,pedidoPendiente);
		 }
	    else
	    {
	     printf("La localidad no existe. Ingrese solo mayusculas\n");
	    }


return ret;
}


return ret;
}

int orderProcessedListByCriteria(Pedidos* pedido,Clients* client,int cant,int size)
{
	    int ret=-1;
		int i=0;//client
		int j=0;//pedido
        int porcentaje=0;
        int cantReciclado;
        int recicladoCliente[7];

		   if(client!= NULL && cant > 0 && pedido!= NULL && size > 0)
		   {
		    for(i=0;i<cant;i++)
		     {
		     if(client[i].isEmpty==FALSE)
		     {
		          for(j=0;j<size;j++)
		           {
		        	  if(pedido[j].isEmpty==FALSE && pedido[j].idCliente == client[i].idCliente)
		        	  {
		              if(pedido[j].estado==ESTADO_COMPLETADO)
		              {
		            	cantReciclado=(pedido[j].HDPE + pedido[j].LDPE + pedido[j].PP);
		              }
		              }
		            }
		      recicladoCliente[i]=cantReciclado;
		      cantReciclado=0;
		     }
		    }
		  }

		   	if(client!= NULL && cant )
		   {
		   	for(i=0;i<7;i++)
		   	{
		   	porcentaje=(recicladoCliente[i]/cant);
		   	ret=0;
		   	}
		   }

	    if(client!= NULL && cant )
	    {
		 for(i=0;i<cant;i++)
		 {
		 if(client[i].isEmpty==FALSE)
		 {
		for(j=0;j<size;j++)
		{
		if(pedido[j].isEmpty==FALSE && pedido[j].idCliente == client[i].idCliente)
		{
		if(pedido[j].estado==ESTADO_COMPLETADO)
		{
		 printf("\nIdPedido%d \nNombre_Empresa:%s \nCUIT:%s \nPlastico_reciclado: %d %c",
		 pedido[j].idPedido,client[i].nombreEmpresa,client[i].cuit,porcentaje,37);
		 printf("____________________________________________________________________\n");
		   }
		  }
		}
		}
	    }
		}

return ret;
}
*/
