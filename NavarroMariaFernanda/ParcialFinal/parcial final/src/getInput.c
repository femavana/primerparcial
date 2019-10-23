#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "getInput.h"


int getFloat(float *input,
			 char* message,
			 char* msgError,
			 int minSize,
			 int maxSize,
			 int retries)
{
    int ret = -1;
	float buffer;
	do
	{
		printf("%s",message);
		//__fpurge(stdin);
		fflush(stdin);
		scanf("%f",&buffer);
		if(buffer >= minSize && buffer <= maxSize)
		{
			*input=buffer;
			ret = 0;
			break;
		}
		   else
		  {
		   printf("\t%s",msgError);
		   retries--;
		 }
	}while(retries >= 0);
return ret;
}

int getInt(	int *input,
			char* message,
			char* msgError,
			int minSize,
			int maxSize,
			int retries)
{
	int ret=-1;
	int buffer;
	do
	{
		printf("%s",message);
		//__fpurge(stdin);
		fflush(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minSize && buffer <= maxSize)
		{
			*input=buffer;
			ret=0;
			break;
		}
		else
		{
		printf("\t%s",msgError);
		retries--;
		}
	}while(retries >= 0);
	return ret;
}

int getSeguir(char *input,
		      char* message,
		      char* msgError,
		      int minSize,
		      int maxSize,
		      int retries)
{
	 int ret = -1;
	 char buffer;
		do
		{
			printf("%s",message);
			//__fpurge(stdin);
			fflush(stdin);
			scanf("%c",&buffer);

	     	if(buffer == minSize ||buffer == maxSize)
			 {
				*input=buffer;
				ret = 0;
				break;
			 }
			else
			{
			printf("\t%s",msgError);
			retries--;
			break;
			}
		}while(retries >= 0);
return ret;
}

int getLetter(char *input,
		      char* message,
		      char* msgError,
		      int retries)
{
	 int ret = -1;
	 char buffer;
		do
		{
			printf("%s",message);
			//__fpurge(stdin);
			fflush(stdin);
			scanf("%c",&buffer);

	     	if((buffer<'A' ||buffer>'Z') && (buffer<'a' || buffer>'z'))
			 {
	     		printf("\t%s",msgError);
	     		retries--;
	     		break;
			 }
			else
			{
			    *input=buffer;
				ret = 0;
				break;
			}
		}while(retries >= 0);
return ret;
}


int getString(char* input,
		      char* message,
			  char* msgError,
			  int   minSize,
			  int   maxSize,
			  int* retries)
{
    int ret=-1;
    char bufferStr[maxSize];
      do{
        	printf("%s",message);
        	//__fpurge(stdin);
        	fflush(stdin);
        	fgets(bufferStr,sizeof(bufferStr),stdin);
        	bufferStr[strlen(bufferStr)-1]='\0';
            if(strlen(bufferStr)>=minSize && strlen(bufferStr)<maxSize)
            {
                strncpy(input,bufferStr,maxSize);
                ret=0;
                break;
            }
            printf("%s 1",msgError);
            (*retries)--;
        }while((*retries)>=0);
    return ret;
}

int getName(char* input,
		      char* message,
			  char* msgError,
			  int   minSize,
			  int   maxSize,
			  int   retries)
{
    int ret=-1;
    char bufferStr[maxSize];

    	 if(message!=NULL && msgError!=NULL && minSize<=maxSize && retries>=0 && input!=NULL)
    	  {
    	  do{
    	     if(!getString(bufferStr,message,msgError,minSize,maxSize,&retries))
    	      {
    	              if(isValidStrChar(bufferStr)==1)
    	                {
    	                    strncpy(input,bufferStr,maxSize);
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
           }
    return ret;
}

int getCUIT(char* input,
		      char* message,
			  char* msgError,
			  int   minSize,
			  int   maxSize,
			  int   retries)
{
    int ret=-1;
    char bufferStr[maxSize];

    	 if(message!=NULL && msgError!=NULL && minSize<=maxSize && retries>=0 && input!=NULL)
    	  {
    	  do{
    	     if(!getString(bufferStr,message,msgError,minSize,maxSize,&retries))
    	      {
    	              if(isValidCUIT(bufferStr)==1)
    	                {
    	            	    strncpy(input,bufferStr,maxSize);
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
           }
    return ret;
}

int getAlfanumerico(char* input,
		      char* message,
			  char* msgError,
			  int   minSize,
			  int   maxSize,
			  int   retries)
{
    int ret=-1;
    char bufferStr[maxSize];

    	 if(message!=NULL && msgError!=NULL && minSize<=maxSize && retries>=0 && input!=NULL)
    	  {
    		do{
    	     if(!getString(bufferStr,message,msgError,minSize,maxSize,&retries))
    	      {
    	              if(isValidAlphanumeric(bufferStr)==1)
    	                {
    	                    strncpy(input,bufferStr,maxSize);
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
           }
    return ret;
}

int getTexto(char* input,
	      char* message,
		  char* msgError,
		  int   minSize,
		  int   maxSize,
		  int   retries)
{
    int ret=-1;
    char bufferStr[maxSize];

       	 if(message!=NULL && msgError!=NULL && minSize<=maxSize && retries>=0 && input!=NULL)
       	  {
       	  do{
       	     if(!getString(bufferStr,message,msgError,minSize,maxSize,&retries))
       	      {
                if(isValidTexto(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    ret=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    retries--;
                }
            }
        } while(retries>=0);
    }
    return ret;
}

//Validaciones

int isValidStrChar(char* auxiliar)
{
    int ret=1;
    int i;
    for(i=0;auxiliar[i]!='\0';i++)
    {
        if((auxiliar[i] != ' ')&&(auxiliar[i]<'A' || auxiliar[i]>'Z') && (auxiliar[i]<'a' || auxiliar[i]>'z'))
        {
        	ret=0;
            break;
        }
    }
 return ret;
}

int isValidCUIT(char* auxiliar)
{
    int ret=1;
    int i;
    for(i=0;auxiliar[i]!='\0';i++)
    {
    	 if((auxiliar[i] != '-') && (auxiliar[i] != '-') && (auxiliar[i] < '0' || auxiliar[i] > '9'))
        {
            ret=0;
            break;
        }
    }
 return ret;
}

int isValidAlphanumeric(char* auxiliar)
{
    int ret=1;
    int i;
    for(i=0;auxiliar[i]!='\0';i++)
    {
    	if((auxiliar[i] != ' ') && (auxiliar[i] < 'a' || auxiliar[i] > 'z') && (auxiliar[i] < 'A' || auxiliar[i] > 'Z') && (auxiliar[i] < '0' || auxiliar[i] > '9'))
        {
            ret=0;
            break;
        }
    }
    return ret;
}

int isValidTexto(char* auxiliar)
{
    int ret=1;
    int i;
    for(i=0;auxiliar[i]!='\0';i++)
    {
        if(auxiliar[i]<' ' || auxiliar[i]>'z')
        {
            ret=0;
            break;
        }
    }
return ret;
}

//system
void clearScreen(void)
{
    system("clear");
    //system("CLS");
}
