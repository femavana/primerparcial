/*
 * getInput.c
 *
 *  Created on:  sep. 2019
 *      Author: Navarro María Fernanda
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int getFloat(float *pResultado,
			 char* mensaje,
			 char* msjError,
			 int minimo,
			 int maximo,
			 int reintentos)
{
    int ret = -1;
	float buffer;
	do
	{
		printf("%s",mensaje);
		__fpurge(stdin);
		scanf("%f",&buffer);
		if(buffer >= minimo && buffer <= maximo)
		{
			*pResultado=buffer;
			ret = 0;
			break;
		}
		else
		{
		printf("\t%s",msjError);
		reintentos--;
		}
	}while(reintentos >= 0);
	return ret;
}

int getInt(	int *pResultado,
			char* mensaje,
			char* mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int ret=-1;
	int buffer;
	do
	{
		printf("%s",mensaje);
		__fpurge(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado=buffer;
			ret=0;
			break;
		}
		else
		{
		printf("%s",mensajeError);
		reintentos--;
		break;
		}
	}while(reintentos >= 0);
	return ret;
}

int getString(char* input,
		      char* message,
			  char* msgError,
			  int   minSize,
			  int   maxSize,
			  int   retries)
{
    int ret=-1;
    char bufferStr[maxSize];
    int size;
     do{
        	printf("%s",message);
        	__fpurge(stdin);
        	fgets(bufferStr,sizeof(bufferStr),stdin);
        	size=strlen(bufferStr)-1;
        	if(size>=minSize && size<maxSize)
        	{    strcpy(input,bufferStr);
        	     ret=0;
        	     break;
        	}
     }while(retries>=0);
    return ret;
}

int getStrChar(char* input,
		      char* message,
		      char* msgError,
		      int minSize,
		      int maxSize,
		      int retries)
{
    int ret=-1;
    char bufferStr[maxSize];

    do{
    if(getString(bufferStr,message,msgError,minSize,maxSize,retries)==0)
            {
                if(onlyText(bufferStr) == 0)
                {
                    strcpy(input,bufferStr);
                    ret=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    retries--;
                }
            }
        }while(retries>=0);
  return ret;
}

//validations

int onlyText(char* aux)
{
int ret=0;
int i;

for(i=0;i<'\0';i++)
{
if((aux[i] != ' ') && (aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z'))
{
	ret=-1;
}
}
return ret;
}



int onlyNumbersStr(char* aux)
{
int ret=0;
int i=0;
for(i=0;i<'\0';i++)
{
if(aux[i]<'0'|| aux[i] > '9')
{
	ret=-1;
}
}
return ret;
}
