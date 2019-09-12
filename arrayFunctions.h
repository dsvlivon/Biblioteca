/*
 * arrayFunctions.h
 *
 *  Created on: 11 sep. 2019
 *      Author: Daniel
 */

int getInt(int *pResul,char *pMsg,char *pMsgFail,int minus,int maximus,int try);
int initArrayInt(int array[],int limit,int value );
int printArrayInt(int array[],int limit );
int getArrayInt(int array[],int limit, char *pMsg,char *pMsgFail,int minus,int maximus,int try);
int maxArrayInt(int array[],int limit,int *pResult);
int orderArrayInt(int array[],int limit);
int averageArrayInt(int array[],int limit);
int maxAndMinArray(int array[],int limit);

