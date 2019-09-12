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

int getAge(int pArray[],int limit)
{
    int i;
	int auxReturn = EXIT_FAIL;

    if(pArray != NULL && limit > 0)
	{
    	auxReturn = 0;
		for(i=0;i<limit;i++)
		{
			printf("\nIngrese la edad de :X");
            scanf("%d",pArray[i]);
		}
	}
    return auxReturn;
}


