
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/*
a)	getInt
b)	getFloat
c)	getChar	    0)isNumeric   1)isDecimal   2)isLetter    3)isAlphaNumeric   4)isOnlyNumber     5)isTelephone      6)isDni    7)isCuitCuil

auxReturn = functionX(&capSpace, "msg", "msgFail", min, max, try, mode);
*/

int getInt(int *pResult ,char *pMsg,char *pMsgFail,int min,int max, int try){
	int auxReturn = -1;
	int buffer, j, length;
	char input[50];

	if(pResult!= NULL || (max>min) || try>0 )
	{
		printf("%s",pMsg);
		for(j=0;j<try;j++)
		{
			fgets(input, sizeof(input), stdin);
			length=strlen(input);
			auxReturn = isNumeric(input, length);
            if(auxReturn == 0)
            {
                buffer = atoi(input);

                if(buffer >= min && buffer <= max)
                {
                    *pResult = buffer;
                    break;
                }
            }
            else
            {
                printf("%s",pMsgFail);
                printf("\n%s",pMsg);
                auxReturn = -1;
            }
        }
        if(auxReturn!=0)
        {
            printf("Sin Reintentos.");
        }
    }
	return auxReturn;
}
/////////////////////////////////////////////////////////////////////////////////////
int getFloat(float *pResult, char *pMsg, char *pMsgFail, int min, int max, int try){
	int auxReturn = 0;
	float buffer;
	int j, length;
	char input[50];

	if(pResult!= NULL || (max>min) || try>0 )
	{
		printf("%s",pMsg);
		for(j=0;j<try;j++)
		{
			fgets(input, sizeof(input), stdin);
			length=strlen(input);
            auxReturn = isDecimal(input, length);
            if(auxReturn == 0)
            {
                buffer = atof(input);

                if(buffer >= min && buffer <= max)
                {
                    *pResult = buffer;
                    break;
                }
            }
            else
            {
                printf("%s",pMsgFail);
                printf("\n%s",pMsg);
            }
        }
        if(auxReturn!=0)
        {
            printf("Sin Reintentos.");
        }
    }
	return auxReturn;
}
//////////////////////////////////////////////////////////////////////////////////
int getInput(char *pResult, char *pMsg, char *pMsgFail, int min, int max, int try, int mode){
    int auxReturn = -1;
	char buffer=0;
	int j, length;
	char input[50];

	if(pResult!= NULL && (max>min) && try>0 )
	{
		for(j=0;j<try;j++)
		{
            printf("%s", pMsg);
            fgets (input, sizeof(input), stdin);
           	length=strlen(input);

			switch (mode)
			{
			    case 0:
                auxReturn = isNumeric(input, length);
                break;
			    case 1:
                auxReturn = isDecimal(input, length);
                break;
                case 2:
                auxReturn = isLetter(input, length);
                break;
                case 3:
                auxReturn = isAlphaNumeric(input, length);
                break;
                case 4:
                auxReturn = isOnlyNumber(input, length);
                break;
                case 5:
                auxReturn = isTelephone(input, length);
                break;
                case 6:
                auxReturn = isDni(input, length);
                break;
                case 7:
                auxReturn = isCuitCuil(input, length);
                break;
                case 8:
                printf("Empty request");
                break;
                case 9:
                printf("Empty request");
                break;
                default:
                printf("invalid request");
                break;
            }
            /*printf("\nmode: %d", mode);
            printf("\nmin: %d", min);
            printf("\nmax: %d", max);
            printf("\nj: %d", j);
            printf("\ntry: %d", try);*/

            if(auxReturn == 0)
            {
                buffer = atof(input);
                if(mode == 0 || mode == 1 || mode == 4)
                {
                    if(buffer>min && buffer<max)
                    {
                        strcpy(pResult, input);
                        //printf("dentro de max y min");
                        break;
                    }
                    else
                    {
                        //printf("fuera de max y min");
                        printf("%s. ", pMsgFail);
                        auxReturn=-1;
                    }
                }
                else
                {
                    strcpy(pResult, input);
                    //printf("valida sin max y min");
                    break;
                }
            }
            else
            {
                printf("%s. ", pMsgFail);
                auxReturn=-1;
            }
		}
		if(auxReturn!=0)
            printf(" Sin reintentos. \n\n");
    }
	return auxReturn;
}
/////////////////////////////////////////(0)
int isNumeric(char aux[], int len){
    int i, auxReturn=0;

    for(i=0;i<len-1;i++)
    {
        if((aux[i] < '0' || aux[i] > '9') && aux[i] != '-') //filtro numerico
        {
			auxReturn = -1;
            break;
		}
		if(aux[i]=='-'&& i!=0) // filtro p/negativos
		{
			auxReturn = -1;
			break;
		}
    }
    return auxReturn;
}
/////////////////////////////////////////(1)
int isDecimal(char aux[], int len){
    int i, auxReturn=0;

    for(i=0;i<len-1;i++)
    {
        if((aux[i] < '0' || aux[i] > '9' )&& aux[i]!= ',' && aux[i]!= '.' && aux[i]!= '-')
		{
            auxReturn = -1;
            break;
        }
		if(aux[i]=='-'&& i!=0) // filtro p/negativos
		{
			auxReturn = -1;
			break;
		}
		if(aux[i]==',')
        {
            aux[i]='.';
        }
        if(aux[i]==' ' && aux[i+1]!= '\0')
        {
            aux[i]='\0';
        }
    }
    return auxReturn;
}
/////////////////////////////////////////(2)
int isLetter(char aux[], int len){
 	int i, auxReturn=0;

	for(i=0;i<len-1;i++)
   	//while(aux[i] != '\0' || aux[i] != '\n')
   	{
		if((aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z')) //filtro letras
		{
			if(aux[i] != ' ') //excepciones
			{
				auxReturn = -1;
       			break;
			//i++;
			}
   		}
	}
   return auxReturn;
}
/////////////////////////////////////////(3)
int isAlphaNumeric(char aux[], int len){
  	int i, auxReturn=0;

	for(i=0;i<len-1;i++)
   	//while(aux[i] != '\0' || aux[i] != '\n')
	{
	   	if((aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z')) //filtro letras
		{
            if(aux[i] < '0' || aux[i] > '9') //filtro numerico
            {
                if((aux[i] != ' ') && (aux[i] != ',') && (aux[i] != '.')) //excepciones
                {
                    auxReturn = -1;
                    //i++;
                }
            }
		}
		break;
	}
   return auxReturn;
}
/////////////////////////////////////////(4)
int isOnlyNumber(char aux[], int len){
    int i, auxReturn=0;

    for(i=0;i<len-1;i++)
    {
        if(aux[i] < '0' || aux[i] > '9') //filtro numerico
        {
			auxReturn = -1;
            break;
		}
    }
    return auxReturn;
}
/////////////////////////////////////////(5)
int isTelephone(char aux[], int len){
   	int i, auxReturn=0;
 	int symbolCounter=0;

	for(i=0;i<len-1;i++)
   	{
		if((aux[i] < '0' || aux[i] > '9') && (aux[i] != ' '|| aux[i] != '-' || aux[i] != '+'))
		{
			auxReturn=-1;
			break;//i++;
		}
		if(symbolCounter >2)
		{
			if(aux[i] == '-' && i!=0)
			{
				symbolCounter ++;
			}
			if(aux[0] == '+')
			{
				symbolCounter ++;
			}
			auxReturn = -1;
		}
    }
    return auxReturn;
}
/////////////////////////////////////////(6)
int isDni(char aux[], int len){
    int i, auxReturn=0;

    if(len >=7 || len <=8)
    {
        for(i=0;i<len-1;i++)
        {
            if(aux[i] < '0' || aux[i] > '9')
            {
                auxReturn=-1;
                break;//i++;
            }
        }
    }
    else
    {
        auxReturn=-1;
    }
    return auxReturn;
}
/////////////////////////////////////////(7)
int isCuitCuil(char aux[], int len) {
    int i, auxReturn=0;

    if(len==11)
    {
        for(i=0;i<len-1;i++)
        {
            if(aux[i] < '0' || aux[i] > '9')
            {
                auxReturn=-1;
                break;//i++;
            }
        }
    }
    else
    {
        auxReturn=-1;
    }
    return auxReturn;
}
