#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "astronauta.h"
#include "extras.h"


/*********************************************************************//**
*
* \brief Inicia un arbol en nulo
* \return NULL
*
**************************************************************************/
arbolAstronautas* inicArbol(){
    return NULL;
}

/*********************************************************//**
*
* \brief Crea un nodo para un arbol
* \param estructura stAstronauta
* \return arbolAstronautas*
*
*************************************************************/
arbolAstronautas* nuevoNodoArbol(stAstronauta dato){
    arbolAstronautas* nuevo = (arbolAstronautas*) malloc(sizeof(arbolAstronautas));

    nuevo->astronauta = dato;
    nuevo->der = NULL;
    nuevo->izq = NULL;

    return nuevo;
}

stAstronauta crearAstronauta(arbolAstronautas* arbol){
    stAstronauta astronauta;

    astronauta.id = NULL;

    printf("\nIngrese el nombre del astronauta: ");
    fflush(stdin);
    gets(astronauta.nombre);

    printf("\nIngrese el apellido del astronauta: ");
    fflush(stdin);
    gets(astronauta.apellido);

    do{
        printf("\nIngrese el apodo del astronauta: ");
        fflush(stdin);
        gets(astronauta.apodo);

        if(buscaAstronautaPorApodo(arbol, astronauta.apodo)){
            rojo("\nYa existe un astronauta con ese apodo! Ingresa uno distinto!\n");
        }
    }while(buscaAstronautaPorApodo(arbol, astronauta.apodo));

    printf("\nIngrese la edad del astronauta: ");
    scanf("%i", &astronauta.edad);

    printf("\nIngrese la nacionalidad del astronauta: ");
    fflush(stdin);
    gets(astronauta.nacionalidad);

    printf("\nIngrese la especialidad del astronauta: ");
    fflush(stdin);
    gets(astronauta.especialidad);

    printf("\nIngrese las horas acumuladas del astronauta: ");
    scanf("%i", &astronauta.horasAcumuladas);

    printf("\nIngrese las misiones realizadas del astronauta: ");
    scanf("%i", &astronauta.misionesRealizadas);

    printf("\nIngrese las horas en la ISS del astronauta: ");
    scanf("%i", &astronauta.horasISS);

    astronauta.estado = 1;


    return astronauta;
}

stAstronauta masDerecha(arbolAstronautas* arbol){
    stAstronauta masDer;

    if(arbol){
        while(arbol->der != NULL){
            arbol = arbol->der;
        }
    }

    return arbol->astronauta;
}

arbolAstronautas* ingresarAstronautas(arbolAstronautas* arbol){
    char opcion = 's';
    stAstronauta astronauta;
    stAstronauta ultAstronauta;
    int ultimoID;

    do{
        system("cls");
        printf("\tSpace X - Nuevo astronauta\n\n");

        astronauta = crearAstronauta(arbol);

        if(arbol){
            ultAstronauta = masDerecha(arbol);
            astronauta.id = ultAstronauta.id + 1;
        } else{
            astronauta.id = 0;
        }

        arbol = insertarArbol(arbol, astronauta);

        printf("\n\nDesea a%cadir otro astronauta? s/n\n", LETRA_ENIE);
        fflush(stdin);
        opcion = getch();

    }while(opcion == 's');


    return arbol;
}

arbolAstronautas* insertarArbol(arbolAstronautas* arbol, stAstronauta dato){
    if(!arbol){
        arbol = nuevoNodoArbol(dato);
    }
    else{
        if(strcmpi(dato.apodo, arbol->astronauta.apodo) > 0){
            arbol->der = insertarArbol(arbol->der, dato);
        } else{
            arbol->izq = insertarArbol(arbol->izq, dato);
        }
    }

    return arbol;
}

void mostrarArbol(arbolAstronautas* arbol){
    if(arbol){
        mostrarArbol(arbol->izq);
        mostrarAstronauta(arbol->astronauta);
        mostrarArbol(arbol->der);
    }
}



/*********************************************************//**
*
* \brief Muestra un astronauta
* \param arreglo stAstronauta
* \return void
*
*************************************************************/
void mostrarAstronauta(stAstronauta astronauta){
    printf("\n -----------------------------------------------------");
    printf("\n  ID:                          %i", astronauta.id);
    printf("\n  Nombre:                      %s", astronauta.nombre);
    printf("\n  Apellido:                    %s", astronauta.apellido);
    printf("\n  Apodo:                       %s", astronauta.apodo);
    printf("\n  Edad:                        %i", astronauta.edad);
    printf("\n  Nacionalidad:                %s", astronauta.nacionalidad);
    printf("\n  Especialidad:                %s", astronauta.especialidad);
    printf("\n  Horas Acumuladas:            %i", astronauta.horasAcumuladas);
    printf("\n  Misiones Realizadas:         %i", astronauta.misionesRealizadas);
    printf("\n  Horas en la ISS:             %i", astronauta.horasISS);
    printf("\n  Estado:                      %i", astronauta.estado);
    printf("\n -----------------------------------------------------\n");
}

arbolAstronautas* archToArbol(arbolAstronautas* arbol, char nombreArch[]){
    stAstronauta aux;

    FILE *pArchArbol = fopen(nombreArch, "rb");

    if(pArchArbol){
        while(fread(&aux, sizeof(stAstronauta), 1, pArchArbol) > 0){
            arbol = insertarArbol(arbol, aux);
        }

        fclose(pArchArbol);
    }

    return arbol;
}

char pideApodo(){
    char apodo[50];

    printf("Introduce el apodo del astronauta que desea buscar: ");
    fflush(stdin);
    gets(apodo);

    return apodo;
}

arbolAstronautas* buscaAstronautaPorApodo(arbolAstronautas* arbol, char apodo[]){
    arbolAstronautas* rta = NULL;

    if(arbol){
        if(strcmpi(apodo, arbol->astronauta.apodo) == 0){
            rta = arbol;
        }else{
            if(strcmpi(apodo, arbol->astronauta.apodo) > 0){
                rta = buscaAstronautaPorApodo(arbol->der, apodo);
            }else{
                rta = buscaAstronautaPorApodo(arbol->izq, apodo);
            }
        }
    }

    return rta;
}

