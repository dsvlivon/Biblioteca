#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/*
a)	getInt
b)	getFloat
c)	getChar	    0)isNumeric   1)isDecimal   2)isLetter    3)isAlphaNumeric   4)isOnlyNumber     5)isTelephone      6)isDni    7)isCuitCuil

auxReturn = functionX(&capSpace, "msg", "msgFail", min, max, try, mode);
*/

int main(void)
{
	char aux[50];
	char name [35], lName [35], adress[50];
	int age, id, dnu;
	float salary, high=0, weigth=0;
	int retorno=0;
    //francisco sebastian adalberto = 29
    //TESTEO PARA OBTENER UN LEGAJO
	retorno = getInput(aux, "Ingrese numero de legajo : ","\nIngreso invalido!",1,1000,2,4);
	if(retorno == 0)
    {
        id = atoi(aux);
        printf("El legajo validado es: %d \n\n", id);
    }
    //TESTEO PARA OBTENER UNA EDAD
	retorno = getInput(aux, "Ingrese la edad: ","\nIngreso invalido!",0,120,2,4);
	if(retorno == 0)
    {
        age = atoi(aux);
        printf("La edad validada es: %d \n\n", age);
    }
    //TESTEO PARA OBTENER UN DNU
	retorno = getInput(aux, "Ingrese numero de DNU: ","\nIngreso invalido!",1000000,99999999,2,4);
	if(retorno == 0)
    {
        dnu = atoi(aux);
        printf("El DNU validado es: %d \n\n", dnu);
    }
	//TESTEO PARA OBTENER UN SUELDO
	retorno = getInput(aux, "Ingrese el sueldo: ","\nIngreso invalido!",0,1999999,2,1);
	if(retorno == 0)
    {
        salary = atof(aux);
        printf("El sueldo validado es: %f \n\n", salary);
    }
	//TESTEO PARA OBTENER NOMBRES
	retorno = getInput(aux, "Ingrese un nombre/s: ","\nIngreso invalido!",0,100,2,2);
	if(retorno == 0)
    {
        strcpy(name, aux);
        printf("El nombre validado es: %s\n", name);
    }
    //TESTEO PARA OBTENER APELLIDOS
	retorno = getInput(aux, "Ingrese un apellido/s: ","\nIngreso invalido!",0,100,2,2);
	if(retorno == 0)
    {
        strcpy(lName, aux);
        printf("El apellido validado es: %s\n", lName);
    }
    //TESTEO PARA OBTENER UNA DIRECCION
	retorno = getInput(aux, "Ingrese la direccion: ","\nIngreso invalido!",0,99999,2,3);
	if(retorno == 0)
    {
        strcpy(adress,aux);
        printf("La direccion validada es: %s\n", adress);
    }
    //TESTEO PARA OBTENER UNA ALTURA
	retorno = getInput(aux, "Ingrese la altura en mts: ","\nIngreso invalido!",0,3,2,1);
	if(retorno == 0)
    {
        strcpy(adress,aux);
        printf("La altura validada es: %f\n", high);
    }
    //TESTEO PARA OBTENER UN PESO
	retorno = getInput(aux, "Ingrese su peso en Kg: ","\nIngreso invalido!",0,400,2,1);
	if(retorno == 0)
    {
        strcpy(adress,aux);
        printf("El peso validado es: %f\n", weigth);
    }


    printf("\nFIN DE LA FUNCION.");
	return EXIT_SUCCESS;
}
