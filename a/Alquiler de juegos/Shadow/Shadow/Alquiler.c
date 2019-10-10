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
#include "Alquiler.h"
#include "Cliente.h"
////////////////////////
#define QTY_RENT 2000
#define QTY_CLIENT 100
#define QTY_GAME 300
#define ID_FAIL "No se puede completar un legajo con datos erroneos.\n\n"
////////////////////////////////////////////////////////////////////////// INIT
void initRent(Rent rArray[],int size){
    int i;

    for(i=0; i<size; i++)//LIBRE=-1 // OCUPADO=0
    {
        rArray[i].isEmpty = -1;
    }
}
/////////////////////////////////////////////////////////////////////////  SFE
int searchForEmptyRent(Rent rArray[], int size, int *pIndex){
    int auxReturn=0; // OJO Q ACA BUSCO UN -1 COMO FLAG DE LIBRE
    int i;
    if(rArray != NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(rArray[i].isEmpty != -1)
                continue;
            if(rArray[i].isEmpty==-1)
            {
                auxReturn = rArray[i].isEmpty;
                *pIndex = i;
                break;
            }
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  ADD
int addRent(Rent rArray[], int size, int *auxCcode, int *auxGcode){
    int auxReturn=0;
    int indexFlag, index;
    int rentID;
    ////////////
    int pCcode;
    int pGcode;
    char pDate[51];
    ////////////
    char aux[51];

    indexFlag = searchForEmptyRent(rArray, size, &index );
    if(indexFlag== 0)
    {
        printf("\n\nNO QUEDAN JUEGOS DISPONIBLES!!!\n");
    }
    else if(indexFlag == -1)
    {
        //rentID = *index // podria tambien tomar la posicion libre de rArray como ID...
        rentID = rentIdGenerator();
        printf("\nAlta Alquiler Nro.%d: \n", rentID);
        /////////////////////////////////////
        pCcode=*auxCcode;
        pGcode=*auxGcode;
        /*/////////////////////////////////////
        if(auxReturn==0)
        {
            auxReturn=findIdGame(gArray, QTY_GAME, &pGameId);
            if(gArray[pGameId].rentFlag!=-1)
            {
                printf("\nJUEGO ALQUILADO\n");
                auxReturn=-1;
            }
        }
        ///////////////////////////////////////*/
        if(auxReturn==0)
        {
            auxReturn = getInput(aux, "Ingrese la fecha (xx/xx/xx): ","\nIngreso invalido!",0,8,2,4);
            if(auxReturn == 0)
            {
                strcpy(pDate,aux);
            }
        }
        ///////////////////////////////////////////////////
        if(searchForEmptyRent(rArray,size,&index)== 0)//BUSCA REPETIDOS
        {
            printf("\n\nEL CODIGO YA EXISTE!!!\n");
        }
        if(auxReturn == 0)
        {
            indexFlag=0;
            rArray[index].rentCode= rentID;
            rArray[index].gameCode = pGcode;
            rArray[index].clientCode = pCcode;
            strcpy(rArray[index].date, pDate);
            rArray[index].isEmpty=0;
        }
        //////////////////////////////////////////// testeo
        /*
        printf("\nAuxReturn: %d\n\n",  auxReturn);
        printf("freeSpotFlag: %d\n",  freeSpotFlag);
        printf("id empleado: %d\n", pArray[freeSpot].id);
        printf("freeSpot: %d  isEmpty: %d\n", freeSpot, pArray[freeSpot].isEmpty);
        printf("freeSpot: %d  isEmpty: %d\n", freeSpot+1, pArray[freeSpot+1].isEmpty);
        */
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  PRINT
int printRent(Rent rArray[],int size){
    int auxReturn=-1;
    int i;

    if(rArray!=NULL && size>=0)
    {
        printf("Cod.Alquiler\t  Cod.Juego\t  Cod.Cliente\t  Fecha\t\n");
        for(i=0;i<size-1;i++)
        {
            if(rArray[i].isEmpty==0)
            {
                auxReturn=0;
                printf("\n  %d\t      %d\t      %d\t      %s\t\n", rArray[i].rentCode, rArray[i].gameCode, rArray[i].clientCode, rArray[i].date);
            }
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  IDG
int rentIdGenerator(){
    static int rentIdCounter=1000; // scoope local.
    rentIdCounter++;
    return rentIdCounter;
}
