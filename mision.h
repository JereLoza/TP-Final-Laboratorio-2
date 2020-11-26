#ifndef MISION_H_INCLUDED
#define MISION_H_INCLUDED
#include "NodoMision.h"
#include "astronauta.h"
#define ARCH_MISIONES "archMisiones.dat"

typedef struct{
    stAstronauta astronauta;
    struct tripulantes* sig;
}tripulantes;

typedef struct{
    int id;
    int idNave;
    char estado[30]; // (Listo, En vuelo, Retornada, Cancelada, Fallida)
    char destino[30]; // (EEI, Órbita terrestre, Luna, etc)
    char cargamento[30];// (Satélite, Insumos para la EEI, el Auto de Elon Musk, etc)
    tripulantes* equipo;
    char detalleMision;
}stMision;

typedef struct{
    nodoMision* fin;
    nodoMision* cabecera;
}filaMision;

stMision crearMision (filaMision* norA, filaMision* norB, arbolAstronautas* arbol); ///Recibe astronauta dentro de la funcion
stMision extraerFila (filaMision* fila);
stMision verPrimero (nodoMision* lista);
void mostrarMision (stMision);
void mostrarTripulantes (tripulantes* lista);


void inicFila (filaMision* nueva);
filaMision* agregar (filaMision* Misiones, stMision nueva);
//filaMision* crearNodoFilaLista (filaMision* EstadoA, stMision nuevo); ///Misiones que cumplan con EL ESTADO REQUERIDO
//filaMision* crearNodoFilaAparte(filaMision* EstadoB, stMision nuevo); ///Misiones que NO cumplan con el ESTADO REQUERIDO
filaMision* decideYCrea (filaMision* fila,filaMision* descarte, stMision nueva); ///Decide a cual FILA van las nuevas misiones
filaMision* cambiarEstado (int id, filaMision* fila);
int buscarUltimaID (filaMision* fila);
int buscarUltimaIDNave (filaMision* fila);


tripulantes* crearNodoTripulantes (stAstronauta nuevo);
tripulantes* inicLista();
tripulantes* agregarPpioTripu (tripulantes* lista, tripulantes* nuevo);
tripulantes* borrarxID (tripulantes* lista, int id);



#endif // MISION_H_INCLUDED
