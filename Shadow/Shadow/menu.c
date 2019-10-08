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
#define FAIL_INITMSG "\n\nNO HAY ID HABILITADOS. \n"
////////////
 int menuX()
 {
    Element pArray[QTY_ELEMENT]; // DECLARO EL ARRAY DE ELEMENTOS

    int auxReturn=-1;
    int option, order;
    char aux[50];

    initElement(pArray,QTY_ELEMENT);//Seteo de array inicial
    do{
        system ("cls");
        printf("        BIENVENIDOS A  U.T.N. F.R.A. \n\n\n1) ALTAS.\n2) MODIFICAR.\n3) BAJAS.\n4) INFORMAR.\n5) SALIR.");
        ///////////////////////////////////////////////
        auxReturn = getInput(aux, "\n\nIngrese una opcion: ","\nIngreso invalido!",1,5,2,1);
        if(auxReturn == 0)
        {
            option= atoi(aux);
        }
        fflush(stdin); //__fpurge para Linux
        auxReturn=-1;
        switch(option)
        {
            case 1:
                auxReturn = addElement(pArray, QTY_ELEMENT);
                //auxReturn = hardCode(arrayEmployee, QTY_EMPLOYEES);
            break;
            case 2:
                auxReturn = searchForOccurrence(pArray, QTY_ELEMENT);
                if(auxReturn== 0)
                {
                    modifElement(pArray, QTY_ELEMENT);
                }
                else
                    printf(FAIL_INITMSG);
            break;
            case 3:
                auxReturn = searchForOccurrence(pArray, QTY_ELEMENT);
                if(auxReturn== 0)
                {
                    removeElement(pArray, QTY_ELEMENT);
                }
                else
                    printf(FAIL_INITMSG);
            break;
            case 4:
                auxReturn = searchForOccurrence(pArray, QTY_ELEMENT);
                if(auxReturn== 0)
                {
                    printf("INFORME: \n");
                    auxReturn = getInput(aux, "\n1)Orden Descendente \n2)Orden Ascendente\n\nIngrese el orden: ","\nIngreso invalido!",1,2,1,1);
                    if(auxReturn==0)
                    {
                        order = atoi(aux);
                        auxReturn = sortElement(pArray, QTY_ELEMENT, order);
                        //////////////////////////////////////////////////////////////
                        if(auxReturn==0)
                        {
                            printElement(pArray,QTY_ELEMENT);
                        }
                    }
                    if(auxReturn==0)
                        informA(pArray, QTY_ELEMENT);
                }
                else
                    printf(FAIL_INITMSG);
            break;
            case 5:
            printf("Saliendo... ");
            break;
            default:
            printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }while (option !=5);
    return auxReturn;
}

