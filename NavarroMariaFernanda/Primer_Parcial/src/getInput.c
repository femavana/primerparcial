
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
    int size;
    char bufferStr[maxSize];
     do{
        	printf("%s",message);
        	__fpurge(stdin);
        	scanf("%[^\n]s", bufferStr);
        	size=strlen(bufferStr);
        	if(size>=minSize && size<maxSize)
        	{    strncpy(input,bufferStr,maxSize);
        	     ret=0;
        	     break;
        	}
     }while(retries>=0);
    return ret;
}

