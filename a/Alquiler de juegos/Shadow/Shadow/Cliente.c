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
#include "Cliente.h"
////////////////////////
#define QTY_CLIENT 100
#define ID_FAIL "No se puede completar un legajo con datos erroneos.\n\n"
////////////////////////////////////////////////////////////////////////// INIT
void initClient(Client pArray[],int size){
    int i;

    for(i=0; i<size; i++)//LIBRE=-1 // OCUPADO=0
    {
        pArray[i].isEmpty = -1;
    }
}
/////////////////////////////////////////////////////////////////////////  ADD
int addClient(Client pArray[], int size){
    int auxReturn=0;
    int freeSpotFlag,freeSpot;
    ////////////
    char pName[51];
    char pLname[51];
    char pSex[51];
    char pTel[51];
    ////////////
    char aux[51];

    freeSpotFlag = searchForEmptyClient(pArray, size ,&freeSpot);
    if(freeSpotFlag == 0)
    {
        printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
    }
    else if(freeSpotFlag == -1)
    {
        printf("\nAlta Codigo Nro.%d: \n", freeSpot);
        /////////////////////////////////////
        auxReturn = getInput(aux, "Ingrese el/los Nombre/s: ","\nIngreso invalido!",0,50,2,3);
        if(auxReturn == 0)
            strcpy(pName,aux);

        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el/los Apellido/s: ","\nIngreso invalido!",0,50,2,3);
            if(auxReturn == 0)
                strcpy(pLname,aux);
        }
        else
            auxReturn=-1;

        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el sexo: ","\nIngreso invalido!",0,2,2,6);
            if(auxReturn == 0)
                    strcpy(pSex,aux);
        }
        else
            auxReturn=-1;

        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el telefono: ","\nIngreso invalido!",0,8,2,7);
            if(auxReturn == 0)
                strcpy(pTel,aux);
        }
        else
            auxReturn=-1;

        if(searchForEmptyClient(pArray,size,&freeSpot)== 0)//BUSCA REPETIDOS
        {
            printf("\n\nEL CODIGO YA EXISTE!!!\n");
        }
        if(auxReturn == 0)
        {
            freeSpotFlag=0;
            pArray[freeSpot].cCode = freeSpot;
            strcpy(pArray[freeSpot].name, pName);
            strcpy(pArray[freeSpot].lName, pLname);
            strcpy(pArray[freeSpot].sex, pSex);
            strcpy(pArray[freeSpot].telephone, pTel);
            pArray[freeSpot].isEmpty=0;
        }
        //////////////////////////////////////////// testeo
        /*printf("\nAuxReturn: %d\n\n",  auxReturn);
        printf("freeSpotFlag: %d\n",  freeSpotFlag);
        printf("id empleado: %d\n", pArray[freeSpot].id);
        printf("freeSpot: %d  isEmpty: %d\n", freeSpot, pArray[freeSpot].isEmpty);
        printf("freeSpot: %d  isEmpty: %d\n", freeSpot+1, pArray[freeSpot+1].isEmpty);*/
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SFE
int searchForEmptyClient(Client pArray[], int size, int* position){
    int flag = 0;
    int i;
    if(pArray != NULL && size>=0 && position!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(pArray[i].isEmpty == -1)
            {
                flag = pArray[i].isEmpty;
                *position = i;
                break;
            }
        }
    }
    return flag;
}
/////////////////////////////////////////////////////////////////////////  FID
int findIdClient(Client pArray[], int size, int *auxId){
    int auxReturn=0;
    int i, value;
    char aux[50];

    if(pArray!= NULL && size>=0)
    {
        auxReturn = getInput(aux, "\n\nIngrese el Codigo de cliente: ","\nIngreso invalido!",0,2000,2,1);
        if(auxReturn == 0)
        {
            value= atoi(aux);
            for(i=0;i<size-1;i++)
            {
                if(pArray[i].isEmpty==-1)
                {
                    continue;
                }
                if(pArray[i].cCode==value)
                {
                    *auxId = value;
                    break;
                }
            }
            if(auxReturn==0 && *auxId!=value)
            {
                printf("\nId No disponible.");
                auxReturn=-1;
            }
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  MODIF
int modifClient(Client pArray[], int size){
    int auxReturn=-1;
    int option, value;
    char aux[6];

    if(pArray!= NULL && size>=0)
    {
        printClient(pArray, QTY_CLIENT);
        auxReturn=findIdClient(pArray, QTY_CLIENT, &value);
        if(auxReturn==0)
        {

            do{
                system ("cls");
                /////////////////////////////////////
                printf("\nMENU MODIFICACION CLIENTE: \n\nCodigo Nro.%d: \n", value);
                printf("\n1)Nombre: %s\n2)Apellido: %s\n3)Telefono: %s\n4)VOLVER\n", pArray[value].name, pArray[value].lName, pArray[value].telephone);
                auxReturn = getInput(aux, "\nIngrese una opcion: ","\nIngreso invalido!",1,5,2,1);
                if(auxReturn == 0){
                    option= atoi(aux);
                }
                fflush(stdin); //__fpurge para Linux
                switch(option)
                {
                    case 1:
                    auxReturn = getInput(aux, "Ingrese el/los Nombre/s: ","\nIngreso invalido!",0,50,2,3);
                    if(auxReturn == 0)
                    {
                        strcpy(pArray[value].name,aux);
                    }
                    break;
                    case 2:
                    auxReturn = getInput(aux, "Ingrese el/los Apellido/s: ","\nIngreso invalido!",0,50,2,3);
                    if(auxReturn == 0)
                    {
                        strcpy(pArray[value].lName,aux);
                    }
                    break;
                    case 3:
                    auxReturn = getInput(aux, "Ingrese el telefono: ","\nIngreso invalido!",0,50,2,3);
                    if(auxReturn == 0)
                    {
                        strcpy(pArray[value].telephone,aux);
                    }
                    break;
                    case 4:
                    printf("Volviendo... ");
                    break;
                    default:
                    printf("Opcion invalida\n");
                    break;
                }
                system("pause");
            }while (option !=4);
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  REMOVE
int removeClient(Client pArray[], int size){
    int auxReturn=0;
    int value;
    char aux[10];


    if(pArray!= NULL && size>=0)
    {
        printClient(pArray, QTY_CLIENT);
        auxReturn=findIdClient(pArray, QTY_CLIENT, &value);
        if(auxReturn==0)
        {
            printf("\nBaja Codigo Nro.%d: \n", value);
            printf("\nNombre: %s\nApellido: %s\n", pArray[value].name, pArray[value].lName);
            ///////////////////////////////////////////////////////////////////////////////////////
            auxReturn = getInput(aux, "\nConfirma la baja? Y/N: ","\nLa Baja no se realizo.",0,2,1,5);
            if(auxReturn==0)
            {
                printf("Baja en curso ...");

                pArray[value].isEmpty = -1;
            }
            else
                auxReturn=-1;
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SFO
int searchForOccurrenceClient(Client pArray[], int size){
    int flag = -1;
    int i;

    if(pArray!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pArray[i].isEmpty == -1)
                continue;
            else if(pArray[i].isEmpty == 0)
            {
                flag = pArray[i].isEmpty;
            }
        }
    }
    return flag;
}
/////////////////////////////////////////////////////////////////////////  PRINT
int printClient(Client pArray[],int size){
    int auxReturn=-1;
    int i;

    if(pArray!=NULL && size>=0)
    {
        printf("CODE\t  APELLIDO\t  NOMBRE\t  SEXO\t  TELEFONO\t\n");
        for(i=0;i<size-1;i++)
        {
            if(pArray[i].isEmpty==0)
            {
                auxReturn=0;
                printf("\n%d\t  %s\t  %s\t  %s\t  %s\t", pArray[i].cCode, pArray[i].lName, pArray[i].name, pArray[i].sex, pArray[i].telephone);
            }
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SORT
int sortClient(Client pArray[], int size){
    int auxReturn=-1;
    int i;

    int pCode;
    char pName[51];
    char pLname[51];
    char pSex[51];
    char pTel[51];
    int pIsEmpty;
    /////////////////////////////////
    if(pArray!=NULL && size>=0)
    {
            for(i=0;i<size-1;i++)
            {
                if(pArray[i].isEmpty!=0)
                    continue;
                else if(strcmp(pArray[i].lName,pArray[i+1].lName)>0)
                {
                    pCode = pArray[i].cCode;
                    strcpy(pName, pArray[i].name);
                    strcpy(pLname, pArray[i].lName);
                    strcpy(pSex, pArray[i].sex);
                    strcpy(pTel, pArray[i].telephone);
                    pIsEmpty = pArray[i].isEmpty;
                    ////////////////////////////////// swap X ascendente step 1
                    pArray[i].cCode = pArray[i+1].cCode;
                    strcpy(pArray[i].name, pArray[i+1].name);
                    strcpy(pArray[i].lName, pArray[i+1].lName);
                    strcpy(pArray[i].sex, pArray[i+1].sex);
                    strcpy(pArray[i].telephone, pArray[i+1].telephone);
                    pArray[i].isEmpty = pArray[i+1].isEmpty;
                    ////////////////////////////////// swap X ascendente step 2
                    pArray[i+1].cCode= pCode;
                    strcpy(pArray[i+1].name, pName);
                    strcpy(pArray[i+1].lName, pLname);
                    strcpy(pArray[i+1].sex, pSex);
                    strcpy(pArray[i+1].telephone, pTel);
                    pArray[i+1].isEmpty = pIsEmpty;
                    ////////////////////////////////// swap X ascendente step 3
                }
            }
        auxReturn=0;
    }
    return auxReturn;
}
