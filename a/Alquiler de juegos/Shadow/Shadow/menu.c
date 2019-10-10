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
#include "Alquiler.h"
#include "Juego.h"
////////////////////////
#define QTY_CLIENT 100
#define QTY_GAME 300
#define QTY_RENT 2000
#define FAIL_INITMSG "\n\nNO HAY CLIENTES HABILITADOS. \n"
////////////
 int menuX()
 {
    Rent rArray[QTY_RENT];// DECLARO EL ARRAY DE ALQUILERES{1000,"Salon",500,102,0},
    Client pArray[QTY_CLIENT]/*={ {0000,"Jon","Doe","m", "4222-1000",0},      {0001,"Jane","Doe","f", "4222-1001",0},
                                {0002,"Jim","Smith","m", "4222-1002",0},    {0003,"Joane","Smith","f", "4222-1003",0},
                                {0004,"Joe","Adams","m", "4222-1004",0},    {0005,"Jenny","Adams","f", "4222-1005",0},
                                {0006,"Jeff","Grant","m", "4222-1002",0},    {0007,"Josie","Grant","f", "4222-1003",0},
    }*/;// DECLARO EL ARRAY DE CLIENTES Hardcodeado // int cCode/char name[51]/char lName[51]/char sex[51]/char telephone[51]/int isEmpty
    Game gArray[QTY_GAME]={ {1000,"Mesa",250,100,0},        {1005,"Mesa",250,100,0},        {1010,"Mesa",150,100,0},
                            {1001,"Azar",120,101,0},        {1006,"Azar",300,101,0},        {1011,"Azar",120,101,0},
                            {1003,"Salon",500,102,0},       {1008,"Salon",500,102,0},       {1013,"Salon",500,102,0},
                            {1002,"Magia",750,103,0},       {1007,"Magia",750,103,0},       {1012,"Magia",750,103,0},
                            {1004,"Estrategia",300,104,0},  {1009,"Estrategia",500,104,0},  {1014,"Estrategia",500,104,0}
    };// DECLARO EL ARRAY DE JUEGOS Hardcodeado  //*int gCode/char desc[51]/float price/int idCategory/int isEmpty
    ////////////////////////////////////////////
    int auxReturn=-1;
    int gOption, cOption;
    char aux[50];
    int pCcode;
    int pGcode;

    initRent(rArray,QTY_RENT);//Seteo de array inicial
    initClient(pArray,QTY_CLIENT);//Seteo de array inicial
    do{
        system ("cls");
        printf("        BIENVENIDOS A  U.T.N. F.R.A. \n\n\n1) CLIENTES.\n2) ALQUILERES.\n3) SALIR.");
        ///////////////////////////////////////////////
        auxReturn = getInput(aux, "\n\nIngrese una opcion: ","\nIngreso invalido!",1,5,2,1);
        if(auxReturn == 0)
        {
            gOption = atoi(aux);
        }

        fflush(stdin); //__fpurge para Linux
        auxReturn=-1;
        switch(gOption)
        {
            case 1:
                do{
                    system ("cls");
                    printf("MENU CLIENTES. \n\n\n1)Alta.\n2)Modificar.\n3)Baja.\n4)Listar\n5)Volver");
                    ///////////////////////////////////////////////
                    auxReturn = getInput(aux, "\n\nIngrese una opcion: ","\nIngreso invalido!",1,5,2,1);
                    if(auxReturn == 0)
                    {
                        cOption = atoi(aux);
                    }
                    fflush(stdin);
                    ///////////////
                    switch(cOption)
                    {
                        case 1:
                            auxReturn = addClient(pArray, QTY_CLIENT);
                        break;
                        //////////
                        case 2:
                            auxReturn = searchForOccurrenceClient(pArray, QTY_CLIENT);
                            if(auxReturn== 0)
                            {
                                modifClient(pArray, QTY_CLIENT);
                            }
                            else
                                printf(FAIL_INITMSG);
                        break;
                        //////////
                        case 3:
                            auxReturn = searchForOccurrenceClient(pArray, QTY_CLIENT);
                            if(auxReturn== 0)
                            {
                                removeClient(pArray, QTY_CLIENT);
                            }
                            else
                                printf(FAIL_INITMSG);
                        break;
                        //////////
                        case 4:
                            auxReturn = searchForOccurrenceClient(pArray, QTY_CLIENT);
                            if(auxReturn== 0)
                            {
                                sortClient(pArray, QTY_CLIENT);
                                printClient(pArray, QTY_CLIENT);
                            }
                            else
                                printf(FAIL_INITMSG);
                        break;
                        //////////
                        case 5:
                            printf("Volviendo... ");
                        break;
                    }
                    system("pause");
            }while (cOption !=5);

            break;
            case 2:
                auxReturn=searchForOccurrenceClient(pArray, QTY_CLIENT);
                if(auxReturn==0)
                {
                    printf("\n\nMENU ALQUILERES\n");
                }
                if(auxReturn==0)
                {
                    printGame(gArray, QTY_GAME);
                    auxReturn=findIdGame(gArray, QTY_GAME, &pGcode);
                    if(auxReturn==0)
                    {
                        printClient(pArray, QTY_CLIENT);
                        auxReturn=findIdClient(pArray, QTY_CLIENT, &pCcode);
                    }
                    if(auxReturn==0)
                    {
                        auxReturn=addRent(rArray, QTY_RENT,&pCcode, &pGcode);
                    }
                    if(auxReturn==0)
                    {
                        printRent(rArray, QTY_RENT);
                    }
                    //addRent(rArray, QTY_RENT,pArray, QTY_CLIENT);
                }
                else
                    printf(FAIL_INITMSG);

            break;
            case 3:
                printf("Saliendo... ");
            break;
            default:
            printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }while (gOption !=3);
    return auxReturn;
}

