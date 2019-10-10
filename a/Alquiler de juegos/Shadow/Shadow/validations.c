/*******************************************************************
*Programa:ABM Shadow
*Objetivo: Esqueleto para ABM generico
*Version: 1.0 del 8 de Octubre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "validations.h"
//////////////////////////
/* INDICE DE USO
getInput  0)isNumeric   1)isOnlyNumber  2)isDecimal   3)isLetter    4)isDate    5) isAnswer 6)Sexo  7)Telefono  8)Empty Request
auxReturn = getInput(&capSpace, "msg", "msgFail", min, max, try, mode);
*/
////////////////////////////////////////////////////////////////////////////////// GIT
int getInput(char *pResult, char *pMsg, char *pMsgFail, int min, int max, int try, int mode){
    int auxReturn = -1;
	int iBuffer=0;
	int j, length;
	int strQty;
	float fBuffer=0;
	char input[50];
	char cBuffer[100];

	if(pResult!= NULL && (max>min) && try>0 )
	{
		for(j=0;j<try;j++)
		{
            printf("%s", pMsg);
            fflush(stdin);
            fgets (input, sizeof(input), stdin);
           	length=strlen(input);

			switch (mode)
			{
			    case 0:
                auxReturn = isNumeric(input, length);
                break;
			    case 1:
                auxReturn = isOnlyNumber(input, length);
                break;
                case 2:
                auxReturn = isDecimal(input, length);
                break;
                case 3:
                auxReturn = isLetter(input, length);
                break;
                case 4:
                auxReturn = isDate(input, length);
                break;
                case 5:
                auxReturn = isAnswer(input, length);
                break;
                case 6:
                auxReturn = isGender(input, length);
                break;
                case 7:
                auxReturn = isTelephone(input, length);
                break;
                default:
                printf("invalid request");
                break;
            }
            if(auxReturn == 0) // retorno exitoso
            {
                if(mode == 0 || mode == 1) {// salida p/modes enteros
                    iBuffer = atoi(input);
                    if(iBuffer>=min && iBuffer<=max)
                    {   //printf("dentro de max y min");
                        strcpy(pResult, input);
                        break;
                    }
                    else
                    {   //printf("fuera de max y min");
                        printf("%s", pMsgFail);
                        auxReturn=-1;
                    }
                }
                else if(mode == 2) {// salida p/modes flotantes
                    fBuffer = atof(input);
                    if(fBuffer>=min && fBuffer<=max)
                    {
                        strcpy(pResult, input);
                        break;
                    }
                    else
                    {
                        printf("%s", pMsgFail);
                        auxReturn=-1;
                    }
                }
                else if(mode == 3 ) {// salida p/modes string
                    strncpy(cBuffer,input,max);
                    strQty=strlen(cBuffer);
                    fflush(stdin);
                    if(strQty>=min && strQty<max)
                    {
                        strcpy(pResult, input);
                        break;
                    }
                    else
                    {
                        printf("%s", pMsgFail);
                        auxReturn=-1;
                    }
                }
                else if(mode == 5 || mode == 6  || mode == 7 || mode == 4) {
                    strcpy(pResult, input);
                    break;
                }
            }
            else // retorno de error
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
////////////////////////////////////////////////////////////////////////////////// (0) IsNumeric
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
////////////////////////////////////////////////////////////////////////////////// (1) isOnlyNumber
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
////////////////////////////////////////////////////////////////////////////////// (2) isDecimal
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
   }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// (3) isLetter
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
////////////////////////////////////////////////////////////////////////////////// (x) isAlphaNumeric
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
                    break;
                }
            }
		}
	}
   return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// (4) isTelephone
int isDate(char aux[], int len){
    int i;
    int counter=0;
    int auxReturn=0;

    for(i=0;i<len-1;i++)
   	{
        if(aux[i] < '0' || aux[i] > '9') //filtro numerico
        {
            if(aux[i] != '/') //excepciones
            {
                if(aux[i] == '/')
                {
                    counter++;
                }
                if(counter>2)
                {
                    auxReturn = -1;
                    //i++;
                    break;
                    //printf("\nIngrese la fecha en formato xx/xx/xx\n");
                }
            }
        }
	}
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// (5) isAnswer
int isAnswer(char aux[], int len){
 	int i, auxReturn=0;

	for(i=0;i<len-1;i++)
   	//while(aux[i] != '\0' || aux[i] != '\n')
   	{
		if((aux[i] < 'y' || aux[i] > 'y') && (aux[i] < 'Y' || aux[i] > 'Y'))  //filtro confirmacion
		{
            auxReturn = -1;
            break;
   		}
	}
   return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// (6) isGender
int isGender(char aux[], int len){
 	int i, auxReturn=0;

	for(i=0;i<len-1;i++)
   	//while(aux[i] != '\0' || aux[i] != '\n')
   	{
		if((aux[i] < 'f' || aux[i] > 'f') && (aux[i] < 'F' || aux[i] > 'F'))  //filtro confirmacion
		{
            if((aux[i] < 'm' || aux[i] > 'm') && (aux[i] < 'M' || aux[i] > 'M'))
            {
                auxReturn = -1;
            }
   		}
	}
   return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// (7) isTelephone
int isTelephone(char aux[], int len){
    int i;
    int counter=0;
    int auxReturn=0;

    for(i=0;i<len-1;i++)
   	{
        if(aux[i] < '0' || aux[i] > '9') //filtro numerico
        {
            if(aux[i] != '-') //excepciones
            {
                auxReturn = -1;
                //i++;
                break;
            }
        }
        if(aux[i] == '-')
        {
            counter++;
        }
        if(counter>1)
        {
            auxReturn = -1;
            printf("\nIngrese el numero en formato xxxx-xxxx\n");
        }
	}
    return auxReturn;
}
