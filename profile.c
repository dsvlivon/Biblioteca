/*
 * profile.c
 *
 *  Created on: 11 sep. 2019
 *      Author: Daniel
 */
#include <stdio.h>
#include <stdlib.h>
#include "profile.h"

#define EXIT_FAIL -1

int getAge(int *result, char *msg, char *msgFail, int try)
{
    int i;
    int buffer=result;
	int auxReturn = EXIT_FAIL;
	char class;

    if(buffer != NULL && try > 0)
	{
    	for(i=0;i<try;i++)
		{
    		printf("%s", msg);
            scanf("%d",buffer);
            if(buffer >0||buffer <110)
            {
            	if(buffer>=18)
            	{
            		class="mayor de edad";
            	}
            	else if(buffer>=13 && buffer <18)
            	{
            		class="Adolescente";
            	}
            	else
            	{
            		class="menor de edad";
            	}
            	i=try;
            	auxReturn = 0;
            }
		}
	}
    return auxReturn;
}


