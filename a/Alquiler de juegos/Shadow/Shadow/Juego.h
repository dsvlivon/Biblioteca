/*******************************************************************
*Programa:ABM Shadow
*Objetivo: Esqueleto para ABM generico
*Version: 1.0 del 8 de Octubre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
///////////////
typedef struct{
    int gCode;
    char desc[51];
    float price;
    int idCategory;
    int isEmpty;
} Game;
///////////////////////////////////////////////////////////////////////////  Game
/** findIdClient
*\brief Pide un valor para recorrer el array, buscarlo y validar su disponibilidad
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\param auxId es el valor a comparar en la busqueda
*\return void
*/
int finIdGntGame(Game gArray[], int size, int *auxId);
/////////////////////////////////////////////////////////////////////////// FIDC
/** printGame
*\brief imprime en pantalla los datos de las posiciones marcadas como ocupado del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int printGame(Game gArray[],int size);
/////////////////////////////////////////////////////////////////////////// PRINT
