/*
 * validations.c
 *
 *  Created on: 11 sep. 2019
 *      Author: Daniel
 */
#define CANTIDAD_NUMEROS 5
#define MAX_INT 65535
#define EXIT_FAIL -1

#include <stdio.h>
#include <stdlib.h>
#include "validations.h"
#include "arrayFunctions.h"
#include "profile.h"


int getInt(int *result, char *msg, char *msgFail, int minus, int maximus, int try)
{
	int auxReturn = EXIT_FAIL;
	int buffer;
	if (result != NULL && msg != NULL && msgFail != NULL && minus < maximus && try >= 0)
	{
		do
		{
			printf("%s", msg);
			fflush(stdin); //__fpurge(stdin); //en windows funciona __fflush para limpiar
			if (scanf("%d", &buffer) == 1 && buffer >= minus && buffer <= maximus)
			{
				auxReturn = EXIT_SUCCESS;
				*result = buffer; //caso de exito
				break; //de aca salgo del while y evito poner el else
			}
			printf("%s", msgFail);
			try--;
		} while (try >= 0);
	}
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
