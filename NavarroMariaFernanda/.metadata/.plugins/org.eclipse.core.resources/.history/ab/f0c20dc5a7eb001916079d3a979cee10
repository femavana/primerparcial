/*
 * arrayEmployees.h
 *
 *  Created on: sep.2019
 *      Author: Navarro María Fernanda
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "getInput.h"
#define SIZE 1000
#define CANT 51
#define TRUE 0
#define FALSE 1

void menu()
{
	printf("\n");
	printf("\n");
	printf("__________Nomina_Empleados____________");
	printf("\n1-Alta");
	printf("\n2-Modificar");
	printf("\n3-Baja");
	printf("\n4-Informar");
	printf("\n5-Salir");
	printf("\n____________________________________ ");
}
void subMenuInfo()
{
	printf("\n");
	printf("\n");
	printf("_____________________________________");
	printf("\n1-Listar empleados alfabeticamente por apellido y sector");
	printf("\n2-Total y promedio de los salarios");
	printf("\n3-Total empleados que superan el salario promedio");
	printf("\n4-Volver a menu principal");
	printf("\n_________________________________");
}

void subMenuChange()
{
	printf("\n");
	printf("___________________________________");
	printf("\n1-Cambiar nombre");
	printf("\n2-Cambiar apellido");
	printf("\n3-Cambiar sueldo");
	printf("\n4-Cambiar sector");
	printf("\n5-Volver a menu principal");
	printf("\n_________________________________");
}

int initEmployees(Employee* personalData,int size)
{
	int ret=-1;
	int i;
	if(personalData!= NULL && size > 0 )
	{
	 for(i=0;i<size;i++)
	 {
	 personalData[i].isEmpty=TRUE;
	 }
	 ret=0;
	}
return ret;
}

int printEmployees(Employee* personalData,int size)
{
	int ret=-1;
	int i;

	if(personalData!= NULL && size > 0)
	{
		printf("____________________________________________________________________");
		printf("\nID \tApellido \tNombre \tSector \tSueldo\n");
		printf("--------------------------------------------------------------------\n");
	for(i=0;i<size;i++)
    {
	   if(personalData[i].isEmpty == FALSE)
		{
		printf("%d %s %s %d %.2f\n",personalData[i].id,personalData[i].lastName,
		personalData[i].name,personalData[i].sector,personalData[i].salary);
		}
	}
	printf("__________________________________________________________________");
	ret=0;
	}
return ret;
}

int printPositionEmployees(Employee* personalData,int size,int position)
{
	int ret=-1;
	if(personalData!= NULL && size > 0 && personalData[position].isEmpty == FALSE)
{
		printf("\n___________________________________________________________________");
		printf("\n|ID\tApellido\tNombre\tSector\tSueldo\n");
		printf("-----------------------------------------------------------------\n");
		printf("%d %s %s %d %.2f\n",personalData[position].id,personalData[position].lastName,
		personalData[position].name,personalData[position].sector,personalData[position].salary);
		printf("\n_________________________________________________________________");
   ret=0;
}
return ret;
}
int addEmployees(Employee* personalData,int size,int *counterId)
{
	int ret=-1;
    int freePosition;
    float salary;
    int sector;
	char name[CANT];
	char lastName[CANT];

	if(personalData!= NULL && size > 0 )
	{
	   if(searchFreeSpace(personalData,size,&freePosition)==0)
	   {
	    (*counterId)++;
		getStrChar(name,"\nIngrese el nombre del empleado: ","\nError!!.Ingrese solo letras",3,51,2);
		getStrChar(lastName,"Ingrese el apellido: ","\nError!!.Ingrese solo letras",3,51,2);
		getFloat(&salary,"Ingrese el salario del empleado: ","\nError!!.Ingrese solo numeros",1,500000,2);
		getInt(&sector,"Ingrese el sector del empleado:  ","\nError!!.Ingrese solo numeros",1,10000,2);
        personalData[freePosition].id=*counterId;
        personalData[freePosition].salary=salary;
		personalData[freePosition].sector=sector;
		strcpy(personalData[freePosition].name,name);
		strcpy(personalData[freePosition].lastName,lastName);
	    personalData[freePosition].isEmpty=FALSE;
		ret=0;
		printPositionEmployees(personalData,size,freePosition);
	   }
		else
		{
			printf("\nNo hay mas lugar!!!");
		}
    }
return ret;
}

int searchFreeSpace(Employee* personalData,int size,int *freePosition)
{
 int i;
 int ret=-1;

 if(personalData!= NULL && size > 0 )
 {
     for(i=0;i<size;i++)
 		{
 			if(personalData[i].isEmpty==TRUE)
 			{
 				ret=0;
 			    *freePosition=i;
 			}
 		}
 }
return ret;
}

int changeEmployee(Employee* personalData, int size,int counterId)
{
    int ret=-1;
    int position;
    int option;
    float salary;
    int sector;
   	char name[CANT];
   	char lastName[CANT];

	   if(personalData!=NULL && size>0 && loadedEmployee(personalData,size,counterId)==0)
       {
    	    if(findEmployeeById(personalData,size,&position)==0)
    	   {
    	    do{
        	 subMenuChange();
        	 getInt(&option,"\n\nIngrese una opcion:","\n\tERROR!!.Opcion invalida\n",1,5,2);
        	   switch(option)
        	  {
        	  case 1:
        	  printf("\n__Cambiar nombre__");
              getStrChar(name,"\nIngrese el nuevo nombre: ","\nError!!.Ingrese solo letras",3,CANT,2);
              strcpy(personalData[position].name,name);
        	  break;
        	  case 2:
        	  printf("\n__Cambiar apellido__");
        	  getStrChar(lastName,"\nIngrese el nuevo apellido: ","\nError!!.Ingrese solo letras",3,CANT,2);
        	  strcpy(personalData[position].lastName,lastName);
        	  break;
        	  case 3:
        	  printf("\n__Cambiar sueldo__");
        	  getFloat(&salary,"\nIngrese el nuevo salario: ","\nError!!.Ingrese solo numeros",1,500000,2);
        	  personalData[position].salary=salary;
        	  break;
        	  case 4:
        	  printf("\n__Cambiar sector__");
        	  getInt(&sector,"\nIngrese el nuevo sector:  ","\nError!!.Ingrese solo numeros",1,10000,2);
        	  personalData[position].sector=sector;
        	  break;
        	  }
        	   if(option!=5)
        	   {printf("El cambio fue exitoso!!\n");
        	    printPositionEmployees(personalData,size,position);
        	    ret=0;
        	    break;
        	   }
		    }while(option!=5);
  		    }
    	    else
            {
        	printf("No existe el id ingresado!!");
            }
       }
 return ret;
}

int removeEmployee(Employee* personalData, int size,int *counterId)
{
    int ret=-1;
    int position;
    int contadorId=*counterId;

    if(personalData!=NULL && size>0 && loadedEmployee(personalData,size,contadorId)==0)
    {
        if(findEmployeeById(personalData,size,&position)==0)
        {
        	(*counterId)--;
            personalData[position].id=0;
            personalData[position].isEmpty=TRUE;
            personalData[position].salary=0;
            personalData[position].sector=0;
            strcpy(personalData[position].lastName,"");
            strcpy(personalData[position].name,"");
            ret=0;
            printf("La baja fue exitosa!!");
        }
        else
        {
        	printf("No existe el ID ingresado");
        }
    }
 return ret;
}

int findEmployeeById(Employee* personalData,int size,int *position)
{
    int ret=-1;
    int i;
    int idEmployee;

    if(personalData!= NULL && size>=0)
    {
    	printEmployees(personalData,size);
    	getInt(&idEmployee,"\n\nIngrese el ID del empleado: ","\nERROR.",1,size,2);
        for(i=0;i<size;i++)
        {
            if(personalData[i].isEmpty == FALSE && personalData[i].id==idEmployee)
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

int searchEmployeeByName(Employee* personalData,int size,int *position)
{
    int ret=-1;
    int i;
    char nameEmployee[CANT];

    if(personalData!= NULL && size>=0)
    {
    	getStrChar(nameEmployee,"\nIngrese el nombre del empleado: ","\nError!!.Ingrese solo letras",3,CANT,2);
        for(i=0;i<size;i++)
        {
            if(personalData[i].isEmpty==FALSE && strcmp(personalData[i].name,nameEmployee)==0)
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

int reportEmployee(Employee* personalData, int size,int counterId)
{
    int ret=-1;
    int option;
    int average;

       if(personalData!=NULL && size>0 && loadedEmployee(personalData,size,counterId)==0)
       {
    	    do{
    	     subMenuInfo();
        	 getInt(&option,"\n\nIngrese una opcion:","\nERROR!!.Opcion no valida\n",1,4,2);
        	   switch(option)
        	  {
        	   case 1:
        	   printf("__Listar empleados alfabeticamente por Apellido y sector__\n");
        	   sortEmployee(personalData,size);
        	   printEmployees(personalData,size);
        	   break;
        	   case 2:
        	   printf("__Total y promedio de los salarios__\n");
        	   averageSalaryEmployee(personalData,size,counterId,&average);
        	   break;
        	   case 3:
        	   printf("__Total empleados que superan el salario promedio__\n");
        	   sortSalaryEmployee(personalData,size,average);
        	   break;
        	  }
        	  if(option!=4)
        	  {
        	  ret=0;
        	  break;
        	  }
		    }while(option!=4);
       }
 return ret;
}

int sortEmployee(Employee* personalData, int size)
{
	int i;
	int j;
	int ret=-1;
	Employee auxiliar;
	if(personalData!= NULL && size>=0)
    {
       for(i=0;i<size-1;i++)
	   {
    	 if(personalData[i].isEmpty == FALSE)
    	 {
    	   	     continue;
    	 }
	   for(j=i+1;j<size;j++)
	   {
		  if(personalData[j].isEmpty == FALSE)
		  {
		  continue;
		  }
		 if(strcmp(personalData[j].lastName,personalData[i].lastName)>0 && personalData[i].sector > personalData[j].sector)
	    {
			           auxiliar = personalData[j];
					   personalData[j] = personalData[i];
					   personalData[i] = auxiliar;
		}
	     }
	    }
       ret=0;
	   }
return ret;
}

int loadedEmployee(Employee* personalData,int size,int counterId)
{
	int ret=-1;
    int i;
    if(personalData!= NULL && size > 0 )
	{
	for(i=0;i<size;i++)
	{
	  if(personalData[i].isEmpty == TRUE && counterId ==0 )
	  {
		  printf("\nError!!.No hay empleados cargados");
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

int averageSalaryEmployee(Employee* personalData,int size,int counterId,int *average)
{
    int ret=-1;
    int i;
    float totalSalary=0;

    if(personalData!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(personalData[i].isEmpty == FALSE)
            {
            	totalSalary=totalSalary+personalData[i].salary;
            }
        }
     ret=0;
     *average= (int)totalSalary/counterId;
     printf("\nLa suma total de los salarios es: %.2f",totalSalary);
     printf("\nEl salario promedio es: %d",*average);
     }
return ret;
}

int sortSalaryEmployee(Employee* personalData,int size,int average)
{
    int ret=-1;
    int i;
    int totalEmployee=0;


    if(personalData!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(personalData[i].salary > average && personalData[i].isEmpty == FALSE)
            {
            	totalEmployee++;
            	ret=0;
                break;
            }
        }
     printf("\nEl total de empleados que superan el salario promedio es: %d",totalEmployee);
     }
return ret;
}
