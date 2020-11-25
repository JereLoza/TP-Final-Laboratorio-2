#include "extras.h"

/*********************************************************//**
*
* \brief Transforma el texto en rojo
* \param char texto[]
* \return void
*
*************************************************************/
void rojo(char texto[]){
    printf("\033[1;31m%s\033[0m", texto);
}

/*********************************************************//**
*
* \brief Transforma el texto en verde
* \param char texto[]
* \return void
*
*************************************************************/
void verde(char texto[]){
    printf("\033[0;32m%s\033[0m", texto);
}

/*********************************************************//**
*
* \brief Transforma el texto en amarillo
* \param char texto[]
* \return void
*
*************************************************************/
void amarillo(char texto[]){
    printf("\033[0;33m%s\033[0m", texto);
}
