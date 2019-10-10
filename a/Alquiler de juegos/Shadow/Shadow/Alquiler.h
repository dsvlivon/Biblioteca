/*******************************************************************
*Programa:ABM Alquiler de juegos
*Objetivo: desarrollo de abm
*Version: 1.0 del 8 de Octubre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
///////////////
typedef struct{
    int rentCode;
    int cCode;
    int gCode;
    int gameCode;
    int clientCode;
    char date[51];
    int isEmpty;
} Rent;
///////////////////////////////////////////////////////////////////////////  Rent
/** initRent
*\brief Inicializa todas las posiciones del array con un valor de posicion libre
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
void initRent(Rent rArray[],int size);
/////////////////////////////////////////////////////////////////////////// INIT
/** addRent
*\brief Agrego datos a los distintos campos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int addRent(Rent rArray[],int size, int *auxCcode, int *auxGcode);
/////////////////////////////////////////////////////////////////////////// ADD
/** printRent
*\brief imprime en pantalla los datos de las posiciones marcadas como ocupado del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int printRent(Rent rArray[], int size);
/////////////////////////////////////////////////////////////////////////// PRINT
/** searchForEmptyRent
*\brief Recorre el array buscando el primer valor de posicion libre disponible
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\param position devuelve la posicion libre en cuestion
*\return void
*/
int searchForEmptyRent(Rent rArray[], int size, int *pIndex);
/////////////////////////////////////////////////////////////////////////// SFE
int rentIdGenerator();
