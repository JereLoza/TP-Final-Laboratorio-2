#ifndef ASTRONAUTA_H_INCLUDED
#define ASTRONAUTA_H_INCLUDED

#define ARCH_ASTRONAUTAS "archAstronautas.dat"
/// ESTRUCTURA ASTRONAUTA
typedef struct{
    int id;
    char nombre[30];
    char apellido[30];
    char apodo[30];
    int edad;
    char nacionalidad[30];
    char especialidad[30]; // (piloto, astrofísico, ingeniero espacial, biólogo, etc)
    int horasAcumuladas;
    int misionesRealizadas;
    int horasISS;
    int estado; // (1- Activo 2- Retirado)
}stAstronauta;

typedef struct{
    stAstronauta astronauta;
    struct arbolAstronautas* izq;
    struct arbolAstronautas* der;
}arbolAstronautas;

arbolAstronautas* inicArbol();
arbolAstronautas* nuevoNodoArbol(stAstronauta dato);
stAstronauta crearAstronauta(arbolAstronautas* arbol);
stAstronauta masDerecha(arbolAstronautas* arbol);
arbolAstronautas* ingresarAstronautas(arbolAstronautas* arbol);
arbolAstronautas* insertarArbol(arbolAstronautas* arbol, stAstronauta dato);
void mostrarArbol(arbolAstronautas* arbol);
void mostrarAstronauta(stAstronauta astronauta);
arbolAstronautas* archToArbol(arbolAstronautas* arbol, char nombreArch[]);
char pideApodo();
arbolAstronautas* buscaAstronautaPorApodo(arbolAstronautas* arbol, char apodo[]);

#endif // ASTRONAUTA_H_INCLUDED
