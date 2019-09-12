/*
 * validations.c
 *
 *  Created on: 11 sep. 2019
 *      Author: Daniel
 */

#define EXIT_FAIL -1

#include <stdio.h>
#include <stdlib.h>
#include "validations.h"
#include "arrayFunctions.h"
#include "profile.h"


int getInt(int *pResult, char *pMsg, char *pMsgFail, int min, int max, int try)
{
	int auxReturn = EXIT_FAIL -1;
	int buffer;
	do
	{
		printf("%s",pMsg);
		fflush(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= min && buffer <= max)
		{
			*pResult = buffer;
			auxReturn = 0;
			break;
		}
		printf("%s",pMsgFail);
		try--;
	}while(try >= 0);
	return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////////////////
float getFloat(float *result, char *msg, char *msgFail, float minus, float maximus, int try)
{
	int auxReturn = EXIT_FAIL;
	float buffer;
	if (result != NULL && msg != NULL && msgFail != NULL && maximus > minus && try >= 0)
	{
		do
		{
			printf("%s", msg);
			fflush(stdin); //__fpurge(stdin);
			if (scanf("%f", &buffer) == 1)
			{
				if (buffer >= minus && buffer <= maximus)
				{
					auxReturn = 0; //EXIT_SUCCESS;
					*result = buffer;
					break;
				}
			}
			printf("%s", msgFail);
			try--;
		} while (try >= 0);
	}
	return auxReturn;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
char getChar(char *resultChar, char *msgChar, char *msgFailChar, char minus, char maximus, int try)
{
	int auxReturn = EXIT_FAIL;
	char bufferChar;
	if (resultChar != NULL && msgChar != NULL && msgFailChar != NULL && minus < maximus && try >= 0)
	{
		do
		{
			printf("%s", msgChar);
			fflush(stdin); //__fpurge(stdin);
			if (scanf("%c", &bufferChar) == 1)
			{
				if (bufferChar >= minus && bufferChar <= maximus)
				{
					auxReturn = EXIT_SUCCESS;
					*resultChar = bufferChar;
					break;
				}
			}
			printf("%s", msgFailChar);
			try--;
		} while (try >= 0);
	}
	return auxReturn;
}
/////////////////////////01
int isNumeric(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int isLetter(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
//////////////////////////////
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int isAlphaNumeric(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}
/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int isTelephone(char str[])
{
   int i=0;
   int scoreCounter=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
    	   scoreCounter++;
       i++;
   }
   if(scoreCounter==1) // debe tener un guion
        return 1;

    return 0;
}
