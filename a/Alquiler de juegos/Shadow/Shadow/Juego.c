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
#include "Juego.h"
////////////////////////////////////////////////////////////////////////// INIT
void initGame(Game gArray[],int size){
    int i;

    for(i=0; i<size; i++)//LIBRE=-1 // OCUPADO=0
    {
        gArray[i].isEmpty = -1;
    }
    /*for(i=0; i<size; i++)//DISPONIBLE=-1 // ALQUILADO=0
    {
        pArray[i].rentFlag = -1;
    }*/
}
/////////////////////////////////////////////////////////////////////////  FID
int findIdGame(Game gArray[], int size, int *auxId){
    int auxReturn=0;
    int i, value;
    char aux[51];

    if(gArray!= NULL && size>=0)
    {
        auxReturn = getInput(aux, "\n\nIngrese el Codigo de juego: ","\nIngreso invalido!",0,2000,2,1);
        if(auxReturn == 0)
        {
            value= atoi(aux);
            for(i=0;i<size-1;i++)
            {
                if(gArray[i].isEmpty==-1)
                {
                    continue;
                }
                if(gArray[i].gCode == value)
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
/////////////////////////////////////////////////////////////////////////  PRINT
int printGame(Game gArray[],int size){
    int auxReturn=-1;
    int i;

    if(gArray!=NULL && size>=0)
    {
        printf("Codigo\t    Descripcion\t   Precio\t    IdCategoria\t\n");
        for(i=0;i</*size-1*/15;i++)
        {
            if(gArray[i].isEmpty==0)
            {
                auxReturn=0;
                printf("\n%d\t    %s\t   %.2f\t      %d\t", gArray[i].gCode, gArray[i].desc, gArray[i].price, gArray[i].idCategory);
            }
        }
    }
    return auxReturn;
}

//////////////////////////////////////////////////////////////////////////  ADD
/*
int addGame(Game pArray[], int size){
    int auxReturn=0;
    int freeSpotFlag,freeSpot;
    ////////////
    char pDesc[50];
    float pPrice;
    int idCategory;
    ////////////
    char aux[50];

    freeSpotFlag = searchForEmpty(pArray, size ,&freeSpot);
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
        {
            strcpy(pName,aux);
            //printf("El nombre validado es: %s\n", pName);
        }
        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el/los Apellido/s: ","\nIngreso invalido!",0,50,2,3);
            if(auxReturn == 0)
            {
                strcpy(pLname,aux);
                //printf("El apellido validado es: %s\n", pLname);
            }
        }
        else
            {
                auxReturn=-1;
            }
        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el Sueldo: ","\nIngreso invalido!",0,1999999,2,2);
            if(auxReturn == 0)
            {
                pSalary = atof(aux);
                //printf("El sueldo validado es: $%.2f \n\n", pSalary);
            }
        }
        else
        {
            auxReturn=-1;
        }
        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el Sector: ","\nIngreso invalido!",1,5,2,1);
            if(auxReturn == 0)
            {
                pSector = atoi(aux);
                //printf("El sector validado es: %d \n\n", pSector);
            }
        }
         else
        {
            auxReturn=-1;
        }
        if(searchForEmpty(pArray,size,&freeSpot)== 0)
        {
            printf("\n\nEL LEGAJO YA EXISTE!!!\n");
        } //BUSCA REPETIDOS
        if(auxReturn == 0)
        {
            freeSpotFlag=0;
            pArray[freeSpot].id = freeSpot;
            strcpy(pArray[freeSpot].name,pName);
            strcpy(pArray[freeSpot].lName,pLname);
            pArray[freeSpot].salary = pSalary;
            pArray[freeSpot].sector = pSector;
            pArray[freeSpot].isEmpty=0;
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SFE
int searchForEmptyGame(Game pArray[], int size, int* position){
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
/////////////////////////////////////////////////////////////////////////  MODIF
int modifGame(Game pArray[], int size){
    int auxReturn=-1;
    int option, value;
    char aux[6];

    if(pArray!= NULL && size>=0)
    {
        printElement(pArray, QTY_ELEMENT);
        auxReturn=findId(pArray, QTY_ELEMENT, &value);
        if(auxReturn==0)
        {

            do{
                system ("cls");
                /////////////////////////////////////
                printf("\nMENU MODIFICACIONES: \n\nLegajo Nro.%d: \n", value);
                printf("\n1)Nombre: %s\n2)Apellido: %s\n3)Sueldo: $%.2f\n4)Sector: %d\n5)VOLVER\n", pArray[value].name, pArray[value].lName, pArray[value].salary, pArray[value].sector);
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
                    auxReturn = getInput(aux, "Ingrese el Sueldo: ","\nIngreso invalido!",0,1999999,2,2);
                    if(auxReturn == 0)
                    {
                        pArray[value].salary = atof(aux);
                    }
                    break;
                    case 4:
                    auxReturn = getInput(aux, "Ingrese el Sector: ","\nIngreso invalido!",1,5,2,1);
                    if(auxReturn == 0)
                    {
                        pArray[value].sector = atoi(aux);
                    }
                    break;
                    case 5:
                    printf("Volviendo... ");
                    break;
                    default:
                    printf("Opcion invalida\n");
                    break;
                }
                system("pause");
            }while (option !=5);
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  REMOVE
int removeGame(Game pArray[], int size){
    int auxReturn=0;
    int value;
    char aux[10];
    char empty[50];

    if(pArray!= NULL && size>=0)
    {
        printElement(pArray, QTY_ELEMENT);
        auxReturn=findId(pArray, QTY_ELEMENT, &value);
        if(auxReturn==0)
        {
            printf("\nBaja Legajo Nro.%d: \n", value);
            printf("\nNombre: %s\nApellido: %s\nSueldo: $%.2f\nSector: %d", pArray[value].name, pArray[value].lName, pArray[value].salary, pArray[value].sector);
            ///////////////////////////////////////////////////////////////////////////////////////
            auxReturn = getInput(aux, "\nConfirma la baja? Y/N: ","\nLa Baja no se realizo.",0,2,1,5);
            if(auxReturn==0)
            {
                printf("Baja en curso ...");
                strcpy(pArray[value].name, empty);
                strcpy(pArray[value].lName, empty);
                pArray[value].salary = 0;
                pArray[value].sector = 0;
                pArray[value].isEmpty = -1;
            }
            else
                auxReturn=-1;
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SFO
int searchForOccurrenceGame(Game pArray[], int size){
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
*/
