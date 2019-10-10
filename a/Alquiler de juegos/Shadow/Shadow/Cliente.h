/*******************************************************************
*Programa:ABM Alquiler de juegos
*Objetivo: desarrollo de abm
*Version: 1.0 del 8 de Octubre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
///////////////
typedef struct{
    int cCode;
    char name[51];
    char lName[51];
    char sex[51];
    char telephone[51];
    int isEmpty;
} Client;
///////////////////////////////////////////////////////////////////////////  Client
/** initCliente
*\brief Inicializa todas las posiciones del array con un valor de posicion libre
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
void initClient(Client pArray[],int size);
/////////////////////////////////////////////////////////////////////////// INIT
/** addCliente
*\brief Agrego datos a los distintos campos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int addClient(Client pArray[], int size);
/////////////////////////////////////////////////////////////////////////// ADD
/** modifCliente
*\brief modifica los datos de los distintos campos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int modifClient(Client pArray[], int size);
/////////////////////////////////////////////////////////////////////////// MODIF
/** removeCLiente
*\brief Realiza la baja logica de los datos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int removeClient(Client pArray[], int size);
/////////////////////////////////////////////////////////////////////////// REMOVE
/** findIdClient
*\brief Pide un valor para recorrer el array, buscarlo y validar su disponibilidad
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\param auxId es el valor a comparar en la busqueda
*\return void
*/
int finIdClient(Client pArray[], int size, int *auxId);
/////////////////////////////////////////////////////////////////////////// FIDC
/** printCliente
*\brief imprime en pantalla los datos de las posiciones marcadas como ocupado del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int printClient(Client pArray[],int size);
/////////////////////////////////////////////////////////////////////////// PRINT
/** searchForEmptyClient
*\brief Recorre el array buscando el primer valor de posicion libre disponible
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\param position devuelve la posicion libre en cuestion
*\return void
*/
int searchForEmptyClient(Client pArray[], int size, int* position);
/////////////////////////////////////////////////////////////////////////// SFE
/** searchForOccurrenceClient
*\brief Recorre el array buscando valores de posicion ocupadas
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int searchForOccurrenceClient(Client pArray[], int size);
/////////////////////////////////////////////////////////////////////////// SFO
/** sortClient
*\brief Realiza uno o más ordenamientos segun un determinado criterio
*\param size indica la longitud del array
*\return void
*/
int sortClient(Client pArray[], int size);
/////////////////////////////////////////////////////////////////////////// SFO
