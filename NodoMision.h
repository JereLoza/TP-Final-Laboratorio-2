#ifndef NODOMISION_H_INCLUDED
#define NODOMISION_H_INCLUDED
#include "mision.h"

typedef struct{
    stMision nuevo;
    struct nodoMision* ste;
}nodoMision;

nodoMision* inicMis ();
nodoMision* agregarFinal (nodoMision* lista, nodoMision* nuevo);
nodoMision* nuevoNodo (stMision nueva);
nodoMision* buscarUltimo (nodoMision* lista);
nodoMision* modificarxID (int id, nodoMision* lista, arbolAstronautas* arbol);

nodoMision* borrarPrimero (nodoMision* lista);
nodoMision* borrar ///Duda con que puedo hacer la eliminacion particular.

int retID (nodoMision* nuevo);
int retIDNave (nodoMision* nodo);

void mostrarLista(nodoMision* lista);
void mostrarMenu1();
void mostrarMenu2();

#endif // NODOMISION_H_INCLUDED
