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
#include "arrayStruct.h"
#include "arraInforms.h"
////////////////////////
#define QTY_ELEMENT 2000
#define ID_FAIL "No se puede completar un legajo con datos erroneos.\n\n"
/////////////////////////////////////////////////////////////////////////  Inform A
int informA(Element pArray[], int size){
    int auxReturn = -1;
    int i;
    int eToken=0;
    int sToken=0;
    float sBuffer=0;

    if(pArray!= NULL && size>=0)
    {
        for(i=0;i<size-1;i++)
        {
            if(pArray[i].isEmpty == -1)
                continue;
            else if(pArray[i].isEmpty == 0)
            {
                eToken++;
                sBuffer = sBuffer + pArray[i].salary;
            }
        }

        printf("\n\nNOMINA SALARIAL: %.2f", sBuffer);
        printf("\nSUELDO PROMEDIO: %.2f", sBuffer/eToken);

        for(i=0;i<size-1;i++)
        {
            if(pArray[i].isEmpty == 0 && pArray[i].salary > sBuffer/eToken)
            {
                sToken++;
            }
        }
        printf("\n\nEmpleados que superan el salario promedio: %d\n", sToken);
    }
    return auxReturn;
}
